#ifndef __ELEVATOR_H
#define __ELEVATOR_H
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("Simulates Elevator and adds system calls and proc file for interacting with and accessing information about simulation");

#define ENTRY_NAME "elevator"
#define PERMS 0644

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

//Retrieve number of passengers serviced to a specific floor
int serviced(int floor);

//Function that elevator can call to check each floor when scheduling
//Returns the passenger next in line without removing them
struct Passenger* checkWaiter(int floor);

//Function that elevator can call to load a passenger
//Returns the passenger next in line and removes them from line
//The elevator must add the returned passenger to itself
struct Passenger* loadWaiter(int floor);

//Returns number of passengers on given floor
int numPassengers(int floor);

//Returns current state of elevator
enum ElevatorState getState(void);

//Returns current floor of elevator
int getFloor(void);

//Returns current destination of elevator
int getDest(void);

//Returns current weight held by elevator
int getWeight(void);

//Returns number of passengers held by elevator
int getCapacity(void);

// returns weight of all passengers waiting ona given floor
int getWaitingLoad(int floor);

//Function prototypes for proc needed by init
int elevator_proc_open (struct inode *sp_inode, struct file *sp_file);
ssize_t elevator_proc_read(struct file *sp_file, char __user * buf, size_t size, loff_t *offset);
int elevator_proc_release(struct inode *sp_inode, struct file *sp_file);
#endif
