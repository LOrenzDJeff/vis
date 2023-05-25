



//#include "object.hpp"

class Coordinates;
class Abs_object;


class UserEquipment : public Abs_object{
    double speed_l;
    double scale;

public:
    UserEquipment(int id1, double lat, double lon, double scale);
    void randomwalk(int limit_x, int limit_y);
    void print_coord();
};







