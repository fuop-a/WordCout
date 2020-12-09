#include<stdio.h>
#include<string.h>
int  main(int argc,char *argv[])
{
	char ch;
	FILE *fp;
	int cnt=0;
	fp=fopen(argv[2],"r");
	if(strcmp(argv[1],"-c")==0||strcmp(argv[1],"-C")==0)
	{
		cnt=-1;
	while(!feof(fp))
	{
	ch=fgetc(fp);
	printf("%c\n",ch);
	cnt++;
	}
	printf("×Ö·ûÊý£º %d\n",cnt);
	}
	else if(strcmp(argv[1],"-w")==0||strcmp(argv[1],"-W")==0)
	{
	while(!feof(fp))
	{
	ch=fgetc(fp);
	if(ch>='a'&&ch<='z')
	{}
	else if (ch>='A'&&ch<='Z')
	{}
	else
	{
	cnt++;
	}
	}
	printf("µ¥´ÊÊý£º %d\n",cnt);
	}
	return 0;
}