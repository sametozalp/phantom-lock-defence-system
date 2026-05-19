#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <vector>
#include "mapobject.h"

class UdpReceiver
{
public:
    UdpReceiver();
    ~UdpReceiver();

private:
    std::vector<MapObject*> mapObjects;
};

#endif // UDPRECEIVER_H
