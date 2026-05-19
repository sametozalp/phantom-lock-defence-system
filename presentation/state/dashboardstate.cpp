#include "dashboardstate.h"

DashboardState::DashboardState() {}

std::vector<MapObject> &DashboardState::getMapObjects() {
    return this->mapObjects;
}

void DashboardState::onMapObjectReceived(std::vector<MapObject> &mapObjects) {
    this->mapObjects = mapObjects;
    emit objectsChanged(this->mapObjects);
}