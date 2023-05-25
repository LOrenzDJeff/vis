#include "object.hpp"
#include "Coordinates.hpp"
#include "UserEquipment.hpp"

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <cmath>



using namespace std;



int main(){
    int map_x = 1000;
    int map_y = 1000;

    double latS = 55.004, lonS = 82.995;
    double latE = 54.9236, lonE = 83.0996;
    vector <Abs_object*> vec_obj;
    int i, i2;
    int count_obj;
    cout<<"Input count object: ";
    cin >> count_obj;
    cout<<"Input moves: ";
    int c_moves;
    cin>>c_moves;
    int i_id = 1;
    Abs_object *i_obj;
    int xp, yp;
    double scale = (lonE - lonS)/(double)map_x;
    for(i = 0; i < count_obj; ++i){
        i_obj = new UserEquipment(i_id, latS + ( (double)(rand() % map_x) * scale), lonS + ( (double)(rand() % map_y) * scale), scale );
        i_obj->print_coord();
        vec_obj.push_back(i_obj);
        i_id++;
    }
    for(i = 0; i < c_moves; ++i){
        cout<<"step"<<i+1<<"\n";
        for(i2 = 0; i2 < count_obj; ++i2){
            vec_obj[i2]->randomwalk(map_x, map_y);
            cout<<"\tid = "<<vec_obj[i2]->get_id()<<"\n\t\t";
            vec_obj[i2]->print_coord();
        }
    }
    for(i = 0; i < count_obj; ++i){
        cout<<"id = "<<vec_obj[i]->get_id()<<" path = "<<vec_obj[i]->get_sum_coord()<<"\n";
        cout<<"rast to:\n";
        for(i2 = 0; i2 < count_obj; ++i2){
            if(i2 != i){
                
                cout<<"\tid = "<<vec_obj[i2]->get_id()<<" - "<<vec_obj[i]->get_rast_coord(vec_obj[i2]->get_pos())<<"\n";
            }
        }
        cout<<"Points: ";
        for(i2 = 0; i2 < vec_obj[i]->get_count_points(); ++i2){
            //cout<<" x = "<<vec_obj[i]->get_coords()[i2]->get_x()<<" y = "<<vec_obj[i]->get_coords()[i2]->get_y()<<", ";
        }
        cout<<"\n";
    }
    cout<<"|end|\n";
    return 0;

}
