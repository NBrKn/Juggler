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
    
    //exit code
    closegraph();
    getch();
    //end exit
}