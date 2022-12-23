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







void KeyboardEventProcess(int key,int event);
void CharEventProcess(char c);
void MouseEventProcess(int x, int y, int button, int event);
void TimerEventProcess(int timerID);




void Main(){
	
	Randomize();
	SetWindowSize(11, 14);
	//InitConsole();
	InitGraphics();
	//DrawBlock_accelerate_left(5,6,2,"Black");
	registerMouseEvent(MouseEventProcess);               //registing
	registerTimerEvent(TimerEventProcess);   			      
	registerKeyboardEvent(KeyboardEventProcess);
	registerCharEvent(CharEventProcess); 
	quality=high;
	int i;
	for(i=0;i<9;i++){
		score[i]='0';
	}
	
	
	DrawStartMenu(FALSE);
	
}

void MouseEventProcess(int x, int y, int button, int event){
	double mx=ScaleXInches(x),my=ScaleYInches(y);
	switch(event){
		case BUTTON_DOWN:
			if(startGame==playingGame && debugMode==TRUE){
				SetPenColor("White");
				DrawMan(animeState);;
				MovePen(mx,my);
				SetPenColor("Black");
				DrawMan(animeState);
				startGame=playingGame;
			
			}
			if(startGame==startMenu && mx>GetWindowWidth()/2-TextStringWidth("ST")-TextStringWidth("A")/2 && mx<GetWindowWidth()/2-TextStringWidth("ST")-TextStringWidth("A")/2+TextStringWidth("START") && my>GetWindowHeight()/2+1.5 && my<GetWindowHeight()/2+2){
				/***game setting***/
				level=0;
				levelUpdate();
				
				/***game setting***/
				switch(gameMode){
					case basic:
						break;
					case slowMode:
						moveVelocityBoost=0.75;
						break;
					case oneShotMode:
						//CurrentHP=1;
						break;
					case levelSkippingMode:
						level=50;
						break;
				}
				
				DrawStartMenu(TRUE);
				MovePen(GetWindowWidth()/2,GetWindowHeight()/2); 
    			SummonBlock(CX-0.5,GetWindowHeight()/30,DEFAULT);
    			SummonBlock(CX-0.5,GetWindowHeight()/30,DEFAULT);
				MovePen(GetWindowWidth()/2,GetWindowHeight()/2-3); 
				   
				DrawMan(animeState);
				startTimer(BLOCKGENERATE,generateSpeed);     
				startTimer(MOVETIME,15);
				
				startTimer(LANDTIME,1);
				startTimer(MOVEBLOCK,5);
				startTimer(MENUREFRESH,5);
				startTimer(SPECIALBLOCKANIMATION,250);
				startTimer(ONESECONDEVENT,1000);
				startGame=playingGame;
				 
			}
			
			else if(startGame==startMenu && mx>GetWindowWidth()/2-TextStringWidth("CHAL")-TextStringWidth("L")/2 && mx<GetWindowWidth()/2-TextStringWidth("CHAL")-TextStringWidth("L")/2+TextStringWidth("CHALLENGE") && my>GetWindowHeight()/2+0.5 && my<GetWindowHeight()/2+1){
				DrawChallengeMenu(FALSE);
			}
			else if(startGame==startMenu && mx>GetWindowWidth()/2-TextStringWidth("HE") && mx<GetWindowWidth()/2+TextStringWidth("LP") && my>GetWindowHeight()/2-0.5 && my<GetWindowHeight()/2){
				DrawHelpMenu(FALSE);
				
			}
			else if(startGame==startMenu && mx>GetWindowWidth()/2-TextStringWidth("EX") && mx<GetWindowWidth()/2+TextStringWidth("IT") && my>GetWindowHeight()/2-1.5 && my<GetWindowHeight()/2-1.0){
				ExitGraphics();
	
			}
			
			else if(startGame==endGame&&mx>GetWindowWidth()/2-0.45*endMenuLength && mx<GetWindowWidth()/2-0.05*endMenuLength && my<GetWindowHeight()/2-0.35*endMenuHeight && my>GetWindowHeight()/2-0.45*endMenuHeight)
			{
				initGame();
				
				characterVelocityX=0;
				
				DrawStartMenu(FALSE);
				startGame=startMenu;
				
			}
			
			else if(startGame==endGame&&mx<GetWindowWidth()/2+0.45*endMenuLength && mx>GetWindowWidth()/2+0.05*endMenuLength && my<GetWindowHeight()/2-0.35*endMenuHeight && my>GetWindowHeight()/2-0.45*endMenuHeight)
			{
				initGame();
				
				MovePen(GetWindowWidth()/2,GetWindowHeight()/2); 
    			SummonBlock(CX-0.5,GetWindowHeight()/30,DEFAULT);
    			SummonBlock(CX-0.5,GetWindowHeight()/30,DEFAULT);
				MovePen(GetWindowWidth()/2,GetWindowHeight()/2-3.4);  
				characterVelocityX=0;
				DrawMan(animeState);
				startTimer(BLOCKGENERATE,generateSpeed);      
				startTimer(MOVETIME,10);
				startTimer(LANDTIME,1);
				startTimer(MOVEBLOCK,5);
				startTimer(MENUREFRESH,5);
				startTimer(SPECIALBLOCKANIMATION,250);
				startGame=playingGame;
				//SetPenSize(50);
				
				
				
			}
			else if((startGame==helpMenu || startGame==challengeMenu) && mx>1 && mx<1+TextStringWidth("BACK") && my>4 && my<4.5){
					
					DrawChallengeMenu(TRUE);
					DrawHelpMenu(TRUE);
					DrawStartMenu(FALSE);
					startGame=startMenu;
				}
			else if((startGame==helpMenu) && mx>5 && mx<5+TextStringWidth("Change Quality") && my>4 && my<4.5){
					
					DrawHelpMenu(TRUE);
					if(quality==high){
						quality=low;
					}
					else{
						quality=high;
					}
					DrawHelpMenu(FALSE);
					
				}
			else if(startGame==challengeMenu && mx>1 && mx<1+TextStringWidth("Slow mode") && my>9 && my<9.5 ){
				DrawChallengeMenu(TRUE);
				DrawStartMenu(FALSE);
				startGame=startMenu;
				gameMode=slowMode;
			}
			else if(startGame==challengeMenu && mx>1 && mx<1+TextStringWidth("OneShot mode") && my>8 && my<8.5 ){
				DrawChallengeMenu(TRUE);
				DrawStartMenu(FALSE);
				startGame=startMenu;
				gameMode=oneShotMode;
			}
			else if(startGame==challengeMenu && mx>1 && mx<1+TextStringWidth("Doom mode") && my>7 && my<7.5 ){
				DrawChallengeMenu(TRUE);
				DrawStartMenu(FALSE);
				startGame=startMenu;
				gameMode=levelSkippingMode;
			}
			else if(startGame==challengeMenu && mx>1 && mx<1+TextStringWidth("Basic mode") && my>6 && my<6.5 ){
				DrawChallengeMenu(TRUE);
				DrawStartMenu(FALSE);
				startGame=startMenu;
				gameMode=basic;
			}
			
				
			
			/*
			else {
				
				break;
			}
			*/
			
			
			
			break;
		case MOUSEMOVE:
			if(startGame==startMenu){
				if(startGame==startMenu && mx>GetWindowWidth()/2-TextStringWidth("ST")-TextStringWidth("A")/2 && mx<GetWindowWidth()/2-TextStringWidth("ST")-TextStringWidth("A")/2+TextStringWidth("START") && my>GetWindowHeight()/2+1.5 && my<GetWindowHeight()/2+2){
					SetPenColor("Red");
					MovePen(GetWindowWidth()/2-TextStringWidth("ST")-TextStringWidth("A")/2 ,GetWindowHeight()/2+1.5);
					DrawTextString("START");
					/*
					DrawLine(2,0);
					DrawLine(0,0.5);
					DrawLine(-2,0);
					DrawLine(0,-0.5);	
					*/
					SetPenColor("Black");
				}
				else if(startGame==startMenu && mx>GetWindowWidth()/2-TextStringWidth("CHAL")-TextStringWidth("L")/2 && mx<GetWindowWidth()/2-TextStringWidth("CHAL")-TextStringWidth("L")/2+TextStringWidth("CHALLENGE") && my>GetWindowHeight()/2+0.5 && my<GetWindowHeight()/2+1){
					SetPenColor("Red");
					MovePen(GetWindowWidth()/2-TextStringWidth("CHAL")-TextStringWidth("L")/2 ,GetWindowHeight()/2+0.5);
					DrawTextString("CHALLENGE");
					/*
					DrawLine(2,0);
					DrawLine(0,0.5);
					DrawLine(-2,0);
					DrawLine(0,-0.5);
					*/
					SetPenColor("Black");
				}
				else if(startGame==startMenu && mx>GetWindowWidth()/2-TextStringWidth("HE") && mx<GetWindowWidth()/2+TextStringWidth("LP") && my>GetWindowHeight()/2-0.5 && my<GetWindowHeight()/2){
					SetPenColor("Red");
					MovePen(GetWindowWidth()/2-TextStringWidth("HE"),GetWindowHeight()/2-0.5);
					DrawTextString("HELP");
					/*
					DrawLine(2,0);
					DrawLine(0,0.5);
					DrawLine(-2,0);
					DrawLine(0,-0.5);
					*/
					SetPenColor("Black");
					
				}
				else if(startGame==startMenu && mx>GetWindowWidth()/2-TextStringWidth("EX") && mx<GetWindowWidth()/2+TextStringWidth("IT") && my>GetWindowHeight()/2-1.5 && my<GetWindowHeight()/2-1.0){
					SetPenColor("Red");
					MovePen(GetWindowWidth()/2-TextStringWidth("EX"),GetWindowHeight()/2-1.5);
					DrawTextString("EXIT");
					/*
					MovePen(GetWindowWidth()/2-1.1,GetWindowHeight()/2-1.5);
					DrawLine(2,0);
					DrawLine(0,0.5);
					DrawLine(-2,0);
					DrawLine(0,-0.5);
					*/
					SetPenColor("Black");
				}
				else {
					DrawStartMenu(FALSE);
				}
			}
			
			else if(startGame==endGame)
			{
				if(mx>GetWindowWidth()/2-0.45*endMenuLength && mx<GetWindowWidth()/2-0.05*endMenuLength && my<GetWindowHeight()/2-0.35*endMenuHeight && my>GetWindowHeight()/2-0.45*endMenuHeight)
				{
					SetPenColor("Light Red");
					StartFilledRegion(1);
					MovePen(GetWindowWidth()/2-0.9*endMenuLength/2.0,GetWindowHeight()/2-0.7*endMenuHeight/2.0);
					DrawLine(0.398*endMenuHeight,0);
					DrawLine(0,-0.098*endMenuHeight);
					DrawLine(-0.398*endMenuHeight,0);
					DrawLine(0,0.098*endMenuHeight);
					EndFilledRegion();
					SetPenColor("White");
					StartFilledRegion(1);
					MovePen(GetWindowWidth()/2-0.25*endMenuLength,GetWindowHeight()/2-0.44*endMenuHeight);
					DrawArc(0.04*endMenuLength,270,270);
					DrawLine(0.01*endMenuLength,0);
					DrawArc(0.03*endMenuLength,180,-270);
					DrawLine(0,0.01*endMenuHeight);
					EndFilledRegion();
					SetPenColor("Light Red");
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
				}
				else if(mx<GetWindowWidth()/2+0.45*endMenuLength && mx>GetWindowWidth()/2+0.05*endMenuLength && my<GetWindowHeight()/2-0.35*endMenuHeight && my>GetWindowHeight()/2-0.45*endMenuHeight)
				{
					SetPenColor("Light Green");
					StartFilledRegion(1);
					MovePen(GetWindowWidth()/2+0.05*endMenuLength,GetWindowHeight()/2-0.7*endMenuHeight/2.0);
					DrawLine(0.398*endMenuHeight,0);
					DrawLine(0,-0.098*endMenuHeight);
					DrawLine(-0.398*endMenuHeight,0);
					DrawLine(0,0.098*endMenuHeight);
					EndFilledRegion();
					SetPenColor("White");
					StartFilledRegion(1);
					MovePen(GetWindowWidth()/2+0.24*endMenuLength,GetWindowHeight()/2-0.375*endMenuHeight);
					DrawLine(0,-0.05*endMenuHeight);
					DrawLine(0.05*endMenuLength,0.025*endMenuHeight);
					DrawLine(-0.05*endMenuLength,0.025*endMenuHeight);
					EndFilledRegion();
				}
				else
				{
					SetPenColor("Red");
					StartFilledRegion(1);
					MovePen(GetWindowWidth()/2-0.9*endMenuLength/2.0,GetWindowHeight()/2-0.7*endMenuHeight/2.0);
					DrawLine(0.4*endMenuHeight,0);
					DrawLine(0,-0.1*endMenuHeight);
					DrawLine(-0.4*endMenuHeight,0);
					DrawLine(0,0.1*endMenuHeight);
					EndFilledRegion();
					SetPenColor("Green");
					StartFilledRegion(1);
					MovePen(GetWindowWidth()/2+0.9*endMenuLength/2.0,GetWindowHeight()/2-0.7*endMenuHeight/2.0);
					DrawLine(-0.4*endMenuHeight,0);
					DrawLine(0,-0.1*endMenuHeight);
					DrawLine(0.4*endMenuHeight,0);
					DrawLine(0,0.1*endMenuHeight);
					EndFilledRegion();
					SetPenColor("White");
					StartFilledRegion(1);
					MovePen(GetWindowWidth()/2+0.24*endMenuLength,GetWindowHeight()/2-0.375*endMenuHeight);
					DrawLine(0,-0.05*endMenuHeight);
					DrawLine(0.05*endMenuLength,0.025*endMenuHeight);
					DrawLine(-0.05*endMenuLength,0.025*endMenuHeight);
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
				}
				
			}
			else if(startGame==helpMenu){
				if(mx>1 && mx<1+TextStringWidth("BACK") && my>4 && my<4.5){
					SetPenColor("Red");
					MovePen(1,4);
					DrawTextString("BACK");
					
					SetPenColor("Black");
					//initGame();
					//DrawStartMenu(FALSE);
					//startGame=startMenu;
				}
				else if(mx>5 && mx<5+TextStringWidth("Change Quality") && my>4 && my<4.3){
					SetPenColor("Red");
					MovePen(5,4);
					DrawTextString("Change Quality");
					
					SetPenColor("Black");
					//initGame();
					//DrawStartMenu(FALSE);
					//startGame=startMenu;
				}
				
				else {
					DrawHelpMenu(TRUE);
					DrawHelpMenu(FALSE);
					
					SetPenColor("Black");
				}
			}
			else if(startGame==challengeMenu){
				if(mx>1 && mx<1+TextStringWidth("BACK") && my>4 && my<4.5){
					SetPenColor("Red");
					MovePen(1,4);
					DrawTextString("BACK");
					
					SetPenColor("Black");
					
				}
				else if(mx>1 && mx<1+TextStringWidth("Slow mode") && my>9 && my<9.5){
					SetPenColor("Red");
					MovePen(1,9);
					DrawTextString("Slow mode");
					
					SetPenColor("Black");
				}
				else if(mx>1 && mx<1+TextStringWidth("OneShot mode") && my>8 && my<8.5){
					SetPenColor("Red");
					MovePen(1,8);
					DrawTextString("OneShot mode");
					
					SetPenColor("Black");
				}
				else if(mx>1 && mx<1+TextStringWidth("Doom mode") && my>7 && my<7.5){
					SetPenColor("Red");
					MovePen(1,7);
					DrawTextString("Doom mode");
					
					SetPenColor("Black");
				}
				else if(mx>1 && mx<1+TextStringWidth("Basic mode") && my>6 && my<6.5){
					SetPenColor("Red");
					MovePen(1,6);
					DrawTextString("Basic mode");
					
					SetPenColor("Black");
				}
				else {
					SetPenColor("Black");
					DrawChallengeMenu(FALSE);
					
					
					SetPenColor("Black");
				}
			}
			
			break;
	//	case BUTTON_UP:
			
		//	break;
			
	}
}


void KeyboardEventProcess(int key,int event){
	if(startGame==playingGame){
		switch (event){
			case KEY_DOWN:
				switch (key){
					case VK_LEFT:
						if(isReverse==FALSE)
				    		characterVelocityX=-MOVEVELOCITY*moveVelocityBoost*levelVelocityAid;
				    	else 
				    		characterVelocityX=MOVEVELOCITY*moveVelocityBoost*levelVelocityAid;
			        	break;
			    	case VK_RIGHT:
			    		if(isReverse==FALSE)
			    			characterVelocityX=MOVEVELOCITY*moveVelocityBoost*levelVelocityAid;
			    		else 
			    			characterVelocityX=-MOVEVELOCITY*moveVelocityBoost*levelVelocityAid;
			        	break;
			    	//case VK_UP:
			    	//	if(canJump){
			    	//		startTimer(JUMPING,1);
			    	//		startTimer(ENDJUMP,100);
			    	//		canJump=FALSE;
			    	//		startTimer(JUMPCD,1000);
					//	}
			        //	break;
			        //case VK_DOWN:
			        //	characterVelocityX=0;
			    	//	break;
						}
					break;
			case KEY_UP:
				switch (key){
					case VK_LEFT:
						if(isReverse==FALSE)
						{
							if(characterVelocityX<0)
							{
								characterVelocityX=0;
							}
						}
						else 
						{
							if(characterVelocityX>0)
							{
								characterVelocityX=0;
							}
						}
						break;
					case VK_RIGHT:
						if(isReverse==FALSE)
						{
							if(characterVelocityX>0)
							{
								characterVelocityX=0;
							}
						}
			    		else
			    		{
			    			if(characterVelocityX<0)
							{
								characterVelocityX=0;
							}
						}
						break;
				}
		
		
			
		}
	}
	
}

void CharEventProcess(char c)
{
	 

     switch (c) {
     	int i=0;
     	case 's':
     		if(startGame==startMenu){
     			/***game setting***/
				level=0;
				levelUpdate();
				
				/***game setting***/
				switch(gameMode){
					case basic:
						break;
					case slowMode:
						moveVelocityBoost=0.75;
						break;
					case oneShotMode:
						//CurrentHP=1;
						break;
					case levelSkippingMode:
						level=50;
						break;
				}
				
				DrawStartMenu(TRUE);
				MovePen(GetWindowWidth()/2,GetWindowHeight()/2); 
    			SummonBlock(CX-0.5,GetWindowHeight()/30,DEFAULT);
    			SummonBlock(CX-0.5,GetWindowHeight()/30,DEFAULT);
				MovePen(GetWindowWidth()/2,GetWindowHeight()/2-3); 
				   
				DrawMan(animeState);
				startTimer(BLOCKGENERATE,generateSpeed);     
				startTimer(MOVETIME,15);
				
				startTimer(LANDTIME,1);
				startTimer(MOVEBLOCK,5);
				startTimer(MENUREFRESH,5);
				startTimer(SPECIALBLOCKANIMATION,250);
				startTimer(ONESECONDEVENT,1000);
				startGame=playingGame;
			}
			break;
		case 'c':
			if(startGame==startMenu){
				DrawChallengeMenu(FALSE);
			}
			break;
		case 'b':
			if(startGame==startMenu){
				ExitGraphics();
			}
			else if(startGame==helpMenu || startGame==challengeMenu){
					DrawChallengeMenu(TRUE);
					DrawHelpMenu(TRUE);
					DrawStartMenu(FALSE);
					startGame=startMenu;
			}
			
			else if(startGame==playingGame){
				die();
				startGame=endGame;
			}
			else if(startGame==endGame){
				initGame();
				
				characterVelocityX=0;
				
				DrawStartMenu(FALSE);
				startGame=startMenu;
			}
			break;
		case 'h':
			if(startGame==startMenu){
				DrawHelpMenu(FALSE);
			}
			break;
        case 'g':
        	if(debugMode==FALSE)
      	 	debugMode=TRUE;
      	 	else {
      	 		debugMode=FALSE;
			   }
      	 	break;
        case 'r':
        	if(startGame==playingGame||startGame==endGame){
				initGame();
				MovePen(GetWindowWidth()/2,GetWindowHeight()/2); 
    			SummonBlock(CX-0.5,GetWindowHeight()/30,DEFAULT);
    			SummonBlock(CX-0.5,GetWindowHeight()/30,DEFAULT);
				MovePen(GetWindowWidth()/2,GetWindowHeight()/2-3.4);  
				characterVelocityX=0;
				DrawMan(animeState);
				startTimer(BLOCKGENERATE,generateSpeed);      
				startTimer(MOVETIME,10);
				startTimer(LANDTIME,1);
				startTimer(MOVEBLOCK,5);
				startTimer(MENUREFRESH,5);
				startTimer(SPECIALBLOCKANIMATION,250);
				startGame=playingGame;
			}
			
			
      		
	 	    break;
		case 'u':
			level+=20;
      		height[7]+=2;
      		levelUpdate();	
			break;	
			
		case 'p':
			if(startGame==playingGame&&pauseIsCoolDown==FALSE)
			{
				if(!isPause)
				{
					PauseTheGame();
					isPause=TRUE;	
				}
				else
				{
					Resume();
					isPause=FALSE;
				}
			}
			
			break;	
			
			/*		
		case 'y':
			isReverse=TRUE;
			characterVelocityX=0;
			isHeal=FALSE;
			startTimer(CLEANSEREVERSE,1000*7);
			reverseTimer=7;
			cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWN);
			cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND);
			specialBlockReverseWordAnimation=10;
			DrawTextAnimation();
			strcpy(SpecialBlockWordDisplay,"REVERSE");
			specialBlockReverseWordAnimation=0;
			startTimer(SPECIALBLOCKANIMATIONCOUNTDOWN,50);
			startTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND,700);
			break;	
		case 't':
			moveVelocityBoost+=0.75;
			isBoost=TRUE;
			isSlow=FALSE;
			startTimer(CLEANSEBOOST,1000*15);
			cancelTimer(CLEANSESLOW);
			slowTimer=0;
			boostTimer=15;
			cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWN);
			cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND);
			specialBlockReverseWordAnimation=10;
			DrawTextAnimation();
			specialBlockReverseWordAnimation=0;
			strcpy(SpecialBlockWordDisplay,"BOOST");
			startTimer(SPECIALBLOCKANIMATIONCOUNTDOWN,50);
			startTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND,700);
			break;
		case 'm':
			moveVelocityBoost-=0.15;
			isBoost=FALSE;
			isSlow=TRUE;
			startTimer(CLEANSESLOW,1000*15);
			cancelTimer(CLEANSEBOOST);
			slowTimer=15;
			boostTimer=0;
			cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWN);
			cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND);
			specialBlockReverseWordAnimation=10;
			DrawTextAnimation();
			specialBlockReverseWordAnimation=0;
			strcpy(SpecialBlockWordDisplay,"SLOW");
			startTimer(SPECIALBLOCKANIMATIONCOUNTDOWN,50);
			startTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND,700);
			break;	
		case 'u':
			DrawBlock_accelerate_right(4,4,3,"Black");	
			*/
		case 'q':
			if(startGame==helpMenu){
					
					DrawHelpMenu(TRUE);
					if(quality==high){
						quality=low;
					}
					else{
						quality=high;
					}
					DrawHelpMenu(FALSE);
					
				}
			else if(quality==high){
						quality=low;
					}
					else{
						quality=high;
					}	
			break;
    }
}

void TimerEventProcess(int timerID){
	double px=CX,py=CY;
	double blockType;
	struct block *blockCount=NULL,*t=NULL;
	static int re=0;
	
	switch(timerID){
	    int i;
	    int x;
		case LANDTIME:
			if(CY<=0.5){
				die();
			}
			else if(CY>=GetWindowHeight()*4/5-BODYSIZE){

				startTimer(DAMAGEGAP,10);
				if(gameMode==oneShotMode){
					die();
				}
				loseHP(4);

				characterVelocityY=-GRAVITYVELOCITY*moveVelocityBoost*levelVelocityAid;
				SetPenColor("White");
				DrawMan(animeState);
				MovePen(CX,GetWindowHeight()*4/5-BODYSIZE-0.1);
				SetPenColor("Black");
				DrawMan(animeState); 
				
				
				
			}
			
			else if(CX-0.3*BODYSIZE<=0){
				SetPenColor("White");
				DrawMan(animeState);
				MovePen(0.01+0.3*BODYSIZE,CY);
				SetPenColor("Black");
				DrawMan(animeState); 
				
			}
			
			else if(CX+0.3*BODYSIZE>=GetWindowWidth()){
				SetPenColor("White");
				DrawMan(animeState);
				MovePen(GetWindowWidth()-0.01-0.3*BODYSIZE,CY);
				SetPenColor("Black");
				DrawMan(animeState); 
				
			}
			
			for(blockCount=headBlock;blockCount->nextBlock!=NULL;blockCount=blockCount->nextBlock){
				if(blockCount->blockPositionX<=CX+0.3*BODYSIZE && blockCount->blockPositionX2>=CX-0.3*BODYSIZE && CY-blockCount->blockPositionY>=-0.08 && CY-blockCount->blockPositionY<=0.08 && blockCount->type!=ORB){
					isLandNumber=1;
					if (animeState>=faceFalling1 && animeState<=faceFalling6){
						SetPenColor("White");
						DrawMan(animeState);
						MovePen(CX,blockCount->blockPositionY);
						SetPenColor("Black");
						animeState=faceForward;
						DrawMan(animeState);
					}
					else {
						
						SetPenColor("White");
						DrawMan(animeState);
						MovePen(CX,blockCount->blockPositionY);
						SetPenColor("Black");
						DrawMan(animeState);	
					}
						switch(blockCount->type){
							case DEFAULT:
								characterVelocityY=speed;
								
								
								break;
							case STING:
								characterVelocityY=speed;
								if(!blockCount->stingTrigger){
									if(gameMode==oneShotMode){
										die();
									}
									loseHP(4);
									
								}
								/*
								if(!blockCount->stingTrigger){
									startTimer(DAMAGED,1);
									startTimer(ENDDAMAGE,30);
								}
								*/
								blockCount->stingTrigger=TRUE;
								break;
							case BOUNCE:
								characterVelocityY=GRAVITYVELOCITY*9*levelVelocityAid;
								
								break;
							case ACCELERATE:
								characterVelocityY=speed;
								if(blockCount->accelDirection==0){
									if(characterVelocityX==0){
										characterVelocityX=-MOVEVELOCITY*0.15;
									}
									else if(characterVelocityX<0 && characterVelocityX!=-MOVEVELOCITY*0.15){
										characterVelocityX=-MOVEVELOCITY*1.25*moveVelocityBoost*levelVelocityAid;
									}
									else if(characterVelocityX>0){
										characterVelocityX=MOVEVELOCITY*0.8*levelVelocityAid;
									}
								}
								else if(blockCount->accelDirection==1){
									if(characterVelocityX==0){
										characterVelocityX=MOVEVELOCITY*0.15;
									}
									else if(characterVelocityX>0 && characterVelocityX!=MOVEVELOCITY*0.15){
										characterVelocityX=MOVEVELOCITY*1.25*moveVelocityBoost*levelVelocityAid;
									}
									else if(characterVelocityX<0){
										characterVelocityX=-MOVEVELOCITY*0.8*levelVelocityAid;
									}
								}
								
								break;
							case REVERSE:
								characterVelocityY=speed;
								if(trapBlock!=blockCount){
									cancelTimer(REVERSETRAP);
									startTimer(REVERSETRAP,250);
								}
								trapBlock=blockCount;
								break;
						 	
						}
						break;
					
				}
				
				else if(blockCount->blockPositionX-length*0.3<=CX&& blockCount->blockPositionX2>=CX && CY>=blockCount->blockPositionY && CY<=blockCount->blockPositionY+BLOCKHEIGHT && blockCount->type==ORB){
					//characterVelocityY=GRAVITYVELOCITY*7.6;
					blockCount->isEliminate=FALSE;
					//free(blockCount);
					switch (blockCount->orbType){
						case HEAL:
							addHP(3);
							cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWN);
							cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND);
							specialBlockReverseWordAnimation=10;
							DrawTextAnimation();
							specialBlockReverseWordAnimation=0;
							strcpy(SpecialBlockWordDisplay,"HEAL");
							startTimer(SPECIALBLOCKANIMATIONCOUNTDOWN,50);
							startTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND,700);
							
							break;
						case ROCKET:
					 		characterVelocityY=GRAVITYVELOCITY*15;
							cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWN);
							cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND);
							specialBlockReverseWordAnimation=10;
							DrawTextAnimation();
							specialBlockReverseWordAnimation=0;
							strcpy(SpecialBlockWordDisplay,"ROCKET");
							startTimer(SPECIALBLOCKANIMATIONCOUNTDOWN,50);
							startTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND,700);
										
							break;
						case BOOSTER:
							if(gameMode!=slowMode){
								moveVelocityBoost=1.35;
							}
							else {
								moveVelocityBoost=1;
							}
							
							isBoost=TRUE;
							isSlow=FALSE;
							startTimer(CLEANSEBOOST,1000*15);
							cancelTimer(CLEANSESLOW);
							slowTimer=0;
							boostTimer=15;
							cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWN);
							cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND);
							specialBlockReverseWordAnimation=10;
							DrawTextAnimation();
							specialBlockReverseWordAnimation=0;
							strcpy(SpecialBlockWordDisplay,"BOOST");
							startTimer(SPECIALBLOCKANIMATIONCOUNTDOWN,50);
							startTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND,700);
										
							break;
						case KEYREVERSE:
							isReverse=TRUE;
							characterVelocityX=0;
							isHeal=FALSE;
							startTimer(CLEANSEREVERSE,1000*7);
							reverseTimer=7;
							cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWN);
							cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND);
							specialBlockReverseWordAnimation=10;
							DrawTextAnimation();
							strcpy(SpecialBlockWordDisplay,"REVERSE");
							specialBlockReverseWordAnimation=0;
							startTimer(SPECIALBLOCKANIMATIONCOUNTDOWN,50);
							startTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND,700);
										
							break;
						case SLOW:
							if(gameMode!=slowMode){
								moveVelocityBoost=0.75;
							}
							else {
								moveVelocityBoost=0.4;
							}
							isBoost=FALSE;
							isSlow=TRUE;
							startTimer(CLEANSESLOW,1000*15);
							cancelTimer(CLEANSEBOOST);
							slowTimer=15;
							boostTimer=0;
							cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWN);
							cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND);
							specialBlockReverseWordAnimation=10;
							DrawTextAnimation();
							specialBlockReverseWordAnimation=0;
							strcpy(SpecialBlockWordDisplay,"SLOW");
							startTimer(SPECIALBLOCKANIMATIONCOUNTDOWN,50);
							startTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND,700);			
							break;
					}
			
				}
				else{
					
					isLandNumber=0;
					
				}
				
			}
			break;
		case MOVETIME:
			if (isLandNumber==0 && characterVelocityY>-GRAVITYVELOCITY*levelVelocityAid){
				characterVelocityY-=GRAVITYVELOCITY*levelVelocityAid;
				if(characterVelocityY<-GRAVITYVELOCITY*levelVelocityAid){
					characterVelocityY=GRAVITYVELOCITY*levelVelocityAid;
				}
						
			}
			SetPenColor("White");

			DrawMan(animeState);
			
			if((animeState<faceFalling1 || animeState>faceFalling5) && characterVelocityY<=-0.8*GRAVITYVELOCITY*levelVelocityAid){   /***/
				
				MovePen(CX+characterVelocityX,CY+characterVelocityY);
				 
				animeState=faceFalling1;
				SetPenColor("Black");
				DrawMan(animeState);
				
			}
			else if(animeState>=faceFalling1 && animeState<=faceFalling5 && characterVelocityY<0){
				bool rev=FALSE;
				MovePen(CX+characterVelocityX,CY+characterVelocityY);
				 
				SetPenColor("Black");
				if(!rev){
					animeState++;
				}
				else if(rev){
					animeState--;
				}
				if(animeState==faceFalling5 || animeState==faceFalling1){
					rev=!rev;
				}
				DrawMan(animeState);
				
			}

			else if((animeState<faceLeft1 || animeState>faceLeft3) && characterVelocityX<-MOVEVELOCITY*0.3*moveVelocityBoost*levelVelocityAid && characterVelocityY>-0.8*GRAVITYVELOCITY*levelVelocityAid){
				
				MovePen(CX+characterVelocityX,CY+characterVelocityY);
				 
				animeState=faceLeft1;
				SetPenColor("Black");
				DrawMan(animeState);	
			}
			else if(animeState>=faceLeft1 && animeState<=faceLeft3 && characterVelocityX<-MOVEVELOCITY*0.3*moveVelocityBoost*levelVelocityAid){
				MovePen(CX+characterVelocityX,CY+characterVelocityY);
				SetPenColor("Black");
				if(animeState<faceLeft3){
					animeState++;
				}
				else if(animeState==faceLeft3){
					animeState=faceLeft1;
				}
				
				DrawMan(animeState);
				
				
			}
			else if((animeState<faceRight1 || animeState>faceRight3) && characterVelocityX>MOVEVELOCITY*0.3*moveVelocityBoost*levelVelocityAid && characterVelocityY>-0.8*GRAVITYVELOCITY*levelVelocityAid){
				
				MovePen(CX+characterVelocityX,CY+characterVelocityY);
				 
				animeState=faceRight1;
				SetPenColor("Black");
				DrawMan(animeState);	
			}
			else if(animeState>=faceRight1 && animeState<=faceRight3 && characterVelocityX>MOVEVELOCITY*0.3*moveVelocityBoost*levelVelocityAid){
				MovePen(CX+characterVelocityX,CY+characterVelocityY);
				SetPenColor("Black");
				if(animeState<faceRight3){
					animeState++;
				}
				else if(animeState==faceRight3){
					animeState=faceRight1;
				}
				
				DrawMan(animeState);
				
				
			}
			
			else if(characterVelocityX==0){
				
				MovePen(CX+characterVelocityX,CY+characterVelocityY);
				
				SetPenColor("Black");
				animeState=faceForward;
				DrawMan(animeState);
				
			}
			else{
				
				MovePen(CX+characterVelocityX,CY+characterVelocityY);
				
				SetPenColor("Black");
				animeState=faceForward;
				DrawMan(animeState);
				
			}
			if(characterVelocityX>-MOVEVELOCITY*0.3 && characterVelocityX<MOVEVELOCITY*0.3*moveVelocityBoost*levelVelocityAid){
				characterVelocityX=0;
			}
			break;
		case MOVEBLOCK:
			for(blockCount=headBlock;blockCount->nextBlock!=NULL;blockCount=blockCount->nextBlock){
				if(blockCount->blockPositionY>=GetWindowHeight()*4/5 || blockCount->isEliminate==FALSE){
					MovePen(blockCount->blockPositionX,blockCount->blockPositionY-BLOCKHEIGHT);
					
						switch(blockCount->type){
							case DEFAULT:
								//DrawBlock_default(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");
								DrawBlock_default(blockCount->blockPositionX+0.1,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");
								blockCount->blockPositionY+=speed;
								break;
							case STING:
								//DrawBlock_Sting(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");
								DrawBlock_Sting(blockCount->blockPositionX+0.1,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");
								blockCount->blockPositionY+=speed;

								break;
							case BOUNCE:
								//DrawBlock_bounce(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");	
								DrawBlock_bounce(blockCount->blockPositionX+0.1,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");
								blockCount->blockPositionY+=speed;

								break;
							case ACCELERATE:
								//DrawBlock_accelerate(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");
								if(blockCount->accelDirection==0)
									DrawBlock_accelerate_left(blockCount->blockPositionX+0.1,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");
								else if (blockCount->accelDirection==1)
									DrawBlock_accelerate_right(blockCount->blockPositionX+0.1,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");
								blockCount->blockPositionY+=speed;
								break;
							case REVERSE:
								//DrawBlock_reverse(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");
								DrawBlock_reverse(blockCount->blockPositionX+0.1,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");	
								blockCount->blockPositionY+=speed;
								break;
							case ORB:
								DrawOrb(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,TRUE);
								//DrawOrb(blockCount->blockPositionX+0.1,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,TRUE);	
								blockCount->blockPositionY+=speed;
								break;
						}
						blockCount->blockPositionY=GetWindowHeight()+10;
						if(blockCount->isEliminate==TRUE){
							t=headBlock;
							headBlock=headBlock->nextBlock;
							free(t);
						}
						
						MovePen(px,py);	
						
				}
				else if(blockCount->blockPositionX!=0 || blockCount->blockPositionY!=0){
						MovePen(blockCount->blockPositionX,blockCount->blockPositionY-BLOCKHEIGHT);
						switch(blockCount->type){
							case DEFAULT:
								DrawBlock_default(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");
								blockCount->blockPositionY+=speed;
								DrawBlock_default(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"Blue");
								break;
							case STING:
								SetPenColor("White");
								DrawBlock_Sting(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");
								blockCount->blockPositionY+=speed;
								DrawBlock_Sting(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"Gray");
								break;
							case BOUNCE:
								DrawBlock_bounce(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");	
								blockCount->blockPositionY+=speed;
								DrawBlock_bounce(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"Yellow");
								break;
							case ACCELERATE:
								DrawBlock_accelerate_left(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");		
								blockCount->blockPositionY+=speed;
								if(blockCount->accelDirection==0)
									DrawBlock_accelerate_left(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"Black");
								else if(blockCount->accelDirection==1)
									DrawBlock_accelerate_right(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"Black");
								break;
							case REVERSE:
								DrawBlock_reverse(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"White");	
								blockCount->blockPositionY+=speed;
								DrawBlock_reverse(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,"Green");
								break;
							case ORB:
								//DrawOrb(blockCount->blockPositionX,blockCount->blockPositionY,length,"Green");
								DrawOrb(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,TRUE);	
								blockCount->blockPositionY+=speed;	
								DrawOrb(blockCount->blockPositionX,blockCount->blockPositionY,blockCount->blockPositionX2-blockCount->blockPositionX,FALSE);
								//DrawOrb_health(blockCount->blockPositionX,blockCount->blockPositionY,length,"White");
								break;
						}
						MovePen(px,py);	
					}	
			}
			break;
		case BLOCKGENERATE:
			if(startGame!=playingGame){
				break;
			}
			blockType=(rand()%100);
			printf("%f\n",blockType);
			
			//x=rand()%((int)GetWindowWidth());
			/*
			if(1){
				SummonBlock(rand()%((int)GetWindowWidth()),GetWindowHeight()/30,ACCELERATE);
				break;
			}
			*/
			
			if(blockType<blockChance[DEFAULT]){

				SummonBlock(rand()%((int)GetWindowWidth()),-1,DEFAULT);
				
				break;
			}
			blockType-=blockChance[DEFAULT];
			if(blockType<blockChance[ACCELERATE]){

				SummonBlock(rand()%((int)GetWindowWidth()),-1,ACCELERATE);
				break;
			}
			blockType-=blockChance[ACCELERATE];
			if(blockType<blockChance[STING]){

				SummonBlock(rand()%((int)GetWindowWidth()),-1,STING);
				break;
			}
			blockType-=blockChance[STING];
			if(blockType<blockChance[REVERSE]){

				SummonBlock(rand()%((int)GetWindowWidth()),-1,REVERSE);
				break;
			}
			blockType-=blockChance[REVERSE];
			if(blockType<blockChance[BOUNCE]){
				SummonBlock(rand()%((int)GetWindowWidth()),-1,BOUNCE);
				break;
			}
			blockType-=blockChance[BOUNCE];
			if(blockType<blockChance[ORB]){
				SummonBlock(rand()%((int)GetWindowWidth()),-1,ORB);
				break;
				
			}
			
			break;
			/*
		case JUMPING:
			SetPenColor("White");
			DrawMan(animeState);;
			MovePen(CX+characterVelocityX,CY+GRAVITYVELOCITY*9);
			
			SetPenColor("Black");
			DrawMan(animeState);
			//characterVelocityX=0;
			break;
		case ENDJUMP:
			cancelTimer(ENDJUMP);
			cancelTimer(JUMPING);
			break;
			*/
		case REVERSETRAP:
			if(trapBlock->blockPositionX<=CX+0.3*BODYSIZE && trapBlock->blockPositionX2>=CX-0.3*BODYSIZE && CY-trapBlock->blockPositionY>=-0.1 && CY-trapBlock->blockPositionY<=0.1){
				SetPenColor("White");
				DrawMan(animeState);;
				MovePen(CX,trapBlock->blockPositionY-0.1);
				
				SetPenColor("Black");
				DrawMan(animeState);
			}
			cancelTimer(REVERSETRAP);
			break;
		case MENUREFRESH: 
		   // printf("%d\n",level);
			if(debugMode==FALSE){
				
				score[8]++;
				for(i=8;i>=0;i--){
						if(score[i]=='9'+1){
							score[i]='0';
							score[i-1]++;
							if(i-1==6){
								level++;
								levelUpdate();
							}
						}
					}
			}
			
			DrawGameMenu();
			if(CurrentHP!=10 && !isHeal){
				isHeal=TRUE;
				startTimer(HPREGENERATE,2000);
			}
			MovePen(px,py);
			break;
		case HPREGENERATE:
			
			if(CurrentHP!=10){
				addHP(1);
			}
			isHeal=FALSE;
			cancelTimer(HPREGENERATE);
			break;
		case SPECIALBLOCKANIMATION:
			specialBlockAnimation++;
			accelerateBlockAnimation++;
			if(specialBlockAnimation>4)
				specialBlockAnimation=specialBlockAnimation-4;
			break;
		case CLEANSEREVERSE:
			isReverse=FALSE;
			characterVelocityX=0;
			cancelTimer(CLEANSEREVERSE);
			break;
		case CLEANSEBOOST:
			isBoost=FALSE;
			if(gameMode!=slowMode){
				moveVelocityBoost=1;
			}
			else {
				moveVelocityBoost=0.55;
			}
			cancelTimer(CLEANSEBOOST);
			break;
		case CLEANSESLOW:
			isSlow=FALSE;
			if(gameMode!=slowMode){
				moveVelocityBoost=1;
			}
			else {
				moveVelocityBoost=0.55;
			}
			cancelTimer(CLEANSESLOW);
			break;
		case SPECIALBLOCKANIMATIONCOUNTDOWN:
			//cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWN);
			DrawTextAnimation();
			specialBlockReverseWordAnimation++;
			break;
		case SPECIALBLOCKANIMATIONCOUNTDOWNEND:
			specialBlockReverseWordAnimation=0;
			cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWN);
			cancelTimer(SPECIALBLOCKANIMATIONCOUNTDOWNEND);
			//DrawReverseAnimation();
			break;

		case ONESECONDEVENT:
			
			if(startGame!=playingGame){
				return;
			}
			re++;
			if(reverseTimer>0){
				reverseTimer--;
			}
			
			if(boostTimer>0){
				boostTimer--;
			}
			if(slowTimer>0){
				slowTimer--;
			}
			if(debugMode==TRUE){
				addHP(10);
			}
			if(re%3==0){
				if(startGame==playingGame)
				{
					MovePen(0,0);
					SetPenColor("White");
					StartFilledRegion(1);
					DrawLine(GetWindowWidth(),0);
					DrawLine(0,GetWindowHeight());
					DrawLine(-GetWindowWidth(),0);
					DrawLine(0,-GetWindowHeight());
					
					EndFilledRegion();
					MovePen(px,py);
					SetPenColor("Black");
				}
			}
			
			break;
		case PAUSECOOLDOWN:
			pauseIsCoolDown=FALSE;
			cancelTimer(PAUSECOOLDOWN);
			break;
			
			

}
}

