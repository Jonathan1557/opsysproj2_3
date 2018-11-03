#include <linux/proc_fs.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/uaccess.h>
#include <linux/time.h>
#include "elevator.h"

#define PARENT NULL

static char * message;
static char * movestate;
static char * currentfloor;
static char * nextfloor;
static char * currentload;
static char * floor1w;		// numer of floor 1 wating passengers
static char * floor1t;		// number of floor 1 total passengers serviced
static char * floor2w;          // numer of floor 1 wating passengers
static char * floor2t;          // number of floor 1 total passengers serviced
static char * floor3w;          // numer of floor 1 wating passengers
static char * floor3t;          // number of floor 1 total passengers serviced
static char * floor4w;          // numer of floor 1 wating passengers
static char * floor4t;          // number of floor 1 total passengers serviced
static char * floor5w;          // numer of floor 1 wating passengers
static char * floor5t;          // number of floor 1 total passengers serviced
static char * floor6w;          // numer of floor 1 wating passengers
static char * floor6t;          // number of floor 1 total passengers serviced
static char * floor7w;          // numer of floor 1 wating passengers
static char * floor7t;          // number of floor 1 total passengers serviced
static char * floor8w;          // numer of floor 1 wating passengers
static char * floor8t;          // number of floor 1 total passengers serviced
static char * floor9w;          // numer of floor 1 wating passengers
static char * floor9t;          // number of floor 1 total passengers serviced
static char * floor10w;          // numer of floor 1 wating passengers
static char * floor10t;          // number of floor 1 total passengers serviced

static int read_p;


int elevator_proc_open (struct inode *sp_inode, struct file *sp_file)
{
	printk(KERN_INFO "proc called open\n");
	read_p = 1;
	message = kmalloc(sizeof(char) * 2000 , __GFP_RECLAIM | __GFP_IO | __GFP_FS);
	if (message == NULL)
	{
		printk(KERN_WARNING "elvator_proc_open");
		return -ENOMEM;
	}

	strcpy(message, "ELEVATOR STATUS: \n");
	return 0;
}

ssize_t elevator_proc_read(struct file *sp_file, char __user *buf, size_t size, loff_t *offset)
{
		read_p = !read_p;
		if (read_p)
			return 0;
		printk(KERN_INFO "proc called read\n");							// allocating strings to hold the elevator values to output

		movestate = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
		currentfloor = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
		nextfloor  = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
		currentload = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);

		floor1w = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
		floor1t = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
		floor2w = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
                floor2t = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
		floor3w = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
                floor3t = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
		floor4w = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
                floor4t = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
		floor5w = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
                floor5t = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
		floor6w = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
                floor6t = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
		floor7w = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
                floor7t = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
		floor8w = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
                floor8t = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
		floor9w = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
                floor9t = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
		floor10w = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);
                floor10t = kmalloc(sizeof(char) * 60, __GFP_RECLAIM | __GFP_IO | __GFP_FS);


		strcat(message,"Elevator Movement State:  ");
		enum ElevatorState es = getState();

		if (es == OFFLINE)
			strcat(message, "OFFLINE");

		if (es == IDLE)
			strcat(message, "IDLE");

		if(es == LOADING)
			strcat(message, "LOADING");

		if (es == UP)
			strcat(message, "UP");

		if (es == DOWN)
			strcat(message, "DOWN");

		strcat(message, "\n");

		strcat(message, "Current Floor of Elevator: ");
		sprintf(currentfloor, "%d", getFloor());
		strcat(message, currentfloor);
		strcat(message, "\n");

		strcat(message, "Next floor to service: ");
		sprintf(nextfloor, "%d", getDest());
		strcat(message, nextfloor);
		strcat(message, "\n");

		strcat(message, "Elevator Current Load: ");
		sprintf(currentload, "%d", getWeight());
		strcat(message, currentload);
		strcat(message, "\n");


		strcat(message, "Floor 1 Total serviced: ");
		sprintf(floor1t, "%d", serviced(0) );		// putting total serviced into their strings for output in proc file
		strcat(message,floor1t);
		strcat(message,"\n");

		strcat(message, "Floor 2 Total serviced: ");
                sprintf(floor2t, "%d", serviced(1) );           // putting total serviced into their strings for output in proc file
                strcat(message,floor2t);
                strcat(message,"\n");

		strcat(message, "Floor 3 Total serviced: ");
                sprintf(floor3t, "%d", serviced(2) );           // putting total serviced into their strings for output in proc file
                strcat(message,floor3t);
                strcat(message,"\n");

		strcat(message, "Floor 4 Total serviced: ");
                sprintf(floor4t, "%d", serviced(3) );           // putting total serviced into their strings for output in proc file
                strcat(message,floor4t);
                strcat(message,"\n");

		strcat(message, "Floor 5 Total serviced: ");
                sprintf(floor5t, "%d", serviced(4) );           // putting total serviced into their strings for output in proc file
                strcat(message,floor5t);
                strcat(message,"\n");

		strcat(message, "Floor 6 Total serviced: ");
                sprintf(floor6t, "%d", serviced(5) );           // putting total serviced into their strings for output in proc file
                strcat(message,floor6t);
                strcat(message,"\n");

		strcat(message, "Floor 7 Total serviced: ");
                sprintf(floor7t, "%d", serviced(6) );           // putting total serviced into their strings for output in proc file
                strcat(message,floor7t);
                strcat(message,"\n");

		strcat(message, "Floor 8 Total serviced: ");
                sprintf(floor8t, "%d", serviced(7) );           // putting total serviced into their strings for output in proc file
                strcat(message,floor8t);
                strcat(message,"\n");


		strcat(message, "Floor 9 Total serviced: ");
                sprintf(floor9t, "%d", serviced(8) );           // putting total serviced into their strings for output in proc file
                strcat(message,floor9t);
                strcat(message,"\n");

		strcat(message, "Floor 10 Total serviced: ");
                sprintf(floor10t, "%d", serviced(9) );           // putting total serviced into their strings for output in proc file
                strcat(message,floor10t);
                strcat(message,"\n");

		strcat(message, "Floor 1 Number Waiting Load: ");
		sprintf(floor1w, "%d", getWaitingLoad(1)  );           // putting waiting people load into their strings for output in proc file
		strcat(message, floor1w);
		strcat(message, "\n");

		strcat(message, "Floor 2 Number Waiting Load: ");
                sprintf(floor2w, "%d", getWaitingLoad(2)  );           // putting waiting people load into their strings for output in proc file
                strcat(message, floor2w);
                strcat(message, "\n");

		strcat(message, "Floor 3 Number Waiting Load: ");
                sprintf(floor3w, "%d", getWaitingLoad(3)  );           // putting waiting people load into their strings for output in proc file
                strcat(message, floor3w);
                strcat(message, "\n");

		strcat(message, "Floor 4 Number Waiting Load: ");
                sprintf(floor4w, "%d", getWaitingLoad(4)  );           // putting waiting people into their strings for output in proc file
                strcat(message, floor4w);
                strcat(message, "\n");

		strcat(message, "Floor 5 Number Waiting Load: ");
                sprintf(floor5w, "%d", getWaitingLoad(5)  );           // putting waiting people load into their strings for output in proc file
                strcat(message, floor5w);
                strcat(message, "\n");

		strcat(message, "Floor 6 Number Waiting Load: ");
                sprintf(floor6w, "%d", getWaitingLoad(6)  );           // putting waiting people load into their strings for output in proc file
                strcat(message, floor6w);
                strcat(message, "\n");

		strcat(message, "Floor 7 Number Waiting Load: ");
                sprintf(floor7w, "%d", getWaitingLoad(7)  );           // putting waiting people load into their strings for output in proc file
                strcat(message, floor7w);
                strcat(message, "\n");

		strcat(message, "Floor 8 Number Waiting Load: ");
                sprintf(floor8w, "%d", getWaitingLoad(8)  );           // putting waiting people load into their strings for output in proc file
                strcat(message, floor8w);
                strcat(message, "\n");

		strcat(message, "Floor 9 Number Waiting Load: ");
                sprintf(floor9w, "%d", getWaitingLoad(9)  );           // putting waiting people load into their strings for output in proc file
                strcat(message, floor9w);
                strcat(message, "\n");

		strcat(message, "Floor 10 Number Waiting Load: ");
                sprintf(floor10w, "%d", getWaitingLoad(10)  );           // putting waiting people load into their strings for output in proc file
                strcat(message, floor10w);
                strcat(message, "\n");

		int len = strlen(message);
		copy_to_user(buf, message, len);			// actually prints to proc file, this will work for elevator
		return len;
}

int elevator_proc_release(struct inode *sp_inode, struct file *sp_file)
{
	printk(KERN_INFO "proc called release\n");			// free all strings here

	kfree(movestate);
        kfree(currentfloor);
        kfree(nextfloor);
        kfree(currentload);

	kfree(floor1w);
	kfree(floor2w);
	kfree(floor3w);
	kfree(floor4w);
	kfree(floor5w);
	kfree(floor6w);
	kfree(floor7w);
	kfree(floor8w);
	kfree(floor9w);
	kfree(floor10w);

	kfree(floor1t);
        kfree(floor2t);
        kfree(floor3t);
        kfree(floor4t);
        kfree(floor5t);
        kfree(floor6t);
        kfree(floor7t);
        kfree(floor8t);
        kfree(floor9t);
        kfree(floor10t);

	kfree(message);
	return 0;
}
