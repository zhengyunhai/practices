#include<stdio.h>
void jh(int *n1,int *n2)
{	//函数输入是指针，是两个量的地址，通过解地址直接对数据操作。 
	//若输入是常量名n1,n2，则对其的操作只影响本函数内部，不在main函数中作用。 
	//此处若改为输入常量名，本函数内数值确实交换，而main函数中输出a,b不变 。 
	int temp;
	temp=*n1;
	*n1=*n2;
	*n2=temp;
	//printf("%d %d\n",*n1,*n2);
	
 } 
 main()
 {
 	int a=3,b=4;
 	jh(&a,&b);
 	printf("a=%d b=%d\n",a,b);
 }
