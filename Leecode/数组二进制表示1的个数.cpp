/**/
#include <iostream>

int main(){
part1:
    int number;
    std::cin>>number;
    int countOne=0;
    for(int i=0;i<32;i++){
        if(number<0){
            countOne++;
        }
        number=number<<1;
    }
    std::cout<<countOne<<"\n";

goto part1;
    return 0;
}