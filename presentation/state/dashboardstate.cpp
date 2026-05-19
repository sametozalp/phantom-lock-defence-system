#include "dashboardstate.h"
#include <iostream>

DashboardState::DashboardState(UdpReceiver *udpReceiver): udpReceiver(udpReceiver) {
    connect(udpReceiver, &UdpReceiver::dataReceived, this, &DashboardState::onRawDataReceived);
}

std::vector<MapObject> &DashboardState::getMapObjects() {
    return this->mapObjects;
}

void DashboardState::onRawDataReceived(std::vector<MapObject> mapObjects)
{
    if(mapObjects.size() > 0)
        emit objectsUpdated(mapObjects);
}