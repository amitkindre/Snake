/*********************
Author: Amit Kindre
Input keys - 'w','a','s','d'
Output - None
*********************/


#include<windows.h>
#include<stdio.h>

#define Y_MAX 45
#define X_MAX 70

void gotoxy(short x,short y);
void moveSnk();
void pstr(char*);
void delay();

typedef struct coord
{
	short x;
	short y;
}coord;

coord coordArr[100] = {{0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8},{0,9}};
coord newCoord;
int snklen = 3;
int cflag;
enum {left,right,up,down} direction;
void main()
{
	direction = right;
	int i;
	char key;
	printf("\n\n\t\tUse 'w' 'a' 's' 'd' keys to navigate");
	printf("\n\n\n\t\t\t");
	pstr("Loading..................");

	while(1)
	{
		if(kbhit())
		{
			key = getch();
			switch(key)
			{
				case 'w':
					direction = up;
					break;
					
				case 'a':
					direction = left;
					break;
					
				case 's':
					direction = down;
					break;
					
				case 'd':
					direction = right;
					break;
				default :
				//	system("exit");
				//	return;
					break;
			}
		}	
		switch(direction)
		{
			case left:
				if(coordArr[snklen].x > 0) 
				{
					moveSnk();
					coordArr[snklen].x--;
				}
				else
				{
					coordArr[snklen].x = X_MAX;
				}
				break;
			
			case right:
				if(coordArr[snklen].x < X_MAX)
				{
					moveSnk();
					coordArr[snklen].x++;
				}
				else
				{
					coordArr[snklen].x = 0;
				}
				
				break;
			
			case up:
				
				if(coordArr[snklen].y > 0)
				{
					moveSnk();
					coordArr[snklen].y--;
				}
				else
				{
					coordArr[snklen].y = Y_MAX;
				}
				break;
			
			case down:
				if(coordArr[snklen].y < Y_MAX)
				{
					moveSnk();
					coordArr[snklen].y++;
				} 
				else
				{
					coordArr[snklen].y = 0;
				}
				break;
		}
		system("cls");
		if(coordArr[snklen].x == newCoord.x && coordArr[i].y == newCoord.y)
		{
			snklen++;
			coordArr[snklen].x = newCoord.x;
			coordArr[snklen].y = newCoord.y;
			cflag = 0;
		}
		for(i = 0; i < snklen; i++)
		{
			gotoxy(coordArr[i].x,coordArr[i].y);
			printf("*");
			
		}
		//to gene
		gotoxy(newCoord.x,newCoord.y);
		printf("*");
		if(!cflag)
		{
			newCoord.x = rand() % X_MAX;
			newCoord.y = rand() % Y_MAX;
			cflag = 1;
		}
		
		delay();
	}
}



void moveSnk()
{
	int i;
	for(i = 0; i < snklen; i++)
	{
		coordArr[i] = coordArr[i+1];
	}
	return;
}


void gotoxy(short x,short y)		//Set Cursor Position on Display Screen
{
	COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);	
}

void pstr(char *str) 
{
	while(*str)
	{
		printf("%c",*str);
		str++;
		delay();
	}			
}

void delay()
{
	int i,j;
	for(i = 0; i < 5000; i ++)
		for(j = 0; j < 10000; j++);
}
