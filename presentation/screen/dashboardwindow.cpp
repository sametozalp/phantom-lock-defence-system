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
    connect(state, &DashboardState::selectedMarkerChanged, this, &DashboardWindow::showVehicleDetail);
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
    
    if (state->getSelectedMarkerId() != -1) {
        MapObject *m = state->getMapObject(state->getSelectedMarkerId());
        if (m) {
            ui->vehicleDetail->setMapObject(m);
        }
    }
}

void DashboardWindow::showVehicleDetail(int id) {
    state->setSelectedMarkerId(id);
    MapObject *m = state->getMapObject(id);
    ui->vehicleDetail->setMapObject(m);
}