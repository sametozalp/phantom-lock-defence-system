#include "dashboardstate.h"
#include <iostream>

DashboardState::DashboardState(std::vector<BaseReceiver*> receivers): receivers(receivers) {
    for (BaseReceiver* receiver : receivers) {
        if (receiver) {
            connect(receiver, &BaseReceiver::dataReceived, this, &DashboardState::onRawDataReceived);
        }
    }
}

std::vector<MapObject> &DashboardState::getMapObjects() {
    return this->mapObjects;
}

void DashboardState::onRawDataReceived(std::vector<MapObject> mapObjects)
{
    if(mapObjects.size() > 0)
        emit objectsUpdated(mapObjects);
}