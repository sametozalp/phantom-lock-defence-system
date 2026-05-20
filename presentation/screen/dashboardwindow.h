#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>
#include "dashboardstate.h"
#include "../component/map/mapmarker.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class DashboardWindow;
}
QT_END_NAMESPACE

class DashboardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DashboardWindow(DashboardState *state, QWidget *parent = nullptr);
    ~DashboardWindow() override;

    void showVehicleDetail(int id);

private slots:
    void refreshUI(std::unordered_map<int, MapObject*> mapObjectsState);

private:
    Ui::DashboardWindow *ui;
    DashboardState *state;
    MapMarker *mapMarker;
};
#endif // DASHBOARDWINDOW_H
