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

#include "setting.h"
#include "summon.h"
#include "object.h"
#include "menu.h"
#include "HPSystem.h"
#include "record.h"


void SummonBlock(double x, double y,MODE mode){
	double px=CX,py=CY;
	MovePen(x,y);
	if (mode== DEFAULT){
		DrawBlock_default(x,y,length,"Blue");
		setBlockInf(x,y,mode);
	} 
	
	else if (mode== STING){
		DrawBlock_Sting(x,y,length,"Gray");
		setBlockInf(x,y,mode);
	}
	
	else if (mode== BOUNCE){
		DrawBlock_bounce(x,y,length,"Yellow");
		setBlockInf(x,y,mode);
	}
	else if (mode==ACCELERATE){
		setBlockInf(x,y,mode);
		if(b->accelDirection==0) 
			DrawBlock_accelerate_left(x,y,length,"Black");
		else if(b->accelDirection==1) 
			DrawBlock_accelerate_right(x,y,length,"Black");
	}
	else if (mode==REVERSE){
		DrawBlock_reverse(x,y,length,"Green");
		setBlockInf(x,y,mode);
	}
	else if (mode==ORB){
		DrawOrb(x,y,length*0.3,FALSE);
		setBlockInf(x,y,mode);
		
		
		
	}
	MovePen(px,py);
	
}

void setBlockInf(double x, double y,MODE mode){
	
	if (b==NULL){
		b=(struct block *)malloc(sizeof(struct block));
		headBlock=b;
		b->nextBlock=NULL;
	}
	else {
		b->nextBlock=(struct block *)malloc(sizeof(struct block));
		b=b->nextBlock;
		b->nextBlock=NULL;
	}
		if(mode==ORB){
			int orbType=rand()%5;
			//0int orbType=1;
			//printf("spwan %d\n",orbType);
			b->blockPositionX=x;
			b->blockPositionX2=x+length*0.3;
			b->blockPositionY=y;
			b->type=mode;
			b->orbType=orbType;
		}

		else {
			b->blockPositionX=x;
			b->blockPositionX2=x+length;
			b->blockPositionY=y+BLOCKHEIGHT;
			b->type=mode;
		}
		
		b->stingTrigger=FALSE;
		b->accelDirection=rand()%2;
		b->isEliminate=TRUE;
		
			
}
