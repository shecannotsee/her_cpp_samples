#include <conio.h>//_kbhit() and _getch()
#include <iostream>
using namespace std;
int main()
{
	int ch;
	while (1){
		if (_kbhit()){//如果有按键按下，则_kbhit()函数返回真
			ch = _getch();//使用_getch()函数获取按下的键值
			cout << ch;
			if (ch == 27){ break; }//ESC,27
		}
	}
	system("pause");
	return 0;
}