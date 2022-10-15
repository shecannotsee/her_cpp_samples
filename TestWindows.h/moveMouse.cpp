#include <Windows.h>
#include <stdio.h> 
#include <time.h>
#include "clickAndMove.hpp"
int main(){
	LONG zx = -1;
	LONG zy = -1;
	POINT ptB = { 0, 0 };
	while (1)
	{				
		LPPOINT xy = &ptB;//variable of mouse position
		GetCursorPos(xy);//get mouse position
        static time_t last = 0;
	    time_t now = time(nullptr);
	    if (now > last) {
		    MouseMove(xy->x,(xy->y)+100);
		    last = now;
	    }
        if ((zx != xy->x) || (zy != xy->y))
		{
			printf("x=%d,y=%d\n", xy->x, xy->y);
			zx = xy->x;
			zy = xy->y;
		}
	}	
}