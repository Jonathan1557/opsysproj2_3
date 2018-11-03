#include <linux/init.h>
#include <linux/proc_fs.h>
#include "elevator.h"

static struct file_operations fops;

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

module_exit(elevator_exit)
