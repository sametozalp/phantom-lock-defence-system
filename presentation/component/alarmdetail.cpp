#include "alarmdetail.h"
#include "ui_alarmdetail.h"

AlarmDetail::AlarmDetail(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AlarmDetail)
{
    ui->setupUi(this);
}

AlarmDetail::~AlarmDetail()
{
    delete ui;
}
