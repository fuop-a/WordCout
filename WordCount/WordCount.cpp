#include<stdio.h>
#include<string.h>
int  main(int argc,char *argv[])
{
	char value;//���ڶ�ȡ�ַ�;
	char character[100];//���ڴ洢��ȡ���ַ�;
	char *charact;//ָ�������ָ��;
	int flag;
	int flagcnt[100];//���ڼ�¼״̬;
	int wordcount = 0;
	FILE *fp;//�����ļ�ָ��;
	int count = 0;//��¼�ַ���;

	fp = fopen(argv[2],"r");//��ȡ�ļ�;
	charact = character;

	if((strcmp(argv[1],"-c") == 0) || (strcmp(argv[1],"-C") == 0))//��������в���Ϊc��C����ִ��if;
	{
		count = -1;//�ļ������ַ�ҲҪռһ����������ǰ����;

	while(!feof(fp))//����ļ�û�����ѭ��;
	{
		value = fgetc(fp);
		count++;
	}
		printf("�ַ����� %d\n",count);
	}
	else if((strcmp(argv[1],"-w") == 0) || (strcmp(argv[1],"-W") == 0))//��������в���Ϊw��W����ִ��else if;
	{
		while(!feof(fp))//��ȡ�ַ�;
		{
			value = fgetc(fp);
			*charact = value;
			charact++;
			count++;
		}
		for(int i=0;i<count;i++)
		{
			if(character[i]>='a' && character[i]<='z')//�����a��z���ַ���flag=1;
				{
					flag = 1;
					flagcnt[i] = flag;
				}
			else if (character[i] >= 'A' && character[i] <= 'Z')//�����A��Z���ַ���flag=1;
				{
					flag = 1;
					flagcnt[i] = flag;
				}
			else//������������ַ���flag=1;
				{	
					flag = 0;
					flagcnt[i] = flag;
				}
		}

		for(int i=0;i<count;i++)
		{
			int high = flagcnt[i];
			int last = flagcnt[i+1];

			if(high != last)//���ǰ��״̬��ͬ��wordcount+1��
			{
				wordcount++;
			}
		}

		printf("�������� %d\n",wordcount/2);//����������״̬�仯��1/2;
	}
}

