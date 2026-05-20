#include "tcpreceiver.h"
#include <iostream>

TcpReceiver::TcpReceiver() {
    tcpServer = new QTcpServer(this);
    clientSocket = nullptr;

    if (!tcpServer->listen(QHostAddress::AnyIPv4, 5001)) {
        qDebug() << "TCP Server başlatılamadı:" << tcpServer->errorString();
    } else {
        qDebug() << "TCP Server port 5001 üzerinde dinleniyor...";
    }

    connect(tcpServer, &QTcpServer::newConnection, this, &TcpReceiver::onNewConnection);
}

TcpReceiver::~TcpReceiver() {
    if (clientSocket) {
        clientSocket->close();
    }
    tcpServer->close();
}

void TcpReceiver::onNewConnection()
{
    clientSocket = tcpServer->nextPendingConnection();

    qDebug() << "Yeni bir istemci bağlandı:" << clientSocket->peerAddress().toString();

    connect(clientSocket, &QTcpSocket::readyRead, this, &TcpReceiver::readData);

    connect(clientSocket, &QTcpSocket::disconnected, this, &TcpReceiver::onClientDisconnected);
}

void TcpReceiver::readData()
{
    if (!clientSocket) return;

    QList<MapObject*> mapObjects;
    QByteArray datagram = clientSocket->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(datagram);

    if (!doc.isNull() && doc.isObject())
    {
        QJsonObject obj = doc.object();

        int id = obj["Id"].toInt();
        QString name = obj["Name"].toString();
        float lat = static_cast<float>(obj["Lat"].toDouble());
        float lon = static_cast<float>(obj["Lon"].toDouble());
        float distance = static_cast<float>(obj["Distance"].toDouble());
        float altitude = static_cast<float>(obj["Altitude"].toDouble());
        int speed = obj["Speed"].toInt();

        MapObject *mapObject = new MapObject(id, lat, lon, name, distance, altitude, speed);
        mapObjects.append(mapObject);
    }

    if (!mapObjects.empty()) {
        emit dataReceived(mapObjects);
    }
}

void TcpReceiver::onClientDisconnected()
{
    if (clientSocket) {
        qDebug() << "Not connected..";
        clientSocket->deleteLater();
        clientSocket = nullptr;
    }
}