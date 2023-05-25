#include "object.hpp"
#include "UserEquipment.hpp"

#include "Coordinates.hpp"

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <cmath>


using namespace std;



UserEquipment::UserEquipment(int id1, double lat, double lon, double scale) : Abs_object(id1){
        position->set_alt(0);
        position->set_lat(lat);
        position->set_lon(lon);
        this->scale = scale;
        
}
void UserEquipment::randomwalk(int limit_x, int limit_y){
        int new_p = (rand() % 60) - 30;
        int xy_r = rand() % 2;
        Coordinates *new_c;
        if(new_p == 0){
            new_p = 100;
        }
        if(xy_r == 1){
            if(xy_r + new_p <= limit_x && xy_r - new_p >= 0){
                new_c = new Coordinates(position->get_lat() + (double)new_p * scale, position->get_lon() );
                coords.push_back(new_c);
                add_sum_coord(distance_points_lat_lon(new_c->get_lat(), new_c->get_lon(), position->get_lat(), position->get_lon()) );
                position = new_c;
            }
        }
        else{
            if(xy_r + new_p <= limit_y && xy_r - new_p >= 0){
                new_c = new Coordinates(position->get_lat(), position->get_lon() + (double)new_p * scale);
                coords.push_back(new_c);
                add_sum_coord(distance_points_lat_lon(new_c->get_lat(), new_c->get_lon(), position->get_lat(), position->get_lon()) );
                position = new_c;
            }
        }
    }
void UserEquipment::print_coord(){
        std::cout<<"lat = "<<position->get_lat()<<"  lon = "<<position->get_lon()<<"\n";
}

