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
	struct Date date;//�ṹ��Ƕ�� 
	char publisher[48]; 
 	
 }; //�����ṹ����
  
 int main(void)
 {
 	int i;
 	struct Book book[5];//����ṹ�� book[]
 	for(i=0;i<5;i++)
 	{
		printf("=====�����%d�������Ϣ��=====\n",i+1);
		printf("����������");
		scanf("%s",book[i].title);
		printf("�������ߣ�");
		scanf("%s",book[i].author);//û��& 
		printf("�����ۼۣ�");
		scanf("%f",&book[i].price);//����& 
		printf("����������ڣ�xx xx xx����");
		scanf("%d %d %d",&book[i].date.year,&book[i].date.month,&book[i].date.day);
		//ע������� book[i].date.year����ʽ 
		printf("��������磺");
		scanf("%s",book[i].publisher);
		
		printf("\n==========��%d�����������=========\n",i+1);
	
		printf("������%s\n",book[i].title);
		printf("���ߣ�%s\n",book[i].author);
		printf("�ۼۣ�%f\n",book[i].price);
		printf("�������ڣ�%d-%d-%d\n",book[i].date.year,book[i].date.month,book[i].date.day);
		printf("�����磺%s\n",book[i].publisher);
}
	
	 
 }
