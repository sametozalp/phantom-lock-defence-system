#include "dashboardwindow.h"

#include <QApplication>
#include "udpreceiver.h"
#include "tcpreceiver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UdpReceiver udpReceiver;
    TcpReceiver tcpReceiver;
    DashboardState state(&udpReceiver);
    DashboardWindow w(&state);
    w.show();
    return QApplication::exec();
}
