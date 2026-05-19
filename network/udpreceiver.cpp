#include "udpreceiver.h"

UdpReceiver::UdpReceiver() {
    mapObjects.push_back(new MapObject(1, 39.9251164, 32.6899684, "UAV-01", 12.2, 450, 54));
}

UdpReceiver::~UdpReceiver() {
    for(MapObject *m: mapObjects) {
        delete m;
    }
    mapObjects.clear();
}