#include "vehicledetail.h"
#include "ui_vehicledetail.h"

VehicleDetail::VehicleDetail(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VehicleDetail)
{
    ui->setupUi(this);
}

VehicleDetail::~VehicleDetail()
{
    delete ui;
}

void VehicleDetail::setMapObject(MapObject *m) {
    this->ui->vehicleName->setText(m->getName());
    this->ui->distance->setText(QString::number(m->getDistance()) + " km");
    this->ui->altitude->setText(QString::number(m->getAltitude()) + " m");
    this->ui->speed->setText(QString::number(m->getSpeed()) + " km/h");
}