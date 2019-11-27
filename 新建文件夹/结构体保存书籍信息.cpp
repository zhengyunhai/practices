#include<stdio.h>
 struct Book {
 	char title[128];
	char author[48];
	float price;
	unsigned int date;
	char publisher[48]; 
 	
 }; //声明结构体框架
  
 int main(void)
 {
 	int i;
 	struct Book book[5];//定义结构体数组 book[]
 	for(i=0;i<5;i++)
 	{
		printf("输入第%d本书的信息：\n",i+1);
		printf("输入书名：");
		scanf("%s",book[i].title);
		printf("输入作者：");
		scanf("%s",book[i].author);
		printf("输入售价：");
		scanf("%f",&book[i].price);
		printf("输入出版日期：");
		scanf("%d",&book[i].date);
		printf("输入出版社：");
		scanf("%s",book[i].publisher);
		
		printf("\n==========输入完毕=========\n");
	
		printf("书名：%s\n",book[i].title);
		printf("作者：%s\n",book[i].author);
		printf("售价：%f\n",book[i].price);
		printf("出版日期：%d\n",book[i].date);
		printf("出版社：%s\n",book[i].publisher);
}
	
	 
 }
