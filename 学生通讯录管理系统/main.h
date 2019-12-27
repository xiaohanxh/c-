#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//--------------------------登录-------------------------------
int dl(){
char hsl[6]={0};
	int i=0;
	printf("学生通讯录管理系统\n""请输入密码：\n");
	for(i=0;i<3;i++)
	{
		scanf("%s",hsl);
		if(strcmp(hsl,"123456")==0)
		{	system("cls");
			printf("登录成功。\n");
			break;
		}
		else
		{
			printf("密码输入错误，请重新输入：\n");
		}
	}
	if(i==3)
	{
			printf("你已经连续三次密码错误,登录失败\n");
	}
	
	return i;
} 
//---------------------------定义学生结构体--------------------- 
typedef struct student   {
 char name[20];
 char iD[11];  
 char sex[10];     //性别
 char Class[10];
 char address[99];
 char email[20];
 char phone[11];    //电话号码
 char QQ[15]; 
 struct student *next;
}stu;	
stu *head;
//--------------------------------菜单------------------------
int caidan(){
	int c;
	printf("学生通讯录管理系统\n""请输入命令（1--7）：\n"
	"(1)	学生通讯信息录入\n""(2)	学生通讯信息浏览\n""(3)	查询\n""(4)     修改\n"
	"(5)     删除\n""(6)     设置\n""(7)     保存\n""(8)     登出\n");
	scanf("%d",&c);
	system("cls");
	return c; 
}

int lr(){	int c;
	printf("学生通讯录管理系统\n""请输入命令（1--3）：\n"
	"(1)	按班级录入\n""(2)	无序录入\n""(3)	返回\n");
	scanf("%d",&c);
	system("cls");
	return c; 
	}
int cx(){	int c;
	printf("学生通讯录管理系统\n""请输入命令（1--3）：\n"
	"(1)	姓名查询\n""(2)	按学号查询\n""(3)	按班级查询\n""(4)	返回\n");
	scanf("%d",&c);
	system("cls");
	return c; 
	} 
int shezhi(){
	int c1;
	printf("学生通讯录管理系统\n""请输入命令（1--3）：\n""(1)     格式化\n(2)     安全中心\n(3)     返回\n");
	scanf("%d",&c1);
	system("cls");
	return c1; 
} 
int aq(){
		int c1;
	printf("学生通讯录管理系统\n""请输入命令（1--2）：\n""(1)     修改密码\n(2)     返回\n");
	scanf("%d",&c1);
	system("cls");
	return c1; 
} 
//-------------------------录入学生通讯信息------------------- 
void Input_Stu_Information(stu *p1){
	printf("姓名:");
    scanf("%s",&p1->name);
    printf("学号:");
    scanf("%s",&p1->iD);
    printf("班级:");
    scanf("%s",&p1->Class);
    printf("性别:");
    scanf("%s",&p1->sex);
    printf("籍贯:");
    scanf("%s",&p1->address);
    printf("手机号:");
    scanf("%s",&p1->phone);
    printf("QQ号:");
    scanf("%s",&p1->QQ);
    printf("email:");
    scanf("%s",&p1->email);
} 
stu * shuru()     //数据输入的函数
{
    stu *p1,*p2;
    int i=1;
    p1=(stu *)malloc(sizeof(stu));
    if(p1!=NULL)
    {
        head=p1;
        printf("\n\t\t\t输入数据\n");
        printf("------------------------------------------------------------------\n");
        printf("姓名处输入‘yes’代表输入数据结束\n");
        while(i)
        {
            printf("姓名:");
            scanf("%s",&p1->name);
            if(strcmp(p1->name,"yes")==0)
            {	system("cls");
                printf("\n输入完毕!\n");
                i=0;
                p2->next=NULL;
                free(p1);
                p1=p2;
            }
            else
            {
			    printf("学号:");
			    scanf("%s",&p1->iD);
			    printf("班级:");
			    scanf("%s",&p1->Class);
			    printf("性别:");
			    scanf("%s",&p1->sex);
			    printf("籍贯:");
			    scanf("%s",&p1->address);
			    printf("手机号:");
			    scanf("%s",&p1->phone);
			    printf("QQ号:");
			    scanf("%s",&p1->QQ);
			    printf("email:");
			    scanf("%s",&p1->email);
			    printf("---------------------------------------------------------------------\n");
                p2=p1;
                p1=(stu *)malloc(sizeof(stu));
                if(p1!=NULL)
                {
                    p2->next=p1;
                }
            }
        }
        return(p1->next);
    }
}
stu * lookdata(stu *p1)     //查看数据
{
    printf("\n\t\t\t显示数据\n");
    printf("----------------------------------------------------------------------\n");
    while(p1!=NULL)
    {
  		printf("姓名:%s\n",p1->name);
  		printf("班级:%s\n",p1->Class);
        printf("学号:%s\t",p1->iD);
        printf("性别:%s\t",p1->sex);
        printf("籍贯:%s\t",p1->address);
        printf("手机号:%s\t",p1->phone);
        printf("QQ号:%s\t",p1->QQ);
        printf("email:%s\n",p1->email);
        printf("---------------------------------------------------------------------\n");
        p1=p1->next;
    }
    return p1;
}
void deletedn()          //通过姓名删除数据
{
    stu *p1,*p2;
    char Name[20];  //想要删除的人的姓名
    printf("\n\t\t\t删除数据\n");
    printf("----------------------------------------------------------------------\n");
    printf("请输入要删除的姓名:");
    scanf("%s",Name);
    p1=head;
    if(head==NULL)
    {
    printf("没有数据呢，先输入吧!\n");
    printf("-----------------------------------------------------------------------\n");
    return;
    }
    if(strcmp(Name,p1->name)==0)
    {
    head=p1->next;
    printf("删除成功!\n");
    printf("-----------------------------------------------------------------------\n");
    return;
    }
    while(p1!=NULL&&(strcmp(Name,p1->name)!=0))
    {
    p2=p1;
    p1=p1->next;
    }
    if(p1==NULL)
    {
    printf("此人不存在!\n");
    printf("-----------------------------------------------------------------------\n");
    return;
    }
    if(p1->next!=NULL)
    {
    p1=p1->next;
    p2->next=p1;
    printf("删除成功!\n");
    printf("-----------------------------------------------------------------------\n");
    return;
    }
    else
    {
    p2->next=NULL;
    printf("删除成功!\n");
    printf("-----------------------------------------------------------------------\n");
    return;
    }
}
void ad(){
	head=NULL;
	printf("格式化完成，三秒后返回主菜单");
	sleep(5); 
}
void find(stu *p2)        //通过姓名查找查看数据的函数
{
    char name[20];
    int b=0;
    printf("\n\t\t\t查看数据\n");
    printf("----------------------------------------------------------------------\n");
    printf("请输入您想查找人的姓名:");
    scanf("%s",&name);
    while(p2!=NULL)
    {
        if(strcmp(name,p2->name)==0)
        {
        printf("姓名:%s\n",p2->name);
  		printf("班级:%s\n",p2->Class);
        printf("学号:%s\t",p2->iD);
        printf("性别:%s\t",p2->sex);
        printf("籍贯:%s\t",p2->address);
        printf("手机号:%s\t",p2->phone);
        printf("QQ号:%s\t",p2->QQ);
        printf("email:%s\n",p2->email);
            b=1;
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("\n您要查找的人不存在!\n");
    }
}
void find1(stu *p2)        //通过学号查找查看数据的函数
{
    char iD[20];
    int b=0;
    printf("\n\t\t\t☆☆☆查看数据☆☆☆\n");
    printf("----------------------------------------------------------------------\n");
    printf("请输入您想查找人的学号:");
    scanf("%s",&iD);
    while(p2!=NULL)
    {
        if(strcmp(iD,p2->iD)==0)
        {
        printf("姓名:%s\n",p2->name);
  		printf("班级:%s\n",p2->Class);
        printf("学号:%s\t",p2->iD);
        printf("性别:%s\t",p2->sex);
        printf("籍贯:%s\t",p2->address);
        printf("手机号:%s\t",p2->phone);
        printf("QQ号:%s\t",p2->QQ);
        printf("email:%s\n",p2->email);
            b=1;
             printf("------------------------------------------------------------------\n");
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("\n您要查找的人不存在!\n");
    }
}
void find2(stu *p2)        //通过班级查找查看数据
{
    char Class[20];
    int b=0;
    printf("\n\t\t\t查看数据\n");
    printf("----------------------------------------------------------------------\n");
    printf("请输入您想查找人的班级:");
    scanf("%s",&Class);
    while(p2!=NULL)
    {
        if(strcmp(Class,p2->Class)==0)
        {
        printf("姓名:%s\n",p2->name);
  		printf("班级:%s\n",p2->Class);
        printf("学号:%s\t",p2->iD);
        printf("性别:%s\t",p2->sex);
        printf("籍贯:%s\t",p2->address);
        printf("手机号:%s\t",p2->phone);
        printf("QQ号:%s\t",p2->QQ);
        printf("email:%s\n",p2->email);
            b=1;
             printf("------------------------------------------------------------------\n");
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("\n您要查找的人不存在!\n");
    }
}
void xiugai(stu *p2)   //通过姓名查找修改数据
{
    char name[20];
    int b=0,i;
    printf("\n\t\t\t修改数据\n");
    printf("----------------------------------------------------------------------\n");
    printf("请输入将要修改人的姓名:");
    scanf("%s",name);
    while(p2!=NULL)
    {
        if(strcmp(name,p2->name)==0)
        {
      	    printf("该同学的基本信息\n");
    		printf("姓名:%s\n",p2->name);
  			printf("班级:%s\n",p2->Class);
        	printf("学号:%s\t",p2->iD);
        	printf("性别:%s\t",p2->sex);
        	printf("籍贯:%s\t",p2->address);
        	printf("手机号:%s\t",p2->phone);
        	printf("QQ号:%s\t",p2->QQ);
        	printf("email:%s\n",p2->email);
            printf("\n请选择要修改的信息\n");
            printf("\t1.姓名\t2.班级\t3.学号\t4.性别\n\t5.籍贯\t6.手机号\t7.QQ\t8.email\n");
            printf("\n您的选择是(1~8):");
            scanf("%d",&i);
            printf("请输入修改之后的内容\n");
            switch(i)
            {
            case 1:printf("姓名:");
                scanf("%s",&p2->name);
                break;
            case 2:printf("班级:");
                scanf("%s",&p2->Class);
                break;
            case 3:printf("学号:");
                scanf("%s",&p2->iD);
                break;
            case 4:printf("性别:");
                scanf("%s",&p2->sex);
                break;
            case 5:printf("籍贯:");
                scanf("%s",&p2->address);
                break;
            case 6:printf("手机号:");
                scanf("%s",&p2->phone);
                break;
            case 7:printf("QQ:");
                scanf("%s",&p2->QQ);
                break;
            case 8:printf("email:");
                scanf("%d",&p2->email);
                break;
            }
            printf("\n修改成功!\n");
            printf("------------------------------------------------------------------------\n");
            b=1;
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("没有找到该人!\n");
    }
}
//-------------------------------------保存-----------------------------------------------------
void save(stu *p2)   //保存数据
{
    FILE *fp;
    char file[15];
    printf("\n\t\t\t保存数据\n");
    printf("----------------------------------------------------------------------\n");
    printf("输入文件名:");
    scanf("%s",file);
    if((fp=fopen(file,"w+"))==NULL)
    {
        printf("打不开，你说怎么办\n");
        exit(0);
    }
    fprintf(fp,"姓名\t班级\t学号\t性别\t籍贯\t手机号\tQQ号\temail\n");
    while(p2!=NULL)
    {
        fprintf(fp,"%s\t",p2->name);
        fprintf(fp,"%s\t",p2->Class);
        fprintf(fp,"%s\t",p2->iD);
        fprintf(fp,"%s\t",p2->sex);
        fprintf(fp,"%s\t",p2->address);
        fprintf(fp,"%s\t",p2->phone);
        fprintf(fp,"%s\t",p2->QQ);
        fprintf(fp,"%s\n",p2->email);
        p2=p2->next;
    }
    printf("\n保存成功!\n");
    printf("--------------------------------------------------------------------------\n");
    fclose(fp);
}
 
