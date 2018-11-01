#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

//Basic struct to store data on a passenger
struct Passenger{
  int weight; //Doubled from problem statement, to remove fractions (i.e. weight = 1 indicates the passenger is a child weighing 1/2 weight unit 
  int passengers;
  int destination;
};

//Enum that stores the current state of the elevator
enum ElevatorState{
  OFFLINE,
  IDLE,
  LOADING,
  UP,
  DOWN
};

//Integers that store the number of passengers serviced to a specific floor
//Needed for proc file
int serviced[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

//Function that elevator can call to check each floor when scheduling
//Returns the passenger next in line without removing them
Passenger checkWaiter(int floor);

//Function that elevator can call to load a passenger
//Returns the passenger next in line and removes them from line
//The elevator must add the returned passenger to itself
Passenger loadWaiter(int floor);

//Returns number of passengers on given floor
int numPassengers(int floor);

//Returns current state of elevator
ElevatorState getState(void);

//Returns current floor of elevator
int getFloor(void);

//Returns current destination of elevator
int getDest(void);

//Returns current weight held by elevator
int getWeight(void);

//Returns number of passengers held by elevator
int getCapacity(void);