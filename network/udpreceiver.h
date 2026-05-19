#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <vector>
#include "mapobject.h"
#include <QObject>
#include <QUdpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

class UdpReceiver: public QObject
{
public:
    UdpReceiver();
    ~UdpReceiver();

private slots:
    void readData();

private:
    std::vector<MapObject*> mapObjects;

    QUdpSocket *udpSocket;

};

#endif // UDPRECEIVER_H
