#include<stdio.h>
struct Date{
	int year;
	int month;
	int day;
}; 
 struct Book {
 	char title[128];
	char author[48];
	float price;
	struct Date date;//结构体嵌套 
	char publisher[48]; 
 	
 }; //声明结构体框架
  
 int main(void)
 {
 	int i;
 	struct Book book[5];//定义结构体 book[]
 	for(i=0;i<5;i++)
 	{
		printf("=====输入第%d本书的信息：=====\n",i+1);
		printf("输入书名：");
		scanf("%s",book[i].title);
		printf("输入作者：");
		scanf("%s",book[i].author);//没用& 
		printf("输入售价：");
		scanf("%f",&book[i].price);//用了& 
		printf("输入出版日期（xx xx xx）：");
		scanf("%d %d %d",&book[i].date.year,&book[i].date.month,&book[i].date.day);
		//注意这里的 book[i].date.year的形式 
		printf("输入出版社：");
		scanf("%s",book[i].publisher);
		
		printf("\n==========第%d本书输入完毕=========\n",i+1);
	
		printf("书名：%s\n",book[i].title);
		printf("作者：%s\n",book[i].author);
		printf("售价：%f\n",book[i].price);
		printf("出版日期：%d-%d-%d\n",book[i].date.year,book[i].date.month,book[i].date.day);
		printf("出版社：%s\n",book[i].publisher);
}
	
	 
 }
