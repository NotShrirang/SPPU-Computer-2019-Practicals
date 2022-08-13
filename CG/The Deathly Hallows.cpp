#include<iostream>
#include<graphics.h>

int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
	line(220,110,330,300.52);
	line(220,110,110,300.52);
	line(330,300.52,110,300.52);
	circle(220,237.013333,63.50666667);
	line(220,110,220,300.52);
	
	getch();
	closegraph();
	return 0;
	
}
