#include<stdio.h>
 struct Book {
 	char title[128];
	char author[48];
	float price;
	unsigned int date;
	char publisher[48]; 
 	
 }; //�����ṹ����
  
 int main(void)
 {
 	int i;
 	struct Book book[5];//����ṹ������ book[]
 	for(i=0;i<5;i++)
 	{
		printf("�����%d�������Ϣ��\n",i+1);
		printf("����������");
		scanf("%s",book[i].title);
		printf("�������ߣ�");
		scanf("%s",book[i].author);
		printf("�����ۼۣ�");
		scanf("%f",&book[i].price);
		printf("����������ڣ�");
		scanf("%d",&book[i].date);
		printf("��������磺");
		scanf("%s",book[i].publisher);
		
		printf("\n==========�������=========\n");
	
		printf("������%s\n",book[i].title);
		printf("���ߣ�%s\n",book[i].author);
		printf("�ۼۣ�%f\n",book[i].price);
		printf("�������ڣ�%d\n",book[i].date);
		printf("�����磺%s\n",book[i].publisher);
}
	
	 
 }
