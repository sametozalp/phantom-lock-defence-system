#ifndef DASHBOARDSTATE_H
#define DASHBOARDSTATE_H

#include <QObject>
#include "mapobject.h"
#include "udpreceiver.h"

class DashboardState: public QObject
{
    Q_OBJECT
public:
    DashboardState(UdpReceiver *udpReceiver);

    std::vector<MapObject> &getMapObjects();

public slots:
    void onRawDataReceived(std::vector<MapObject> mapObjects);

signals:
    void objectsUpdated(std::vector<MapObject> mapObjects);

private:
    std::vector<MapObject> mapObjects;
    UdpReceiver *udpReceiver;
};

#endif // DASHBOARDSTATE_H
