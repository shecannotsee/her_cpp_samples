#include <iostream>
#include "clickAndMove.hpp"
using namespace std;

int main(){
part1:
    cout<<"输入需要点击的位置\n";
    cout<<"x is?\n";
    int x=0;
    cin>>x;
    cout<<"y is?\n";
    int y=0;
    cin>>y;

    MouseMove(x,y);
    for(int i=0;i<5000;i++){
        LeftClick();
    }

    goto part1;
    return 0;
}