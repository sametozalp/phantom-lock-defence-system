#include "mapobject.h"

MapObject::MapObject(int id, float lat, float lon, QString name, float distance, float altitude, int speed) {
    this->id = id;
    this->lat = lat;
    this->lon = lon;
    this->name = name;
    this->speed = speed;
    this->distance = distance;
    this->altitude = altitude;
}

int MapObject::getId() {
    return this->id;
}