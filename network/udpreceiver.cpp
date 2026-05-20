#include "udpreceiver.h"
#include <iostream>

UdpReceiver::UdpReceiver() {
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::AnyIPv4, 5000);

    connect(udpSocket, &QUdpSocket::readyRead, this, &UdpReceiver::readData);
}

UdpReceiver::~UdpReceiver() {
}

void UdpReceiver::readData()
{
    QList<MapObject*> mapObjects;
    while(udpSocket->hasPendingDatagrams()) // okunammış udp paketi var mı ?
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());

        udpSocket->readDatagram(datagram.data(), datagram.size());

        QJsonDocument doc = QJsonDocument::fromJson(datagram);

        QJsonObject obj = doc.object();

        int id = obj["Id"].toInt();
        QString name = obj["Name"].toString();
        float lat = static_cast<float>(obj["Lat"].toDouble());
        float lon = static_cast<float>(obj["Lon"].toDouble());
        float distance = static_cast<float>(obj["Distance"].toDouble());
        float altitude = static_cast<float>(obj["Altitude"].toDouble());
        int speed = obj["Speed"].toInt();

        MapObject *mapObject = new MapObject(id, lat, lon, name, distance, altitude,speed);

        mapObjects.append(mapObject);
    }

    if (!mapObjects.empty()) {
        emit dataReceived(mapObjects);
    }
}