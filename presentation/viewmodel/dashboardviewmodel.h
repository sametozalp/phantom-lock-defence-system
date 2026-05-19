#ifndef DASHBOARDVIEWMODEL_H
#define DASHBOARDVIEWMODEL_H

#include "udpreceiver.h"
#include "dashboardstate.h"

class DashboardViewModel: public QObject
{
    Q_OBJECT
public:
    DashboardViewModel(DashboardState *state, UdpReceiver *udpReceiver);
    ~DashboardViewModel();

public slots:
    void onRawDataReceived(std::vector<MapObject> mapObjects);

private:
    DashboardState *state;
    UdpReceiver *udpReceiver;
};

#endif // DASHBOARDVIEWMODEL_H