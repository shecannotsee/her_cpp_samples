#include <iostream>
#include <string>
using namespace std;

int main(){
part2:
	int aa=0;
	switch(aa){
		case 0:
		cout<<"1"<<endl;
	}
	goto part2;
part1:
	string str;
	cin>>str;
	int a = 0 ;
	int temp = 0;
	for( int i=0 ; i<str.size() ; i++ ){
		if( str[i]=='1' ){
			temp = 0 ;
			for( int j=0 ; j<(str.size()-i) ; j++){
				if( j==0 ){
					temp = 1 ;
				}
				else{
					temp = temp * 2 ;
				}
			}
			a = a + temp ;
		}
	}
	cout << str <<"(2)=" << a << "(10)" <<endl;
	
	int index = 0;
	while(a!=1){
		if(a%2==0){// a/2=0
			index++;
			cout<<"a is"<<a<<"and a/2 is"<<a/2<<"now is"<<index<<endl;
			a=a/2;
		}
		else{// a/2=1
			index++;
			cout<<"a is"<<a<<"and a+1 is"<<a+1<<"now is"<<index<<endl;
			a=a+1;
		}
	}
	
goto part1;
	return 0;
}
