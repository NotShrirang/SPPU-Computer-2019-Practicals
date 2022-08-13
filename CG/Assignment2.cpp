#include <graphics.h>
#include <math.h>
using namespace std;
class cir
{
public:
    int x1, y1, x2, y2, k;
    float X, Y, xn, yn,x, y;

    int r,d;
    void bressenham(int xi, int yi,int i);

    void dda(int x1, int y1, int x2, int y2);
};
void cir::bressenham(int xi, int yi,int i)
{
	r=i;
	x=0;
	y=r;
	d=3-(2*r);
	while(x<y)
	{
		
		putpixel(xi+x,yi+y,GREEN);
		delay(20);
		putpixel(xi+y,yi+x,GREEN);
		putpixel(xi+y,yi-x,GREEN);
		putpixel(xi+x,yi-y,GREEN);
		putpixel(xi-x,yi+y,GREEN);
		putpixel(xi-y,yi+x,GREEN);
		putpixel(xi-y,yi-x,GREEN);
		putpixel(xi-x,yi-y,GREEN);
		if(d<0)
		{
			d=d+(4*x+6);	
		}
		else
		{
			d=d+(4*(x-y))+10;
			y=y-1;
		}
		x=x+1;
	}

	
}
void cir::dda(int x1, int y1, int x2, int y2)
{
    float x, y,le;
    x = x2 - x1;
    y = y2 - y1;
    float m = y / x;
    float X, Y, xn, yn;
    if (m < 1)
    {
        xn = 1;
        yn = m;
        le = x;
        
    }
    if (m > 1)
    {
        xn = 1 / m;
        yn = 1;
        le = y;
    }
    if (m == 1)
    {
        xn = 1;
        yn = 1;
        le = x;
    }
    X = x1;
    Y = y1;
    for (k = 0; k <= le; k++)
    {
        putpixel(X, Y, GREEN);
        X = X + xn;
        Y = Y + yn;
    }
}
int main()
{
    cir cr,line;
    int gm, gd, i,r;
    gd = DETECT;
    i = 100;
    r=i/2;
    initgraph(&gd, &gm, NULL);
    cr.bressenham(200,200,i);
	cr.bressenham(200,200,r);
	
    line.dda(115,250,200,100);
	line.dda(115,250,288,250);
	line.dda(200,100,288,250);
	
	line.dda(50,400,450,400);
	line.dda(50,700,450,700);
	line.dda(50,400,50,700);
	line.dda(450,400,450,700);
	
	line.dda(250,400,450,550);
	line.dda(50,550,250,400);
	line.dda(50,550,250,700);
	line.dda(250,700,450,550);
	
	cr.bressenham(250,550,120);
	
    getch();
    closegraph();
    return 0;
}
