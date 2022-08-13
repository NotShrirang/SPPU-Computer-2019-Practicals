#include <iostream>
#include <graphics.h>
using namespace std;
class lineClip
{
	private:
		int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
		//  0001      0010       0100        1000
		int x1, x2, y1, y2, xl, yl, xh, yh, x, y;
	public:
		int getcode(int x, int y);
		void process();
};
int lineClip :: getcode(int x, int y)
{
	int code = 0;
	if (y > yh)
		code |= TOP;   //code = code | TOP
	if (y < yl)
		code |= BOTTOM;
	if (x < xl)
		code |= LEFT;
	if (x > xh)
		code |= RIGHT;
	return code;
}
void lineClip :: process()
{
	int code1, code2;	
	cout<<"Enter top left coordinates of window:\n";
	cin>>xl>>yl;
	cout<<"Enter bottom right coordinates of window:\n";
	cin>>xh>>yh;
	setcolor(YELLOW);
	rectangle(xl, yl, xh, yh);
	cout<<"\nEnter the line coordinates:\n";
	cout<<"Starting coordinate:\n";
	cin>>x1>>y1;
	cout<<"\nEnding coordinate:\n";
	cin>>x2>>y2;
	setcolor(WHITE);
	line (x1, y1, x2, y2);
	delay(1500);
	code1 = getcode(x1, y1);
	code2 = getcode(x2, y2);
	int temp;
	float m;
	int flag = 0;
	while (1)
	{
		m = (float)(y2 - y1)/(x2 - x1);
		if ((code1 == 0) && (code2 == 0))
		{
			flag = 1;
			break;
		}
		else if((code1 & code2) != 0)
		{
			break;
		}
		else
		{
			if (code1 == 0)
				temp = code2;
			else
				temp = code1;
			if (temp & TOP)
			{
				x = x1 + (yh - y1)/m;   
				y = yh;
			}
			else if (temp & BOTTOM)
			{
				x = x1 + (yl - y1)/m;
				y = yl;
			}
			else if (temp & LEFT)
			{
				y = y1 + m*(xl - x1);
				x = xl;
			}
			else if (temp & RIGHT)
			{
				y = y1 + m*(xh - x1);
				x = xh;
			}
			if (temp == code1)
			{
				x1 = x;
				y1 = y;
				code1 = getcode(x1, y1);
			}
			else
			{
				x2 = x;
				y2 = y;
				code2 = getcode(x2, y2);
			}
		}
	}
cleardevice();
rectangle (xl, yl, xh, yh);
setcolor(YELLOW);
if (flag == 1)
	line(x1, y1, x2, y2);
getch();
closegraph();
}
int main()
{
	int gd = DETECT, gm;
	initgraph (&gd, &gm, NULL);
	lineClip li;
	li.process();
	return 0;
}
