#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
#include<sys/times.h>
#include<sys/resource.h>
static struct tms sutime,etime;
void my_handler(int sn)
{
	if(sn==SIGALRM)
		{	
			//Do nothing just create alarm
			
		}
	if(sn==SIGINT)
		{
			times(&etime);
			printf("\nSIGINT Signal %d initiated i.e user has pressed CTRL+C \n",sn);
 			printf("\nUser Time taken is %f ms \nSystem Time taken is %f ms\n",(double)(etime.tms_utime - sutime.tms_utime)/sysconf (_SC_CLK_TCK),
        	(double)(etime.tms_stime - sutime.tms_stime)/sysconf (_SC_CLK_TCK));	
		}
	if(sn==SIGTERM)
		{
			times(&etime);
			printf("SIGTERM Signal %d detected i.e user has pressed CTRL+Z\n",sn);
			printf("User Time taken is %f ms \nSystem Time taken is %f ms\n",(double)(etime.tms_utime - sutime.tms_utime)/sysconf (_SC_CLK_TCK),
        	(double)(etime.tms_stime - sutime.tms_stime)/sysconf (_SC_CLK_TCK));
			exit(sn);
		}
	if(sn==SIGTSTP)
		{
			printf("SIGTSTP Signal %d  detected i.e user has pressed CTRL+Z",sn);
			/*make an array to record what user types in */
			char input[200];
			int i=0;
			int number_of_lines=10;
			printf("\n Enter 10 characters in new lines\n");
			while(i<number_of_lines)
				{
					scanf("%c\n",&input[i]);
					i++;
				}
			int j=number_of_lines;
			printf("Last 10 lines entered");
			while(j>=number_of_lines-10)
				{
					printf("%c\n",input[j]);
					j--;
				}
		}

}




int main(int argc, char* argv[])
{
int test=0;
times(&sutime);
while(test<200000){
test++;
int test2;
for(test2=0;test2<300;test2++){
}
}
int count=0;	
int time_to_sleep=10;
	if(argc==1)
		printf("\n Please enter the program name ./sig folowed by the time to run heartbeat in seconds");
	else
		{
		int time_to_run= atoi(argv[1]);
		//Initiate listeners of all signals 
		signal(SIGALRM, my_handler);
		signal(SIGINT, my_handler);
		signal(SIGTERM, my_handler);
		signal(SIGTSTP, my_handler);
		printf("Heartbeat initiated\n");
		struct sigaction mysig_action;
		struct sigaction myoldsig_action;
		memset(&mysig_action, 0, sizeof(mysig_action));
		mysig_action.sa_handler = my_handler; // Assign myhandler to sigaction's sa_handler
		sigaction(SIGALRM, &mysig_action, &myoldsig_action);// When sigalrm interrupt happens call myhandler inside mysig_action
		//sigemptyset(&mysig_action.sa_mask);
		//Using alarm , set the time_to_sleep that is 10 seconds  
		while(count<=time_to_run)
		{
		alarm(time_to_sleep); 
		pause();
		printf("Tick Tick ... %d\n",count);
		count=count+time_to_sleep;
			//mysig_action.sa_flags =0; 
		}	

	}	
		
return 0;
}
