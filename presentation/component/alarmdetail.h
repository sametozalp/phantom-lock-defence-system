#ifndef ALARMDETAIL_H
#define ALARMDETAIL_H

#include <QWidget>

namespace Ui {
class AlarmDetail;
}

class AlarmDetail : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmDetail(QWidget *parent = nullptr);
    ~AlarmDetail();

private:
    Ui::AlarmDetail *ui;
};

#endif // ALARMDETAIL_H
