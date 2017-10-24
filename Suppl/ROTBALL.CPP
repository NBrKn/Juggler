#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
void main()
{
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"..\\bgi");
    setcolor(WHITE);

    rectangle(10,60,400,400);

    //Central inner circle
    int CC_x,CC_y;
    CC_x=10+390/2;
    CC_y=60+340/2;
    outtextxy(CC_x, CC_y, "Central Circle");
    circle(CC_x,CC_y,30);

    //orbit
    circle(CC_x,CC_y,120);

    //Outer circle
    int c_x, c_x_copy,  c_y;
    double angle;
    angle=0;
    c_x=CC_x+120;
    c_y=CC_y;
    while(1){
	    setcolor(WHITE);
	    outtextxy(c_x, c_y, "Outer Circle");
	    circle(c_x,c_y,10);
	    // Blinking effect
	    circle(CC_x,CC_y,120);
	    delay(100);
	    setcolor(BLACK);
	    outtextxy(c_x, c_y, "Outer Circle");
	    circle(c_x,c_y,10);
	    delay(90);
	    // modified code
	    c_x_copy = c_x;
	    c_x = CC_x + (c_x - CC_x)*cos(angle) - (c_y - CC_y)*sin(angle);
	    c_y = CC_y + (c_x_copy - CC_x)*sin(angle) - (c_y - CC_y)*cos(angle);
	    angle++;
	    // end of modified code
	    }

    getch();
    }