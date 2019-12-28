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
int dl();					//登录密码 
int ll();					// 浏览数据 
int lr();					//录入菜单 
int cx(); 					//查询 
int aq();
int caidan();				//菜单 
int shezhi();				//设置 
void ad();              //格式化 
stu * lookdata(stu *p1);     //查看数据
void deletedn();          //通过姓名删除数据
void find(stu *p2);     // 通过姓名查找查看数据
void find2(stu *p2);  //通过班级查找查看数据
void find1(stu *p2);        //通过学号查找查看数据
void xiugai(stu *p2);   //通过姓名查找修改数据
void save(stu *p2);   //保存数据
stu *duqu();                     //从文件中读取 

int main(){

//----------------------------登录--------------;
if(dl()==3)goto end; 
//----------------------------菜单选择---------- 
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
		case 2:printf("1.从文件中读取\n""2.直接浏览\n""3.  返回\n");
		scanf("%d",&a);
					 switch(a){
					 	case 1:*duqu();
							break;
						case 2:	lookdata(head);
							break;
						case 3:
							break;
						
					 }
			   break;  //查看数据	
		case 3:switch(cx()){
					case 1: find(head);break;
					case 2: find1(head);break;
					case 3: find2(head);break;
					case 4: break;}break;
		case 4:xiugai(head);break;
		case 5: deletedn();break;
		case 6:	switch(shezhi()){
					case 1:ad();break;
					case 2:printf("无，即将返回主菜单");Sleep(3300);break;
					case 3:break;}	break;
		case 7:save(head);break;
		case 8: goto end;
	}}else{printf("输入错误，请正确输入");
	Sleep(2000);
	}
	}
end:	return 0;
}
