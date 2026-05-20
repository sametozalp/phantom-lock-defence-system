#include "dashboardwindow.h"
#include "./ui_dashboardwindow.h"
#include <iostream>

DashboardWindow::DashboardWindow(DashboardState *state, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DashboardWindow)
    , state(state)
{
    ui->setupUi(this);
    connect(state, &DashboardState::objectsUpdated, this, &DashboardWindow::refreshUI);
}

DashboardWindow::~DashboardWindow()
{
    delete ui;
}

void DashboardWindow::refreshUI(std::unordered_map<int, MapObject*> mapObjectsState)
{
    qDebug() << mapObjectsState.size();
}