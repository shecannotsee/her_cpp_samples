#include <string>
#include <iostream>
using namespace std;

int numSteps(string s) {
    int a = 0 ; int temp = 0 ;
	//二进制转十进制
    for ( int i=0 ; i<s.size() ; i++ ){
        if( s[i]=='1' ){
            for( int j=0 ; j<(s.size()-i) ; j++ ){
                if( j==0 ){
                    temp = 1 ;
                }
                else{
                    temp = temp * 2;
                }
            }
            a = a + temp;
        }
    }
        
	//用十进制计算
    temp = 0 ;
    while(a>1){
        if( a%2 == 1 ){//是奇数
            a = a + 1 ;
        }
        else{//是偶数
            a = a / 2 ;
        }
        temp++;
    }

    return temp;
}

int main(){
part1:
	string s;
	cin>>s;
	cout<<numSteps(s)<<endl;
goto part1;
	return 0;
}