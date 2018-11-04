#include "elevator.h"


struct Passenger firstPassList;
struct Passenger secondPassList;
struct Passenger thirdPassList;
struct Passenger fourthPassList;
struct Passenger fifthPassList;    // declaring lists for each floor
struct Passenger sixthPassList;
struct Passenger seventhPassList;
struct Passenger eigthPassList;
struct Passenger ninthPassList;
struct Passenger tenthPassList;

LIST_HEAD_INIT(&firstPassList.list);
LIST_HEAD_INIT(&secondPassList.list);
LIST_HEAD_INIT(&thirdPassList.list);
LIST_HEAD_INIT(&fourthPassList.list);
LIST_HEAD_INIT(&fifthPassList.list);
LIST_HEAD_INIT(&sixthPassList.list);    // intitializes each list to empty
LIST_HEAD_INIT(&seventhPassList.list);
LIST_HEAD_INIT(&eigthPassList.list);
LIST_HEAD_INIT(&ninthPassList.list);
LIST_HEAD_INIT(&tenthPassList.list);

long issue_request(int passType, int initialFloor, int destinationFloor){
	if (passType == 0){
		struct Passenger* passPtr;
		passPtr = kmalloc(sizeof(*passPtr), GFP_KERNEL);
		passPtr->weight = 2;
		passPtr->destination = destinationFloor;    
		passPtr->passengers = 1;
		INIT_LIST_HEAD(&passPtr->list);
	}
	if (passType == 1){
		struct Passenger* passPtr;
		passPtr = kmalloc(sizeof(*passPtr), GFP_KERNEL);
		passPtr->weight = 1;
		passPtr->destination = destinationFloor;    
		passPtr->passengers = 1;
		INIT_LIST_HEAD(&passPtr->list);
	}
	if (passType == 2){
		struct Passenger* passPtr;
		passPtr = kmalloc(sizeof(*passPtr), GFP_KERNEL);
		passPtr->weight = 4;
		passPtr->destination = destinationFloor;    
		passPtr->passengers = 1;
		INIT_LIST_HEAD(&passPtr->list);
	}
	if (passType == 3){
		struct Passenger* passPtr;
		passPtr = kmalloc(sizeof(*passPtr), GFP_KERNEL);
		passPtr->weight = 4;
		passPtr->destination = destinationFloor;    
		passPtr->passengers = 2;
		INIT_LIST_HEAD(&passPtr->list);
	}
	if (initialFloor == 1){
		list_add_tail(&passPtr->list, &firstPassList.list);
		
	}
	if (initialFloor == 2){
		list_add_tail(&passPtr->list, &secondPassList.list);
		
	}
	if (initialFloor == 3){
		list_add_tail(&passPtr->list, &thirdPassList.list);
		
	}
	if (initialFloor == 4){
		list_add_tail(&passPtr->list, &fourthPassList.list);
		
	}
	if (initialFloor == 5){
		list_add_tail(&passPtr->list, &fifthPassList.list);
		
	}
	if (initialFloor == 6){
		list_add_tail(&passPtr->list, &sixthPassList.list);
		
	}
	if (initialFloor == 7){
		list_add_tail(&passPtr->list, &seventhPassList.list);
		
	}
	if (initialFloor == 8){
		list_add_tail(&passPtr->list, &eigthPassList.list);
		
	}
	if (initialFloor == 9){
		list_add_tail(&passPtr->list, &ninthPassList.list);
		
	}
	if (initialFloor == 10){
		list_add_tail(&passPtr->list, &tenthPassList.list);
	}
}

int numPassengers(int floor){
	struct list_head *temp;
	struct list_head *dummy;
	Item *item;
	int numPassengers = 0;
	if (floor == 1){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &firstPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			numPassengers++;
			if(item->passengers == 2)
				numPassengers++
		//can access item->num
		}
		return numPassengers;
		
	}
	if (floor == 2){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &secondPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			numPassengers++;
			if(item->passengers == 2)
				numPassengers++
		//can access item->num
		}
		return numPassengers;
	
	}
	if (floor == 3){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &thirdPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			numPassengers++;
			if(item->passengers == 2)
				numPassengers++
		//can access item->num
		}
		return numPassengers;
		
	}
	if (floor == 4){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &fourthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			numPassengers++;
			if(item->passengers == 2)
				numPassengers++
		//can access item->num
		}
		return numPassengers;
		
		
	}
	if (floor == 5){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &fifthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			numPassengers++;
			if(item->passengers == 2)
				numPassengers++
		//can access item->num
		}
		return numPassengers;
		
		
	}
	if (floor == 6){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &sixthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			numPassengers++;
			if(item->passengers == 2)
				numPassengers++
		//can access item->num
		}
		return numPassengers;
		
		
	}
	if (floor == 7){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &seventhPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			numPassengers++;
			if(item->passengers == 2)
				numPassengers++
		//can access item->num
		}
		return numPassengers;
		
		
	}
	if (floor == 8){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &eigthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			numPassengers++;
			if(item->passengers == 2)
				numPassengers++
		//can access item->num
		}
		return numPassengers;
		
		
	}
	if (floor == 9){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &ninthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			numPassengers++;
			if(item->passengers == 2)
				numPassengers++
		//can access item->num
		}
		return numPassengers;
	}
	if (floor == 10){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &tenthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			numPassengers++;
			if(item->passengers == 2)
				numPassengers++
		//can access item->num
		}
		return numPassengers;	
	}
}

 int getWaitingLoad(int floor){
	 struct list_head *temp;
	 struct list_head *dummy;
	 Item *item;
	 int weightOfLoad = 0;
	 if (floor == 1){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &firstPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			weightOfLoad += item->weight;
		//can access item->num
		}
		return weightOfLoad;
		
	}
	if (floor == 2){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &secondPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			weightOfLoad += item->weight;
		//can access item->num
		}
		return weightOfLoad;
	
	}
	if (floor == 3){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &thirdPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			weightOfLoad += item->weight;
		//can access item->num
		}
		return weightOfLoad;
		
	}
	if (floor == 4){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &fourthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			weightOfLoad += item->weight;
		//can access item->num
		}
		return weightOfLoad;
		
		
	}
	if (floor == 5){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &fifthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			weightOfLoad += item->weight;
		//can access item->num
		}
		return weightOfLoad;
		
		
	}
	if (floor == 6){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &sixthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			weightOfLoad += item->weight;
		//can access item->num
		}
		return weightOfLoad;
		
		
	}
	if (floor == 7){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &seventhPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			weightOfLoad += item->weight;
		//can access item->num
		}
		return weightOfLoad;
		
		
	}
	if (floor == 8){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &eigthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			weightOfLoad += item->weight;
		//can access item->num
		}
		return weightOfLoad;
		
		
	}
	if (floor == 9){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &ninthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			weightOfLoad += item->weight;
		//can access item->num
		}
		return weightOfLoad;
		
		
	}
	if (floor == 10){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &tenthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			weightOfLoad += item->weight;
		//can access item->num
		}
		return weightOfLoad;
	}
 }
 struct Passenger* checkWaiter(int floor){
	 struct list_head *temp;
	 struct list_head *dummy;
	 Item *item;
	 if (floor == 1){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &firstPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			return item;
		//can access item->num
		}
	}
	if (floor == 2){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &secondPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			return item;
		//can access item->num
		}
	}
	if (floor == 3){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &thirdPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			return item;
		//can access item->num
		}
	}
	if (floor == 4){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &fourthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			return item;
		//can access item->num
		}
	}
	if (floor == 5){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &fifthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			return item;
		//can access item->num
		}
	}
	if (floor == 6){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &sixthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			return item;
		//can access item->num
		}
	}
	if (floor == 7){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &seventhPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			return item;
		//can access item->num
		}
	}
	if (floor == 8){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &eigthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			return item;
		//can access item->num
		}
	}
	if (floor == 9){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &ninthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			return item;
		//can access item->num
		}
	}
	if (floor == 10){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &tenthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			return item;
		//can access item->num
		}
	} 
 }
 struct Passenger* loadWaiter(int floor){
	 struct list_head *temp;
	 struct list_head *dummy;
	 Item *item;
	 if (floor == 1){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &firstPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			list_del(temp);
			return item;
		//can access item->num
		}
	}
	if (floor == 2){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &secondPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			list_del(temp);
			return item;
		//can access item->num
		}
	}
	if (floor == 3){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &thirdPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			list_del(temp);
			return item;
		//can access item->num
		}
	}
	if (floor == 4){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &fourthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			list_del(temp);
			return item;
		//can access item->num
		}
	}
	if (floor == 5){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &fifthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			list_del(temp);
			return item;
		//can access item->num
		}
	}
	if (floor == 6){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &sixthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			list_del(temp);
			return item;
		//can access item->num
		}
	}
	if (floor == 7){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &seventhPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			list_del(temp);
			return item;
		//can access item->num
		}
	}
	if (floor == 8){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &eigthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			list_del(temp);
			return item;
		//can access item->num
		}
	}
	if (floor == 9){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &ninthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			list_del(temp);
			return item;
		//can access item->num
		}
	}
	if (floor == 10){
		/* Use this if you need to change pointers */
		list_for_each_safe(temp, dummy, &tenthPassList) {
		/* Use this to get the surrounding struct */
			item = list_entry(temp, Item, list);
			list_del(temp);
			return item;
		//can access item->num
		}
	} 
 }
