#include "dashboardwindow.h"

#include <QApplication>
#include "udpreceiver.h"
#include "dashboardviewmodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UdpReceiver udpReceiver;
    DashboardState state;
    DashboardViewModel dashboardViewModel(&state, &udpReceiver);
    DashboardWindow w(&dashboardViewModel, &state);
    w.show();
    return QApplication::exec();
}
