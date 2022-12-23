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




void DrawStartMenu(bool isClear){
	double px=CX,py=CY;
	if(isClear==FALSE){
		SetPenColor("Black");
	}
	else {
		SetPenColor("White");
	}
	SetPointSize(50);
	MovePen(GetWindowWidth()/2-TextStringWidth("ST")-TextStringWidth("A")/2,GetWindowHeight()/2+1.5);
	DrawTextString("START");
	MovePen(GetWindowWidth()/2-TextStringWidth("CHAL")-TextStringWidth("L")/2,GetWindowHeight()/2+0.5);
	DrawTextString("CHALLENGE");
	MovePen(GetWindowWidth()/2-TextStringWidth("HE"),GetWindowHeight()/2-0.5);
	DrawTextString("HELP");
	MovePen(GetWindowWidth()/2-TextStringWidth("EX"),GetWindowHeight()/2-1.5);
	DrawTextString("EXIT");
	SetPointSize(35);
	
	if(isClear==FALSE){
		MovePen(0,GetWindowHeight()/2-2.5);
		SetPenColor("Black");
		StartFilledRegion(1);
		DrawLine(GetWindowWidth(),0);
		DrawLine(0,0.35);
		DrawLine(-GetWindowWidth(),0);
		DrawLine(0,-0.35);
		EndFilledRegion();
		SetPenColor("White");
	}
	else {
		MovePen(0,GetWindowHeight()/2-3);
		SetPenColor("White");
		StartFilledRegion(1);
		DrawLine(GetWindowWidth(),0);
		DrawLine(0,2);
		DrawLine(-GetWindowWidth(),0);
		DrawLine(0,-2);
		EndFilledRegion();
	}
	
	switch(gameMode){
		case basic:
			MovePen(GetWindowWidth()/2-TextStringWidth("HAVE"),GetWindowHeight()/2-2.5);
			DrawTextString("HAVE FUN");
			break;
		case slowMode:
			MovePen(GetWindowWidth()/2-TextStringWidth("You look lik"),GetWindowHeight()/2-2.5);
			DrawTextString("You look like a tortoise");	
			break;
		case oneShotMode:
			MovePen(GetWindowWidth()/2-TextStringWidth("You loo"),GetWindowHeight()/2-2.5);
			DrawTextString("You look weak");	
			break;
		case levelSkippingMode:
			MovePen(GetWindowWidth()/2-TextStringWidth("You may want so"),GetWindowHeight()/2-2.5);
			DrawTextString("You may want something easier");	
			break;
	}
	SetPointSize(50);
	SetPenColor("Black");
	MovePen(GetWindowWidth()/2-TextStringWidth(""),GetWindowHeight()/2-1.5);
	
	// title
	if(isClear==FALSE){
		MovePen(GetWindowWidth()/2-TextStringWidth("UNDERGROUND")/1.5,GetWindowHeight()/2+4);
		SetPointSize(70);
		SetStyle(Bold + Italic);
		SetPenColor("Dark Green1");
		DrawTextString("U");
		SetPenColor("Dark Green2");
		DrawTextString("N");
		SetPenColor("Dark Green3");
		DrawTextString("D");
		SetPenColor("Dark Green4");
		DrawTextString("E");
		SetPenColor("Dark Green5");
		DrawTextString("R");
		SetStyle(Italic);
		SetPenColor("Brown1");
		DrawTextString("GR");
		SetPenColor("Brown2");
		DrawTextString("OU");
		SetPenColor("Brown3");
		DrawTextString("ND");
		SetPointSize(50);
		SetStyle(Normal);
	}
	else 
	{
		SetPenColor("White");
		MovePen(GetWindowWidth()/2-TextStringWidth("UNDERGROUND")/1.5,GetWindowHeight()/2+4);
		SetPointSize(70);
		SetStyle(Bold + Italic);
		DrawTextString("U");
		DrawTextString("N");
		DrawTextString("D");
		DrawTextString("E");
		DrawTextString("R");
		SetStyle(Italic);
		DrawTextString("GR");
		DrawTextString("OU");
		DrawTextString("ND");
		SetPointSize(50);
		SetStyle(Normal);
		StartFilledRegion(1);
		MovePen(GetWindowWidth()/2-TextStringWidth("UNDERGROUND")/1.5,GetWindowHeight()/2+4);
		DrawLine(0,GetFontHeight());
		DrawLine(GetWindowWidth(),0);
		DrawLine(0,-GetFontHeight());
		DrawLine(-GetWindowWidth(),0);
		EndFilledRegion();
	}
	MovePen(px,py);
	SetPenColor("Black");
	
	
}



void DrawGameMenu(){
	int i;
	SetPenColor("Black");
	StartFilledRegion(1);
	MovePen(0,GetWindowHeight());
	DrawLine(GetWindowWidth(),0);
	DrawLine(0,-GetWindowHeight()/5);
	DrawLine(-GetWindowWidth(),0);
	DrawLine(0,GetWindowHeight()/5);
	EndFilledRegion();
	MovePen(0,GetWindowHeight()*4/5);
	StartFilledRegion(1);
	for(i=0;i<100;i++)
	{
		DrawLine(0.1,-0.2);
		DrawLine(0.1,0.2);
		
	}
	EndFilledRegion();
	
	SetPenColor("Black");
	StartFilledRegion(1);
	MovePen(0,0.5);
	DrawLine(GetWindowWidth(),0);
	DrawLine(0,-0.5);
	DrawLine(-GetWindowWidth(),0);
	DrawLine(0,0.5);
	EndFilledRegion();
	
	
	
	SetPointSize(35);
	MovePen(GetWindowWidth()-TextStringWidth("SCORE: 9999999999"),GetWindowHeight()-0.75);
	SetPenColor("White");
	DrawTextString("SCORE: ");
	DrawTextString(score);
	MovePen(GetWindowWidth()-TextStringWidth("FLOOR: 9999999999"),GetWindowHeight()-1.25);
	DrawTextString("FLOOR: ");
	DrawTextString(height);
	DrawHpBar();
	SetPointSize(1);
	
	
	
	
	if(CurrentHP<=0)
	{
		die();	
	}
	
}

void DrawEndMenu()
{
	double initX=CX, initY=CY;
	//int numberOfGames;
	addRecord(score);
	//getRecord(*maxRecord);
	//shape of end menu
	SetPenColor("White");
	StartFilledRegion(1);
	MovePen(GetWindowWidth()/2-endMenuLength/2.0,GetWindowHeight()/2+endMenuHeight/2.0);
	DrawLine(endMenuHeight,0);
	DrawLine(0,-endMenuHeight);
	DrawLine(-endMenuHeight,0);
	DrawLine(0,endMenuHeight);
	EndFilledRegion();
	SetPenColor("Black");
	MovePen(GetWindowWidth()/2- endMenuLength/2.0,GetWindowHeight()/2+endMenuHeight/2.0);
	/*
	DrawLine(endMenuHeight,0);
	DrawLine(0,-endMenuHeight);
	DrawLine(-endMenuHeight,0);
	DrawLine(0,endMenuHeight);
	*/
	//end menu content
	SetPointSize(50);
	double temp=TextStringWidth("Score : ")+TextStringWidth(score);
	MovePen(GetWindowWidth()/2-temp/2.0,GetWindowHeight()/2+2.5*endMenuHeight/8.0);
	DrawTextString("Score : ");
	DrawTextString(score);

	SetPointSize(35);
	temp=TextStringWidth("Max Score : ")+TextStringWidth("9999999999");
	MovePen(GetWindowWidth()/2-temp/2.0,GetWindowHeight()/2+endMenuHeight/8.0);
	DrawTextString("Max Score : ");
	getRecord(1);
	
	SetPointSize(35);
	temp=TextStringWidth("Your place : ")+TextStringWidth("1st");
	MovePen(GetWindowWidth()/2-temp/2.0,GetWindowHeight()/2);
	/*
	DrawTextString("Your place : ");
	DrawTextString("1st");
	*/
	SetPointSize(23);
	temp=TextStringWidth("marks: 9999999999  place: 1st");
	MovePen(GetWindowWidth()/2-temp,GetWindowHeight()/2-1*endMenuHeight/16.0);
	DrawTextString("     History Reccords :");
	MovePen(GetWindowWidth()/2-temp/2.0,GetWindowHeight()/2-2*endMenuHeight/16.0); //history 1st place record
	DrawTextString("marks: ");
	getRecord(1);
	DrawTextString("   place: 1st");
	MovePen(GetWindowWidth()/2-temp/2.0,GetWindowHeight()/2-3*endMenuHeight/16.0); //history 2nd place record
	DrawTextString("marks: ");
	getRecord(2);
	DrawTextString("   place: 2nd");
	MovePen(GetWindowWidth()/2-temp/2.0,GetWindowHeight()/2-4*endMenuHeight/16.0); //history 3rd place record
	DrawTextString("marks: ");
	getRecord(3);
	DrawTextString("   place: 3rd");
	MovePen(GetWindowWidth()/2-temp/2.0,GetWindowHeight()/2-5*endMenuHeight/16.0); //history 4th place record
	DrawTextString("marks: ");
	getRecord(4);
	DrawTextString("   place: 4th");
	
	SetPenColor("Red");
	StartFilledRegion(1);
	MovePen(GetWindowWidth()/2-0.9*endMenuLength/2.0,GetWindowHeight()/2-0.7*endMenuHeight/2.0);
	DrawLine(0.4*endMenuLength,0);
	DrawLine(0,-0.1*endMenuHeight);
	DrawLine(-0.4*endMenuLength,0);
	DrawLine(0,0.1*endMenuHeight);
	EndFilledRegion();
	SetPenColor("White");
	StartFilledRegion(1);
	MovePen(GetWindowWidth()/2-0.25*endMenuLength,GetWindowHeight()/2-0.44*endMenuHeight);
	DrawArc(0.04*endMenuLength,270,270);
	DrawLine(0.01*endMenuLength,0);
	DrawArc(0.03*endMenuLength,180,-270);
	DrawLine(0,0.01*endMenuHeight);
	EndFilledRegion();
	SetPenColor("Red");
	StartFilledRegion(1);
	MovePen(GetWindowWidth()/2-0.25*endMenuLength,GetWindowHeight()/2-0.43*endMenuHeight);
	DrawArc(0.03*endMenuLength,270,360);
	EndFilledRegion();
	SetPenColor("White");
	StartFilledRegion(1);
	MovePen(GetWindowWidth()/2-0.29*endMenuLength,GetWindowHeight()/2-0.4*endMenuHeight);
	DrawLine(-0.01*endMenuLength,0);
	DrawLine(0.015*endMenuLength,-0.01*endMenuHeight);
	DrawLine(0.015*endMenuLength,0.01*endMenuHeight);
	DrawLine(-0.01*endMenuLength,0);
	EndFilledRegion();
	
	
	SetPenColor("Green");
	StartFilledRegion(1);
	MovePen(GetWindowWidth()/2+0.9*endMenuLength/2.0,GetWindowHeight()/2-0.7*endMenuHeight/2.0);
	DrawLine(-0.4*endMenuLength,0);
	DrawLine(0,-0.1*endMenuHeight);
	DrawLine(0.4*endMenuLength,0);
	DrawLine(0,0.1*endMenuHeight);
	EndFilledRegion();
	SetPenColor("White");
	StartFilledRegion(1);
	MovePen(GetWindowWidth()/2+0.24*endMenuLength,GetWindowHeight()/2-0.375*endMenuHeight);
	DrawLine(0,-0.05*endMenuHeight);
	DrawLine(0.05*endMenuLength,0.025*endMenuHeight);
	DrawLine(-0.05*endMenuLength,0.025*endMenuHeight);
	EndFilledRegion();
	
	
	MovePen(initX,initY);
}


void PauseTheGame()
{
	int i;
	SaveGraphicsState();
	for(i=1;i<20;i++)
		cancelTimer(i);
	DrawPauseAnimation();
	
}

void Resume()
{
	DrawResumeAnimation();
	RestoreGraphicsState();
	startTimer(BLOCKGENERATE,generateSpeed);      
	startTimer(MOVETIME,15);
	startTimer(LANDTIME,1);
	startTimer(MOVEBLOCK,5);
	startTimer(MENUREFRESH,5);
	startTimer(SPECIALBLOCKANIMATION,250);
	startTimer(ONESECONDEVENT,1000);
	if(CurrentHP<10)
		startTimer(HPREGENERATE,2000);
	if(reverseTimer>0)
	{
		startTimer(CLEANSEREVERSE,reverseTimer*1000);
	}
	if(boostTimer>0)
	{
		startTimer(CLEANSEBOOST,boostTimer*1000);
	}
	if(slowTimer>0)
	{
		startTimer(CLEANSESLOW,slowTimer*1000);
	}
	startTimer(PAUSECOOLDOWN,20*1000);   
	pauseIsCoolDown=TRUE; 
}


void DrawPauseAnimation()
{
	int i;
	double coefficient;
	for(i=1;i<10;i++) // animation
	{
		coefficient=(double)i/10.0;
		SetPenColor("Black");
		MovePen(GetWindowWidth()/2-coefficient*2*PauseAnimationLength,GetWindowHeight()/2+coefficient*PauseAnimationHeight/2);
		DrawLine(coefficient*PauseAnimationLength,0);
		DrawLine(0,-coefficient*PauseAnimationHeight);
		DrawLine(-coefficient*PauseAnimationLength,0);
		DrawLine(0,coefficient*PauseAnimationHeight);
		MovePen(GetWindowWidth()/2+coefficient*2*PauseAnimationLength,GetWindowHeight()/2+coefficient*PauseAnimationHeight/2);
		DrawLine(-coefficient*PauseAnimationLength,0);
		DrawLine(0,-coefficient*PauseAnimationHeight);
		DrawLine(coefficient*PauseAnimationLength,0);
		DrawLine(0,coefficient*PauseAnimationHeight);
		Pause(0.05);
		
		SetPenColor("White");
		MovePen(GetWindowWidth()/2-coefficient*2*PauseAnimationLength,GetWindowHeight()/2+coefficient*PauseAnimationHeight/2);
		DrawLine(coefficient*PauseAnimationLength,0);
		DrawLine(0,-coefficient*PauseAnimationHeight);
		DrawLine(-coefficient*PauseAnimationLength,0);
		DrawLine(0,coefficient*PauseAnimationHeight);
		MovePen(GetWindowWidth()/2+coefficient*2*PauseAnimationLength,GetWindowHeight()/2+coefficient*PauseAnimationHeight/2);
		DrawLine(-coefficient*PauseAnimationLength,0);
		DrawLine(0,-coefficient*PauseAnimationHeight);
		DrawLine(coefficient*PauseAnimationLength,0);
		DrawLine(0,coefficient*PauseAnimationHeight);
	}
		SetPenColor("White");
		StartFilledRegion(1);
		MovePen(GetWindowWidth()/2-2*PauseAnimationLength,GetWindowHeight()/2+PauseAnimationHeight/2);
		DrawLine(PauseAnimationLength,0);
		DrawLine(0,-PauseAnimationHeight);
		DrawLine(-PauseAnimationLength,0);
		DrawLine(0,PauseAnimationHeight);
		EndFilledRegion();
		StartFilledRegion(1);
		MovePen(GetWindowWidth()/2+2*PauseAnimationLength,GetWindowHeight()/2+PauseAnimationHeight/2);
		DrawLine(-PauseAnimationLength,0);
		DrawLine(0,-PauseAnimationHeight);
		DrawLine(PauseAnimationLength,0);
		DrawLine(0,PauseAnimationHeight);
		EndFilledRegion();
		SetPenColor("Black");
		MovePen(GetWindowWidth()/2-2*PauseAnimationLength,GetWindowHeight()/2+PauseAnimationHeight/2);
		DrawLine(PauseAnimationLength,0);
		DrawLine(0,-PauseAnimationHeight);
		DrawLine(-PauseAnimationLength,0);
		DrawLine(0,PauseAnimationHeight);
		MovePen(GetWindowWidth()/2+2*PauseAnimationLength,GetWindowHeight()/2+PauseAnimationHeight/2);
		DrawLine(-PauseAnimationLength,0);
		DrawLine(0,-PauseAnimationHeight);
		DrawLine(PauseAnimationLength,0);
		DrawLine(0,PauseAnimationHeight);
		
		double temp;
		SetPenColor("Red");
		SetPointSize(35);
		temp=TextStringWidth("Press P again to continue");
		MovePen(GetWindowWidth()/2-temp/2,GetWindowHeight()/2-PauseAnimationHeight);
		DrawTextString("Press P again to continue");
	
}


void DrawResumeAnimation()
{
	SetPenColor("White");
	MovePen(GetWindowWidth()/2-2*PauseAnimationLength,GetWindowHeight()/2+PauseAnimationHeight/2);
	DrawLine(PauseAnimationLength,0);
	DrawLine(0,-PauseAnimationHeight);
	DrawLine(-PauseAnimationLength,0);
	DrawLine(0,PauseAnimationHeight);
	MovePen(GetWindowWidth()/2+2*PauseAnimationLength,GetWindowHeight()/2+PauseAnimationHeight/2);
	DrawLine(-PauseAnimationLength,0);
	DrawLine(0,-PauseAnimationHeight);
	DrawLine(PauseAnimationLength,0);
	DrawLine(0,PauseAnimationHeight);
	
	double temp;
	SetPenColor("White");
	SetPointSize(35);
	temp=TextStringWidth("Press P again to continue");
	MovePen(GetWindowWidth()/2-temp/2,GetWindowHeight()/2-PauseAnimationHeight);
	DrawTextString("Press P again to continue");
		
	int i;
	double coefficient;
	for(i=1;i<10;i++)
	{
		coefficient=(double)i/10;
		SetPenColor("Black");
		MovePen(GetWindowWidth()/2-coefficient*ResumeAnimationLength/3,GetWindowHeight()/2+coefficient*ResumeAnimationHeight/2);
		DrawLine(0,-coefficient*ResumeAnimationHeight);
		DrawLine(coefficient*ResumeAnimationLength,coefficient*ResumeAnimationHeight/2);
		DrawLine(-coefficient*ResumeAnimationLength,coefficient*ResumeAnimationHeight/2);
		Pause(0.05);
		
		SetPenColor("White");
		StartFilledRegion(1);
		MovePen(GetWindowWidth()/2-coefficient*ResumeAnimationLength/3,GetWindowHeight()/2+coefficient*ResumeAnimationHeight/2);
		DrawLine(0,-coefficient*ResumeAnimationHeight);
		DrawLine(coefficient*ResumeAnimationLength,coefficient*ResumeAnimationHeight/2);
		DrawLine(-coefficient*ResumeAnimationLength,coefficient*ResumeAnimationHeight/2);
		EndFilledRegion();
	}
	
	
}


void initGame()
{
	struct block *blockCount=NULL,*t=NULL;
	double px=CX,py=CY;
	
	level=0;
	isHeal=FALSE;
	isPause=FALSE;
	debugMode=FALSE;
	levelUpdate();
	int i;
	for(i=0;i<9;i++)
	{
		score[i]='0';
	}
	SetPenColor("White");
	StartFilledRegion(1);
	MovePen(0,0);
	DrawLine(GetWindowWidth(),0);
	DrawLine(0,GetWindowHeight());
	DrawLine(-GetWindowWidth(),0);
	DrawLine(0,-GetWindowHeight());
	EndFilledRegion();
	characterVelocityX=0;
	moveVelocityBoost=1;
	CurrentHP=10;
	isReverse=FALSE; 
	isBoost=FALSE;
	isSlow=FALSE;
	SetPenColor("Black");
	if(headBlock==NULL){
		MovePen(px,py); 
		return;
	}		 
	for(blockCount=headBlock;blockCount->nextBlock!=NULL;blockCount=blockCount->nextBlock)
	{
		MovePen(blockCount->blockPositionX,blockCount->blockPositionY-BLOCKHEIGHT);
		switch(blockCount->type)
		{
			case DEFAULT:
				DrawBlock_default(blockCount->blockPositionX,blockCount->blockPositionY,length,"White");
				DrawBlock_default(blockCount->blockPositionX+0.1,blockCount->blockPositionY,length,"White");
				blockCount->blockPositionY+=speed;
				break;
			case STING:
				DrawBlock_Sting(blockCount->blockPositionX,blockCount->blockPositionY,length,"White");
				DrawBlock_Sting(blockCount->blockPositionX+0.1,blockCount->blockPositionY,length,"White");
				blockCount->blockPositionY+=speed;
				break;
			case BOUNCE:
				DrawBlock_bounce(blockCount->blockPositionX,blockCount->blockPositionY,length,"White");	
				DrawBlock_bounce(blockCount->blockPositionX+0.1,blockCount->blockPositionY,length,"White");
				blockCount->blockPositionY+=speed;
				break;
			case ACCELERATE:
				DrawBlock_accelerate_left(blockCount->blockPositionX,blockCount->blockPositionY,length,"White");
				DrawBlock_accelerate_left(blockCount->blockPositionX+0.1,blockCount->blockPositionY,length,"White");
				blockCount->blockPositionY+=speed;
				break;
			case REVERSE:
				DrawBlock_reverse(blockCount->blockPositionX,blockCount->blockPositionY,length,"White");
				DrawBlock_reverse(blockCount->blockPositionX+0.1,blockCount->blockPositionY,length,"White");	
				blockCount->blockPositionY+=speed;
				break;
			}
			blockCount->blockPositionY=GetWindowHeight()+10;
			
			
			t=blockCount;
			free(t);
	}
	
	b=(struct block *)malloc(sizeof(struct block));
	headBlock=b;
	//free(headBlock);
	MovePen(px,py);	
			
}



void DrawTextAnimation()
{
	
	if(specialBlockReverseWordAnimation>=11)
	{
		specialBlockReverseWordAnimation=0;
	}
	
	else
	{
		double initX=CX, initY=CY,temp;
		int initPenSize=GetPenSize();
		SetPointSize(70);
		temp=TextStringWidth(SpecialBlockWordDisplay)+TextStringWidth("!!");
		
		MovePen(GetWindowWidth()/2-temp/2,GetWindowHeight()/1.5);
		
		SetPenColor(specialBlockWordDisplayAnimation[specialBlockReverseWordAnimation]);
		DrawTextString(SpecialBlockWordDisplay); 
		DrawTextString("!!"); 
		//startTimer(SPECIALBLOCKANIMATIONCOUNTDOWN,100);
		
		SetPointSize(initPenSize);
		MovePen(initX,initY);
		
	}
	
	
	
} 

void levelUpdate(){
	int i=0;
	if(level==0){
		for(i=8;i>=0;i--){

				height[i]='0';

			
		}
	}
	else {
		height[8]++;
		for(i=8;i>=0;i--){
			if(height[i]>='9'+1){
				height[i]-=10;
				height[i-1]++;
			}
		}
	}
	if(level<20){
		blockChance[DEFAULT]=80;		  			
	 	blockChance[ACCELERATE]=2;			  	
		blockChance[STING]=2;				
		blockChance[REVERSE]=2;				
		blockChance[BOUNCE]=2;						
		blockChance[ORB]=12;
		length=((3.15)/(1+0.1));
		speed=0.075;
		generateSpeed=800;	
	}
	else {
		blockChance[DEFAULT]=28;		  			
 		blockChance[ACCELERATE]=15;			  	
		blockChance[STING]=15;				
		blockChance[REVERSE]=15;				
		blockChance[BOUNCE]=15;						
		blockChance[ORB]=12;
		length=((3.15)/(1+0.005*level));
		speed=0.075+0.0001*level;
		generateSpeed=800-5*(level/10);
	}
    				  		
	
	if(level%10==0){
		if(generateSpeed>=100){
			cancelTimer(BLOCKGENERATE);
			startTimer(BLOCKGENERATE,generateSpeed);
		}
		
		
	}
	levelVelocityAid=1;
	
	
	 
	
}

void DrawHelpMenu(bool isClear){
	DrawStartMenu(TRUE);
	if(isClear==FALSE){
		SetPenColor("Black");
	}
	else {
		SetPenColor("White");
	}
	startGame=helpMenu;
	SetPointSize(30);
	MovePen(1,9);
	DrawTextString("press 's' to start game.");
	MovePen(1,8.5);
	DrawTextString("press 'r' to restart.");
	MovePen(1,8);
	DrawTextString("press 'b' to back or quit");	
	MovePen(1,7.5);
	DrawTextString("press 'c' to challenge menu");
	MovePen(1,7);
	DrawTextString("press 'h' to help menu");
	MovePen(1,6.5);
	DrawTextString("use arrow button to move.");
	MovePen(1,6);
	if(quality==high){
		DrawTextString("Current Quality : High");
	}
	else{
		DrawTextString("Current Quality : Low");
	}
	MovePen(1,5);
	SetPointSize(40);
	DrawTextString("try to stay as long as possible.");
	SetPointSize(30);
	MovePen(1,4);
	DrawTextString("BACK");
	MovePen(5,4);
	DrawTextString("Change Quality");
	
	
	
	
	
	
	
	
}

void DrawChallengeMenu(bool isClear){
	DrawStartMenu(TRUE);
	startGame=challengeMenu;
	if(isClear==FALSE){
		SetPenColor("Black");
	}
	else {
		SetPenColor("White");
	}
	SetPointSize(30);
	MovePen(1,9);
	//SetPenColor("White");
	DrawTextString("Slow mode  ");
	DrawTextString("(You are permanent slower)");
	MovePen(1,8);
	DrawTextString("OneShot mode  ");
	DrawTextString("(You are permanent one health)");
	MovePen(1,7);
	DrawTextString("Doom mode  ");
	DrawTextString("(unreasonable level)");
	//DrawTextString("Boost mode");
	MovePen(1,6);
	DrawTextString("Basic mode  ");
	
	//DrawTextString("try to stay as long as possible.");
	
	MovePen(1,4);
	DrawTextString("BACK");
	
}

















