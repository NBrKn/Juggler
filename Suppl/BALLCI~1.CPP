#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
void main(){
    //init code
    int gdriver=DETECT,gmode;
    initgraph(&gdriver, &gmode, "c:\\TURBOC3\\BGI");
    int errorcode = graphresult();
    if (errorcode != grOk) {  /* an error occurred */
	printf("Graphics error: %s\n", grapherrormsg(errorcode));
	printf("Press any key to halt:");
	getch();
	exit(1);               /* terminate with an error code */
    }
    //end init

    int angle=0;
    float rad_angle, c_x, c_y;

    int orig_x=300, orig_y=300, radius=100;
    while(!kbhit()){
	rad_angle = angle * M_PI / 180;
	c_x = orig_x + cos(rad_angle)*radius;
	c_y = orig_y + cos(rad_angle)*radius;
	circle(c_x, c_y, 5);
	angle=(angle+1)%180;
	delay(50);
    }
    //exit code
    closegraph();
    getch();
    //end exit
}