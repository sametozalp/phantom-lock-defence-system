#ifndef DASHBOARDSTATE_H
#define DASHBOARDSTATE_H

#include <QObject>
#include "mapobject.h"
#include "basereceiver.h"

class DashboardState: public QObject
{
    Q_OBJECT
public:
    DashboardState(BaseReceiver *receiver);

    std::vector<MapObject> &getMapObjects();

public slots:
    void onRawDataReceived(std::vector<MapObject> mapObjects);

signals:
    void objectsUpdated(std::vector<MapObject> mapObjects);

private:
    std::vector<MapObject> mapObjects;
    BaseReceiver *receiver;
};

#endif // DASHBOARDSTATE_H
