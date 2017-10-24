#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

void drawman(){
     int cap[]={298,85,319,45,341,85,319,45};
     int legs[]={290,200,285,280,305,280,320,225,322,225,335,280,355,280,350,200};
     int lshoe[]={285,280,275,287,305,287,305,280};
     int rshoe[]={335,280,335,287,365,287,355,280};

     //draw man
     ellipse(320,95,360,0,25,20);
     setfillstyle(1,YELLOW);
     floodfill(320,95,WHITE);

     drawpoly(4,cap);
     setfillstyle(1,MAGENTA);
     floodfill(325,70,WHITE);

   //  line(298,85,319,45); //cap left slant line
    // line(341,85,319,45); //cap right slant line

     circle(319,40,5); //top circle
     setfillstyle(1,CYAN);
     floodfill(319,40,WHITE);


     arc(345,95,280,90,5);  //for right ear
     setfillstyle(1,RED);
     floodfill(345,95,WHITE);

     arc(295,95,90,280,5); //for left ear
     setfillstyle(1,YELLOW);
     floodfill(295,95,WHITE);

     setcolor(BLACK);
     line(320,92,320,100);

     setcolor(WHITE);
     circle(310,90,2);
     setfillstyle(1,BLACK);
     floodfill(310,90,WHITE);

     circle(330,90,2);
     setfillstyle(1,BLACK);
     floodfill(330,90,WHITE);

     setcolor(BLACK);
     arc(320,100,200,-20,10);


     //for neck
     setcolor(WHITE);
     rectangle(313,115,328,129);
     setfillstyle(1,YELLOW);
     floodfill(320,120,WHITE);

    // line(313,115,313,129);
    // line(328,115,328,129);


     //For centre part
     setcolor(WHITE);
    // arc(320,225,72,107,100);
     rectangle(290,129,350,200);
     setfillstyle(1,RED);
     floodfill(300,150,WHITE);
    // line(290,129,290,200);
    // line(350,129,350,200);
    // line(290,193,350,193);
    // line(290,200,350,200);

     //for legs
     drawpoly(8,legs);
     setfillstyle(1,BLUE);
     floodfill(300,220,WHITE);
    // line(290,200,285,280);
    // line(320,225,305,280);
    // line(322,225,335,280);
    // line(350,200,355,280);

     //for right hand
     line(290,129,255,165);
     line(255,165,290,200);
     line(290,149,275,165);
     line(275,165,290,182);

     //for left hand
     line(350,129,385,165);
     line(385,165,350,200);
     line(350,149,365,165);
     line(365,165,350,182);

     //for shoes
     drawpoly(4,lshoe);
     setfillstyle(1,RED);
     floodfill(290,285,WHITE);
    // line(285,280,275,287);
    // line(275,287,305,287);
    // line(305,280,305,287);
    // line(285,280,305,280);

    drawpoly(4,rshoe);
    setfillstyle(1,RED);
    floodfill(345,285,WHITE);
    // line(335,280,335,287);
    // line(335,287,365,287);
    // line(355,280,365,287);
    // line(335,280,355,280);

    //end draw man

}
void main(){
    //init code
    int gdriver=DETECT,gmode;
    initgraph(&gdriver, &gmode, "..\\BGI");
    int errorcode = graphresult();
    if (errorcode != grOk) {  /* an error occurred */
	printf("Graphics error: %s\n", grapherrormsg(errorcode));
	printf("Press any key to halt:");
	getch();
	exit(1);               /* terminate with an error code */
    }
    //end init

    //ball movement
    int angle=180, angle2=180, angle3=360;
    float rad_angle, rad_angle2 ,rad_angle3, c_x, c_y, c_x2, c_y2, c_x3, c_y3;

    int orig_x=320, orig_y=165, radius=50, flag=1, flag2=1, flag3=1;
    while(!kbhit()){
	rad_angle = angle * 3.14 / 180;
	c_x = orig_x + cos(rad_angle)*radius;
	c_y = orig_y + sin(rad_angle)*radius;
	setcolor(RED);
	circle(c_x, c_y, 5);
	angle+=flag;
	if(angle==360){
		flag=-1;
	} else if(angle==180){
		flag=1;
	}
	rad_angle2 = angle2 * 3.14 / 180;
	c_x2 = orig_x + cos(rad_angle2)*(radius-3);
	c_y2 = orig_y + sin(rad_angle2)*(radius-3);
	setcolor(BLUE);
	circle(c_x2, c_y2, 5);
	angle2+=(flag2*2);
	if(angle2>=360){
		flag2=-1;
	} else if(angle2<=180){
		flag2=1;
	}
	rad_angle3 = angle3 * 3.14 / 180;
	c_x3 = orig_x + cos(rad_angle3)*(radius-2);
	c_y3 = orig_y + sin(rad_angle3)*(radius-2);
	setcolor(GREEN);
	circle(c_x3, c_y3, 5);
	angle3+=(flag3*3);
	if(angle3>=360){
		flag3=-1;
	} else if(angle3<=180){
		flag3=1;
	}
	setcolor(WHITE);
	drawman();
	delay(10);
	cleardevice();
    }
    //end ball movement

    //exit code
    closegraph();
    getch();
    //end exit
}