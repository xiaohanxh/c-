#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define N 100
struct book
{
	char num[15];//图书编号
	char name[20];//书名
	char author[50];//作者名
    char publish[100];//出版单位
	char time[100];//出版时间
    char price[100];//图书单价	
}bo[N];

int b=0;
//显示主菜单//
void menu()
{
	printf("\n图书信息管理系统\n");
	printf("——————————\n");
	printf("1.录入图书信息\n");
    printf("2.输出图书信息\n");
	printf("3.查询图书信息\n");
	printf("4.删除图书信息\n");
	printf("5.修改图书编号\n");
	printf("0.退出系统\n");
	printf("——————————\n");
}
void intput()//输入图书信息
{
	int ch;
	for(;b<=N;b++)
	{
	   printf("请输入图书编号\t图书名\n");
	   scanf("%s,%s",bo[b].num,bo[b].name);
	   printf("请输入作者名：\n");
	   scanf("%s",bo[b].author);
	   printf("请输入出版商\t出版时间\n");
	   scanf("%s,%s",bo[b].publish,bo[b].time);
 	   printf("请输入图书单价：\n");
	   scanf("%s",bo[b].price);
	   printf("按0退出");
	   scanf("%d",&ch);
	   if(ch==0)
	     break;
	}  
}

void file()//写入文件
{
	FILE *fp;
	int i;
	if((fp=fopen("*bookfile","w+"))==NULL)
	{
       printf("file函数打开文件bookfile失败，按任意键退出！\n");
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

void display()//显示图书信息
{b=0;
	int i,j;
	printf("所有图书信息如下：\n");
	{
//		for(j=1;j<=40;j++)
//			printf("——");
		for(i=0;i<=2;i++){
	
		   printf("\t图书号\t图书名\t\t作者名\t时间\n");
		   printf("%-16s,%-16s,%-8s,%s\n",bo[i].num,bo[i].name,bo[i].author,bo[i].time);
           printf("\t出版商\t\t图书单价\n");
		   printf("%-24s,%s\n",bo[i].publish,bo[i].price);	}
//        for(j=1;j<=40;j++)
//			printf("——");
	}
	printf("所有图书信息如上");
}

void search_menu()//查询图书信息菜单
{
	printf("\n图书信息查询 \n");
	printf("---------------\n");
	printf(" 1.按书名查询  \n");
    printf(" 2.按作者名查询\n");
	printf(" 0.退出查询    \n");
	printf("---------------\n");
}

void search1()//书名查询
{
	int i;
	char ch;
	char nname[20];
	do
	{
		printf("请输入要查询的书名：\n");
		scanf("%s",nname);
		getchar();
		for(i=0;i<=b;i++)
		{
			if(strcmp(bo[i].name,nname)==0)
			{
				printf("该图书信息如下：\n");
				printf("图书号\t\t图书名\t\t作者名\t时间\n");
				printf("%-16s,%-16s,%-8s,%s\n",bo[i].num,bo[i].name,bo[i].author,bo[i].time);
				printf("出版商\t\t图书单价\n");
				printf("%-24s,%d\n",bo[i].publish,bo[i].price);
                break;
			}else
			    printf("抱歉，你所找的图书不存在！\n");
		}
		printf("请按y键继续查询，其他键结束\n");
		ch=getchar();
	}while(ch=='y'||ch=='Y');
}

int search2()//作者名查询
{
	int i;
	char ch;
	char nauthor[20];
	do
	{
		printf("请输入要查询的作者名：\n");
		scanf("%s",nauthor);
		getchar();
		for(i=0;i<=b;i++)
		{
			if(strcmp(bo[i].author,nauthor)==0)
			{
				printf("该图书信息如下：\n");
				printf("图书号\t\t图书名\t\t作者名\t时间\n");
				printf("%-16s,%-16s,%-8s,%s\n",bo[i].num,bo[i].name,bo[i].author,bo[i].time);
				printf("出版商\t\t图书单价\n");
				printf("%-24s,%d\n",bo[i].publish,bo[i].price);
                break;
			}else
			    printf("抱歉，你所找的图书不存在！\n");
		}
		printf("请按y键继续查询，其他键结束\n");
		ch=getchar();
		getchar();
	}while(ch=='y'||ch=='Y');
	return i;
}

void del()//删除图书信息
{
    int i;
	FILE *fp;
	char *xname[20];
	printf("请输入要删除书的名字：");
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
			printf("该书已删除\n");		
			fp=fopen("*bookfile.dat","wb");
			fwrite(&bo[i],sizeof(bo),b,fp);
	        fclose(fp);
		}
	}
	printf("没有该书记录\n");   
}

void modify()//修改图书信息
{
	int i=0;
	char xauthor[50];
	FILE *fp;
	if((fp=fopen("*bookfile.dat","wb"))==NULL)
	{
		printf("modify函数打开文件bookfile!失败，按任意键退出!");
		return;
	}
	printf("请输入要修改图书的名字：");
	scanf("%s",xauthor);
    i=search2(xauthor);
	printf("请输入新的图书信息（编号，书名，作者名，出版商，出版时间，单价）：");
    scanf("%s",&bo[i].num,&bo[i].name,&bo[i].author,&bo[i].publish,&bo[i].time,&bo[i].price);
	fwrite(&bo[i],sizeof(bo),b,fp);
	fclose(fp);
}

//主菜单查询//
void search_data()		
{
 int select,flag=1;
 char shu[20];			//书名
 char zuo[50];			//作者名    
 while(flag)
 {
  search_menu();
  printf("请输入所选查询功能号:");
  scanf("%d",&select);
  switch(select)
  { 
   case 2:printf("请输入查询作者名:");
          scanf("%s",zuo);
          search2(zuo);
          break;
   case 1:printf("请输入查询书名\n");
          scanf("%d",shu);
          search1(shu);
          break;
   default:break;
  }
  if (select==0)   //退出标志置零
	 flag=0;
  else
     flag=1;
 }
}



void main()//主函数           
{
 int iselectnum,flag=1;  //flag为退出标志
 while(flag)
 {
  menu();
  printf("请输入所选功能号0-5:");
  scanf("%d",&iselectnum);
  switch(iselectnum)
  { 
   case 1:intput(); //录入图书信息
          break;
   case 2:          //显示图书信息
           display();
          break;
   case 3:               //图书信息查询
           search_data();
          break;
   case 4:               //删除图书信息
           del();
          break;
   case 5:               //修改图书信息
           modify();
          break;
   default:printf("输入错误,重新选择功能号!\n");
          break;
   }
  if (iselectnum==0)     //退出标志置零
	 flag=0;
  else
     flag=1;
 } 
}

