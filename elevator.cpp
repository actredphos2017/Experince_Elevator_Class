#pragma once

#include <iostream>
#include <windows.h>

using namespace std;

Elevator::Elevator(int floor = 10){
    this->floor_num = floor;
    this->up = true;
    this->down = false;
    this->current_floor = 1;
}

Elevator::~Elevator(){
    cout << "Uninstalling the elevator..." << endl;
}

void Elevator::setUpButton(int target_floor){
    if(target_floor > this->floor_num || target_floor < 1){
        cout << "        Error! The target floor is not existed!" << endl;
        return;
    }
    this->setFloorNumber(target_floor);
    this->up = true;
    this->down = false;
}

void Elevator::setDownButton(int target_floor){
    if(target_floor > this->floor_num || target_floor < 1){
        cout << "        Error! The target floor is not existed!" << endl;
        return;
    }
    this->setFloorNumber(target_floor);
    this->up = false;
    this->down = true;
}

void Elevator::setFloorNumber(int target_floor){
    this->show_panel(this->current_floor);
    while(target_floor != this->current_floor){
        Sleep(1000);
        this->current_floor += this->Direction(target_floor, this->current_floor);
        this->show_panel(this->current_floor);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    cout << endl << "        The elevator has arrived~" << endl << endl << "        ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return;
}

int Elevator::Direction(int target, int current){
    if(target > current) return 1;
    else return -1;
}

int Elevator::getCurrentFloor(){
    return this->current_floor;
}

int Elevator::get_floor_nums(){
    cout << "Please enter the number of floors: " << endl;
    int floor_nums;
    cin >> floor_nums;
    while(floor_nums < 1){
        cout << "Wrong input value." << endl;
        cout << "Please enter again: ";
        cin >> floor_nums;
    }
    if(floor_nums == 1){
        cout << "This building is no need to install an elevator. ^_^" << endl;
        system("pause");
        exit(0);
    }
    return floor_nums;
}

void Elevator::show_panel(int current_floor){
    system("cls");
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    cout << "              " << current_floor << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "        +-------------+" << endl << "        |  1. ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
    cout << "Up" ;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "      |" << endl << "        |  2. ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
    cout << "Down";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "    |" << endl << "        |  3. ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << "Leave";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "   |" << endl << "        +-------------+" << endl;
}