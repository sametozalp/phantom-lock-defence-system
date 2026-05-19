#include "udpreceiver.h"
#include <iostream>

UdpReceiver::UdpReceiver() {
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::AnyIPv4, 5000);

    connect(udpSocket, &QUdpSocket::readyRead, this, &UdpReceiver::readData);
}

UdpReceiver::~UdpReceiver() {
    delete udpSocket;
}

void UdpReceiver::readData()
{
    std::vector<MapObject> mapObjects;
    while(udpSocket->hasPendingDatagrams()) // okunammış udp paketi var mı ?
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());

        udpSocket->readDatagram(datagram.data(), datagram.size());

        QJsonDocument doc = QJsonDocument::fromJson(datagram);

        QJsonObject obj = doc.object();

        int id = obj["Id"].toInt();
        std::string name =obj["Name"].toString().toStdString();
        float lat = static_cast<float>(obj["Lat"].toDouble());
        float lon = static_cast<float>(obj["Lon"].toDouble());
        float distance = static_cast<float>(obj["Distance"].toDouble());
        float altitude = static_cast<float>(obj["Altitude"].toDouble());
        int speed = obj["Speed"].toInt();

        MapObject mapObject(id, lat, lon, name, distance, altitude,speed);

        mapObjects.push_back(mapObject);
    }

    if (!mapObjects.empty()) {
        emit dataReceived(mapObjects);
    }
}