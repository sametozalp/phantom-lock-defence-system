#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <QObject>
#include <QUdpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "baseReceiver.h"

class UdpReceiver: public BaseReceiver
{
    Q_OBJECT
public:
    UdpReceiver();
    ~UdpReceiver();

protected slots:
    void readData() override;

private:
    QUdpSocket *udpSocket;

};

#endif // UDPRECEIVER_H
