#ifndef TCPRECEIVER_H
#define TCPRECEIVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "basereceiver.h"

class TcpReceiver : public BaseReceiver
{
    Q_OBJECT
public:
    TcpReceiver();
    ~TcpReceiver();

private slots:
    void onNewConnection();
    void readData() override;
    void onClientDisconnected();

private:
    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;
};

#endif // TCPRECEIVER_H