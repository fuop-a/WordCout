#include<stdio.h>
#include<string.h>
int  main(int argc,char *argv[])
{
	char value;//用于读取字符;
	char character[100];//用于存储读取的字符;
	char *charact;//指向数组的指针;
	int flag;
	int flagcnt[100];//用于记录状态;
	int wordcount = 0;
	FILE *fp;//定义文件指针;
	int count = 0;//记录字符数;

	fp = fopen(argv[2],"r");//读取文件;
	charact = character;

	if((strcmp(argv[1],"-c") == 0) || (strcmp(argv[1],"-C") == 0))//如果命令行参数为c或C，则执行if;
	{
		count = -1;//文件结束字符也要占一个字数，提前减掉;

	while(!feof(fp))//如果文件没读完就循环;
	{
		value = fgetc(fp);
		count++;
	}
		printf("字符数： %d\n",count);
	}
	else if((strcmp(argv[1],"-w") == 0) || (strcmp(argv[1],"-W") == 0))//如果命令行参数为w或W，则执行else if;
	{
		while(!feof(fp))//读取字符;
		{
			value = fgetc(fp);
			*charact = value;
			charact++;
			count++;
		}
		for(int i=0;i<count;i++)
		{
			if(character[i]>='a' && character[i]<='z')//如果是a到z的字符则flag=1;
				{
					flag = 1;
					flagcnt[i] = flag;
				}
			else if (character[i] >= 'A' && character[i] <= 'Z')//如果是A到Z的字符则flag=1;
				{
					flag = 1;
					flagcnt[i] = flag;
				}
			else//如果是其他的字符则flag=1;
				{	
					flag = 0;
					flagcnt[i] = flag;
				}
		}

		for(int i=0;i<count;i++)
		{
			int high = flagcnt[i];
			int last = flagcnt[i+1];

			if(high != last)//如果前后状态不同则wordcount+1；
			{
				wordcount++;
			}
		}

		printf("单词数： %d\n",wordcount/2);//单词数等于状态变化数1/2;
	}
}

