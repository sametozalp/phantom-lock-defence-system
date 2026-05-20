#include "dashboardwindow.h"
#include "./ui_dashboardwindow.h"
#include <iostream>
#include <QVariantList>
#include <QVariantMap>
#include <QQmlContext>

DashboardWindow::DashboardWindow(DashboardState *state, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DashboardWindow)
    , state(state)
    , mapMarker(new MapMarker(this))
{
    ui->setupUi(this);
    connect(state, &DashboardState::objectsUpdated, this, &DashboardWindow::refreshUI);
    connect(mapMarker, &MapMarker::markerClicked, this, &DashboardWindow::showVehicleDetail);
    
    ui->quickWidget->rootContext()->setContextProperty("mapMarker", mapMarker);
}

DashboardWindow::~DashboardWindow()
{
    delete mapMarker;
    delete ui;
}

void DashboardWindow::refreshUI(std::unordered_map<int, MapObject*> mapObjectsState)
{    
    QVariantList markers;
    for (const auto& pair : mapObjectsState) {
        MapObject* obj = pair.second;
        QVariantMap marker;
        marker["id"] = obj->getId();
        marker["lat"] = obj->getLat();
        marker["lon"] = obj->getLon();
        markers.append(marker);
    }
    
    mapMarker->setMarkers(markers);
}

void DashboardWindow::showVehicleDetail(int id) {
    MapObject *m = state->getMapObject(id);
    ui->vehicleDetail->setMapObject(m);
}