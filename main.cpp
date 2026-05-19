#include "dashboardwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DashboardState state;
    DashboardWindow w(&state);
    w.show();
    return QApplication::exec();
}
