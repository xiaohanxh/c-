#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <windows.h>
#include <unistd.h>
#include <sys/types.h> 
typedef struct student;
stu *shuru();
void Input_Stu_Information(stu *p1);	
int dl();					//��¼���� 
int ll();					// ������� 
int lr();					//¼��˵� 
int cx(); 					//��ѯ 
int aq();
int caidan();				//�˵� 
int shezhi();				//���� 
void ad();              //��ʽ�� 
stu * lookdata(stu *p1);     //�鿴����
void deletedn();          //ͨ������ɾ������
void find(stu *p2);     // ͨ���������Ҳ鿴����
void find2(stu *p2);  //ͨ���༶���Ҳ鿴����
void find1(stu *p2);        //ͨ��ѧ�Ų��Ҳ鿴����
void xiugai(stu *p2);   //ͨ�����������޸�����
void save(stu *p2);   //��������
stu *duqu();                     //���ļ��ж�ȡ 

int main(){

//----------------------------��¼--------------;
if(dl()==3)goto end; 
//----------------------------�˵�ѡ��---------- 
  int a,c;
while(1){

	c=caidan();
	if(0<c&&c<9){
	
	switch(c){
//------------------------------------
		case 1:switch(lr()){ 
				case 1:shuru() ;break; 
				case 2:shuru() ;break;
				case 3:break;
			}		break;
		case 2:printf("1.���ļ��ж�ȡ\n""2.ֱ�����\n""3.  ����\n");
		scanf("%d",&a);
					 switch(a){
					 	case 1:*duqu();
							break;
						case 2:	lookdata(head);
							break;
						case 3:
							break;
						
					 }
			   break;  //�鿴����	
		case 3:switch(cx()){
					case 1: find(head);break;
					case 2: find1(head);break;
					case 3: find2(head);break;
					case 4: break;}break;
		case 4:xiugai(head);break;
		case 5: deletedn();break;
		case 6:	switch(shezhi()){
					case 1:ad();break;
					case 2:printf("�ޣ������������˵�");Sleep(3300);break;
					case 3:break;}	break;
		case 7:save(head);break;
		case 8: goto end;
	}}else{printf("�����������ȷ����");
	Sleep(2000);
	}
	}
end:	return 0;
}
