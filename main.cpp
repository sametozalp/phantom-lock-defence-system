#include "dashboardwindow.h"

#include <QApplication>
#include "udpreceiver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UdpReceiver udpReceiver;
    DashboardState state;
    DashboardWindow w(&state);
    w.show();
    return QApplication::exec();
}
