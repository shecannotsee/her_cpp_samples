#include <iostream>
#include <windows.h>
#include <conio.h>

int main(){
    char flag;
    int key=0;
    while(true){
        if(_kbhit()){
            key=_getch();
            printf("KeyCode is:%d",key);
            printf("\n");
        }
    }

    getchar();
    return 0;
}