# Elevator Simulator - By Steven, Chris, & John
COP4610 Project 1, part 3

Division of Labor:

Chris Oserer:
	Creation of Proc File

Jonathan Molina:
	Manage storage of passengers on floors
	Create syscall to add passengers to floors

Steven Perez:
	Build Scheduler for elevator
	Wrote Makefile and Syscall Wrapper

To Do:
	Still need passenger storage
	Still need elevator scheduler
	Still need to add syscalls
	Function prototypes for syscalls should be added to header file
	We will likely need to add locks for various components to the program
	Syscall 353 will need to spawn new thread to continue running elevator
	For extra credit, we can optimize the elevator scheduler to run more efficiently