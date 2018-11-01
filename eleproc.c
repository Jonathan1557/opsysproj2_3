#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/uaccess.h>
#include <linux/time.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Displays Information regarding the elevator status, along with status of passengers and the floor");

#define ENTRY_NAME "elevator"
#define PERMS 0644
#define PARENT NULL
static struct file_operations fops;

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
	message = kmalloc(sizeof(char) * 1000 , __GFP_RECLAIM | __GFP_IO | __GFP_FS);
	if (message == NULL)
	{
		printk(KERN_WARNING "elvator_proc_open");
		return -ENOMEM;
	}

	strcpy(message, "elevator status: ");
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

		//sprintf(seconds, "%lu", time_spec1.tv_sec);
		//strcat(seconds,"\n");
		//strcat(message, seconds );
		int len = strlen(message);
		copy_to_user(buf, message, len);			// actually prints to proc file, this will work for elevator
		return len;
}

int elevator_proc_release(struct inode *sp_inode, struct file *sp_file)
{
	printk(KERN_INFO "proc called release\n");
	kfree(message);
	return 0;
}

static int elevator_init(void)
{
	printk(KERN_NOTICE "/proc/%s create\n", ENTRY_NAME);
	fops.open = elevator_proc_open;
	fops.read = elevator_proc_read;
	fops.release = elevator_proc_release;

	if (!proc_create(ENTRY_NAME, PERMS, NULL, &fops))
	 {
		printk("ERROR! proc_create\n");
		remove_proc_entry(ENTRY_NAME, NULL);
		return -ENOMEM;
	 }
	 return 0;
}

module_init(elevator_init);

static void elevator_exit(void)
{
	remove_proc_entry(ENTRY_NAME, NULL);
	printk(KERN_NOTICE "Removing /proc/%s.\n", ENTRY_NAME);
}

module_exit(elevator_exit);
