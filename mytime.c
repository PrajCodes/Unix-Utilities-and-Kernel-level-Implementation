/*A program to simulate the unix utility time: "time" is used to determine the duration of execution of a particular command in unix. This command will report user CPU time (time spent running program's code) , system CPU time (time spent by program making system calls to kernel such as exec and fork)  and real time(time elapsed).*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<wait.h>

int run_command(int count, char* command[])
{
	clock_t start_time, end_time;
	double cpu_time;
	/*Forking a child to run the command*/
	pid_t pid=fork();
	start_time=clock();
	
	if(pid==0)
	{ /*inside child*/
		
		//printf("Start Time is %ld\n",start_time);
		//free(command[0]);/* avoid memory leak*/
		for(int i=1;i<count;i++)
		{
			command[i-1]=command[i]; /* Reshuffling string pointers inside argv to pass into execv command */
		}
		command[count-1]=NULL;
		execv(command[0], command);		
		
	}
	else
	{ /*Inside parent*/
		wait(NULL);//Parent is waiting until child finishes execution
		end_time=clock();
		//printf("End Time is %ld\n",end_time);
		cpu_time=((double)(end_time-start_time))/CLOCKS_PER_SEC;
		printf("CPU Time used is %f seconds\n", cpu_time);
	}
	return 0;
}
int main(int argc, char *argv[])
{
	if(argc==1)
		printf("\n Please enter the program name ./mytime followed by a command name");
	else
		{ 
		/*Invoking another program to get CPU time, forks child and gets difference time */
		run_command(argc, argv);
		}
		
return 0;
}





