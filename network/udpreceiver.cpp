#include "udpreceiver.h"

UdpReceiver::UdpReceiver() {
    //mapObjects.push_back(new MapObject(1, 39.9251164, 32.6899684, "UAV-01", 12.2, 450, 54));

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::AnyIPv4, 5000);

    connect(udpSocket, &QUdpSocket::readyRead, this, &UdpReceiver::readData);
}

UdpReceiver::~UdpReceiver() {
    for(MapObject *m: mapObjects) {
        delete m;
    }
    mapObjects.clear();

    delete udpSocket;
}

void UdpReceiver::readData()
{
    while(udpSocket->hasPendingDatagrams()) // okunammış udp paketi var mı ?
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;

        udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        QJsonParseError parseError;

        QJsonDocument doc = QJsonDocument::fromJson(datagram, &parseError);

        QJsonObject obj = doc.object();

        int id = obj["Id"].toInt();
        std::string name =obj["Name"].toString().toStdString();
        float lat = static_cast<float>(obj["Lat"].toDouble());
        float lon = static_cast<float>(obj["Lon"].toDouble());
        float distance = static_cast<float>(obj["Distance"].toDouble());
        float altitude = static_cast<float>(obj["Altitude"].toDouble());
        int speed = obj["Speed"].toInt();

        MapObject *mapObject = new MapObject(id, lat, lon, name, distance, altitude,speed);

        mapObjects.push_back(mapObject);

        qDebug() << "----- MAP OBJECT -----";
        qDebug() << "Id:" << id;
        qDebug() << "Name:" << name;
        qDebug() << "Lat:" << lat;
        qDebug() << "Lon:" << lon;
        qDebug() << "Distance:" << distance;
        qDebug() << "Altitude:" << altitude;
        qDebug() << "Speed:" << speed;
    }
}