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
    Q_OBJECT
public:
    UdpReceiver();
    ~UdpReceiver();

private slots:
    void readData();

signals:
    void dataReceived(std::vector<MapObject> mapObjects);

private:
    QUdpSocket *udpSocket;

};

#endif // UDPRECEIVER_H
