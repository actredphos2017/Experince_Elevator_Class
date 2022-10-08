#pragma once

class Elevator{
private:
    int floor_num, current_floor;
    bool up, down;
public:
    Elevator(int);
    ~Elevator();
    void setUpButton(int);
    void setDownButton(int);
    void setFloorNumber(int);
    int getCurrentFloor();
    static int Direction(int, int);
    static int get_floor_nums();
    static void show_panel(int);
};

#include "elevator.cpp"