#ifndef _object_h
#define _object_h




void DrawMan(int animeState);
void DrawMan_forward();
void DrawMan_left1();
void DrawMan_left2();
void DrawMan_left3();
void DrawMan_left4();
void DrawMan_left5();
void DrawMan_right1();
void DrawMan_right2();
void DrawMan_right3();
void DrawMan_right4();
void DrawMan_right5();
void DrawMan_falling1();
void DrawMan_falling2();
void DrawMan_falling3();
void DrawMan_falling4();
void DrawMan_falling5();
void DrawMan_falling6();
void DrawBlock_Sting(double x,double y,double BlockSize,string Color); 
void DrawBlock_default(double x,double y,double BlockSize,string Color);
void DrawBlock_bounce(double x,double y,double BlockSize,string Color); 
void DrawBlock_accelerate_left(double x,double y,double BlockSize,string Color);
void DrawBlock_accelerate_left1(double x,double y,double BlockSize,string Color);
void DrawBlock_accelerate_left2(double x,double y,double BlockSize,string Color);
void DrawBlock_accelerate_right(double x,double y,double BlockSize,string Color);
void DrawBlock_accelerate_right1(double x,double y,double BlockSize,string Color);
void DrawBlock_accelerate_right2(double x,double y,double BlockSize,string Color);
void DrawBlock_reverse(double x,double y,double BlockSize,string Color);
void DrawOrb(double x,double y,double BlockSize,bool isClear);
void DrawOrb_anime1(double x,double y,double BlockSize);
void DrawOrb_erase(double x,double y,double BlockSize);
void DrawOrb_anime2(double x,double y,double BlockSize);
void DrawOrb_anime3(double x,double y,double BlockSize);
void DrawOrb_anime4(double x,double y,double BlockSize); 


#endif
