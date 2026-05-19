#include "dashboardviewmodel.h"

DashboardViewModel::DashboardViewModel(DashboardState *state, UdpReceiver *udpReceiver): state(state), udpReceiver(udpReceiver) {
    connect(udpReceiver, &UdpReceiver::dataReceived, this, &DashboardViewModel::onRawDataReceived);
}

DashboardViewModel::~DashboardViewModel(){
}

void DashboardViewModel::onRawDataReceived(std::vector<MapObject> mapObjects)
{
    if (state) {
        state->onMapObjectReceived(mapObjects);
    }
}