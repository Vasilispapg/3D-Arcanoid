#include <iostream>
using namespace std;

class Ball{
public:
    float x;
    float y;
    float z;
    float prev_pos;
    float vx=0.1;
    float vy=0.1;
    float vz=40*0.03;
    // float vz=40*0.008;


void printInformation(){
    cout << "Pos: "<<  x << ", " << y << ", " << z << " Velocity: " << vx << ", " << vy << ", " << vz ;
}

};