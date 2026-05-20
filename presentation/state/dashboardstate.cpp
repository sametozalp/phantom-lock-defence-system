#include "dashboardstate.h"
#include <iostream>

DashboardState::DashboardState(QList<BaseReceiver*> receivers): receivers(receivers) {
    for (BaseReceiver* receiver : receivers) {
        if (receiver) {
            connect(receiver, &BaseReceiver::dataReceived, this, &DashboardState::onRawDataReceived);
        }
    }
}

DashboardState::~DashboardState() {
    for (std::pair<const int, MapObject*>& pair : mapObjectsState) {
        delete pair.second;
    }
    mapObjectsState.clear();
}

void DashboardState::onRawDataReceived(QList<MapObject*> mapObjects)
{
    if(mapObjects.size() > 0) {
        for(MapObject *m: mapObjects) {
            std::unordered_map<int, MapObject*>::iterator it = mapObjectsState.find(m->getId());

            // != and end() are mean -> is it exist ?
            if (it != mapObjectsState.end()) {
                delete it->second;
            }
            mapObjectsState[m->getId()] = m;
        }

        emit objectsUpdated(mapObjectsState);
    }
}

MapObject* DashboardState::getMapObject(int id) {
    return this->mapObjectsState.at(id);
}

int DashboardState::getSelectedMarkerId() const {
    return selectedMarkerId;
}

void DashboardState::setSelectedMarkerId(int id) {
    if (selectedMarkerId != id) {
        selectedMarkerId = id;
        emit selectedMarkerChanged(id);
    }
}