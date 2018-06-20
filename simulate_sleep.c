/*This program simulates the sleep utility in unix by using system calls to change the action taken by a process on reciept of a signal.
( here alarm is used to wake up and pause is used to mimic sleep function )  */

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
void my_handler(int sn)
{
	/*Do nothing because the intention of this function is just to stop the pause function */
	//printf("Inside my_handler");
}

void do_sleep(int time_to_sleep)
{
	//Declare sigaction structure's parameters in order to be able to call my_handler
	
	struct sigaction mysig_action;
	struct sigaction myoldsig_action;
	memset(&mysig_action, 0, sizeof(mysig_action));
	//sigemptyset(&mysig_action.sa_mask);
	mysig_action.sa_handler = my_handler; // Assign myhandler to sigaction's sa_handler
	//mysig_action.sa_flags =0; 
	sigaction(SIGALRM, &mysig_action, &myoldsig_action);
	//Using alarm , set the time_to_sleep 
	alarm(time_to_sleep);
	//pause until alarm interrupts
	pause();
	
}

int main(int argc, char* argv[])
{
	if(argc==1)
		printf("\n Please enter the program name ./simulate_sleep followed by the time to sleep in seconds");
	else
		{ 
		 int time_in_sec= atoi(argv[1]);
		 do_sleep(time_in_sec);
		}
		
return 0;
}
