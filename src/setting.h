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

#ifndef _setting_h
#define _setting_h

//player status related
#define BODYSIZE (0.5)									//the size of character
#define MOVEVELOCITY (0.099)							//the velocity when character moving in x direction
#define GRAVITYVELOCITY (0.045)							//how the gravity affect character
#define HPOneBarLength (0.15) 							// the length of HP bar
#define HPBarHeight (0.2) 								// the height of HP bar
#define HP (10) 										// the hp that the main character has
#define HPBarPosition (1.05)
extern double characterVelocityX;						//velocity of character
extern double characterVelocityY;	
extern double moveVelocityBoost;						//the coefficient of the boost velocity
extern double levelVelocityAid;							//all velocity change due to level

extern int isLandNumber;								//determind if player is landing
extern bool damageScreen;								//determind if player view is red
extern int CurrentHP;									//show player current hp
extern bool isHeal;										//determind if player is heal
extern bool isDamage;									//determind if player is damaging
extern bool isReverse; 									//a value the distingulish whether the character is in the reverse mode or not
extern int reverseTimer;
extern bool isBoost;									//determine if player is boosting
extern int boostTimer;
extern bool isSlow;										//determine if player is slowing
extern int slowTimer;

enum {
	faceLeft1,
	faceLeft2,
	faceLeft3,
	//faceLeft4,
	//faceLeft5,
	faceRight1,
	faceRight2,
	faceRight3,
	//faceRight4,
	//faceRight5,
	faceForward,
	faceFalling1,
	faceFalling2,
	faceFalling3,
	faceFalling4,
	faceFalling5,
	faceFalling6,
}animeState ;

enum{
	high,
	low,
}quality;


//pen position related
#define CX (GetCurrentX())								//position of pen 
#define CY (GetCurrentY())								//position of pen

//time event related
#define LANDTIME (1)									//on landing
#define MOVETIME (2)									//place the character base on velocity
#define MOVEBLOCK (3)									//move the block
#define BLOCKGENERATE (4)								//time that generate the new block
#define DAMAGED (5)										//time that turn screen into red
#define ENDDAMAGE (6)									//end DAMAGED
#define JUMPING (7)										//jumping movement
#define ENDJUMP (8)										//end jump
#define REVERSETRAP (9)									//time of reverse block
#define MENUREFRESH (10) 								//refreshing game menu
#define HPREGENERATE (11)								//HP regeneration 
#define DAMAGEGAP (12)									//the time player wont hurt
#define SPECIALBLOCKANIMATION (13)						//the animation of turning the special block
#define CLEANSEREVERSE (14)							//the time that count how many time the special block REVERSE left
#define SPECIALBLOCKANIMATIONCOUNTDOWN (15)				//the animation of the word display of the special block name in the menu
#define SPECIALBLOCKANIMATIONCOUNTDOWNEND (16)
#define ONESECONDEVENT (17)
#define CLEANSEBOOST (18)							//the time that count how many time the BOOST left
#define CLEANSESLOW (19)							//the time that count how many time the SLOW left
#define PAUSECOOLDOWN (20)


//game difficulty related


typedef int LEVEL;										//difficulty
extern LEVEL level;										//show the current level


//menu
#define endMenuLength (6)
#define endMenuHeight (6)
extern char *specialBlockWordDisplayAnimation[11];
//PauseAnimation
#define PauseAnimationLength (0.5)                      //the length of pause sign -> ||
#define PauseAnimationHeight (2)						//the height of pause sign -> || 
#define ResumeAnimationLength (2)                      //the length of resume sign -> ||
#define ResumeAnimationHeight (2)						//the height of resume sign -> || 


//block setting related
#define DEFAULT (0)										//block setting:noraml
#define ACCELERATE (1)									//block that can accelerate
#define STING (2)										//block with sting
#define REVERSE (3)										//block that reverse
#define BOUNCE	(4)										//block that can jump
#define ORB (5)											//orb that is special type
#define BLOCKHEIGHT (0.15)								//the height of block
typedef int MODE ;										//block setting
struct block {											//record the position of the block
	double blockPositionX;								//start position
	double blockPositionX2;								//end position
	double blockPositionY;								//Y position
	bool stingTrigger;							        //**STING blcok only** determind if the block is triggered already	
	int accelDirection;									//**ACCELERATE block only** determind the direction it accelerate,1 for right and 0 for left						
	int type;											//state the type
	int orbType;										//**ORB onlt** state orb type
	bool isEliminate;									//determine if the block should exist
	struct block *nextBlock;
	
}*b,*headBlock,*trapBlock;
extern double speed;									//the speed of block
extern int generateSpeed;								//the gap between generate
extern double blockChance[6];							//the chance spawn block respectively
//extern int trapNumber;									//the number of block player trigger
extern double length;
enum{
	HEAL=0,
	ROCKET=1,
	BOOSTER=2,
	KEYREVERSE=3,
	SLOW=4,
}o;


//game setting related
enum 
{
	startMenu,
	helpMenu,
	challengeMenu,
	playingGame,
	endGame,	
}startGame;												//determind if the game started
enum
{	
	basic,
	slowMode,
	oneShotMode,
	levelSkippingMode,
}gameMode; 
												
extern char score[10];									//the score 	
extern char height[10];									//same as the level
extern bool isPause;
extern bool debugMode;									//enable to use special move
extern char *defaultBlockColor[7];
extern char *reverseBlockColor[5];
extern bool pauseIsCoolDown;

extern int specialBlockReverseWordAnimation;
extern int specialBlockAnimation;
extern int accelerateBlockAnimation;
extern char SpecialBlockWordDisplay[20];
#endif
