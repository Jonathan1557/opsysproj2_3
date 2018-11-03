#include "elevator.h"

int servicedCount[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

enum ElevatorState getState()
{
  return OFFLINE;
}

int getFloor() {
  return 1;
}

int getDest() {
  return 1;
}

int getWeight() {
  return 123;
}

int getCapacity() {
  return 10;
}

int serviced(int floor) {
  if(floor > 9 || floor < 0)
    return -1;
  else
    return servicedCount[floor];
}
