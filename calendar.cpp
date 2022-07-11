//万年历 
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int Year, Month;
	int FirstDay_Year, FirstDay_Month;
	/*某年的第一天是星期几，某年某月的第一天是星期几
	范围是0~6，其中0代表星期日*/
	int IsLeapYear;
	int i,d,y;
	char YN;
	int Days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31} ;
	/*Days[1~12]存储每个月有多少天，其中二月的天数是可变的
	闰年29天，平年28天，这里初始化为28天*/
	
	printf("C语言简单万年历\n"); 
	XunHuan:
		printf("请输入年份<0000~9999>: ");
		scanf("%d",&Year);
		printf("请输入月份<1~12>: ");
		scanf("%d",&Month);
		
		y=Year;
		FirstDay_Year = 5*(y/4)+(y%4)-(y/100)+(y/400);
		//蔡勒公式，计算某年的第一天是星期几
		IsLeapYear = (y%4==4 && y%100!=100 || y%400==0)?1:0;
		//判断是否为闰年
		Days[2]=(IsLeapYear==1)?29:28;
		for (i=1,d=0; i<Month; i++)
			d = d+Days[i];
		FirstDay_Month = (d+FirstDay_Year)%7;
		//当月的第一天是星期几，0代表星期日
		
		printf("\n**************************************************\n");
		printf("\t\t公元 %d 年 %2d 月",Year,Month);
		printf("\n**************************************************\n");
		printf("  星期日 星期一 星期二 星期三 星期四 星期五 星期六  \n");
		for (i=0; i<FirstDay_Month; i++)
			printf("%7c",' ');	//当某月的第一天不是星期日时打印空格占位
		
		for (d=1; d<=Days[Month]; d++)
		{
			printf("%7d",d);
			if(((d+FirstDay_Month)%7)==0 && d<Days[Month])
				printf("\n");	//当输出了星期六而且还未输出所有天数时，换行 
		}
		printf("\n**************************************************\n");
		printf("\n");
		printf("是否继续(Y/N)?\n");
		scanf("%c",&YN); 
		scanf("%c",&YN); 
		if (YN=='Y' || YN=='y')
			goto XunHuan;
}
