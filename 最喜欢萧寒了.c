#include <windows.h>

LPCSTR argv[1];
int WINAPI WinMain(

HINSTANCE hInstance,

HINSTANCE hPrevInstance,

LPSTR lpCmdLine,

int nCmdShow

){  ShowWindow(FindWindow("ConsoleWindowClass",argv[0]),0);
    while(1){
        
    int a = MessageBox(NULL, TEXT("��ϲ�������ˣ�"), TEXT("��ʾ"), MB_OKCANCEL);

    if(a == IDOK){

    MessageBox(NULL, TEXT("���ţ�����Ҳϲ���㣡"), TEXT("��ʾ"), MB_OK);
    break;
    }else{

    MessageBox(NULL, TEXT("������ ��!����ͬ�⣡"), TEXT("��ʾ"), MB_OK);}

//�ڶ���
    int b = MessageBox(NULL, TEXT("��ϲ�������ˣ�"), TEXT("��ʾ"), MB_OKCANCEL);

    if(b == IDOK){

    MessageBox(NULL, TEXT("���ţ�����ˣ�"), TEXT("��ʾ"), MB_OK);
    break;
    }else{

    MessageBox(NULL, TEXT("��㣬��������ȷ����"), TEXT("��ʾ"), MB_OK);}
//������
    int c = MessageBox(NULL, TEXT("��ϲ�������ˣ�"), TEXT("��ʾ"), MB_OKCANCEL);

    if(c == IDOK){

    MessageBox(NULL, TEXT("���ţ�����ˣ�"), TEXT("��ʾ"), MB_OK);
    break;
    }else{

    MessageBox(NULL, TEXT("�ۣ��㲻���˰���"), TEXT("��ʾ"), MB_OK);}
//���Ĵ�
    int d = MessageBox(NULL, TEXT("��ϲ�������ˣ�"), TEXT("��ʾ"), MB_OKCANCEL);

    if(d == IDOK){

    MessageBox(NULL, TEXT("���ţ�����ˣ�"), TEXT("��ʾ"), MB_OK);
    break;
    }else{

    MessageBox(NULL, TEXT("�����˰ɣ��㲻��ȷ���ͳ���ȥ��"), TEXT("��ʾ"), MB_OK);}
//�����
int e = MessageBox(NULL, TEXT("��ϲ�������ˣ�"), TEXT("��ʾ"), MB_OKCANCEL);

    if(e == IDOK){

    MessageBox(NULL, TEXT("���ţ�����ˣ�"), TEXT("��ʾ"), MB_OK);
    break;
    }else{

    MessageBox(NULL, TEXT("���ȷ�������������ˣ�"), TEXT("��ʾ"), MB_OK);}
//������
int f = MessageBox(NULL, TEXT("��ϲ�������ˣ�"), TEXT("��ʾ"), MB_OKCANCEL);

    if(f == IDOK){

    MessageBox(NULL, TEXT("���ţ�����ˣ�"), TEXT("��ʾ"), MB_OK);
    break;
    }else{

    MessageBox(NULL, TEXT("(�V��??�V��)������Ҫ���ˣ�"), TEXT("��ʾ"), MB_OK);
   }
    }
  return 0;}