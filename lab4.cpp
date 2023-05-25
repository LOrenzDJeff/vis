#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <cmath>

using namespace std;
class Coord{

    int x, y;
public:
    Coord(int X, int Y){
        x = X;
        y = Y;
    }
    int get_x(){
        return x;
    }
    int get_y(){
        return y;
    }
};  

int dist_point(Coord *A, Coord *B){
    return sqrt(pow((B->get_x() - A->get_x()), 2) + pow((B->get_y() - A->get_y()), 2));
}

class Abs_object{
    Coord *position;
    vector <Coord*> coords;
    int id;
    int sum_coord;
public:
    Abs_object(int id1, int x, int y){
        position = new Coord(x, y);
        id = id1;
        coords.push_back(position);
        sum_coord = 0;
    }
    int get_id(){
        return id;
    }
    int get_sum_coord(){
        return sum_coord;
    }
    vector<Coord*> get_coords(){
        return coords;
    }
    Coord* get_pos(){
        return position;
    }
    void randomwalk(int limit_x, int limit_y){
        int new_p = (rand() % 60) - 30;
        int xy_r = rand() % 2;
        Coord *new_c;
        if(new_p == 0){
            new_p = 100;
        }
        if(xy_r == 1){
            if(xy_r + new_p <= limit_x && xy_r - new_p >= 0){
                new_c = new Coord(position->get_x() + new_p, position->get_y());
                coords.push_back(new_c);
                sum_coord += dist_point(position, new_c);
                position = new_c;
            }
        }
        else{
            if(xy_r + new_p <= limit_y && xy_r - new_p >= 0){
                new_c = new Coord(position->get_x(), position->get_y() + new_p);
                coords.push_back(new_c);

                sum_coord += dist_point(position, new_c);
                position = new_c;
            }
        }
    }
    int get_count_points(){
        return coords.size();
    }
    int get_rast_coord(Coord *C){
        return dist_point(position, C);
    }

};



int main(){
    int map_x = 1000;
    int map_y = 1000;
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
    for(i = 0; i < count_obj; ++i){

        i_obj = new Abs_object(i_id, rand() % map_x, rand() % map_y);
        vec_obj.push_back(i_obj);
        i_id++;
    }
    for(i = 0; i < c_moves; ++i){
        for(i2 = 0; i2 < count_obj; ++i2){
            vec_obj[i2]->randomwalk(map_x, map_y);
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
            cout<<" x = "<<vec_obj[i]->get_coords()[i2]->get_x()<<" y = "<<vec_obj[i]->get_coords()[i2]->get_y()<<", ";
        }
        cout<<"\n";
    }
    cout<<"|end|\n";
    return 0;
}


