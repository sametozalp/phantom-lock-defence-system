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
