#include "dashboardwindow.h"
#include "./ui_dashboardwindow.h"
#include <iostream>

DashboardWindow::DashboardWindow(DashboardViewModel *viewmodel, DashboardState *state, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DashboardWindow)
    , viewmodel(viewmodel)
    , state(state)
{
    ui->setupUi(this);
    connect(state, &DashboardState::objectsChanged, this, &DashboardWindow::refreshUI);
}

DashboardWindow::~DashboardWindow()
{
    delete ui;
}

void DashboardWindow::refreshUI(std::vector<MapObject> &mapObjects)
{
    for (MapObject m: mapObjects)
    {
        // show on map
    }
}