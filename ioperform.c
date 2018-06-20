#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/time.h>
int main()
{
struct timeval start, end;
//Using write system call 
gettimeofday(&start, NULL);
	for(int i=0;i<3;i++)
	{
		char buffer[20];
		sprintf(buffer, "write_24b_%d",i);
		int nfd=open(buffer, O_RDWR | O_CREAT);
			if(nfd==-1)
			{
				 printf("Error opening the file");	
			}
		
		write(nfd, "This should be 24 Bytes", 24);
		close(nfd);
	}
gettimeofday(&end, NULL);
double total_24b_write= (end.tv_sec - start.tv_sec)+((end.tv_usec = start.tv_usec)/1000000.0);
printf("\n Created 3 small files of 24b size each using write system call and Time taken is : %f ",total_24b_write); 
gettimeofday(&start, NULL);
	for(int i=0;i<3;i++)
	{
		char buffer[20];
		sprintf(buffer, "write_1kb_%d",i);
		int nfd=open(buffer, O_RDWR | O_CREAT);
			if(nfd==-1)
			{
				 printf("Error opening the file");	
			}
		
		write(nfd, "Operating Systems make computer hardware usable by programs. We focus on the kernel of the OS in this class. The course will cover basic OS concepts, algorithms, and structure in a general context as well as some Linux specifics. Topics: Designing processes and threads, synchronization, IPC, I/O, deadlock, memory management, file systems kernel structure.1) Students will learn the system call API for POSIX, including the use of processes, threads files and directories. Experience in installing Linux in a virtual machine, using it at the command line and from programs, and modifying the Linux kernel.Review of basic OS concepts such as scheduling, memory management, and virtualization.Multi-process and multi-thread programming in C/C++.Projects will involve writing systems programs in scripting languages and C/C++, and building and modifying the Linux kernel",1000);
		close(nfd);
	}
gettimeofday(&end, NULL);
double total_1kb_write= (end.tv_sec - start.tv_sec)+((end.tv_usec = start.tv_usec)/1000000.0);
printf("\n Created 3 large files of 1000b size each using write system call and Time taken is : %f",total_1kb_write); 
//Using fwrite function 

gettimeofday(&start, NULL);
	for(int i=0;i<3;i++)
	{
		char buffer[20];
		sprintf(buffer, "fwrite_24b_%d",i);
		FILE *fp;
		char nst[]= "This should be 24 Bytes";
		fp= fopen(buffer, "w");
		fwrite(nst, 1, sizeof(nst), fp);
		fclose(fp);
	}
gettimeofday(&end, NULL);
double total_24b_fwrite= (end.tv_sec - start.tv_sec)+((end.tv_usec = start.tv_usec)/1000000.0);
printf("\n Created 3 small files of 24 b size each using fwrite function and Time taken is : %f",total_24b_fwrite); 

gettimeofday(&start, NULL);
	for(int i=0;i<3;i++)
	{
		char buffer[20];
		sprintf(buffer, "fwrite_1kb_%d",i);
		FILE *fp;
		char nst[]= "Operating Systems make computer hardware usable by programs. We focus on the kernel of the OS in this class. The course will cover basic OS concepts, algorithms, and structure in a general context as well as some Linux specifics. Topics: Designing processes and threads, synchronization, IPC, I/O, deadlock, memory management, file systems kernel structure.1) Students will learn the system call API for POSIX, including the use of processes, threads files and directories. Experience in installing Linux in a virtual machine, using it at the command line and from programs, and modifying the Linux kernel.Review of basic OS concepts such as scheduling, memory management, and virtualization.Multi-process and multi-thread programming in C/C++.Projects will involve writing systems programs in scripting languages and C/C++, and building and modifying the Linux kernel";
		fp= fopen(buffer, "w");
		fwrite(nst, 1, sizeof(nst), fp);
		fclose(fp);
	}

gettimeofday(&end, NULL);
double total_1kb_fwrite= (end.tv_sec - start.tv_sec)+((end.tv_usec = start.tv_usec)/1000000.0);
printf("\n Created 3 large files of 1 kb size each using fwrite system call and Time taken is : %f",total_1kb_fwrite); 


}

/*Observations

For larger files  I observed that overall for multiple size of files and buffers of strings , write function is almost 10 times slower than fwrite. 
The write function is a system call and hence the program makes multiple OS system calls involving kernel operations making it slow.
The fwrite however writes to a file pointer instead of file descriptor and hence is faster access to IO.
fwrite adds buffering capability (buffered stdio stream) to write.
*/

