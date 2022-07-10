//这是一个测试项目 
#include<stdio.h>
void swap(int *x, int *y);

int main()
{
	int num[10];
	int n,i,j;
	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%d",&num[i]);
	}
	for (i=0; i<n-1; i++) {
		for (j=0; j<n-1-i; j++) {
			if (num[j]<num[j+1]) swap(&num[j],&num[j+1]);
		}
	}
	for (i=0; i<n; i++) {
		printf("%d ",num[i]);
	}
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
