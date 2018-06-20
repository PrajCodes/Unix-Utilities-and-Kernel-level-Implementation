#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int access_dev(int device_num)
{
	if(device_num>2)
		{
		perror("\n Device number invalid. Can accept 0, 1 or 2");
		exit(0);
		}
	else
		{
		if(device_num==0)
			{
			int read_buf[1000];
			//Linux open function 
			int access_check = open("/dev/input/mouse0", O_RDONLY);
			if(access_check<0)
				{
				perror("\n Mouse device driver file is not present in mouse0 ");
				exit(0);
				}
			while(1)//Infinite loop
				{
				//int m=0;
					if(read(access_check,read_buf,1))
					{
					printf("%d \n", read_buf[0]);
					}
				}
			close(access_check);
			}		
		if(device_num==1)
		{
		clock_t start_time,end_time;
		start_time=clock();
		int acc_chk_urand= open("/dev/urandom", O_RDONLY);
		int acc_chk_null= open("/dev/null", O_RDONLY);
		char big_buf[10000000];
		int c=0, b=10000000;
		if(acc_chk_urand <0 || acc_chk_null <0)
			{
			perror("urandom file and null file not present inside dev");
			exit(0);
			}
		do
		{
			if(read(acc_chk_urand,big_buf,b)!=-1)
			{
				if(c<10000000)
				{
					if(write(acc_chk_null, big_buf, b)!=-1)
					{
						printf("\n Dumping to /null folder");
					}
					c++;
				}

			}
			
			close(acc_chk_null);
		}
			while(c<b);
			close(acc_chk_urand);
		end_time=clock();
		double time_taken=(end_time-start_time);
		printf("Total taken: %f", time_taken);
		}		
	if(device_num==2)
	{
	char error_buf[100]; int error_num=0;
	int acc_chk_tkt = open("/dev/ticket0", O_RDONLY);
	if(	acc_chk_tkt <0)
		{
		perror("Cannot accesss /dev/ticket");
		exit(0);
		}
	while(error_num<10)
		{
			int q=read(acc_chk_tkt,error_buf,100);
			while(q<100){
			printf("%d",error_buf[q]);
			}
		sleep(1);
		error_num++;
		}
	exit(0);
	}	

	}
return 0;
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
	printf("\n Please enter the program name ./dev_access followed by a device number whose folder is to be accessed");
	}
	else
	{
	//Invoking access_dev
	access_dev(atoi(argv[1]));
	}
	return 0;
}


