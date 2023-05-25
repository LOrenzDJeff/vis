#include "object.hpp"
#include "Coordinates.hpp"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <cmath>
using namespace std;



Abs_object::Abs_object(int id1, int x, int y){
        position = new Coordinates(x, y);
        id = id1;
        coords.push_back(position);
        sum_coord = 0.0;
}
Abs_object::Abs_object(int id1){
        position = new Coordinates(0, 0);
        id = id1;
        coords.push_back(position);
        sum_coord = 0;
}
int Abs_object::get_id(){
        return id;
}
int Abs_object::get_sum_coord(){
        return sum_coord;
}
vector<Coordinates*> Abs_object::get_coords(){
        return coords;
}
Coordinates* Abs_object::get_pos(){
        return position;
}
void Abs_object::randomwalk(int limit_x, int limit_y){
        int new_p = (rand() % 60) - 30;
        int xy_r = rand() % 2;
        Coordinates *new_c;
        if(new_p == 0){
            new_p = 100;
        }
        if(xy_r == 1){
            if(xy_r + new_p <= limit_x && xy_r - new_p >= 0){
                new_c = new Coordinates(position->get_x() + new_p, position->get_y());
                coords.push_back(new_c);
                sum_coord += dist_point(position, new_c);
                position = new_c;
            }
        }
        else{
            if(xy_r + new_p <= limit_y && xy_r - new_p >= 0){
                new_c = new Coordinates(position->get_x(), position->get_y() + new_p);
                coords.push_back(new_c);

                sum_coord += dist_point(position, new_c);
                position = new_c;
            }
}
}
int Abs_object::get_count_points(){
        return coords.size();
}
int Abs_object::get_rast_coord(Coordinates *C){
        return dist_point(position, C);
}
void Abs_object::print_coord(){
        std::cout<<"x = "<<position->get_x()<<"  y = "<<position->get_y()<<"\n";
}
void Abs_object::add_sum_coord(double r){
        sum_coord += r;
}



