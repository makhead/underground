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


double characterVelocityX=0;									//velocity of character
double characterVelocityY=-GRAVITYVELOCITY;	
double moveVelocityBoost=1;
double levelVelocityAid=1;

int isLandNumber=0;												//determind if player is landing
bool damageScreen=FALSE;										//determind if player view is red
int CurrentHP=10;												//show player current hp
bool isHeal=FALSE;												//determind if player is heal
bool isDamage=FALSE;											//determind if player is damaging
int reverseTimer=0;
int boostTimer=0;
int slowTimer=0;

double speed=0;													//the speed of block
int generateSpeed=0;											//the gap between generate
double blockChance[6]={0,0,0,0,0,0};								//the chance spawn block respectively
//int trapNumber=0;												//the number of block player trigger

bool isPause=FALSE;
bool debugMode=FALSE;											//enable to use special move
char score[10]={'0','0','0','0','0','0','0','0','0','\0'};
char height[10]={'0','0','0','0','0','0','0','0','0','\0'};
char *defaultBlockColor[7]={"Sky Blue","Mid Blue","Light Blue","Lightest Blue","Light Blue","Mid Blue","Sky Blue"};
char *reverseBlockColor[5]={"Dark Gray","Gray","Light Gray","Gray","Dark Gray"};
char *specialBlockWordDisplayAnimation[11]={"Black","BlackToWhite1","BlackToWhite2","BlackToWhite3","BlackToWhite4","BlackToWhite5","BlackToWhite6","BlackToWhite7","BlackToWhite8","BlackToWhite9","White"};

LEVEL level=0;				  								
double length=0;
bool isReverse=FALSE;									//a value the distingulish whether the character is in the reverse mode or not
int specialBlockReverseWordAnimation=0;							//a value to accomplish the special block word Display animation
int specialBlockAnimation=0;
int accelerateBlockAnimation=0;
char SpecialBlockWordDisplay[20];
bool isBoost=FALSE;
bool isSlow=FALSE;
bool pauseIsCoolDown=FALSE;

struct block *b=NULL;
struct block *headBlock=NULL;
struct block *trapBlock=NULL;

