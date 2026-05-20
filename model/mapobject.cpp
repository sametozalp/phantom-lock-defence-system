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

int MapObject::getId() const {
    return this->id;
}

float MapObject::getLat() const {
    return this->lat;
}

float MapObject::getLon() const {
    return this->lon;
}

QString MapObject::getName() const {
    return this->name;
}

float MapObject::getDistance() const {
    return this->distance;
}

float MapObject::getAltitude() const {
    return this->altitude;
}

int MapObject::getSpeed() const {
    return this->speed;
}