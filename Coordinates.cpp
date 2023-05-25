#include "Coordinates.hpp"

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <cmath>


using namespace std;

Coordinates::Coordinates(int x, int y) : x(x), y(y)
{
    z = 0;
    lat = 0.0;
    lon = atan2((double)x, (double)y);
}
Coordinates::Coordinates(int x, int y, int z) : x(x), y(y), z(z)
{
    lon = atan2((double)x, (double)y);
    lat = asin((double)z / R);
}

Coordinates::Coordinates(double lat, double lon, double alt = 0){
    this->lat = lat;
    this->lon = lon;
    x = R * cos(lat) * cos(lon);
    y = R * cos(lat) * sin(lon);
    z = R * sin(lat);
    this->alt = alt;
}
Coordinates::~Coordinates(){
}
int Coordinates::get_x(){
    return x;
}
int Coordinates::get_y(){
    return y;
}
int Coordinates::get_z(){
    return z;
}
void Coordinates::set_x(int x){
    this->x = x;
    lon = atan2((double)x, (double)y);
}
void Coordinates::set_y(int y){
    this->y = y;
    lon = atan2((double)x, (double)y);
}
void Coordinates::set_z(int z){
    this->z = z;
    lat = asin((double)this->z / R);
}
double Coordinates::get_lat(){
    return lat;
}
double Coordinates::get_lon(){
    return lon;
}
double Coordinates::get_alt(){
    return alt;
}

void Coordinates::set_lat(double lat){
    this->lat = lat;
    z = R * sin(this->lat);
}
void Coordinates::set_lon(double lon){
    this->lon = lon;
    x = R * cos(this->lat) * cos(this->lon);
    y = R * cos(this->lat) * sin(this->lon);
}
void Coordinates::set_alt(double alt){
    this->alt = alt;

}

int dist_point(Coordinates *A, Coordinates *B){
    return sqrt(pow((B->get_x() - A->get_x()), 2) + pow((B->get_y() - A->get_y()), 2));
}
double distance_points_lat_lon(double lat1, double lon1, double lat2, double lon2){
    double sin1=sin( (lat1-lat2) / 2.0 );
    double sin2=sin( (lon1-lon2) / 2.0 );
    return 2.0 * R_earth * asin( sqrt( sin1 * sin1 + sin2 * sin2 * cos(lat1) * cos(lat2) ) );
}


