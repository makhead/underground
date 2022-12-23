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

void DrawHpBar()
{
	double initX,initY;
	initX=CX;
	initY=CY;
	SetPenColor("White");
	MovePen(0.75,GetWindowHeight()-0.65);
	SetPointSize(15);
	SetPenColor("White");
	DrawTextString("HP");
	StartFilledRegion(1);
	
	MovePen(HPBarPosition,GetWindowHeight()-0.5);
	DrawLine(HP*HPOneBarLength,0);
	DrawLine(0,-HPBarHeight);
	DrawLine(-HP*HPOneBarLength,0);
	DrawLine(0,HPBarHeight);
	EndFilledRegion();
	
	/*
	SetPenColor("Black");
	StartFilledRegion(1);
	MovePen(0,GetWindowHeight());
	DrawLine(GetWindowWidth(),0);
	DrawLine(0,-GetWindowHeight()/5);
	DrawLine(-GetWindowWidth(),0);
	DrawLine(0,GetWindowHeight()/5);
	EndFilledRegion();
	*/
	
	
	
	
	if(CurrentHP>0)
	{
		SetPenColor("Yellow");
		StartFilledRegion(1);
		MovePen(HPBarPosition,GetWindowHeight()-0.5);
		DrawLine(CurrentHP*HPOneBarLength,0);
		DrawLine(0,-HPBarHeight);
		DrawLine(-CurrentHP*HPOneBarLength,0);
		DrawLine(0,HPBarHeight);
		EndFilledRegion();
		SetPenColor("Red");
		MovePen(HPBarPosition,GetWindowHeight()-0.5);
		DrawLine(HP*HPOneBarLength,0);
		DrawLine(0,-HPBarHeight);
		DrawLine(-HP*HPOneBarLength,0);
		DrawLine(0,HPBarHeight);
	}
	else
	{
		SetPenColor("Red");
		MovePen(HPBarPosition,GetWindowHeight()-0.5);
		DrawLine(HP*HPOneBarLength,0);
		DrawLine(0,-HPBarHeight);
		DrawLine(-HP*HPOneBarLength,0);
		DrawLine(0,HPBarHeight);
	}
	
	int i;
	for(i=1;i<HP;i++)
	{
		MovePen(HPBarPosition+i*HPOneBarLength,GetWindowHeight()-0.5);
		DrawLine(0,-HPBarHeight);
	}
	
	if(isReverse==TRUE){
		MovePen(0.75,GetWindowHeight()-0.9);
		SetPointSize(15);
		SetPenColor("White");
		DrawTextString("rev");
		MovePen(HPBarPosition,GetWindowHeight()-0.75);
		StartFilledRegion(1);
		SetPenColor("Green");
		DrawLine(reverseTimer*1.75*HPOneBarLength,0);
		DrawLine(0,-HPBarHeight);
		DrawLine(-reverseTimer*1.75*HPOneBarLength,0);
		DrawLine(0,HPBarHeight);
		EndFilledRegion();
	}
	if(isBoost==TRUE){
		MovePen(0.35,GetWindowHeight()-1.165);
		SetPointSize(15);
		SetPenColor("White");
		DrawTextString("BOOST");
		
		MovePen(HPBarPosition,GetWindowHeight()-1);
		StartFilledRegion(1);
		SetPenColor("Red");
		DrawLine(boostTimer*HPOneBarLength,0);
		DrawLine(0,-HPBarHeight);
		DrawLine(-boostTimer*HPOneBarLength,0);
		DrawLine(0,HPBarHeight);
		EndFilledRegion();
	}
	if(isSlow==TRUE){
		MovePen(0.35,GetWindowHeight()-1.165);
		SetPointSize(15);
		SetPenColor("White");
		DrawTextString("SLOW");
		
		MovePen(HPBarPosition,GetWindowHeight()-1);
		StartFilledRegion(1);
		SetPenColor("Red");
		DrawLine(slowTimer*HPOneBarLength,0);
		DrawLine(0,-HPBarHeight);
		DrawLine(-slowTimer*HPOneBarLength,0);
		DrawLine(0,HPBarHeight);
		EndFilledRegion();
	}
	
	
	
	MovePen(initX,initY);
}
void loseHP(int hp)
{
	CurrentHP=CurrentHP-hp;
	if(CurrentHP<=0)
		CurrentHP=0;
	
}
void addHP(int hp)
{
	if(CurrentHP+hp<=HP){
		CurrentHP+=hp;
	}
	else {
		CurrentHP=10;
	}
	
	
}

void die()
{
	startGame=endGame;
	int i;
	for(i=1;i<17;i++)
		cancelTimer(i);
	DrawEndMenu(score);
}




















