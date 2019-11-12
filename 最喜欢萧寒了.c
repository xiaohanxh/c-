#include <windows.h>

LPCSTR argv[1];
int WINAPI WinMain(

HINSTANCE hInstance,

HINSTANCE hPrevInstance,

LPSTR lpCmdLine,

int nCmdShow

){  ShowWindow(FindWindow("ConsoleWindowClass",argv[0]),0);
    while(1){
        
    int a = MessageBox(NULL, TEXT("最喜欢萧寒了！"), TEXT("提示"), MB_OKCANCEL);

    if(a == IDOK){

    MessageBox(NULL, TEXT("嗯嗯，萧寒也喜欢你！"), TEXT("提示"), MB_OK);
    break;
    }else{

    MessageBox(NULL, TEXT("不可以 啊!必须同意！"), TEXT("提示"), MB_OK);}

//第二次
    int b = MessageBox(NULL, TEXT("最喜欢萧寒了！"), TEXT("提示"), MB_OKCANCEL);

    if(b == IDOK){

    MessageBox(NULL, TEXT("嗯嗯，最好了！"), TEXT("提示"), MB_OK);
    break;
    }else{

    MessageBox(NULL, TEXT("快点，听话，点确定！"), TEXT("提示"), MB_OK);}
//第三次
    int c = MessageBox(NULL, TEXT("最喜欢萧寒了！"), TEXT("提示"), MB_OKCANCEL);

    if(c == IDOK){

    MessageBox(NULL, TEXT("嗯嗯，最好了！"), TEXT("提示"), MB_OK);
    break;
    }else{

    MessageBox(NULL, TEXT("哇！你不乖了啊！"), TEXT("提示"), MB_OK);}
//第四次
    int d = MessageBox(NULL, TEXT("最喜欢萧寒了！"), TEXT("提示"), MB_OKCANCEL);

    if(d == IDOK){

    MessageBox(NULL, TEXT("嗯嗯，最好了！"), TEXT("提示"), MB_OK);
    break;
    }else{

    MessageBox(NULL, TEXT("看到了吧，你不点确定就出不去！"), TEXT("提示"), MB_OK);}
//第五次
int e = MessageBox(NULL, TEXT("最喜欢萧寒了！"), TEXT("提示"), MB_OKCANCEL);

    if(e == IDOK){

    MessageBox(NULL, TEXT("嗯嗯，最好了！"), TEXT("提示"), MB_OK);
    break;
    }else{

    MessageBox(NULL, TEXT("快点确定啦！！生气了！"), TEXT("提示"), MB_OK);}
//第六次
int f = MessageBox(NULL, TEXT("最喜欢萧寒了！"), TEXT("提示"), MB_OKCANCEL);

    if(f == IDOK){

    MessageBox(NULL, TEXT("嗯嗯，最好了！"), TEXT("提示"), MB_OK);
    break;
    }else{

    MessageBox(NULL, TEXT("(￢︿??￢☆)萧寒不要你了！"), TEXT("提示"), MB_OK);
   }
    }
  return 0;}