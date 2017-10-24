#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

int total;

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

     //For centre part
     setcolor(WHITE);
     rectangle(290,129,350,200);
     setfillstyle(1,RED);
     floodfill(300,150,WHITE);

     //for legs
     drawpoly(8,legs);
     setfillstyle(1,BLUE);
     floodfill(300,220,WHITE);

     //for shoes
     drawpoly(4,lshoe);
     setfillstyle(1,RED);
     floodfill(290,285,WHITE);

    drawpoly(4,rshoe);
    setfillstyle(1,RED);
    floodfill(345,285,WHITE);
    
    //Hands
    setlinestyle(0,1,7);
    setcolor(YELLOW);
    //left
    line(290, 129, 255, 165);
    //right
    line(350, 129, 385, 165);
    //end draw man

}

void juggle2(){
    //ball movement
    int angle=180, angle2=180, angle3=360;
    float rad_angle, rad_angle2 ,rad_angle3, c_x, c_y, c_x2, c_y2, c_x3, c_y3;

    int orig_x=320, orig_y=115, radius=95, flag=1, flag2=1, flag3=1;
    int i;
    int count =0;
    //for(i=0; count<=3; i++){
    while(!kbhit()){
    //setactivepage(i);
    rad_angle = angle * 3.14 / 180;
	c_x = orig_x + cos(rad_angle)*radius;
	c_y = orig_y + sin(rad_angle)*radius;
    setcolor(LIGHTRED);
    circle(c_x, c_y, 10);
    setfillstyle(1, LIGHTRED);
    floodfill(c_x, c_y, LIGHTRED);
	angle+=flag*25;
	if(angle>=360){
        flag=-1;
        angle=360;
	} else if(angle<=180){
        flag=1;
        angle=180;
        count++;
	}
	rad_angle2 = angle2 * 3.14 / 180;
	c_x2 = orig_x + cos(rad_angle2)*(radius-3);
	c_y2 = orig_y + sin(rad_angle2)*(radius-3);
	setcolor(LIGHTBLUE);
    circle(c_x2, c_y2, 10);
    setfillstyle(3, LIGHTBLUE);
    floodfill(c_x2, c_y2, LIGHTBLUE);
	angle2+=(flag2*20);
	if(angle2>=360){
        flag2=-1;
        angle2=360;
	} else if(angle2<=180){
        flag2=1;
        angle2=180;
        count++;
	}
	rad_angle3 = angle3 * 3.14 / 180;
	c_x3 = orig_x + cos(rad_angle3)*(radius-2);
	c_y3 = orig_y + sin(rad_angle3)*(radius-2);
	setcolor(LIGHTGREEN);
    circle(c_x3, c_y3, 10);
    setfillstyle(2, LIGHTGREEN);   
    floodfill(c_x3, c_y3, LIGHTGREEN);
	angle3+=(flag3*30);
	if(angle3>=360){
        flag3=-1;
        angle=360;
        count++;
	} else if(angle3<=180){
        flag3=1;
        angle=180;
	}
	setcolor(WHITE);
    drawman();
    if(angle3>=360 || angle3<=180 || angle2>=360 || angle2<=180 || angle>=360 || angle<=180){
        line(255, 165, 235, 100);
        line(385, 165, 405,100);
        setfillstyle(1, YELLOW);
        fillellipse(235, 100, 10, 5);
        fillellipse(405, 100, 10, 5);
    } else {
        line(255, 165, 225, 120);
        line(385, 165, 415,120);
        setfillstyle(1, YELLOW);        
        fillellipse(225, 120, 10, 5);
        fillellipse(415, 120, 10, 5);
    }
    
	delay(100);
	cleardevice();
    }
    //total = i;
    //end ball movement
}

// void flipper(){
//     int i; 
//     while(!kbhit()){
//         for (i = 0 ; i<=total; i++){
//             setvisualpage(i);
//             delay(100);
            
//         }
//     }
// }

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

    juggle2();
    //flipper();
    //exit code
    getch();
    closegraph();
    //end exit
}