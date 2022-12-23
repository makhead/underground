#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include "strlib.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
#include <string.h>
#include <math.h>

#include "setting.h"
#include "summon.h"
#include "object.h"
#include "menu.h"
#include "HPSystem.h"
#include "record.h"

void DrawMan(int animeState){

	switch(animeState){
		case faceLeft1:
			DrawMan_left1();
			break;
		case faceLeft2:
			DrawMan_left2();
			break;
		case faceLeft3:
			DrawMan_left3();
			break;
		case faceRight1:
			DrawMan_right1();
			break;
		case faceRight2:
			DrawMan_right2();
			break;
		case faceRight3:
			DrawMan_right3();
			break;
		case faceForward:
			DrawMan_forward();
			break;
		case faceFalling1:
			DrawMan_falling1();
			break;
		case faceFalling2:
			DrawMan_falling2();
			break;
		case faceFalling3:
			DrawMan_falling3();
			break;
		case faceFalling4:
			DrawMan_falling4();
			break;
		case faceFalling5:
			DrawMan_falling5();
			break;
		case faceFalling6:
			DrawMan_falling6();
			break;
	}
	return;
}
void DrawMan_forward()
{
	double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;
	
	//draw leg
	MovePen(initX-0.3*BODYSIZE,initY);
	DrawLine(0.2*BODYSIZE,0);
	DrawEllipticalArc(0.1*BODYSIZE,0.05*BODYSIZE,0,180);
	MovePen(initX-0.2*BODYSIZE,initY+0.05*BODYSIZE);
	MovePen(initX+0.1*BODYSIZE,initY);
	DrawLine(0.2*BODYSIZE,0);
	DrawEllipticalArc(0.1*BODYSIZE,0.05*BODYSIZE,0,180);
	//draw body
	MovePen(initX-0.1*BODYSIZE,initY);//pants
	DrawLine(0.05*BODYSIZE,0.15*BODYSIZE);
	DrawLine(0.1*BODYSIZE,0);
	DrawLine(0.05*BODYSIZE,-0.15*BODYSIZE);
	MovePen(initX-0.3*BODYSIZE,initY);
	DrawLine(0.15*BODYSIZE,0.25*BODYSIZE);
	tempXleft=CX;
	tempYleft=CY;
	DrawLine(0.3*BODYSIZE,0);
	tempXright=CX;
	tempYright=CY;
	DrawLine(0.15*BODYSIZE,-0.25*BODYSIZE);
	
	
	MovePen(tempXleft,tempYleft);//left hand
	DrawLine(0,0.3*BODYSIZE);
	DrawLine(-0.2*BODYSIZE,-0.2*BODYSIZE);
	tempXleft=CX;
	tempYleft=CY;
	DrawArc(0.05*BODYSIZE,90,270);
	DrawLine(0.15*BODYSIZE,0.15*BODYSIZE);
	MovePen(tempXleft,tempYleft);
	DrawLine(0.05*BODYSIZE,-0.05*BODYSIZE);
	
	MovePen(tempXright,tempYright);//right hand
	DrawLine(0,0.3*BODYSIZE);
	MovePen(CX,CY-0.1*BODYSIZE); 
	DrawLine(0.15*BODYSIZE,-0.15*BODYSIZE);
	tempXright=CX;
	tempYright=CY;
	DrawArc(0.05*BODYSIZE,180,270);
	DrawLine(-0.2*BODYSIZE,0.2*BODYSIZE);
	MovePen(tempXright,tempYright);
	DrawLine(0.05*BODYSIZE,0.05*BODYSIZE);
	
	//draw head
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX-0.3*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.1*BODYSIZE,0);
	MovePen(initX+0.3*BODYSIZE,initY+0.8*BODYSIZE);
	DrawLine(-0.1*BODYSIZE,0);
	MovePen(initX-0.1*BODYSIZE,initY+0.7*BODYSIZE);//mouth
	DrawLine(0.2*BODYSIZE,0);
	
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,0,180);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,0,180);
	//draw hat
	
	/*
	MovePen(initX+0.5*BODYSIZE,initY+1.1*BODYSIZE);
	DrawEllipticalArc(0.5*BODYSIZE,0.25*BODYSIZE,30,120);
	//DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,0,360);
	*/
	MovePen(initX,initY);
	
	
}

void DrawMan_left1(){
double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;
	//draw body(left)
	MovePen(initX-0.17*BODYSIZE,initY+0.58*BODYSIZE);//pants
	DrawLine(-0.06*BODYSIZE,-0.3*BODYSIZE);
	DrawEllipticalArc(0.23*BODYSIZE,0.05*BODYSIZE,200,150);
	DrawEllipticalArc(0.1*BODYSIZE,0.35*BODYSIZE,0,60);
	tempXleft=CX;
	tempYleft=CY;
	tempXright=CX;
	tempYright=CY;
	
	//left hand(left)
	MovePen(tempXleft-0.13*BODYSIZE,tempYleft-0.08*BODYSIZE);
	DrawLine(-0.18*BODYSIZE,-0.07*BODYSIZE);
	DrawLine(-0.15*BODYSIZE,-0.02*BODYSIZE);
	DrawLine(0.001*BODYSIZE,-0.1*BODYSIZE);
	DrawEllipticalArc(0.8*BODYSIZE,0.1*BODYSIZE,300,50);
	DrawArc(0.07*BODYSIZE,270,230);
	MovePen(tempXleft-0.46*BODYSIZE,tempYleft-0.17*BODYSIZE);
	DrawArc(0.055*BODYSIZE,60,250);

	//right hand(left)	
	MovePen(tempXright+0.17*BODYSIZE,tempYright-0.18*BODYSIZE);
	DrawEllipticalArc(0.36*BODYSIZE,0.13*BODYSIZE,5,50);
	DrawLine(0.01*BODYSIZE,-0.1*BODYSIZE);
	DrawLine(0.06*BODYSIZE,-0.038*BODYSIZE);
	DrawLine(0.09*BODYSIZE,0.045*BODYSIZE);
	MovePen(tempXright+0.09*BODYSIZE,tempYright-0.22*BODYSIZE);
	DrawArc(0.047*BODYSIZE,180,230);

	//draw leg(left)
	MovePen(initX-0.23*BODYSIZE,initY+0.28*BODYSIZE);
	DrawEllipticalArc(0.35*BODYSIZE,0.25*BODYSIZE,180,105);
	DrawLine(0.05*BODYSIZE,0);
	DrawLine(0.005*BODYSIZE,0.12*BODYSIZE);
	DrawLine(-0.08*BODYSIZE,0.005*BODYSIZE);
	DrawEllipticalArc(0.14*BODYSIZE,0.15*BODYSIZE,320,60);
	MovePen(initX+0.26*BODYSIZE,initY+0.052*BODYSIZE);
	DrawLine(0,-0.05*BODYSIZE);
	DrawArc(0.047*BODYSIZE,180,200);
	DrawLine(0.005*BODYSIZE,0.13*BODYSIZE);
	DrawLine(-0.09*BODYSIZE,0.01*BODYSIZE);
	
	//draw leg(left)
	MovePen(initX-0.23*BODYSIZE,initY+0.25*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.25*BODYSIZE,140,40);
	DrawLine(0.09*BODYSIZE,-0.05*BODYSIZE);
	DrawLine(0.1*BODYSIZE,0.08*BODYSIZE);
	MovePen(initX-0.32*BODYSIZE,initY+0.08*BODYSIZE);
	DrawArc(0.047*BODYSIZE,30,200);
	DrawLine(0.12*BODYSIZE,-0.06*BODYSIZE);
	DrawLine(0.05*BODYSIZE,0.07*BODYSIZE);

	//draw head(left)
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX-0.3*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.125*BODYSIZE,0);
	MovePen(initX-0.15*BODYSIZE,initY+0.65*BODYSIZE);//mouth
	DrawLine(-0.1*BODYSIZE,0); 
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,10,176);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,10,176);
	MovePen(initX+0.05*BODYSIZE,initY+0.7*BODYSIZE);//ear
	DrawEllipticalArc(0.08*BODYSIZE,0.08*BODYSIZE,240,280);

	
	/*
	MovePen(initX+0.5*BODYSIZE,initY+1.1*BODYSIZE);
	DrawEllipticalArc(0.5*BODYSIZE,0.25*BODYSIZE,30,120);
	//DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,0,360);
	*/
	MovePen(initX,initY);
}

void DrawMan_left2(){
double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;
	//draw body(left)
	MovePen(initX-0.17*BODYSIZE,initY+0.58*BODYSIZE);//pants
	DrawLine(-0.06*BODYSIZE,-0.3*BODYSIZE);
	DrawEllipticalArc(0.23*BODYSIZE,0.05*BODYSIZE,200,150);
	DrawEllipticalArc(0.1*BODYSIZE,0.35*BODYSIZE,0,60);
	tempXleft=CX;
	tempYleft=CY;
	tempXright=CX;
	tempYright=CY;
	
	//left hand(left)
	MovePen(tempXleft-0.13*BODYSIZE,tempYleft-0.08*BODYSIZE);
	DrawLine(-0.18*BODYSIZE,-0.12*BODYSIZE);
	DrawLine(-0.15*BODYSIZE,-0.06*BODYSIZE);
	DrawLine(0.05*BODYSIZE,-0.1*BODYSIZE);
	DrawEllipticalArc(0.9*BODYSIZE,0.48*BODYSIZE,300,28);
	DrawArc(0.06*BODYSIZE,295,200);
	MovePen(tempXleft-0.46*BODYSIZE,tempYleft-0.26*BODYSIZE);
	DrawArc(0.055*BODYSIZE,105,230);
//	DrawLine(0,-0.3*BODYSIZE);

	//right hand(left)	
	MovePen(tempXright+0.13*BODYSIZE,tempYright-0.23*BODYSIZE);
	DrawEllipticalArc(0.2*BODYSIZE,0.16*BODYSIZE,4,60);
	DrawLine(0.019*BODYSIZE,-0.16*BODYSIZE);
	DrawLine(0.09*BODYSIZE,0.034*BODYSIZE);
	MovePen(tempXright+0.05*BODYSIZE,tempYright-0.26*BODYSIZE);
	DrawArc(0.047*BODYSIZE,180,230);

	//draw leg(left)
	MovePen(initX-0.23*BODYSIZE,initY+0.28*BODYSIZE);
	DrawEllipticalArc(0.35*BODYSIZE,0.25*BODYSIZE,180,105);
	DrawLine(0.05*BODYSIZE,0);
	DrawLine(0.005*BODYSIZE,0.12*BODYSIZE);
	DrawLine(-0.08*BODYSIZE,0.005*BODYSIZE);
	DrawEllipticalArc(0.14*BODYSIZE,0.15*BODYSIZE,320,60);
	MovePen(initX+0.26*BODYSIZE,initY+0.052*BODYSIZE);
	DrawLine(0,-0.05*BODYSIZE);
	DrawArc(0.047*BODYSIZE,180,200);
	DrawLine(0.005*BODYSIZE,0.13*BODYSIZE);
	DrawLine(-0.09*BODYSIZE,0.01*BODYSIZE);
	
	//draw leg(left)
	MovePen(initX-0.23*BODYSIZE,initY+0.25*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.25*BODYSIZE,140,40);
	DrawLine(0.09*BODYSIZE,-0.05*BODYSIZE);
	DrawLine(0.1*BODYSIZE,0.08*BODYSIZE);
	MovePen(initX-0.32*BODYSIZE,initY+0.08*BODYSIZE);
	DrawArc(0.047*BODYSIZE,30,200);
	DrawLine(0.12*BODYSIZE,-0.06*BODYSIZE);
	DrawLine(0.05*BODYSIZE,0.07*BODYSIZE);

	//draw head(left)
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX-0.3*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.125*BODYSIZE,0);
	MovePen(initX-0.15*BODYSIZE,initY+0.65*BODYSIZE);//mouth
	DrawLine(-0.1*BODYSIZE,0); 
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,10,176);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,10,176);
	MovePen(initX+0.05*BODYSIZE,initY+0.7*BODYSIZE);//ear
	DrawEllipticalArc(0.08*BODYSIZE,0.08*BODYSIZE,240,280);

	
	/*
	MovePen(initX+0.5*BODYSIZE,initY+1.1*BODYSIZE);
	DrawEllipticalArc(0.5*BODYSIZE,0.25*BODYSIZE,30,120);
	//DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,0,360);
	*/
	MovePen(initX,initY);
}

void DrawMan_left3(){
double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;
	//draw body(left)
	MovePen(initX-0.17*BODYSIZE,initY+0.58*BODYSIZE);//pants
	DrawLine(-0.06*BODYSIZE,-0.3*BODYSIZE);
	DrawEllipticalArc(0.23*BODYSIZE,0.05*BODYSIZE,200,170);
	DrawEllipticalArc(0.1*BODYSIZE,0.35*BODYSIZE,0,60);
	tempXleft=CX;
	tempYleft=CY;
	tempXright=CX;
	tempYright=CY;
	//left hand(left)
	MovePen(tempXleft-0.22*BODYSIZE,tempYleft-0.15*BODYSIZE);
	DrawLine(0,-0.25*BODYSIZE);
	DrawLine(0.1*BODYSIZE,0);
	DrawLine(0,0.25*BODYSIZE);
	DrawArc(0.05*BODYSIZE,15,180);
	MovePen(tempXleft-0.22*BODYSIZE,tempYleft-0.4*BODYSIZE);
	DrawArc(0.053*BODYSIZE,180,200);
	//draw leg(left)
	MovePen(initX-0.23*BODYSIZE,initY+0.28*BODYSIZE);
	DrawEllipticalArc(0.26*BODYSIZE,0.3*BODYSIZE,180,70);
	DrawLine(0.13*BODYSIZE,0);
	DrawEllipticalArc(0.22*BODYSIZE,0.3*BODYSIZE,285,70);
	MovePen(initX-0.06*BODYSIZE,initY+0.006*BODYSIZE);
	DrawLine(-0.05*BODYSIZE,0);
	DrawArc(0.047*BODYSIZE,90,200);
	DrawLine(0.17*BODYSIZE,0);
	DrawLine(0,0.09*BODYSIZE);
	//draw head(left)
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX-0.3*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.125*BODYSIZE,0);
	MovePen(initX-0.15*BODYSIZE,initY+0.65*BODYSIZE);//mouth
	DrawLine(-0.1*BODYSIZE,0); 
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,10,176);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,10,176);
	MovePen(initX+0.05*BODYSIZE,initY+0.7*BODYSIZE);//ear
	DrawEllipticalArc(0.08*BODYSIZE,0.08*BODYSIZE,240,280);

	/*
	MovePen(initX+0.5*BODYSIZE,initY+1.1*BODYSIZE);
	DrawEllipticalArc(0.5*BODYSIZE,0.25*BODYSIZE,30,120);
	//DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,0,360);
	*/
	MovePen(initX,initY);

}

void DrawMan_left4(){
double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;

	//draw body(left)
	MovePen(initX-0.17*BODYSIZE,initY+0.58*BODYSIZE);//pants
	DrawLine(-0.06*BODYSIZE,-0.3*BODYSIZE);
	DrawEllipticalArc(0.23*BODYSIZE,0.05*BODYSIZE,200,185);
	DrawEllipticalArc(0.1*BODYSIZE,0.35*BODYSIZE,4,60);
	tempXleft=CX;
	tempYleft=CY;
	tempXright=CX;
	tempYright=CY;
	
	//left hand(left)
	MovePen(tempXleft-0.23*BODYSIZE,tempYleft-0.18*BODYSIZE);
	DrawLine(0.1*BODYSIZE,-0.09*BODYSIZE);
	DrawLine(0.03*BODYSIZE,-0.12*BODYSIZE);
	DrawLine(0.12*BODYSIZE,0.01*BODYSIZE);
	DrawEllipticalArc(0.26*BODYSIZE,0.3*BODYSIZE,0,80);
	DrawArc(0.06*BODYSIZE,50,180);
	MovePen(tempXleft-0.09*BODYSIZE,tempYleft-0.39*BODYSIZE);
	DrawArc(0.055*BODYSIZE,170,200);

	//left hand(right)
	MovePen(tempXleft-0.355*BODYSIZE,tempYleft-0.14*BODYSIZE);
	DrawLine(-0.09*BODYSIZE,-0.05*BODYSIZE);
	DrawLine(0.03*BODYSIZE,-0.09*BODYSIZE);
	DrawLine(0.03*BODYSIZE,0.01*BODYSIZE);
	MovePen(tempXleft-0.44*BODYSIZE,tempYleft-0.19*BODYSIZE);
	DrawArc(0.053*BODYSIZE,90,215);

	//draw leg(left)
	MovePen(initX-0.22*BODYSIZE,initY+0.28*BODYSIZE);
	DrawEllipticalArc(0.23*BODYSIZE,0.26*BODYSIZE,110,55);
	DrawLine(0.13*BODYSIZE,-0.08*BODYSIZE);
	DrawLine(0.1*BODYSIZE,0.05*BODYSIZE);
	DrawEllipticalArc(0.7*BODYSIZE,0.2*BODYSIZE,300,60);
	MovePen(initX-0.37*BODYSIZE,initY+0.1*BODYSIZE);
	DrawArc(0.05*BODYSIZE,50,180);
	DrawLine(0.14*BODYSIZE,-0.08*BODYSIZE);
	DrawLine(0.05*BODYSIZE,0.08*BODYSIZE);

	//draw leg(right)
	MovePen(initX+0.15*BODYSIZE,initY+0.03*BODYSIZE);
	DrawLine(-0.1*BODYSIZE,0.1*BODYSIZE);
	DrawLine(0.14*BODYSIZE,0.13*BODYSIZE);
	DrawLine(0.1*BODYSIZE,-0.13*BODYSIZE);
	DrawLine(-0.15*BODYSIZE,-0.1*BODYSIZE);
	MovePen(initX+0.15*BODYSIZE,initY+0.03*BODYSIZE);
	DrawArc(0.05*BODYSIZE,90,230);
	DrawLine(0.16*BODYSIZE,0.1*BODYSIZE);
	DrawLine(-0.06*BODYSIZE,0.09*BODYSIZE);

	//draw head(left)
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX-0.3*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.125*BODYSIZE,0);
	MovePen(initX-0.15*BODYSIZE,initY+0.65*BODYSIZE);//mouth
	DrawLine(-0.1*BODYSIZE,0); 
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,10,176);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,0,176);
	MovePen(initX+0.05*BODYSIZE,initY+0.7*BODYSIZE);//ear
	DrawEllipticalArc(0.08*BODYSIZE,0.08*BODYSIZE,240,280);

	/*
	MovePen(initX+0.5*BODYSIZE,initY+1.1*BODYSIZE);
	DrawEllipticalArc(0.5*BODYSIZE,0.25*BODYSIZE,30,120);
	//DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,0,360);
	*/
	MovePen(initX,initY);

}

void DrawMan_left5(){
double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;

	//draw body(left)
	MovePen(initX-0.17*BODYSIZE,initY+0.58*BODYSIZE);//pants
	DrawLine(-0.06*BODYSIZE,-0.3*BODYSIZE);
	DrawEllipticalArc(0.23*BODYSIZE,0.05*BODYSIZE,200,185);
	DrawEllipticalArc(0.1*BODYSIZE,0.35*BODYSIZE,4,60);
	tempXleft=CX;
	tempYleft=CY;
	tempXright=CX;
	tempYright=CY;
	
	//left hand(left)
	MovePen(tempXleft-0.2*BODYSIZE,tempYleft-0.18*BODYSIZE);
	DrawLine(0.12*BODYSIZE,-0.07*BODYSIZE);
	DrawLine(-0.01*BODYSIZE,-0.12*BODYSIZE);
	DrawLine(0.1*BODYSIZE,-0.01*BODYSIZE);
	DrawEllipticalArc(0.26*BODYSIZE,0.27*BODYSIZE,350,85);
	DrawArc(0.06*BODYSIZE,60,205);
	MovePen(tempXleft-0.09*BODYSIZE,tempYleft-0.37*BODYSIZE);
	DrawArc(0.055*BODYSIZE,170,200);

	//left hand(right)
	MovePen(tempXleft-0.345*BODYSIZE,tempYleft-0.16*BODYSIZE);
	DrawLine(-0.09*BODYSIZE,-0.07*BODYSIZE);
	DrawLine(0.08*BODYSIZE,-0.08*BODYSIZE);
//	DrawLine(0.03*BODYSIZE,0.01*BODYSIZE);
	MovePen(tempXleft-0.42*BODYSIZE,tempYleft-0.24*BODYSIZE);
	DrawArc(0.053*BODYSIZE,110,250);

	//draw leg(left)
	MovePen(initX-0.22*BODYSIZE,initY+0.28*BODYSIZE);
	DrawEllipticalArc(0.23*BODYSIZE,0.26*BODYSIZE,110,55);
	DrawLine(0.13*BODYSIZE,-0.08*BODYSIZE);
	DrawLine(0.1*BODYSIZE,0.05*BODYSIZE);
	DrawEllipticalArc(0.7*BODYSIZE,0.2*BODYSIZE,300,60);
	MovePen(initX-0.37*BODYSIZE,initY+0.1*BODYSIZE);
	DrawArc(0.05*BODYSIZE,50,180);
	DrawLine(0.14*BODYSIZE,-0.08*BODYSIZE);
	DrawLine(0.05*BODYSIZE,0.08*BODYSIZE);

	//draw leg(right)
	MovePen(initX+0.15*BODYSIZE,initY+0.03*BODYSIZE);
	DrawLine(-0.1*BODYSIZE,0.1*BODYSIZE);
	DrawLine(0.14*BODYSIZE,0.13*BODYSIZE);
	DrawLine(0.1*BODYSIZE,-0.13*BODYSIZE);
	DrawLine(-0.15*BODYSIZE,-0.1*BODYSIZE);
	MovePen(initX+0.15*BODYSIZE,initY+0.03*BODYSIZE);
	DrawArc(0.05*BODYSIZE,90,230);
	DrawLine(0.16*BODYSIZE,0.1*BODYSIZE);
	DrawLine(-0.06*BODYSIZE,0.09*BODYSIZE);

	//draw head(left)
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX-0.3*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.125*BODYSIZE,0);
	MovePen(initX-0.15*BODYSIZE,initY+0.65*BODYSIZE);//mouth
	DrawLine(-0.1*BODYSIZE,0); 
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,10,176);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,0,176);
	MovePen(initX+0.05*BODYSIZE,initY+0.7*BODYSIZE);//ear
	DrawEllipticalArc(0.08*BODYSIZE,0.08*BODYSIZE,240,280);

	/*
	MovePen(initX+0.5*BODYSIZE,initY+1.1*BODYSIZE);
	DrawEllipticalArc(0.5*BODYSIZE,0.25*BODYSIZE,30,120);
	//DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,0,360);
	*/
	MovePen(initX,initY);
}



void DrawMan_right1() 
{
	double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;
	
	
	//draw body(right)(1) 
	MovePen(initX-0.2*BODYSIZE,initY+0.59*BODYSIZE);
	DrawEllipticalArc(0.3*BODYSIZE,0.4*BODYSIZE,120,57);
	MovePen(initX-0.35*BODYSIZE,initY+0.3*BODYSIZE);
	DrawLine(0.1*BODYSIZE,-0.03*BODYSIZE);
	DrawEllipticalArc(0.5*BODYSIZE,0.1*BODYSIZE,180,80);
	tempXleft=CX;
	tempYleft=CY;
	tempXright=CX;
	tempYright=CY;
	MovePen(initX+0.17*BODYSIZE,initY+0.19*BODYSIZE);
	DrawLine(-0.008*BODYSIZE,0.1*BODYSIZE);
	MovePen(initX+0.148*BODYSIZE,initY+0.44*BODYSIZE);
	DrawLine(-0.012*BODYSIZE,0.14*BODYSIZE);
	
	//right hand(right)(1)  
	MovePen(tempXright-0.35*BODYSIZE,tempYright+0.3*BODYSIZE);
	DrawEllipticalArc(0.32*BODYSIZE,0.15*BODYSIZE,160,150);
	MovePen(tempXright+0.15*BODYSIZE,tempYright+0.13*BODYSIZE);
	DrawArc(0.05*BODYSIZE,270,225);
	MovePen(tempXright+0.15*BODYSIZE,tempYright+0.13*BODYSIZE);
	DrawLine(-0.02*BODYSIZE,0.1*BODYSIZE);
	DrawLine(-0.2*BODYSIZE,0.03*BODYSIZE);
	MovePen(tempXright-0.08*BODYSIZE,tempYright+0.27*BODYSIZE);
	DrawEllipticalArc(0.68*BODYSIZE,0.08*BODYSIZE,2,53);
//	DrawLine(-0.008*BODYSIZE,-0.03*BODYSIZE);
	
	//left hand(right)(1) 
	MovePen(tempXleft-0.42*BODYSIZE,tempYleft+0.37*BODYSIZE);
	DrawEllipticalArc(0.37*BODYSIZE,0.3*BODYSIZE,100,50);
	MovePen(tempXleft-0.67*BODYSIZE,tempYleft+0.23*BODYSIZE);
	DrawLine(0.06*BODYSIZE,-0.07*BODYSIZE);
	MovePen(tempXleft-0.67*BODYSIZE,tempYleft+0.23*BODYSIZE);
	DrawArc(0.06*BODYSIZE,90,260);
	MovePen(tempXleft-0.5*BODYSIZE,tempYleft+0.2*BODYSIZE);
	DrawEllipticalArc(0.37*BODYSIZE,0.3*BODYSIZE,100,23);

	//draw leg(right)(1) 
	MovePen(tempXleft-0.52*BODYSIZE,tempYleft+0.08*BODYSIZE);
	DrawEllipticalArc(0.37*BODYSIZE,0.3*BODYSIZE,182,30);
	MovePen(tempXleft-0.48*BODYSIZE,tempYleft-0.07*BODYSIZE);
	DrawLine(-0.16*BODYSIZE,-0.02*BODYSIZE);
	DrawLine(0.001*BODYSIZE,-0.12*BODYSIZE);
	DrawLine(-0.001*BODYSIZE,0.12*BODYSIZE);
	DrawLine(-0.1*BODYSIZE,-0.007*BODYSIZE);
	DrawLine(0.008*BODYSIZE,-0.13*BODYSIZE);
	DrawArc(0.05*BODYSIZE,180,210);
	MovePen(tempXleft-0.64*BODYSIZE,tempYleft-0.21*BODYSIZE);
	DrawLine(0.17*BODYSIZE,0);
	DrawEllipticalArc(0.4*BODYSIZE,0.23*BODYSIZE,250,80);
	DrawLine(0,0.15*BODYSIZE);
	
	//draw leg(left)(1) 
	MovePen(tempXleft-0.13*BODYSIZE,tempYleft-0.15*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.4*BODYSIZE,240,30);
	DrawLine(0.03*BODYSIZE,0.11*BODYSIZE);
	DrawLine(-0.03*BODYSIZE,-0.11*BODYSIZE);
	DrawLine(0.08*BODYSIZE,-0.01*BODYSIZE);
	DrawEllipticalArc(0.055*BODYSIZE,0.11*BODYSIZE,270,265);
	DrawEllipticalArc(0.9*BODYSIZE,0.2*BODYSIZE,0,30); 

	//draw head(right)(1)  
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);	
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX+0.15*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.125*BODYSIZE,0);
	MovePen(initX+0.15*BODYSIZE,initY+0.65*BODYSIZE);//mouth
	DrawLine(-0.1*BODYSIZE,0); 
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,0,180);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,0,180);
	MovePen(initX-0.05*BODYSIZE,initY+0.8*BODYSIZE);//ear
	DrawEllipticalArc(0.08*BODYSIZE,0.08*BODYSIZE,45,270);
	
	MovePen(initX,initY);
	
	
}

void DrawMan_right2() 
{
	double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;
	
	
	//draw body(right)(2) 
	MovePen(initX-0.2*BODYSIZE,initY+0.59*BODYSIZE);
	DrawEllipticalArc(0.2*BODYSIZE,0.4*BODYSIZE,120,70);
	DrawLine(0.5*BODYSIZE,0);
	tempXleft=CX;
	tempYleft=CY;
	tempXright=CX;
	tempYright=CY;
	DrawEllipticalArc(0.2*BODYSIZE,0.43*BODYSIZE,350,70);
	
	//right hand(right)(2) 
	MovePen(tempXright-0.15*BODYSIZE,tempYright+0.25*BODYSIZE);
	DrawArc(0.09*BODYSIZE,0,190);
	MovePen(tempXright-0.33*BODYSIZE,tempYright+0.25*BODYSIZE);
	DrawEllipticalArc(0.2*BODYSIZE,0.35*BODYSIZE,162,72);
	MovePen(tempXright-0.27*BODYSIZE,tempYright-0.13*BODYSIZE);
	DrawLine(0.14*BODYSIZE,0);
	MovePen(tempXright-0.27*BODYSIZE,tempYright-0.13*BODYSIZE);
	DrawArc(0.07*BODYSIZE,173,210);
	MovePen(tempXright-0.13*BODYSIZE,tempYright-0.13*BODYSIZE);
	DrawEllipticalArc(0.1*BODYSIZE,0.55*BODYSIZE,0,48);
	
	//left hand(right)(2) 

	//draw leg(right)(1)
	MovePen(tempXleft-0.5*BODYSIZE,tempYleft);
	DrawEllipticalArc(0.37*BODYSIZE,0.35*BODYSIZE,180,53);
	MovePen(tempXleft-0.37*BODYSIZE,tempYleft-0.27*BODYSIZE);
	DrawLine(0.2*BODYSIZE,0);
	MovePen(tempXleft-0.37*BODYSIZE,tempYleft-0.27*BODYSIZE);
	DrawLine(0,-0.1*BODYSIZE);
	DrawLine(0.2*BODYSIZE,0);
	MovePen(tempXleft-0.2*BODYSIZE,tempYleft-0.37*BODYSIZE);
	DrawArc(0.05*BODYSIZE,273,205);
	MovePen(tempXleft-0.17*BODYSIZE,tempYleft-0.27*BODYSIZE);
	DrawEllipticalArc(0.16*BODYSIZE,0.3*BODYSIZE,265,85);
	
	//draw leg(left)(2) 

	//draw head(right)(2) 
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX+0.15*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.125*BODYSIZE,0);
	MovePen(initX+0.15*BODYSIZE,initY+0.65*BODYSIZE);//mouth
	DrawLine(-0.1*BODYSIZE,0); 
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,0,180);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,0,180);
	MovePen(initX-0.05*BODYSIZE,initY+0.8*BODYSIZE);//ear
	DrawEllipticalArc(0.08*BODYSIZE,0.08*BODYSIZE,45,270);
	
	
	//draw body(right)(3) 
	MovePen(initX-0.2*BODYSIZE,initY+0.59*BODYSIZE);
	DrawEllipticalArc(0.3*BODYSIZE,0.4*BODYSIZE,120,60);
	DrawEllipticalArc(0.6*BODYSIZE,0.1*BODYSIZE,180,85);
	tempXleft=CX;
	tempYleft=CY;
	tempXright=CX;
	tempYright=CY;
	MovePen(initX+0.19*BODYSIZE,initY+0.16*BODYSIZE);
	DrawLine(-0.05*BODYSIZE,0.4*BODYSIZE);
	
	//right hand(right)(3) 
	MovePen(tempXright-0.35*BODYSIZE,tempYright+0.33*BODYSIZE);
	DrawLine(-0.07*BODYSIZE,-0.15*BODYSIZE);
	DrawEllipticalArc(0.3*BODYSIZE,0.25*BODYSIZE,240,50);
	MovePen(tempXright-0.17*BODYSIZE,tempYright+0.17*BODYSIZE);
	DrawArc(0.06*BODYSIZE,270,225);
	DrawLine(0.02*BODYSIZE,-0.1*BODYSIZE);
	DrawLine(-0.02*BODYSIZE,0.1*BODYSIZE);
	DrawLine(-0.1*BODYSIZE,-0.01*BODYSIZE);
	
	MovePen(initX,initY);
	
	
}

void DrawMan_right3() 
{
	double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;
	
	
	///draw body(right)(3) 
	MovePen(initX-0.2*BODYSIZE,initY+0.59*BODYSIZE);
	DrawEllipticalArc(0.3*BODYSIZE,0.4*BODYSIZE,120,60);
	DrawEllipticalArc(0.6*BODYSIZE,0.1*BODYSIZE,180,85);
	tempXleft=CX;
	tempYleft=CY;
	tempXright=CX;
	tempYright=CY;
	MovePen(initX+0.19*BODYSIZE,initY+0.16*BODYSIZE);
	DrawLine(-0.05*BODYSIZE,0.4*BODYSIZE);
	
	//right hand(right)(3) 
	MovePen(tempXright-0.35*BODYSIZE,tempYright+0.33*BODYSIZE);
	DrawLine(-0.07*BODYSIZE,-0.15*BODYSIZE);
	DrawEllipticalArc(0.3*BODYSIZE,0.25*BODYSIZE,240,50);
	MovePen(tempXright-0.17*BODYSIZE,tempYright+0.17*BODYSIZE);
	DrawArc(0.06*BODYSIZE,270,225);
	DrawLine(0.02*BODYSIZE,-0.1*BODYSIZE);
	DrawLine(-0.02*BODYSIZE,0.1*BODYSIZE);
	DrawLine(-0.1*BODYSIZE,-0.01*BODYSIZE);
	
	//left hand(right)(3) 
	MovePen(tempXleft-0.038*BODYSIZE,tempYleft+0.3*BODYSIZE);
	DrawLine(0.06*BODYSIZE,0.02*BODYSIZE);
	DrawLine(0.02*BODYSIZE,-0.09*BODYSIZE);
	DrawArc(0.05*BODYSIZE,270,210);
	DrawLine(0.02*BODYSIZE,-0.09*BODYSIZE);
	DrawLine(-0.06*BODYSIZE,-0.02*BODYSIZE);

	//draw leg(right)(3) 
	MovePen(tempXleft-0.52*BODYSIZE,tempYleft+0.08*BODYSIZE);
	DrawEllipticalArc(0.37*BODYSIZE,0.25*BODYSIZE,180,60);
	MovePen(tempXleft-0.33*BODYSIZE,tempYleft-0.13*BODYSIZE);
	DrawLine(0.13*BODYSIZE,-0.03*BODYSIZE);
	DrawLine(0.06*BODYSIZE,-0.03*BODYSIZE);
	DrawLine(0.14*BODYSIZE,0.03*BODYSIZE);
	DrawLine(-0.14*BODYSIZE,-0.03*BODYSIZE);
	DrawLine(0.01*BODYSIZE,-0.08*BODYSIZE);
	DrawLine(0.15*BODYSIZE,0.03*BODYSIZE);
	DrawArc(0.04*BODYSIZE,270,210);
	MovePen(tempXleft+0.02*BODYSIZE,tempYleft-0.16*BODYSIZE);
	DrawEllipticalArc(0.1*BODYSIZE,0.28*BODYSIZE,1,50); 
	
	//draw leg(left)(3) 
	MovePen(tempXleft-0.5*BODYSIZE,tempYleft-0.02*BODYSIZE);
	DrawLine(-0.08*BODYSIZE,-0.02*BODYSIZE);
	DrawLine(0.03*BODYSIZE,-0.13*BODYSIZE);
	DrawLine(-0.03*BODYSIZE,0.13*BODYSIZE);
	DrawLine(-0.08*BODYSIZE,-0.02*BODYSIZE);
	DrawLine(0.03*BODYSIZE,-0.13*BODYSIZE);
	DrawArc(0.045*BODYSIZE,180,210);
	MovePen(tempXleft-0.55*BODYSIZE,tempYleft-0.16*BODYSIZE);
	DrawLine(0.19*BODYSIZE,0.03*BODYSIZE);
	
	//draw head(right)(3)  
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX+0.15*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.125*BODYSIZE,0);
	MovePen(initX+0.15*BODYSIZE,initY+0.65*BODYSIZE);//mouth
	DrawLine(-0.1*BODYSIZE,0); 
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,0,180);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,0,180);
	MovePen(initX-0.05*BODYSIZE,initY+0.8*BODYSIZE);//ear
	DrawEllipticalArc(0.08*BODYSIZE,0.08*BODYSIZE,45,270);
	
	MovePen(initX,initY);
	
	
}

void DrawMan_right4() 
{
	double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;
	
	//draw body(right)
	MovePen(initX-0.2*BODYSIZE,initY+0.59*BODYSIZE);
	DrawEllipticalArc(0.3*BODYSIZE,0.4*BODYSIZE,120,60);
	DrawEllipticalArc(0.55*BODYSIZE,0.1*BODYSIZE,180,80);
	tempXleft=CX;
	tempYleft=CY;
	tempXright=CX;
	tempYright=CY;
	MovePen(initX+0.1*BODYSIZE,initY+0.15*BODYSIZE);
	DrawLine(-0.01*BODYSIZE,0.09*BODYSIZE);
	MovePen(initX+0.08*BODYSIZE,initY+0.41*BODYSIZE);
	DrawLine(-0.01*BODYSIZE,0.15*BODYSIZE);
	
	//right hand(right)
	MovePen(tempXright-0.25*BODYSIZE,tempYright+0.35*BODYSIZE);//arm
	DrawEllipticalArc(0.45*BODYSIZE,0.25*BODYSIZE,170,90);
	DrawLine(0.03*BODYSIZE,0.09*BODYSIZE);
	DrawLine(-0.15*BODYSIZE,0.09*BODYSIZE);
	DrawEllipticalArc(0.43*BODYSIZE,0.17*BODYSIZE,20,50);
	MovePen(tempXright+0.146*BODYSIZE,tempYright+0.15*BODYSIZE);//hand
	DrawLine(-0.03*BODYSIZE,-0.09*BODYSIZE);
	DrawArc(0.055*BODYSIZE,210,255);

	
	//left hand(right)
	MovePen(tempXleft-0.4*BODYSIZE,tempYleft+0.34*BODYSIZE);
	DrawEllipticalArc(0.35*BODYSIZE,0.3*BODYSIZE,110,50);
	DrawLine(0.07*BODYSIZE,-0.05*BODYSIZE);
	DrawLine(-0.07*BODYSIZE,0.05*BODYSIZE);
	DrawArc(0.06*BODYSIZE,100,260);
	DrawLine(0.1*BODYSIZE,0.09*BODYSIZE);

	//draw leg(right)
	MovePen(tempXleft-0.45*BODYSIZE,tempYleft+0.08*BODYSIZE);
	DrawEllipticalArc(0.37*BODYSIZE,0.3*BODYSIZE,182,30);
	MovePen(tempXleft-0.4*BODYSIZE,tempYleft-0.07*BODYSIZE);
	DrawLine(-0.16*BODYSIZE,-0.02*BODYSIZE);
	DrawLine(0.001*BODYSIZE,-0.12*BODYSIZE);
	DrawLine(-0.001*BODYSIZE,0.12*BODYSIZE);
	DrawLine(-0.1*BODYSIZE,-0.007*BODYSIZE);
	DrawLine(0.008*BODYSIZE,-0.13*BODYSIZE);
	DrawArc(0.05*BODYSIZE,180,210);
	MovePen(tempXleft-0.55*BODYSIZE,tempYleft-0.21*BODYSIZE);
	DrawLine(0.05*BODYSIZE,0);
	DrawEllipticalArc(0.4*BODYSIZE,0.23*BODYSIZE,250,80);
	DrawLine(0.02,0.15*BODYSIZE);
	
	//draw leg(left)
	MovePen(tempXleft-0.13
	*BODYSIZE,tempYleft-0.15*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.4*BODYSIZE,240,30);
	DrawLine(0.03*BODYSIZE,0.11*BODYSIZE);
	DrawLine(-0.03*BODYSIZE,-0.11*BODYSIZE);
	DrawLine(0.08*BODYSIZE,-0.01*BODYSIZE);
	DrawEllipticalArc(0.055*BODYSIZE,0.11*BODYSIZE,270,265);
	DrawEllipticalArc(0.9*BODYSIZE,0.2*BODYSIZE,0,30); 

	//draw head(right)
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);	
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX+0.15*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.125*BODYSIZE,0);
	MovePen(initX+0.15*BODYSIZE,initY+0.65*BODYSIZE);//mouth
	DrawLine(-0.1*BODYSIZE,0); 
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,0,180);
	MovePen(initX+0.44*BODYSIZE,initY+0.84*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,0,180);
	MovePen(initX-0.05*BODYSIZE,initY+0.8*BODYSIZE);//ear
	DrawEllipticalArc(0.08*BODYSIZE,0.08*BODYSIZE,45,270);
	
	/*
	MovePen(initX+0.5*BODYSIZE,initY+1.1*BODYSIZE);
	DrawEllipticalArc(0.5*BODYSIZE,0.25*BODYSIZE,30,120);
	//DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,0,360);
	*/
	MovePen(initX,initY);
	
	
}

void DrawMan_right5() 
{
	double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;
	
	//draw body(right)(3) 
	MovePen(initX-0.2*BODYSIZE,initY+0.59*BODYSIZE);
	DrawEllipticalArc(0.3*BODYSIZE,0.4*BODYSIZE,120,60);
	DrawEllipticalArc(0.6*BODYSIZE,0.1*BODYSIZE,180,85);
	tempXleft=CX;
	tempYleft=CY;
	tempXright=CX;
	tempYright=CY;
	DrawLine(-0.05*BODYSIZE,0.43*BODYSIZE);
	
	//right hand(right)(3) 
	MovePen(tempXright-0.35*BODYSIZE,tempYright+0.33*BODYSIZE);
	DrawEllipticalArc(0.3*BODYSIZE,0.25*BODYSIZE,120,50);
	DrawEllipticalArc(0.25*BODYSIZE,0.25*BODYSIZE,200,50);
	DrawLine(0.07*BODYSIZE,0.07*BODYSIZE);
	DrawLine(-0.1*BODYSIZE,0.1*BODYSIZE);
	DrawLine(0.1*BODYSIZE,0.1*BODYSIZE);
	DrawArc(0.06*BODYSIZE,15,95);
	MovePen(tempXright-0.35*BODYSIZE,tempYright+0.008*BODYSIZE);
	DrawArc(0.055*BODYSIZE,200,225);
	DrawLine(-0.07*BODYSIZE,-0.07*BODYSIZE);
	
	//left hand(right)(3) 
	MovePen(tempXleft-0.02*BODYSIZE,tempYleft+0.23*BODYSIZE);
	DrawLine(0.06*BODYSIZE,-0.015*BODYSIZE);	
	DrawLine(-0.025*BODYSIZE,-0.09*BODYSIZE);
	DrawLine(-0.025*BODYSIZE,0.005*BODYSIZE);
	MovePen(tempXleft+0.01*BODYSIZE,tempYleft+0.12*BODYSIZE);
	DrawArc(0.05*BODYSIZE,240,240);

	//draw leg(right)(3) 
	MovePen(tempXleft-0.52*BODYSIZE,tempYleft+0.08*BODYSIZE);
	DrawEllipticalArc(0.37*BODYSIZE,0.25*BODYSIZE,180,62);
	MovePen(tempXleft-0.33*BODYSIZE,tempYleft-0.13*BODYSIZE);
	DrawLine(0.13*BODYSIZE,-0.03*BODYSIZE);
	DrawLine(0.06*BODYSIZE,-0.03*BODYSIZE);
	DrawLine(0.14*BODYSIZE,0.03*BODYSIZE);
	DrawLine(-0.14*BODYSIZE,-0.03*BODYSIZE);
	DrawLine(0.01*BODYSIZE,-0.08*BODYSIZE);
	DrawLine(0.15*BODYSIZE,0.03*BODYSIZE);
	DrawArc(0.04*BODYSIZE,300,210);
	MovePen(tempXleft+0.02*BODYSIZE,tempYleft-0.16*BODYSIZE);
	DrawEllipticalArc(0.12*BODYSIZE,0.28*BODYSIZE,10,50); 
	
	//draw leg(left)(3) 
	MovePen(tempXleft-0.5*BODYSIZE,tempYleft-0.02*BODYSIZE);
	DrawLine(-0.08*BODYSIZE,-0.02*BODYSIZE);
	DrawLine(0.03*BODYSIZE,-0.13*BODYSIZE);
	DrawLine(-0.03*BODYSIZE,0.13*BODYSIZE);
	DrawLine(-0.08*BODYSIZE,-0.02*BODYSIZE);
	DrawLine(0.03*BODYSIZE,-0.13*BODYSIZE);
	DrawArc(0.045*BODYSIZE,180,210);
	MovePen(tempXleft-0.55*BODYSIZE,tempYleft-0.16*BODYSIZE);
	DrawLine(0.19*BODYSIZE,0.03*BODYSIZE);
	
	//draw head(right)(3)  
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX+0.15*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.125*BODYSIZE,0);
	MovePen(initX+0.15*BODYSIZE,initY+0.65*BODYSIZE);//mouth
	DrawLine(-0.1*BODYSIZE,0); 
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,0,180);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,0,180);
	MovePen(initX-0.05*BODYSIZE,initY+0.8*BODYSIZE);//ear
	DrawEllipticalArc(0.08*BODYSIZE,0.08*BODYSIZE,45,270);

	
	/*
	MovePen(initX+0.5*BODYSIZE,initY+1.1*BODYSIZE);
	DrawEllipticalArc(0.5*BODYSIZE,0.25*BODYSIZE,30,120);
	//DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,0,360);
	*/
	MovePen(initX,initY);
	
	
}

void DrawMan_falling1(){
double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;
	//draw leg(up)
	MovePen(initX-0.3*BODYSIZE,initY);
	DrawLine(0.2*BODYSIZE,0);
	DrawEllipticalArc(0.1*BODYSIZE,0.05*BODYSIZE,0,180);
	MovePen(initX-0.2*BODYSIZE,initY+0.05*BODYSIZE);
	MovePen(initX+0.1*BODYSIZE,initY);
	DrawLine(0.2*BODYSIZE,0);
	DrawEllipticalArc(0.1*BODYSIZE,0.05*BODYSIZE,0,180);
	
	//draw body(up)
	MovePen(initX-0.1*BODYSIZE,initY);//pants
	DrawLine(0.05*BODYSIZE,0.15*BODYSIZE);
	DrawLine(0.1*BODYSIZE,0);
	DrawLine(0.05*BODYSIZE,-0.15*BODYSIZE);
	MovePen(initX-0.3*BODYSIZE,initY);
	DrawLine(0.15*BODYSIZE,0.25*BODYSIZE);
	tempXleft=CX;
	tempYleft=CY;
	DrawLine(0.3*BODYSIZE,0);
	tempXright=CX;
	tempYright=CY;
	DrawLine(0.15*BODYSIZE,-0.25*BODYSIZE);

	MovePen(tempXleft,tempYleft);//left hand(up)
	DrawLine(0,0.3*BODYSIZE);
	DrawLine(-0.2*BODYSIZE,0.1*BODYSIZE);
	tempXleft=CX;
	tempYleft=CY;
	DrawArc(0.05*BODYSIZE,90,180);
	DrawLine(0.05*BODYSIZE,0.08*BODYSIZE);
	DrawLine(-0.05*BODYSIZE,-0.08*BODYSIZE);
	DrawLine(0.2*BODYSIZE,-0.1*BODYSIZE);

	MovePen(tempXright,tempYright);//right hand(up)
	DrawLine(0,0.3*BODYSIZE);
	DrawLine(0.2*BODYSIZE,0.1*BODYSIZE);
	tempXright=CX;
	tempYright=CY;
	DrawLine(0.04*BODYSIZE,-0.08*BODYSIZE);
	DrawArc(0.05*BODYSIZE,270,230);
	DrawLine(0.04*BODYSIZE,-0.08*BODYSIZE);
	DrawLine(-0.25*BODYSIZE,-0.12*BODYSIZE);

	//draw head(up)
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX-0.3*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.1*BODYSIZE,0);
	MovePen(initX+0.3*BODYSIZE,initY+0.8*BODYSIZE);
	DrawLine(-0.1*BODYSIZE,0);
	MovePen(initX-0.1*BODYSIZE,initY+0.7*BODYSIZE);//mouth
	DrawLine(0.2*BODYSIZE,0);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,0,180);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,0,180);
	
	MovePen(initX,initY);
	
	
}

void DrawMan_falling2(){
	double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;
	
	//draw leg(up)
	MovePen(initX-0.3*BODYSIZE,initY);
	DrawLine(0.2*BODYSIZE,0);
	DrawEllipticalArc(0.1*BODYSIZE,0.05*BODYSIZE,0,180);
	MovePen(initX-0.2*BODYSIZE,initY+0.05*BODYSIZE);
	MovePen(initX+0.1*BODYSIZE,initY);
	DrawLine(0.2*BODYSIZE,0);
	DrawEllipticalArc(0.1*BODYSIZE,0.05*BODYSIZE,0,180);
	
	//draw body(up)
	MovePen(initX-0.1*BODYSIZE,initY);//pants
	DrawLine(0.05*BODYSIZE,0.15*BODYSIZE);
	DrawLine(0.1*BODYSIZE,0);
	DrawLine(0.05*BODYSIZE,-0.15*BODYSIZE);
	MovePen(initX-0.3*BODYSIZE,initY);
	DrawLine(0.15*BODYSIZE,0.25*BODYSIZE);
	tempXleft=CX;
	tempYleft=CY;
	DrawLine(0.3*BODYSIZE,0);
	tempXright=CX;
	tempYright=CY;
	DrawLine(0.15*BODYSIZE,-0.25*BODYSIZE);
	
	
	MovePen(tempXleft,tempYleft);//left hand(up)(1)
	DrawLine(0,0.3*BODYSIZE);
	DrawLine(-0.2*BODYSIZE,0.1*BODYSIZE);
	tempXleft=CX;
	tempYleft=CY;
	DrawArc(0.05*BODYSIZE,90,180);
	DrawLine(0.05*BODYSIZE,0.08*BODYSIZE);
	DrawLine(-0.05*BODYSIZE,-0.08*BODYSIZE);
	DrawLine(0.2*BODYSIZE,-0.1*BODYSIZE);
		
	MovePen(tempXright,tempYright);//right hand(up)(1)
	DrawLine(0,0.3*BODYSIZE);
	DrawLine(0.2*BODYSIZE,0.1*BODYSIZE);
	tempXright=CX;
	tempYright=CY;
	DrawLine(0.04*BODYSIZE,-0.08*BODYSIZE);
	DrawArc(0.05*BODYSIZE,270,230);
	DrawLine(0.04*BODYSIZE,-0.08*BODYSIZE);
	DrawLine(-0.25*BODYSIZE,-0.12*BODYSIZE);

	//draw head(up)
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX-0.3*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.1*BODYSIZE,0);
	MovePen(initX+0.3*BODYSIZE,initY+0.8*BODYSIZE);
	DrawLine(-0.1*BODYSIZE,0);
	MovePen(initX-0.1*BODYSIZE,initY+0.7*BODYSIZE);//mouth
	DrawLine(0.2*BODYSIZE,0);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,0,180);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,0,180);

	MovePen(initX,initY);
	
	
}

void DrawMan_falling3(){
		double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;
	
	//draw leg(up)
	MovePen(initX-0.3*BODYSIZE,initY);
	DrawLine(0.2*BODYSIZE,0);
	DrawEllipticalArc(0.1*BODYSIZE,0.05*BODYSIZE,0,180);
	MovePen(initX-0.2*BODYSIZE,initY+0.05*BODYSIZE);
	MovePen(initX+0.1*BODYSIZE,initY);
	DrawLine(0.2*BODYSIZE,0);
	DrawEllipticalArc(0.1*BODYSIZE,0.05*BODYSIZE,0,180);
	
	//draw body(up)
	MovePen(initX-0.1*BODYSIZE,initY);//pants
	DrawLine(0.05*BODYSIZE,0.15*BODYSIZE);
	DrawLine(0.1*BODYSIZE,0);
	DrawLine(0.05*BODYSIZE,-0.15*BODYSIZE);
	MovePen(initX-0.3*BODYSIZE,initY);
	DrawLine(0.15*BODYSIZE,0.25*BODYSIZE);
	tempXleft=CX;
	tempYleft=CY;
	DrawLine(0.3*BODYSIZE,0);
	tempXright=CX;
	tempYright=CY;
	DrawLine(0.15*BODYSIZE,-0.25*BODYSIZE);
	
	

	
	MovePen(tempXleft,tempYleft);//left hand(up)(2)
	DrawLine(0,0.3*BODYSIZE);
	DrawLine(-0.27*BODYSIZE,0.05*BODYSIZE);
	tempXleft=CX;
	tempYleft=CY;
	DrawArc(0.05*BODYSIZE,90,180);
	DrawLine(0.05*BODYSIZE,0.08*BODYSIZE);
	DrawLine(-0.05*BODYSIZE,-0.08*BODYSIZE);
	DrawLine(0.25*BODYSIZE,-0.05*BODYSIZE);



	MovePen(tempXright,tempYright);//right hand(up)(2)
	DrawLine(0,0.3*BODYSIZE);
	DrawLine(0.27*BODYSIZE,0.05*BODYSIZE);
	tempXright=CX;
	tempYright=CY;
	DrawLine(0.03*BODYSIZE,-0.08*BODYSIZE);
	DrawArc(0.05*BODYSIZE,270,230);
	DrawLine(0.03*BODYSIZE,-0.08*BODYSIZE);
	DrawLine(-0.3*BODYSIZE,-0.08*BODYSIZE);
	
	//draw head(up)
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX-0.3*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.1*BODYSIZE,0);
	MovePen(initX+0.3*BODYSIZE,initY+0.8*BODYSIZE);
	DrawLine(-0.1*BODYSIZE,0);
	MovePen(initX-0.1*BODYSIZE,initY+0.7*BODYSIZE);//mouth
	DrawLine(0.2*BODYSIZE,0);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,0,180);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,0,180);

	MovePen(initX,initY);
}

void DrawMan_falling4(){
		double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;
	
	//draw leg(up)
	MovePen(initX-0.3*BODYSIZE,initY);
	DrawLine(0.2*BODYSIZE,0);
	DrawEllipticalArc(0.1*BODYSIZE,0.05*BODYSIZE,0,180);
	MovePen(initX-0.2*BODYSIZE,initY+0.05*BODYSIZE);
	MovePen(initX+0.1*BODYSIZE,initY);
	DrawLine(0.2*BODYSIZE,0);
	DrawEllipticalArc(0.1*BODYSIZE,0.05*BODYSIZE,0,180);
	
	//draw body(up)
	MovePen(initX-0.1*BODYSIZE,initY);//pants
	DrawLine(0.05*BODYSIZE,0.15*BODYSIZE);
	DrawLine(0.1*BODYSIZE,0);
	DrawLine(0.05*BODYSIZE,-0.15*BODYSIZE);
	MovePen(initX-0.3*BODYSIZE,initY);
	DrawLine(0.15*BODYSIZE,0.25*BODYSIZE);
	tempXleft=CX;
	tempYleft=CY;
	DrawLine(0.3*BODYSIZE,0);
	tempXright=CX;
	tempYright=CY;
	DrawLine(0.15*BODYSIZE,-0.25*BODYSIZE);
	
	MovePen(tempXleft,tempYleft);//left hand(up)(3)
	DrawLine(0,0.3*BODYSIZE);
	DrawLine(-0.27*BODYSIZE,0.01*BODYSIZE);
	tempXleft=CX;
	tempYleft=CY;
	DrawArc(0.05*BODYSIZE,90,190);
	DrawLine(0,0.08*BODYSIZE);
	DrawLine(0,-0.08*BODYSIZE);
	DrawLine(0.27*BODYSIZE,-0.01*BODYSIZE);
	
	MovePen(tempXright,tempYright);//right hand(up)(3)
	DrawLine(0,0.3*BODYSIZE);
	DrawLine(0.25*BODYSIZE,-0.03*BODYSIZE);
	tempXright=CX;
	tempYright=CY;
	DrawLine(0.01*BODYSIZE,-0.09*BODYSIZE);
	DrawArc(0.05*BODYSIZE,240,255);
	DrawLine(0.02*BODYSIZE,-0.075*BODYSIZE);
	DrawLine(-0.27*BODYSIZE,0.01*BODYSIZE);
	
	//draw head(up)
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX-0.3*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.1*BODYSIZE,0);
	MovePen(initX+0.3*BODYSIZE,initY+0.8*BODYSIZE);
	DrawLine(-0.1*BODYSIZE,0);
	MovePen(initX-0.1*BODYSIZE,initY+0.7*BODYSIZE);//mouth
	DrawLine(0.2*BODYSIZE,0);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,0,180);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,0,180);
	
	MovePen(initX,initY);
}

void DrawMan_falling5(){
	double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;
	
	//draw leg(up)
	MovePen(initX-0.3*BODYSIZE,initY);
	DrawLine(0.2*BODYSIZE,0);
	DrawEllipticalArc(0.1*BODYSIZE,0.05*BODYSIZE,0,180);
	MovePen(initX-0.2*BODYSIZE,initY+0.05*BODYSIZE);
	MovePen(initX+0.1*BODYSIZE,initY);
	DrawLine(0.2*BODYSIZE,0);
	DrawEllipticalArc(0.1*BODYSIZE,0.05*BODYSIZE,0,180);
	
	//draw body(up)
	MovePen(initX-0.1*BODYSIZE,initY);//pants
	DrawLine(0.05*BODYSIZE,0.15*BODYSIZE);
	DrawLine(0.1*BODYSIZE,0);
	DrawLine(0.05*BODYSIZE,-0.15*BODYSIZE);
	MovePen(initX-0.3*BODYSIZE,initY);
	DrawLine(0.15*BODYSIZE,0.25*BODYSIZE);
	tempXleft=CX;
	tempYleft=CY;
	DrawLine(0.3*BODYSIZE,0);
	tempXright=CX;
	tempYright=CY;
	DrawLine(0.15*BODYSIZE,-0.25*BODYSIZE);
	
	MovePen(tempXleft,tempYleft);//left hand(up)(4)
	DrawLine(0,0.3*BODYSIZE);
	DrawLine(-0.25*BODYSIZE,-0.07*BODYSIZE);
	tempXleft=CX;
	tempYleft=CY;
	DrawArc(0.05*BODYSIZE,90,190);
	DrawLine(0,0.08*BODYSIZE);
	DrawLine(0,-0.08*BODYSIZE);
	DrawLine(0.25*BODYSIZE,0.06*BODYSIZE);

	MovePen(tempXright,tempYright);//right hand(up)(4)
	DrawLine(0,0.3*BODYSIZE);
	DrawLine(0.25*BODYSIZE,-0.07*BODYSIZE);
	tempXright=CX;
	tempYright=CY;
	DrawLine(-0.01*BODYSIZE,-0.09*BODYSIZE);
	DrawArc(0.05*BODYSIZE,260,189);
	DrawLine(-0.01*BODYSIZE,-0.09*BODYSIZE);
	DrawLine(-0.25*BODYSIZE,0.06*BODYSIZE);
	
	//draw head(up)
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX-0.3*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.1*BODYSIZE,0);
	MovePen(initX+0.3*BODYSIZE,initY+0.8*BODYSIZE);
	DrawLine(-0.1*BODYSIZE,0);
	MovePen(initX-0.1*BODYSIZE,initY+0.7*BODYSIZE);//mouth
	DrawLine(0.2*BODYSIZE,0);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,0,180);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,0,180);

	MovePen(initX,initY);
}

void DrawMan_falling6(){
	double initX=CX,initY=CY,tempXleft,tempYleft,tempXright,tempYright;
	
	//draw leg(up)
	MovePen(initX-0.3*BODYSIZE,initY);
	DrawLine(0.2*BODYSIZE,0);
	DrawEllipticalArc(0.1*BODYSIZE,0.05*BODYSIZE,0,180);
	MovePen(initX-0.2*BODYSIZE,initY+0.05*BODYSIZE);
	MovePen(initX+0.1*BODYSIZE,initY);
	DrawLine(0.2*BODYSIZE,0);
	DrawEllipticalArc(0.1*BODYSIZE,0.05*BODYSIZE,0,180);
	
	//draw body(up)
	MovePen(initX-0.1*BODYSIZE,initY);//pants
	DrawLine(0.05*BODYSIZE,0.15*BODYSIZE);
	DrawLine(0.1*BODYSIZE,0);
	DrawLine(0.05*BODYSIZE,-0.15*BODYSIZE);
	MovePen(initX-0.3*BODYSIZE,initY);
	DrawLine(0.15*BODYSIZE,0.25*BODYSIZE);
	tempXleft=CX;
	tempYleft=CY;
	DrawLine(0.3*BODYSIZE,0);
	tempXright=CX;
	tempYright=CY;
	DrawLine(0.15*BODYSIZE,-0.25*BODYSIZE);
	
	MovePen(tempXleft,tempYleft);//left hand(up)(5)
	DrawLine(0,0.3*BODYSIZE);
	DrawLine(-0.23*BODYSIZE,-0.15*BODYSIZE);
	tempXleft=CX;
	tempYleft=CY;
	DrawArc(0.05*BODYSIZE,90,220);
	DrawLine(-0.03*BODYSIZE,0.1*BODYSIZE);
	DrawLine(0.03*BODYSIZE,-0.1*BODYSIZE);
	DrawLine(0.2*BODYSIZE,0.15*BODYSIZE);
	
	MovePen(tempXright,tempYright);//right hand(up)(5)
	DrawLine(0,0.3*BODYSIZE);
	DrawLine(0.23*BODYSIZE,-0.15*BODYSIZE);
	tempXright=CX;
	tempYright=CY;
	DrawLine(-0.04,-0.09*BODYSIZE);
	DrawArc(0.06*BODYSIZE,230,215);
	DrawLine(-0.035,-0.09*BODYSIZE);
	DrawLine(-0.2*BODYSIZE,0.12*BODYSIZE);
	
	//draw head(up)
	MovePen(initX-0.4*BODYSIZE,initY+0.9*BODYSIZE);
	DrawEllipticalArc(0.4*BODYSIZE,0.3*BODYSIZE,170,200);//face
	MovePen(initX-0.3*BODYSIZE,initY+0.8*BODYSIZE);//eye
	DrawLine(0.1*BODYSIZE,0);
	MovePen(initX+0.3*BODYSIZE,initY+0.8*BODYSIZE);
	DrawLine(-0.1*BODYSIZE,0);
	MovePen(initX-0.1*BODYSIZE,initY+0.7*BODYSIZE);//mouth
	DrawLine(0.2*BODYSIZE,0);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);//hair
	DrawEllipticalArc(0.45*BODYSIZE,0.3*BODYSIZE,0,180);
	MovePen(initX+0.45*BODYSIZE,initY+0.85*BODYSIZE);
	DrawEllipticalArc(0.45*BODYSIZE,0.1*BODYSIZE,0,180);

	MovePen(initX,initY);
}

void DrawBlock_Sting(double x,double y,double BlockSize,string Color)
{
	SetPenColor("White");
	DrawLine(BlockSize,0);
	DrawLine(0,-BLOCKHEIGHT);
	DrawLine(-BlockSize,0);
	DrawLine(0,BLOCKHEIGHT);
	SetPenColor(Color);
	StartFilledRegion(1);
	MovePen(x,y);
	DrawLine(BlockSize,0);
	DrawLine(0,-BLOCKHEIGHT);
	DrawLine(-BlockSize,0);
	DrawLine(0,BLOCKHEIGHT);
	EndFilledRegion();
	int i;
	
	
	StartFilledRegion(1);
	
	for(i=0;i<10;i++)
	{
		DrawLine(0.05*BlockSize,0.1*BlockSize);
		DrawLine(0.05*BlockSize,-0.1*BlockSize);
	}
	
	EndFilledRegion();
	MovePen(x,y);
	SetPenColor("Black");
	/*
	if(strcmp(Color,"White")!=0)
	{
		SetPenColor("Black");
		DrawLine(BlockSize,0);
		DrawLine(0,-0.05);
		DrawLine(-BlockSize,0);
		DrawLine(0,0.05);
		
		for(i=0;i<10;i++)
		{
			DrawLine(0.05*BlockSize,0.1*BlockSize);
			DrawLine(0.05*BlockSize,-0.1*BlockSize);
		}
		
	}
	*/
}

void DrawBlock_default(double x,double y,double BlockSize,string Color)
{
	
	MovePen(x,y);
	SetPenColor("White");
	DrawLine(BlockSize,0);
	DrawLine(0,-BLOCKHEIGHT);
	DrawLine(-BlockSize,0);
	DrawLine(0,BLOCKHEIGHT);
	if(strcmp("White",Color)==0)
	{
		SetPenColor("White");
		StartFilledRegion(1);
		DrawLine(BlockSize,0);
		DrawLine(0,-BLOCKHEIGHT);
		DrawLine(-BlockSize,0);
		DrawLine(0,BLOCKHEIGHT);
		EndFilledRegion();
	}
	else
	{
		if(quality==high)
		{	
			int i,j,width=21,height=3,count=0;
			for(i=0;i<height;i++)
			{
				for(j=0;j<width;j++)
				{
					if(count>=7)
						count=count-7;
					SetPenColor(defaultBlockColor[count]);
					MovePen(x+j*1.0/width*BlockSize,y-i*1.0/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/height*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/height*BLOCKHEIGHT);
					EndFilledRegion();
					count++;
				}
				count++;
			}
		
		}
		else if(quality==low)
		{
			SetPenColor("Blue");
			StartFilledRegion(1);
			DrawLine(BlockSize,0);
			DrawLine(0,-BLOCKHEIGHT);
			DrawLine(-BlockSize,0);
			DrawLine(0,BLOCKHEIGHT);
			EndFilledRegion();
		}
		
		 
	}
	MovePen(x,y);
	SetPenColor("Black");
}

void DrawBlock_bounce(double x,double y,double BlockSize,string Color){
	MovePen(x,y);
	SetPenColor("White");
	DrawLine(BlockSize,0);
	DrawLine(0,-BLOCKHEIGHT);
	DrawLine(-BlockSize,0);
	DrawLine(0,BLOCKHEIGHT);
	if(strcmp("White",Color)==0)
	{
		SetPenColor("White");
		StartFilledRegion(1);
		DrawLine(BlockSize,0);
		DrawLine(0,-BLOCKHEIGHT);
		DrawLine(-BlockSize,0);
		DrawLine(0,BLOCKHEIGHT);
		EndFilledRegion();
	}
	else
	{
		if(quality==high)
		{
			int i,j,width=16,height=6,count=0;
			SetPenColor("Green");
			StartFilledRegion(1);
			DrawLine(1.0*BlockSize,0);
			DrawLine(0,-1.0/height*BLOCKHEIGHT);
			DrawLine(-1.0*BlockSize,0);
			DrawLine(0,1.0/height*BLOCKHEIGHT);
			EndFilledRegion();
			for(i=1;i<height-1;i++)
			{
				for(j=0;j<width;j++)
				{
					if(j%3==0)
						SetPenColor("Black");
					else
					{
						if(count%2==0)
							SetPenColor("Black");	
						else 
							SetPenColor("White");	
					}
					MovePen(x+j*1.0/width*BlockSize,y-i*1.0/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/height*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/height*BLOCKHEIGHT);
					EndFilledRegion();
				}
				count++;
			}
			MovePen(x,y-i*1.0/height*BLOCKHEIGHT);
			SetPenColor("Green");
			StartFilledRegion(1);
			DrawLine(1.0*BlockSize,0);
			DrawLine(0,-1.0/height*BLOCKHEIGHT);
			DrawLine(-1.0*BlockSize,0);
			DrawLine(0,1.0/height*BLOCKHEIGHT);
			EndFilledRegion();
		}
		else if(quality==low)
		{
			MovePen(x,y);
			SetPenColor("Green");
			StartFilledRegion(1);
			DrawLine(BlockSize,0);
			DrawLine(0,-1.0/3*BLOCKHEIGHT);
			DrawLine(-BlockSize,0);
			DrawLine(0,1.0/3*BLOCKHEIGHT);
			EndFilledRegion();
			SetPenColor("Black");
			MovePen(x,y-1.0/3*BLOCKHEIGHT);
			StartFilledRegion(1);
			DrawLine(BlockSize,0);
			DrawLine(0,-1.0/3*BLOCKHEIGHT);
			DrawLine(-BlockSize,0);
			DrawLine(0,1.0/3*BLOCKHEIGHT);
			EndFilledRegion();
			MovePen(x,y-2.0/3*BLOCKHEIGHT);
			SetPenColor("Green");
			StartFilledRegion(1);
			DrawLine(BlockSize,0);
			DrawLine(0,-1.0/3*BLOCKHEIGHT);
			DrawLine(-BlockSize,0);
			DrawLine(0,1.0/3*BLOCKHEIGHT);
			EndFilledRegion();
		}
	}
	MovePen(x,y);
	SetPenColor("Black");
}
void DrawBlock_accelerate_left(double x,double y,double BlockSize,string Color)
{
	if(strcmp(Color,"White")==0)
	{
		DrawBlock_accelerate_left1(x,y,BlockSize,"White");
	}
	else 
	{
		if(accelerateBlockAnimation%2==0)
			DrawBlock_accelerate_left1(x,y,BlockSize,"Black");
		
		else if(accelerateBlockAnimation%2==1)
			DrawBlock_accelerate_left2(x,y,BlockSize,"Black");
		
	}

}
void DrawBlock_accelerate_right(double x,double y,double BlockSize,string Color)
{
	if(strcmp(Color,"White")==0)
	{
		DrawBlock_accelerate_right1(x,y,BlockSize,"White");
	}
	else 
	{
		if(accelerateBlockAnimation%2==0)
			DrawBlock_accelerate_right1(x,y,BlockSize,"Black");
			
		else if(accelerateBlockAnimation%2==1)
			DrawBlock_accelerate_right2(x,y,BlockSize,"Black");
			
	}

}
void DrawBlock_accelerate_left2(double x,double y,double BlockSize,string Color){
	
	if(strcmp(Color,"White")==0)
	{
		MovePen(x,y);
		SetPenColor("White");
		DrawLine(BlockSize,0);
		DrawLine(0,-BLOCKHEIGHT);
		DrawLine(-BlockSize,0);
		DrawLine(0,BLOCKHEIGHT);
		StartFilledRegion(1);
		MovePen(x,y);
		DrawLine(BlockSize,0);
		DrawLine(0,-BLOCKHEIGHT);
		DrawLine(-BlockSize,0);
		DrawLine(0,BLOCKHEIGHT);
		EndFilledRegion();
	}
	else
	{
		int i,j,width=15,height=5;
		for(i=0;i<width;i++)//top part
		{
			if(i%2==0)
			{
				SetPenColor("Gray");
				MovePen(x+i*1.0/width*BlockSize,y);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
				
			}
			else
			{
				SetPenColor("Red");
				MovePen(x+i*1.0/width*BlockSize,y);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
			}
		}
		//====================================================================
		//middle part
		
			for(j=1;j<height-1;j++)
			{
				if(j%2==0)
				{
					SetPenColor("Gray");
					MovePen(x,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
					
					MovePen(x+(width-1)*1.0/width*BlockSize,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
					
				}
				else
				{
					SetPenColor("Red");
					MovePen(x,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
					
					MovePen(x+(width-1)*1.0/width*BlockSize,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
				}
				MovePen(x+1.0/width*BlockSize,y-(double)j/height*BLOCKHEIGHT);
				SetPenColor("Black");
				StartFilledRegion(1);
				DrawLine((width-2)*1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-(width-2)*1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
			}
			
		//======================================================================
		for(i=0;i<width;i++)//end part
		{
			if(i%2==0)
			{
				SetPenColor("Gray");
				MovePen(x+i*1.0/width*BlockSize,y-4.0/5*BLOCKHEIGHT);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
				
			}
			else
			{
				SetPenColor("Red");
				MovePen(x+i*1.0/width*BlockSize,y-4.0/5*BLOCKHEIGHT);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
			}
		}
		
		// two triangles
		
			MovePen(x+BlockSize/3.0,y-BLOCKHEIGHT/2.0);
			SetPenColor("Dark Yellow");
			StartFilledRegion(1);
			DrawLine(BlockSize/10,BLOCKHEIGHT/4);
			DrawLine(0,-BLOCKHEIGHT/2);
			DrawLine(-BlockSize/10,BLOCKHEIGHT/4);
			EndFilledRegion();
			
			MovePen(x+2.0*BlockSize/3,y-BLOCKHEIGHT/2.0);
			SetPenColor("Yellow");
			StartFilledRegion(1);
			DrawLine(BlockSize/10,BLOCKHEIGHT/4);
			DrawLine(0,-BLOCKHEIGHT/2);
			DrawLine(-BlockSize/10,BLOCKHEIGHT/4);
			EndFilledRegion();
		
		MovePen(x,y);
		SetPenColor("Black");
	}
	
}


void DrawBlock_accelerate_right2(double x,double y,double BlockSize,string Color){
	if(strcmp(Color,"White")==0)
	{
		MovePen(x,y);
		SetPenColor("White");
		DrawLine(BlockSize,0);
		DrawLine(0,-BLOCKHEIGHT);
		DrawLine(-BlockSize,0);
		DrawLine(0,BLOCKHEIGHT);
		StartFilledRegion(1);
		MovePen(x,y);
		DrawLine(BlockSize,0);
		DrawLine(0,-BLOCKHEIGHT);
		DrawLine(-BlockSize,0);
		DrawLine(0,BLOCKHEIGHT);
		EndFilledRegion();
	}
	else
	{
		int i,j,width=15,height=5;
		for(i=0;i<width;i++)//top part
		{
			if(i%2==0)
			{
				SetPenColor("Gray");
				MovePen(x+i*1.0/width*BlockSize,y);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
				
			}
			else
			{
				SetPenColor("Red");
				MovePen(x+i*1.0/width*BlockSize,y);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
			}
		}
		//====================================================================
		//middle part
		
			for(j=1;j<height-1;j++)
			{
				if(j%2==0)
				{
					SetPenColor("Gray");
					MovePen(x,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
					
					MovePen(x+(width-1)*1.0/width*BlockSize,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
					
				}
				else
				{
					SetPenColor("Red");
					MovePen(x,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
					
					MovePen(x+(width-1)*1.0/width*BlockSize,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
				}
				MovePen(x+1.0/width*BlockSize,y-(double)j/height*BLOCKHEIGHT);
				SetPenColor("Black");
				StartFilledRegion(1);
				DrawLine((width-2)*1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-(width-2)*1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
			}
			
		//======================================================================
		for(i=0;i<width;i++)//end part
		{
			if(i%2==0)
			{
				SetPenColor("Gray");
				MovePen(x+i*1.0/width*BlockSize,y-4.0/5*BLOCKHEIGHT);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
				
			}
			else
			{
				SetPenColor("Red");
				MovePen(x+i*1.0/width*BlockSize,y-4.0/5*BLOCKHEIGHT);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
			}
		}
		
		// two triangles
			MovePen(x+BlockSize/3.0,y-BLOCKHEIGHT/2.0);
			SetPenColor("Yellow");
			StartFilledRegion(1);
			DrawLine(0,BLOCKHEIGHT/4);
			DrawLine(BlockSize/10,-BLOCKHEIGHT/4);
			DrawLine(-BlockSize/10,-BLOCKHEIGHT/4);
			DrawLine(0,BLOCKHEIGHT/4);
			EndFilledRegion();
			
			MovePen(x+2.0*BlockSize/3,y-BLOCKHEIGHT/2.0);
			SetPenColor("Dark Yellow");
			StartFilledRegion(1);
			DrawLine(0,BLOCKHEIGHT/4);
			DrawLine(BlockSize/10,-BLOCKHEIGHT/4);
			DrawLine(-BlockSize/10,-BLOCKHEIGHT/4);
			DrawLine(0,BLOCKHEIGHT/4);
			EndFilledRegion();
		
		MovePen(x,y);
		SetPenColor("Black");
	}
	
}
void DrawBlock_accelerate_left1(double x,double y,double BlockSize,string Color){
	if(strcmp(Color,"White")==0)
	{
		MovePen(x,y);
		SetPenColor("White");
		DrawLine(BlockSize,0);
		DrawLine(0,-BLOCKHEIGHT);
		DrawLine(-BlockSize,0);
		DrawLine(0,BLOCKHEIGHT);
		StartFilledRegion(1);
		MovePen(x,y);
		DrawLine(BlockSize,0);
		DrawLine(0,-BLOCKHEIGHT);
		DrawLine(-BlockSize,0);
		DrawLine(0,BLOCKHEIGHT);
		EndFilledRegion();
	}
	else
	{
		int i,j,width=15,height=5;
		for(i=0;i<width;i++)//top part
		{
			if(i%2!=0)
			{
				SetPenColor("Gray");
				MovePen(x+i*1.0/width*BlockSize,y);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
				
			}
			else
			{
				SetPenColor("Red");
				MovePen(x+i*1.0/width*BlockSize,y);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
			}
		}
		//====================================================================
		//middle part
		
			for(j=1;j<height-1;j++)
			{
				if(j%2!=0)
				{
					SetPenColor("Gray");
					MovePen(x,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
					
					MovePen(x+(width-1)*1.0/width*BlockSize,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
					
				}
				else
				{
					SetPenColor("Red");
					MovePen(x,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
					
					MovePen(x+(width-1)*1.0/width*BlockSize,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
				}
				MovePen(x+1.0/width*BlockSize,y-(double)j/height*BLOCKHEIGHT);
				SetPenColor("Black");
				StartFilledRegion(1);
				DrawLine((width-2)*1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-(width-2)*1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
			}
			
		//======================================================================
		for(i=0;i<width;i++)//end part
		{
			if(i%2!=0)
			{
				SetPenColor("Gray");
				MovePen(x+i*1.0/width*BlockSize,y-4.0/5*BLOCKHEIGHT);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
				
			}
			else
			{
				SetPenColor("Red");
				MovePen(x+i*1.0/width*BlockSize,y-4.0/5*BLOCKHEIGHT);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
			}
		}
		// two triangles
			MovePen(x+BlockSize/3.0,y-BLOCKHEIGHT/2.0);
			SetPenColor("Yellow");
			StartFilledRegion(1);
			DrawLine(BlockSize/10,BLOCKHEIGHT/4);
			DrawLine(0,-BLOCKHEIGHT/2);
			DrawLine(-BlockSize/10,BLOCKHEIGHT/4);
			EndFilledRegion();
			
			MovePen(x+2.0*BlockSize/3,y-BLOCKHEIGHT/2.0);
			SetPenColor("Dark Yellow");
			StartFilledRegion(1);
			DrawLine(BlockSize/10,BLOCKHEIGHT/4);
			DrawLine(0,-BLOCKHEIGHT/2);
			DrawLine(-BlockSize/10,BLOCKHEIGHT/4);
			EndFilledRegion();
		
		MovePen(x,y);
		SetPenColor("Black");
	}
	
}
void DrawBlock_accelerate_right1(double x,double y,double BlockSize,string Color)
{
	if(strcmp(Color,"White")==0)
	{
		MovePen(x,y);
		SetPenColor("White");
		DrawLine(BlockSize,0);
		DrawLine(0,-BLOCKHEIGHT);
		DrawLine(-BlockSize,0);
		DrawLine(0,BLOCKHEIGHT);
		StartFilledRegion(1);
		MovePen(x,y);
		DrawLine(BlockSize,0);
		DrawLine(0,-BLOCKHEIGHT);
		DrawLine(-BlockSize,0);
		DrawLine(0,BLOCKHEIGHT);
		EndFilledRegion();
	}
	else
	{
		int i,j,width=15,height=5;
		for(i=0;i<width;i++)//top part
		{
			if(i%2!=0)
			{
				SetPenColor("Gray");
				MovePen(x+i*1.0/width*BlockSize,y);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
				
			}
			else
			{
				SetPenColor("Red");
				MovePen(x+i*1.0/width*BlockSize,y);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
			}
		}
		//====================================================================
		//middle part
		
			for(j=1;j<height-1;j++)
			{
				if(j%2!=0)
				{
					SetPenColor("Gray");
					MovePen(x,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
					
					MovePen(x+(width-1)*1.0/width*BlockSize,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
					
				}
				else
				{
					SetPenColor("Red");
					MovePen(x,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
					
					MovePen(x+(width-1)*1.0/width*BlockSize,y-(double)j/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/5*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/5*BLOCKHEIGHT);
					EndFilledRegion();
				}
				MovePen(x+1.0/width*BlockSize,y-(double)j/height*BLOCKHEIGHT);
				SetPenColor("Black");
				StartFilledRegion(1);
				DrawLine((width-2)*1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-(width-2)*1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
			}
			
		//======================================================================
		for(i=0;i<width;i++)//end part
		{
			if(i%2!=0)
			{
				SetPenColor("Gray");
				MovePen(x+i*1.0/width*BlockSize,y-4.0/5*BLOCKHEIGHT);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
				
			}
			else
			{
				SetPenColor("Red");
				MovePen(x+i*1.0/width*BlockSize,y-4.0/5*BLOCKHEIGHT);
				StartFilledRegion(1);
				DrawLine(1.0/width*BlockSize,0);
				DrawLine(0,-1.0/5*BLOCKHEIGHT);
				DrawLine(-1.0/width*BlockSize,0);
				DrawLine(0,1.0/5*BLOCKHEIGHT);
				EndFilledRegion();
			}
		}
		// two triangles
			MovePen(x+BlockSize/3.0,y-BLOCKHEIGHT/2.0);
			SetPenColor("Dark Yellow");
			StartFilledRegion(1);
			DrawLine(0,BLOCKHEIGHT/4);
			DrawLine(BlockSize/10,-BLOCKHEIGHT/4);
			DrawLine(-BlockSize/10,-BLOCKHEIGHT/4);
			DrawLine(0,BLOCKHEIGHT/4);
			EndFilledRegion();
			
			MovePen(x+2.0*BlockSize/3,y-BLOCKHEIGHT/2.0);
			SetPenColor("Yellow");
			StartFilledRegion(1);
			DrawLine(0,BLOCKHEIGHT/4);
			DrawLine(BlockSize/10,-BLOCKHEIGHT/4);
			DrawLine(-BlockSize/10,-BLOCKHEIGHT/4);
			DrawLine(0,BLOCKHEIGHT/4);
			EndFilledRegion();
		
		MovePen(x,y);
		SetPenColor("Black");
	}
	
}

void DrawBlock_reverse(double x,double y,double BlockSize,string Color){
	MovePen(x,y);
	SetPenColor("White");
	DrawLine(BlockSize,0);
	DrawLine(0,-BLOCKHEIGHT);
	DrawLine(-BlockSize,0);
	DrawLine(0,BLOCKHEIGHT);
	if(strcmp("White",Color)==0)
	{
		SetPenColor("White");
		StartFilledRegion(1);
		DrawLine(BlockSize,0);
		DrawLine(0,-BLOCKHEIGHT);
		DrawLine(-BlockSize,0);
		DrawLine(0,BLOCKHEIGHT);
		EndFilledRegion();
	}
	else
	{
		if(quality==high)
		{
			int i,j,width=15,height=3,count=0;
			for(i=0;i<height;i++)
			{
				for(j=0;j<width;j++)
				{
					if(count>=5)
						count=count-5;
					SetPenColor(reverseBlockColor[count]);
					MovePen(x+j*1.0/width*BlockSize,y-i*1.0/height*BLOCKHEIGHT);
					StartFilledRegion(1);
					DrawLine(1.0/width*BlockSize,0);
					DrawLine(0,-1.0/height*BLOCKHEIGHT);
					DrawLine(-1.0/width*BlockSize,0);
					DrawLine(0,1.0/height*BLOCKHEIGHT);
					EndFilledRegion();
					count++;
				}
				count++;
			}
		}
		else if(quality==low)
		{
			SetPenColor("Gray");
			StartFilledRegion(1);
			DrawLine(BlockSize,0);
			DrawLine(0,-BLOCKHEIGHT);
			DrawLine(-BlockSize,0);
			DrawLine(0,BLOCKHEIGHT);
			EndFilledRegion();
		}
		
	}
	MovePen(x,y);
	SetPenColor("Black");
}

void DrawOrb(double x,double y,double BlockSize,bool isClear)
{
	if(isClear==FALSE)
	{
		if(specialBlockAnimation%4==0)
			DrawOrb_anime1(x,y,BlockSize);
		else if(specialBlockAnimation%4==1)
			DrawOrb_anime2(x,y,BlockSize);
		else if(specialBlockAnimation%4==2)
			DrawOrb_anime3(x,y,BlockSize);
		else if(specialBlockAnimation%4==3)
			DrawOrb_anime4(x,y,BlockSize);
	}
	else {
		
		DrawOrb_erase(x,y,BlockSize);
		
	}

}

void DrawOrb_anime1(double x,double y,double BlockSize)
{
	double tempX,tempY;
	int initPenSize=GetPenSize();
	MovePen(x-0.5*BlockSize,y+0.5*BlockSize);
	SetPenColor("Yellow");
	StartFilledRegion(1);
	DrawLine(BlockSize,0);
	DrawLine(0,-BlockSize);
	DrawLine(-BlockSize,0);
	DrawLine(0,BlockSize);
	EndFilledRegion();
	MovePen(x-0.25*BlockSize,y+0.2*BlockSize);
	SetPenColor("Black");
	SetPenSize(10*BlockSize);
	DrawEllipticalArc(0.25*BlockSize,0.2*BlockSize,180,-240);
	DrawEllipticalArc(0.1*BlockSize,0.2*BlockSize,90,90);
	MovePen(CX+0.01*BlockSize,CY-0.2*BlockSize);
	StartFilledRegion(1);
	DrawArc(0.01*BlockSize,0,360);
	EndFilledRegion();
	SetPenSize(initPenSize);
	MovePen(x-0.5*BlockSize,y+0.5*BlockSize);
	DrawLine(BlockSize,0);
	DrawLine(0,-BlockSize);
	DrawLine(-BlockSize,0);
	DrawLine(0,BlockSize);
}

void DrawOrb_erase(double x,double y,double BlockSize)
{
	MovePen(x-0.5*BlockSize,y+0.5*BlockSize);
	SetPenColor("White");
	StartFilledRegion(1);
	DrawLine(BlockSize,0);
	DrawLine(0,-BlockSize);
	DrawLine(-BlockSize,0);
	DrawLine(0,BlockSize);
	EndFilledRegion();
	MovePen(x-0.5*BlockSize,y+0.5*BlockSize);
	DrawLine(BlockSize,0);
	DrawLine(0,-BlockSize);
	DrawLine(-BlockSize,0);
	DrawLine(0,BlockSize);
	SetPenColor("Black");
}






void DrawOrb_anime2(double x,double y,double BlockSize)
{
	double tempX,tempY;
	int initPenSize=GetPenSize();
	MovePen(x-0.5*BlockSize,y+0.5*BlockSize);
	SetPenColor("Yellow");
	StartFilledRegion(1);
	DrawLine(BlockSize,0);
	DrawLine(0,-BlockSize);
	DrawLine(-BlockSize,0);
	DrawLine(0,BlockSize);
	EndFilledRegion();
	SetPenColor("Black");
	MovePen(x-0.5*BlockSize,y+0.5*BlockSize);
	DrawLine(BlockSize,0);
	DrawLine(0,-BlockSize);
	DrawLine(-BlockSize,0);
	DrawLine(0,BlockSize);
	SetPenSize(3*BlockSize);
	MovePen(x,y+0.5*BlockSize); 
	DrawLine(0,-BlockSize);
	
	MovePen(x-0.35*BlockSize,y+0.2*BlockSize);
	SetPenSize(10*BlockSize);
	DrawEllipticalArc(0.1*BlockSize,0.2*BlockSize,180,-240);
	DrawEllipticalArc(0.05*BlockSize,0.2*BlockSize,90,90);
	MovePen(CX+0.005*BlockSize,CY-0.2*BlockSize);
	StartFilledRegion(1);
	DrawArc(0.01*BlockSize,0,360);
	EndFilledRegion();
	
	MovePen(x+0.15*BlockSize,y+0.2*BlockSize);
	SetPenSize(10*BlockSize);
	DrawEllipticalArc(0.1*BlockSize,0.2*BlockSize,180,-240);
	DrawEllipticalArc(0.05*BlockSize,0.2*BlockSize,90,90);
	MovePen(CX+0.01*BlockSize,CY-0.2*BlockSize);
	StartFilledRegion(1);
	DrawArc(0.01*BlockSize,0,360);
	EndFilledRegion();
	
	SetPenSize(initPenSize);
}



void DrawOrb_anime3(double x,double y,double BlockSize)
{
	double tempX,tempY;
	int initPenSize=GetPenSize();
	MovePen(x-0.5*BlockSize,y+0.5*BlockSize);
	SetPenColor("Yellow");
	StartFilledRegion(1);
	DrawLine(BlockSize,0);
	DrawLine(0,-BlockSize);
	DrawLine(-BlockSize,0);
	DrawLine(0,BlockSize);
	EndFilledRegion();
	SetPenColor("Black");
	MovePen(x-0.5*BlockSize,y+0.5*BlockSize);
	DrawLine(BlockSize,0);
	DrawLine(0,-BlockSize);
	DrawLine(-BlockSize,0);
	DrawLine(0,BlockSize);
	SetPenSize(3*BlockSize);
	MovePen(x+0.25*BlockSize,y+0.5*BlockSize); 
	DrawLine(0,-BlockSize);
	
	MovePen(x-0.3*BlockSize,y+0.2*BlockSize);
	SetPenSize(10*BlockSize);
	DrawEllipticalArc(0.2*BlockSize,0.2*BlockSize,180,-240);
	DrawEllipticalArc(0.1*BlockSize,0.2*BlockSize,90,90);
	MovePen(CX+0.0075*BlockSize,CY-0.2*BlockSize);
	StartFilledRegion(1);
	DrawArc(0.015*BlockSize,0,360);
	EndFilledRegion();
	
	MovePen(x+0.35*BlockSize,y+0.2*BlockSize);
	SetPenSize(7*BlockSize);
	DrawEllipticalArc(0.05*BlockSize,0.2*BlockSize,180,-240);
	DrawEllipticalArc(0.01*BlockSize,0.2*BlockSize,90,90);
	MovePen(CX,CY-0.2*BlockSize);
	StartFilledRegion(1);
	DrawArc(0.001*BlockSize,0,360);
	EndFilledRegion();
	
	SetPenSize(initPenSize);
}






void DrawOrb_anime4(double x,double y,double BlockSize)
{
	double tempX,tempY;
	int initPenSize=GetPenSize();
	MovePen(x-0.5*BlockSize,y+0.5*BlockSize);
	SetPenColor("Yellow");
	StartFilledRegion(1);
	DrawLine(BlockSize,0);
	DrawLine(0,-BlockSize);
	DrawLine(-BlockSize,0);
	DrawLine(0,BlockSize);
	EndFilledRegion();
	SetPenColor("Black");
	MovePen(x-0.5*BlockSize,y+0.5*BlockSize);
	DrawLine(BlockSize,0);
	DrawLine(0,-BlockSize);
	DrawLine(-BlockSize,0);
	DrawLine(0,BlockSize);
	SetPenSize(3*BlockSize);
	MovePen(x-0.25*BlockSize,y+0.5*BlockSize); 
	DrawLine(0,-BlockSize);
	
	MovePen(x-0.05*BlockSize,y+0.2*BlockSize);
	SetPenSize(10*BlockSize);
	DrawEllipticalArc(0.2*BlockSize,0.2*BlockSize,180,-240);
	DrawEllipticalArc(0.1*BlockSize,0.2*BlockSize,90,90);
	MovePen(CX+0.008*BlockSize,CY-0.2*BlockSize);
	StartFilledRegion(1);
	DrawArc(0.01*BlockSize,0,360);
	EndFilledRegion();
	
	MovePen(x-0.45*BlockSize,y+0.2*BlockSize);
	SetPenSize(7*BlockSize);
	DrawEllipticalArc(0.05*BlockSize,0.2*BlockSize,180,-240);
	DrawEllipticalArc(0.01*BlockSize,0.2*BlockSize,90,90);
	MovePen(CX+0.0005*BlockSize,CY-0.2*BlockSize);
	StartFilledRegion(1);
	DrawArc(0.001*BlockSize,0,360);
	EndFilledRegion();
	
	SetPenSize(initPenSize);
}







