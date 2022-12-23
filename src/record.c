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

void addRecord()
{
	FILE *fp;   
	int i;
	fpos_t position; 
	char record1[10],record2[10],record3[10],record4[10];
	
	fp=fopen("record.txt","a+");
	fprintf(fp,"%s\n",score);
	fclose(fp);
	
	fp=fopen("rank.txt","r+");
	
	if(fp==NULL){
		fp=fopen("rank.txt","w");
		fprintf(fp,"%s\n",score);
		fprintf(fp,"%s\n","000000000");
		fprintf(fp,"%s\n","000000000");
		fprintf(fp,"%s\n","000000000");
		fclose(fp);
		return;
	}
	
	fscanf(fp,"%s\n",record1);
	fscanf(fp,"%s\n",record2);
	fscanf(fp,"%s\n",record3);
	fscanf(fp,"%s\n",record4);
	if(strcmp(score,record1)>0){
		rewind(fp);
		fprintf(fp,"%s\n",score);
		fprintf(fp,"%s\n",record1);
		fprintf(fp,"%s\n",record2);
		fprintf(fp,"%s\n",record3);
	}
	else if(strcmp(score,record2)>0){
		rewind(fp);
		fprintf(fp,"%s\n",record1);
		fprintf(fp,"%s\n",score);
		fprintf(fp,"%s\n",record2);
		fprintf(fp,"%s\n",record3);
	}
	else if(strcmp(score,record3)>0){
		rewind(fp);
		fprintf(fp,"%s\n",record1);
		fprintf(fp,"%s\n",record2);
		fprintf(fp,"%s\n",score);
		fprintf(fp,"%s\n",record3);
	}
	else if(strcmp(score,record4)>0){
		rewind(fp);
		fprintf(fp,"%s\n",record1);
		fprintf(fp,"%s\n",record2);
		fprintf(fp,"%s\n",record3);
		fprintf(fp,"%s\n",score);
	}
	else{
		rewind(fp);
		fprintf(fp,"%s\n",record1);
		fprintf(fp,"%s\n",record2);
		fprintf(fp,"%s\n",record3);
		fprintf(fp,"%s\n",record4);
	}
	
	fclose(fp);
	

	
}

	
	


void getRecord(int rank)
{
	FILE *fp;   
	int i=0;
	char record[10];  
	fp=fopen("rank.txt","r");
	for(i=0;i<rank;i++){
		fscanf(fp,"%s\n",record);
	}
	DrawTextString(record);
	//printf("%s\n",record);
	fclose(fp);
	
}

		/*
		if(strcmp(score,max1)>0)
		{
			strcpy(max4,max3);
			strcpy(max3,max2);
			strcpy(max2,max1);
			strcpy(max1,score);

		}
		else if(strcmp(score,max2)>0)
		{
			strcpy(max4,max3);
			strcpy(max3,max2);
			strcpy(max2,score);
		}
		else if(strcmp(score,max3)>0)
		{
			strcpy(max4,max3);
			strcpy(max3,score);
		}
		else if(strcmp(score,max4)>0)
		{
			strcpy(max4,score);
		}
		*/
		
		
		/*
		else if(temp<min)
			min=temp;
	
	
	
	
	if(i<4)
	{
		switch(i)
		{
			case 3:
				max4=-1;
				break;
			case 2:
				max4=-1;
				max3=-1;
				break;
			case 1:
				max4=-1;
				max3=-1;
				max2=-1;
				break;
		}
	}
	*/









