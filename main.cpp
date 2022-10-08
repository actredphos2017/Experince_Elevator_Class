#include "elevator.h"

int main(){
    Elevator ele(Elevator::get_floor_nums());
    bool leave = false;
    int choose;
    int your_floor;
    while(!leave){
        Elevator::show_panel(ele.getCurrentFloor());
        cout << endl << "              ";
        cin >> choose;
        while(choose < 1 || choose > 3){
            cout << "        Wrong input value." << endl;
            cout << "        Please enter again: ";
            cin >> choose;
        }
        if(choose == 1 || choose == 2){
            cout << "        Which floor are you on? ";
            cin >> your_floor;
        }
        switch(choose){
            case 1:
                ele.setUpButton(your_floor);
                break;
            case 2:
                ele.setDownButton(your_floor);
                break;
            case 3:
                leave = true;
                break;
            default:
                return -1;
        }
        system("pause");
    }
    return 0;
}