#ifndef DASHBOARDSTATE_H
#define DASHBOARDSTATE_H

#include <QObject>
#include "mapobject.h"

class DashboardState: public QObject
{
    Q_OBJECT
public:
    DashboardState();

    std::vector<MapObject> &getMapObjects();

public slots:
    void onMapObjectReceived(std::vector<MapObject> &mapObjects);

signals:
    void objectsChanged(std::vector<MapObject> &mapObjects);

private:
    std::vector<MapObject> mapObjects;
};

#endif // DASHBOARDSTATE_H
