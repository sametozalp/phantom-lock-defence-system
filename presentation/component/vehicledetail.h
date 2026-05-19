#ifndef VEHICLEDETAIL_H
#define VEHICLEDETAIL_H

#include <QWidget>

namespace Ui {
class VehicleDetail;
}

class VehicleDetail : public QWidget
{
    Q_OBJECT

public:
    explicit VehicleDetail(QWidget *parent = nullptr);
    ~VehicleDetail();

private:
    Ui::VehicleDetail *ui;
};

#endif // VEHICLEDETAIL_H
