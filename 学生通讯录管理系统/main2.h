#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <windows.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/stat.h>
struct stat buf;
//--------------------------��¼-------------------------------
int dl(){
char hsl[7]={0};
	int i=0;
	printf("ѧ��ͨѶ¼����ϵͳ\n""���������룺\n");
	for(i=0;i<3;i++)
	{
		scanf("%s",hsl);
		if(strcmp(hsl,"123456")==0)
		{	system("cls");
			printf("��¼�ɹ���\n");
			break;
		}
		else
		{
			printf("��������������������룺\n");
		}
	}
	if(i==3)
	{
			printf("���Ѿ����������������,��¼ʧ��\n");
	}
	
	return i;
} 
//---------------------------����ѧ���ṹ��--------------------- 
typedef struct student   {
 char name[20];
 char iD[11];  
 char sex[10];     //�Ա�
 char Class[10];
 char address[20];
 char email[20];
 char phone[11];    //�绰����
 char QQ[15]; 
 struct student *next;
}stu;	
stu *head;
//--------------------------------�˵�------------------------
int caidan(){
	int c;
	printf("ѧ��ͨѶ¼����ϵͳ\n""���������1--7����\n"
	"(1)	ѧ��ͨѶ��Ϣ¼��\n""(2)	ѧ��ͨѶ��Ϣ���\n""(3)	��ѯ\n""(4)     �޸�\n"
	"(5)     ɾ��\n""(6)     ����\n""(7)     ����\n""(8)     �ǳ�\n");
	scanf("%d",&c);
	system("cls");
	return c; 
}

int lr(){	int c;
	printf("ѧ��ͨѶ¼����ϵͳ\n""���������1--3����\n"
	"(1)	���༶¼��\n""(2)	����¼��\n""(3)	����\n");
	scanf("%d",&c);
	system("cls");
	return c; 
	}
int cx(){	int c;
	printf("ѧ��ͨѶ¼����ϵͳ\n""���������1--3����\n"
	"(1)	������ѯ\n""(2)	��ѧ�Ų�ѯ\n""(3)	���༶��ѯ\n""(4)	����\n");
	scanf("%d",&c);
	system("cls");
	return c; 
	} 
int shezhi(){
	int c1;
	printf("ѧ��ͨѶ¼����ϵͳ\n""���������1--3����\n""(1)     ��ʽ��\n(2)     ��ȫ����\n(3)     ����\n");
	scanf("%d",&c1);
	system("cls");
	return c1; 
} 
int aq(){
		int c1;
	printf("ѧ��ͨѶ¼����ϵͳ\n""���������1--2����\n""(1)     �޸�����\n(2)     ����\n");
	scanf("%d",&c1);
	system("cls");
	return c1; 
} 
//-------------------------¼��ѧ��ͨѶ��Ϣ------------------- 
void Input_Stu_Information(stu *p1){
	printf("����:");
    scanf("%s",&p1->name);
    printf("ѧ��:");
    scanf("%s",&p1->iD);
    printf("�༶:");
    scanf("%s",&p1->Class);
    printf("�Ա�:");
    scanf("%s",&p1->sex);
    printf("����:");
    scanf("%s",&p1->address);
    printf("�ֻ���:");
    scanf("%s",&p1->phone);
    printf("QQ��:");
    scanf("%s",&p1->QQ);
    printf("email:");
    scanf("%s",&p1->email);
} 
stu * shuru()     //��������ĺ���
{
    stu *p1,*p2;
    int i=1;
    p1=(stu *)malloc(sizeof(stu));
    p2=(stu *)malloc(sizeof(stu));
    if(p1!=NULL)
    {
        head=p1;
        printf("\n\t\t\t��������\n");
        printf("------------------------------------------------------------------\n");
        printf("���������롮yes�������������ݽ���\n");
        while(i)
        {
            printf("����:");
            scanf("%s",&p1->name);
            if(strcmp(p1->name,"yes")==0)
            {	system("cls");
                printf("\n�������!\n");
                i=0;
                p2->next=NULL;
                free(p1);
                p1=p2;
            }
            else
            {
			    printf("ѧ��:");
			    scanf("%s",&p1->iD);
			    printf("�༶:");
			    scanf("%s",&p1->Class);
			    printf("�Ա�:");
			    scanf("%s",&p1->sex);
			    printf("����:");
			    scanf("%s",&p1->address);
			    printf("�ֻ���:");
			    scanf("%s",&p1->phone);
			    printf("QQ��:");
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
stu * lookdata(stu *p1)     //�鿴����
{
    printf("\n\t\t\t��ʾ����\n");
    printf("----------------------------------------------------------------------\n");
    while(p1!=NULL&&strcmp("0",p1->name))
    {
  		printf("����:%s\n",p1->name);
  		printf("�༶:%s\n",p1->Class);
        printf("ѧ��:%s\t",p1->iD);
        printf("�Ա�:%s\t",p1->sex);
        printf("����:%s\t",p1->address);
        printf("�ֻ���:%s\t",p1->phone);
        printf("QQ��:%s\t",p1->QQ);
        printf("email:%s\n",p1->email);
        printf("---------------------------------------------------------------------\n");
        p1=p1->next;
    }
    return p1;
}
void deletedn()          //ͨ������ɾ������
{
    stu *p1,*p2;
    char Name[20];  //��Ҫɾ�����˵�����
    printf("\n\t\t\tɾ������\n");
    printf("----------------------------------------------------------------------\n");
    printf("������Ҫɾ��������:");
    scanf("%s",Name);
    p1=head;
    if(head==NULL)
    {
    printf("û�������أ��������!\n");
    printf("-----------------------------------------------------------------------\n");
    return;
    }
    if(strcmp(Name,p1->name)==0)
    {
    head=p1->next;
    printf("ɾ���ɹ�!\n");
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
    printf("���˲�����!\n");
    printf("-----------------------------------------------------------------------\n");
    return;
    }
    if(p1->next!=NULL)
    {
    p1=p1->next;
    p2->next=p1;
    printf("ɾ���ɹ�!\n");
    printf("-----------------------------------------------------------------------\n");
    return;
    }
    else
    {
    p2->next=NULL;
    printf("ɾ���ɹ�!\n");
    printf("-----------------------------------------------------------------------\n");
    return;
    }
}
void ad(){
	head=NULL;
	printf("��ʽ����ɣ�����󷵻����˵�");
	Sleep(3000); 
}
void find(stu *p2)        //ͨ���������Ҳ鿴����
{
    char name[20];
    int b=0;
    printf("\n\t\t\t�鿴����\n");
    printf("----------------------------------------------------------------------\n");
    printf("��������������˵�����:");
    scanf("%s",&name);
    while(p2!=NULL)
    {
        if(strcmp(name,p2->name)==0)
        {
        printf("����:%s\n",p2->name);
  		printf("�༶:%s\n",p2->Class);
        printf("ѧ��:%s\t",p2->iD);
        printf("�Ա�:%s\t",p2->sex);
        printf("����:%s\t",p2->address);
        printf("�ֻ���:%s\t",p2->phone);
        printf("QQ��:%s\t",p2->QQ);
        printf("email:%s\n",p2->email);
            b=1;
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("\n��Ҫ���ҵ��˲�����!\n");
    }
}
void find1(stu *p2)        //ͨ��ѧ�Ų��Ҳ鿴����
{
    char iD[20];
    int b=0;
    printf("\n\t\t\t�鿴����\n");
    printf("----------------------------------------------------------------------\n");
    printf("��������������˵�ѧ��:");
    scanf("%s",&iD);
    while(p2!=NULL)
    {
        if(strcmp(iD,p2->iD)==0)
        {
        printf("����:%s\n",p2->name);
  		printf("�༶:%s\n",p2->Class);
        printf("ѧ��:%s\t",p2->iD);
        printf("�Ա�:%s\t",p2->sex);
        printf("����:%s\t",p2->address);
        printf("�ֻ���:%s\t",p2->phone);
        printf("QQ��:%s\t",p2->QQ);
        printf("email:%s\n",p2->email);
            b=1;
             printf("------------------------------------------------------------------\n");
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("\n��Ҫ���ҵ��˲�����!\n");
    }
}
void find2(stu *p2)        //ͨ���༶���Ҳ鿴����
{
    char Class[20];
    int b=0;
    printf("\n\t\t\t�鿴����\n");
    printf("----------------------------------------------------------------------\n");
    printf("��������������˵İ༶:");
    scanf("%s",&Class);
    while(p2!=NULL)
    {
        if(strcmp(Class,p2->Class)==0)
        {
        printf("����:%s\n",p2->name);
  		printf("�༶:%s\n",p2->Class);
        printf("ѧ��:%s\t",p2->iD);
        printf("�Ա�:%s\t",p2->sex);
        printf("����:%s\t",p2->address);
        printf("�ֻ���:%s\t",p2->phone);
        printf("QQ��:%s\t",p2->QQ);
        printf("email:%s\n",p2->email);
            b=1;
             printf("------------------------------------------------------------------\n");
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("\n��Ҫ���ҵ��˲�����!\n");
    }
}
void xiugai(stu *p2)   //ͨ�����������޸�����
{
    char name[20];
    int b=0,i;
    printf("\n\t\t\t�޸�����\n");
    printf("----------------------------------------------------------------------\n");
    printf("�����뽫Ҫ�޸��˵�����:");
    scanf("%s",name);
    while(p2!=NULL)
    {
        if(strcmp(name,p2->name)==0)
        {
      	    printf("��ͬѧ�Ļ�����Ϣ\n");
    		printf("����:%s\n",p2->name);
  			printf("�༶:%s\n",p2->Class);
        	printf("ѧ��:%s\t",p2->iD);
        	printf("�Ա�:%s\t",p2->sex);
        	printf("����:%s\t",p2->address);
        	printf("�ֻ���:%s\t",p2->phone);
        	printf("QQ��:%s\t",p2->QQ);
        	printf("email:%s\n",p2->email);
            printf("\n��ѡ��Ҫ�޸ĵ���Ϣ\n");
            printf("\t1.����\t2.�༶\t3.ѧ��\t4.�Ա�\n\t5.����\t6.�ֻ���\t7.QQ\t8.email\n");
            printf("\n����ѡ����(1~8):");
            scanf("%d",&i);
            printf("�������޸�֮�������\n");
            switch(i)
            {
            case 1:printf("����:");
                scanf("%s",&p2->name);
                break;
            case 2:printf("�༶:");
                scanf("%s",&p2->Class);
                break;
            case 3:printf("ѧ��:");
                scanf("%s",&p2->iD);
                break;
            case 4:printf("�Ա�:");
                scanf("%s",&p2->sex);
                break;
            case 5:printf("����:");
                scanf("%s",&p2->address);
                break;
            case 6:printf("�ֻ���:");
                scanf("%s",&p2->phone);
                break;
            case 7:printf("QQ:");
                scanf("%s",&p2->QQ);
                break;
            case 8:printf("email:");
                scanf("%d",&p2->email);
                break;
            }
            printf("\n�޸ĳɹ�!\n");
            printf("------------------------------------------------------------------------\n");
            b=1;
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("û���ҵ�����!\n");
    }
}
//-------------------------------------����-----------------------------------------------------
void save(stu *p2)   //��������
{	int i;
    FILE *fp;
    char file[15];
    printf("\n\t\t\t��������\n");
    printf("----------------------------------------------------------------------\n");
    printf("�����ļ���:");
    scanf("%s",file);
    if((fp=fopen(file,"w+"))==NULL)
    {
        printf("�򲻿�����˵��ô��\n");
        exit(0);
    }
  //  fprintf(fp,"����\t�༶\tѧ��\t�Ա�\t����\t�ֻ���\tQQ��\t email\n");
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
        i=0;
    }
    fprintf(fp,"0");	
    printf("\n����ɹ�!\n");
    printf("--------------------------------------------------------------------------\n");
    fclose(fp);
}
stu* duqu(){
	FILE *fp;
	int i;
// int result;   
char filename[20];
//int rows;            // ����һ���ļ�������¼����
// ����һ��Student�ṹ��
stu *stur,*p1;
p1=(stu *)malloc(sizeof(stu));
stur=(stu *)malloc(sizeof(stu));
printf("�������ļ���");
scanf("%s",filename);
head=stur;
// ���ļ��е���������¼������
//result = stat(filename, &buf);
//    if (result != 0)  
//      {  
//          perror ("Failed ^_^");  
//      }  
//    else  {
//
//rows = buf.st_size/sizeof(stu);
//	}
fp = fopen(filename,"r");// ���ļ�
//rewind(fp);
    //���ļ��е���Ϣ��ȡ�������Ҵ洢��temp��
while(feof(fp)==0)                     //��ȡһ�����ݺ�ָ��ָ����һ�����ݣ������ж��Ƿ�ָ�����һ�� 
	{ 
		fscanf(fp,"%s\t%s\t%s%s\t%s\t%s\t%s\t%s",&stur->name,&stur->Class,stur->iD,&stur->sex,&stur->address,&stur->phone,&stur->QQ,&stur->email );
				 p1=stur;
                stur=(stu *)malloc(sizeof(stu));
                if(stur!=NULL)
                {
                    p1->next=stur;
                }
	} 
  //  fscanf(fp, "%s\t%s\t%s%s\t%s\t%s\t%s\t%s",stur[0].name,stur[0].Class,stur[0].iD,stur[0].sex,stur[0].address,stur[0].phone,stur[0].QQ,stur[0].email );
//fread((char *)stur,sizeof(stu),rows,fp);// ��ȡ���ݵ�������
fclose(fp);// �ر��ļ�
 return(p1->next);
 }
