#include <Windows.h>
#include <stdio.h> 

int main(){
	LONG zx = -1;
	LONG zy = -1;
	POINT ptB = { 0, 0 };
	while (1)
	{				
		LPPOINT xy = &ptB;	//位置变量
		GetCursorPos(xy);	//获取鼠标当前位置		
		//如果鼠标移动，（即当前的坐标改变则打印出坐标）打印出做坐标。
		if ((zx != xy->x) || (zy != xy->y))
		{
			printf("x=%d,y=%d\n", xy->x, xy->y);
			zx = xy->x;
			zy = xy->y;
		}
	}	
}