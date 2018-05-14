/*Simulation of Copy command*/

#include <stdio.h>
#include <stdlib.h>

void copy(FILE *source,FILE *target)
{
	char ch;
	while((ch=fgetc(source))!=EOF) //read each character from source 
		fputc(ch,target);           // file and put it into
	printf("Copy is successful!!!\n\n");  //destination file
}

int main(int argc,char *argv[])
{
	FILE *source,*target;
	if(argc!=3)             
	{
		printf("Error! Enter 3 arguments!!!");
		exit(-1);
	}
	source=fopen(argv[1],"r");   //opens source and destination files
	target=fopen(argv[2],"w");   //in read and write mode
	if(source==NULL)
	{
		printf("Unable to open the file!!!");
		exit(-1);
	}
	copy(source,target);
	fclose(source);
	fclose(target);
	return 0;
} 
