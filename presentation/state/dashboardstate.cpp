#include "dashboardstate.h"
#include <iostream>

DashboardState::DashboardState(std::vector<BaseReceiver*> receivers): receivers(receivers) {
    for (BaseReceiver* receiver : receivers) {
        if (receiver) {
            connect(receiver, &BaseReceiver::dataReceived, this, &DashboardState::onRawDataReceived);
        }
    }
}

void DashboardState::onRawDataReceived(std::vector<MapObject> mapObjects)
{
    if(mapObjects.size() > 0) {
        for(MapObject m: mapObjects) {
            mapObjectsState.emplace(m.getId(), m);
        }

        emit objectsUpdated(mapObjectsState);
    }
}

MapObject DashboardState::getMapObject(int id) {
    return this->mapObjectsState.at(id);
}