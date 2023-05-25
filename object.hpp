#include <vector>


class Coordinates;


using namespace std;


class Abs_object{
    
private:    
    int id;
    double sum_coord;
protected:
    Coordinates *position;
    vector <Coordinates*> coords;
public:
    Abs_object(int id1, int x, int y);
    Abs_object(int id1);
    int get_id();
    int get_sum_coord();
    vector<Coordinates*> get_coords();
    Coordinates* get_pos();
    virtual void randomwalk(int limit_x, int limit_y);
    int get_count_points();
    int get_rast_coord(Coordinates *C);
    virtual void print_coord();
    void add_sum_coord(double r);

};



















