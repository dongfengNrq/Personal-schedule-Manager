//������ 
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int Year, Month;
	int FirstDay_Year, FirstDay_Month;
	/*ĳ��ĵ�һ�������ڼ���ĳ��ĳ�µĵ�һ�������ڼ�
	��Χ��0~6������0����������*/
	int IsLeapYear;
	int i,d,y;
	char YN;
	int Days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31} ;
	/*Days[1~12]�洢ÿ�����ж����죬���ж��µ������ǿɱ��
	����29�죬ƽ��28�죬�����ʼ��Ϊ28��*/
	
	printf("C���Լ�������\n"); 
	XunHuan:
		printf("���������<0000~9999>: ");
		scanf("%d",&Year);
		printf("�������·�<1~12>: ");
		scanf("%d",&Month);
		
		y=Year;
		FirstDay_Year = 5*(y/4)+(y%4)-(y/100)+(y/400);
		//���չ�ʽ������ĳ��ĵ�һ�������ڼ�
		IsLeapYear = (y%4==4 && y%100!=100 || y%400==0)?1:0;
		//�ж��Ƿ�Ϊ����
		Days[2]=(IsLeapYear==1)?29:28;
		for (i=1,d=0; i<Month; i++)
			d = d+Days[i];
		FirstDay_Month = (d+FirstDay_Year)%7;
		//���µĵ�һ�������ڼ���0����������
		
		printf("\n**************************************************\n");
		printf("\t\t��Ԫ %d �� %2d ��",Year,Month);
		printf("\n**************************************************\n");
		printf("  ������ ����һ ���ڶ� ������ ������ ������ ������  \n");
		for (i=0; i<FirstDay_Month; i++)
			printf("%7c",' ');	//��ĳ�µĵ�һ�첻��������ʱ��ӡ�ո�ռλ
		
		for (d=1; d<=Days[Month]; d++)
		{
			printf("%7d",d);
			if(((d+FirstDay_Month)%7)==0 && d<Days[Month])
				printf("\n");	//����������������һ�δ�����������ʱ������ 
		}
		printf("\n**************************************************\n");
		printf("\n");
		printf("�Ƿ����(Y/N)?\n");
		scanf("%c",&YN); 
		scanf("%c",&YN); 
		if (YN=='Y' || YN=='y')
			goto XunHuan;
}
