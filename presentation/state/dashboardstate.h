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
    DashboardState(QList<BaseReceiver*> receivers);
    ~DashboardState();

    MapObject* getMapObject(int id);

public slots:
    void onRawDataReceived(QList<MapObject*> mapObjects);

signals:
    void objectsUpdated(std::unordered_map<int, MapObject*> mapObjectsState);

private:
    QList<BaseReceiver*> receivers;
    std::unordered_map<int, MapObject*> mapObjectsState;
};

#endif // DASHBOARDSTATE_H
