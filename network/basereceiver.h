#ifndef BASERECEIVER_H
#define BASERECEIVER_H
#include <QObject>
#include "mapobject.h"
#include <vector>

class BaseReceiver: public QObject
{
    Q_OBJECT
public:
    BaseReceiver();

protected slots:
    virtual void readData() = 0;

signals:
    void dataReceived(std::vector<MapObject> mapObjects);
};

#endif // BASERECEIVER_H
