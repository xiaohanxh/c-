#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define N 100
struct book
{
	char num[15];//ͼ����
	char name[20];//����
	char author[50];//������
    char publish[100];//���浥λ
	char time[100];//����ʱ��
    char price[100];//ͼ�鵥��	
}bo[N];

int b=0;
//��ʾ���˵�//
void menu()
{
	printf("\nͼ����Ϣ����ϵͳ\n");
	printf("��������������������\n");
	printf("1.¼��ͼ����Ϣ\n");
    printf("2.���ͼ����Ϣ\n");
	printf("3.��ѯͼ����Ϣ\n");
	printf("4.ɾ��ͼ����Ϣ\n");
	printf("5.�޸�ͼ����\n");
	printf("0.�˳�ϵͳ\n");
	printf("��������������������\n");
}
void intput()//����ͼ����Ϣ
{
	int ch;
	for(;b<=N;b++)
	{
	   printf("������ͼ����\tͼ����\n");
	   scanf("%s,%s",bo[b].num,bo[b].name);
	   printf("��������������\n");
	   scanf("%s",bo[b].author);
	   printf("�����������\t����ʱ��\n");
	   scanf("%s,%s",bo[b].publish,bo[b].time);
 	   printf("������ͼ�鵥�ۣ�\n");
	   scanf("%s",bo[b].price);
	   printf("��0�˳�");
	   scanf("%d",&ch);
	   if(ch==0)
	     break;
	}  
}

void file()//д���ļ�
{
	FILE *fp;
	int i;
	if((fp=fopen("*bookfile","w+"))==NULL)
	{
       printf("file�������ļ�bookfileʧ�ܣ���������˳���\n");
	   exit(1);
	}
	for(i=0;i<=b;i++)
	    if(fwrite(&bo[i],sizeof(bo),1,fp)!=1)
		{
			printf("write file error!\n");
			exit(1);
		}
	fclose(fp);
}

void display()//��ʾͼ����Ϣ
{b=0;
	int i,j;
	printf("����ͼ����Ϣ���£�\n");
	{
//		for(j=1;j<=40;j++)
//			printf("����");
		for(i=0;i<=2;i++){
	
		   printf("\tͼ���\tͼ����\t\t������\tʱ��\n");
		   printf("%-16s,%-16s,%-8s,%s\n",bo[i].num,bo[i].name,bo[i].author,bo[i].time);
           printf("\t������\t\tͼ�鵥��\n");
		   printf("%-24s,%s\n",bo[i].publish,bo[i].price);	}
//        for(j=1;j<=40;j++)
//			printf("����");
	}
	printf("����ͼ����Ϣ����");
}

void search_menu()//��ѯͼ����Ϣ�˵�
{
	printf("\nͼ����Ϣ��ѯ \n");
	printf("---------------\n");
	printf(" 1.��������ѯ  \n");
    printf(" 2.����������ѯ\n");
	printf(" 0.�˳���ѯ    \n");
	printf("---------------\n");
}

void search1()//������ѯ
{
	int i;
	char ch;
	char nname[20];
	do
	{
		printf("������Ҫ��ѯ��������\n");
		scanf("%s",nname);
		getchar();
		for(i=0;i<=b;i++)
		{
			if(strcmp(bo[i].name,nname)==0)
			{
				printf("��ͼ����Ϣ���£�\n");
				printf("ͼ���\t\tͼ����\t\t������\tʱ��\n");
				printf("%-16s,%-16s,%-8s,%s\n",bo[i].num,bo[i].name,bo[i].author,bo[i].time);
				printf("������\t\tͼ�鵥��\n");
				printf("%-24s,%d\n",bo[i].publish,bo[i].price);
                break;
			}else
			    printf("��Ǹ�������ҵ�ͼ�鲻���ڣ�\n");
		}
		printf("�밴y��������ѯ������������\n");
		ch=getchar();
	}while(ch=='y'||ch=='Y');
}

int search2()//��������ѯ
{
	int i;
	char ch;
	char nauthor[20];
	do
	{
		printf("������Ҫ��ѯ����������\n");
		scanf("%s",nauthor);
		getchar();
		for(i=0;i<=b;i++)
		{
			if(strcmp(bo[i].author,nauthor)==0)
			{
				printf("��ͼ����Ϣ���£�\n");
				printf("ͼ���\t\tͼ����\t\t������\tʱ��\n");
				printf("%-16s,%-16s,%-8s,%s\n",bo[i].num,bo[i].name,bo[i].author,bo[i].time);
				printf("������\t\tͼ�鵥��\n");
				printf("%-24s,%d\n",bo[i].publish,bo[i].price);
                break;
			}else
			    printf("��Ǹ�������ҵ�ͼ�鲻���ڣ�\n");
		}
		printf("�밴y��������ѯ������������\n");
		ch=getchar();
		getchar();
	}while(ch=='y'||ch=='Y');
	return i;
}

void del()//ɾ��ͼ����Ϣ
{
    int i;
	FILE *fp;
	char *xname[20];
	printf("������Ҫɾ��������֣�");
	scanf("%s",&xname);
	for(i=0;i<=b;i++)
	{
		if(strcmp(bo[i].name,xname[20]))
		{
			for(;i<=b;i++)
			{
			   strcpy(bo[i].num,bo[i+1].num);
			   strcpy(bo[i].name,bo[i+1].name);
			   strcpy(bo[i].author,bo[i+1].author);
			   strcpy(bo[i].publish,bo[i+1].publish);
			   strcpy(bo[i].time,bo[i+1].time);
			   strcpy(bo[i].price,bo[i+1].price);
			}
			printf("������ɾ��\n");		
			fp=fopen("*bookfile.dat","wb");
			fwrite(&bo[i],sizeof(bo),b,fp);
	        fclose(fp);
		}
	}
	printf("û�и����¼\n");   
}

void modify()//�޸�ͼ����Ϣ
{
	int i=0;
	char xauthor[50];
	FILE *fp;
	if((fp=fopen("*bookfile.dat","wb"))==NULL)
	{
		printf("modify�������ļ�bookfile!ʧ�ܣ���������˳�!");
		return;
	}
	printf("������Ҫ�޸�ͼ������֣�");
	scanf("%s",xauthor);
    i=search2(xauthor);
	printf("�������µ�ͼ����Ϣ����ţ��������������������̣�����ʱ�䣬���ۣ���");
    scanf("%s",&bo[i].num,&bo[i].name,&bo[i].author,&bo[i].publish,&bo[i].time,&bo[i].price);
	fwrite(&bo[i],sizeof(bo),b,fp);
	fclose(fp);
}

//���˵���ѯ//
void search_data()		
{
 int select,flag=1;
 char shu[20];			//����
 char zuo[50];			//������    
 while(flag)
 {
  search_menu();
  printf("��������ѡ��ѯ���ܺ�:");
  scanf("%d",&select);
  switch(select)
  { 
   case 2:printf("�������ѯ������:");
          scanf("%s",zuo);
          search2(zuo);
          break;
   case 1:printf("�������ѯ����\n");
          scanf("%d",shu);
          search1(shu);
          break;
   default:break;
  }
  if (select==0)   //�˳���־����
	 flag=0;
  else
     flag=1;
 }
}



void main()//������           
{
 int iselectnum,flag=1;  //flagΪ�˳���־
 while(flag)
 {
  menu();
  printf("��������ѡ���ܺ�0-5:");
  scanf("%d",&iselectnum);
  switch(iselectnum)
  { 
   case 1:intput(); //¼��ͼ����Ϣ
          break;
   case 2:          //��ʾͼ����Ϣ
           display();
          break;
   case 3:               //ͼ����Ϣ��ѯ
           search_data();
          break;
   case 4:               //ɾ��ͼ����Ϣ
           del();
          break;
   case 5:               //�޸�ͼ����Ϣ
           modify();
          break;
   default:printf("�������,����ѡ���ܺ�!\n");
          break;
   }
  if (iselectnum==0)     //�˳���־����
	 flag=0;
  else
     flag=1;
 } 
}

