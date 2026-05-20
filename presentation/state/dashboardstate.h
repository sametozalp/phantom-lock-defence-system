#ifndef DASHBOARDSTATE_H
#define DASHBOARDSTATE_H

#include <QObject>
#include "mapobject.h"
#include "basereceiver.h"
#include <unordered_map>

class DashboardState: public QObject
{
    Q_OBJECT
public:
    DashboardState(std::vector<BaseReceiver*> receivers);

    MapObject getMapObject(int id);

public slots:
    void onRawDataReceived(std::vector<MapObject> mapObjects);

signals:
    void objectsUpdated(std::unordered_map<int, MapObject> mapObjectsState);

private:
//    std::vector<MapObject> mapObjects;
    std::vector<BaseReceiver*> receivers;
    std::unordered_map<int, MapObject> mapObjectsState;
};

#endif // DASHBOARDSTATE_H
