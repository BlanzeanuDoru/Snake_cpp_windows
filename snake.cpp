#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define LENGHT 20
#define WIDTH  40
#define X LENGHT/2
#define Y WIDTH/2

#include "worm.h"
#include "worm.cpp"

worm snake(X,0,RIGHT,1);

struct fo
{
	int x;
	int y;
}foo;

int ** init(int m,int n)
{
	int **a,i;
	
	a=(int**)malloc(m*sizeof(int*));	
	for(i=0 ; i<m ; i++)
	  a[i]=(int*)calloc(n,sizeof(int));
	  
	return a;
}


bool eatfood()
{
	if( snake.GetX(0)==foo.x && snake.GetY(0)==foo.y )
	 {
	 	return true;
	 }
	 return false;
}

void ini1(int **a,int x,int y)
{
	int i,j;
	for(i=0;i<LENGHT;i++)
	 for(j=0;j<WIDTH;j++)
	  a[i][j]=0;
	
	a[x][y]=2;  //capul
	
	
	for(i=1;i<snake.GetBody();i++)
	  {
	  	a[snake.GetX(i)][snake.GetY(i)]=1;
	  }
}


void food(int **a,struct fo * foo)
{
	int i,v=0;
	
	foo->x=rand()%(LENGHT-1) +1;
	foo->y=rand()%(WIDTH-1)  +1;
	for(i=0;i<snake.GetBody();i++)
	  {
	  	if(snake.GetX(i)==foo->x && snake.GetY(i)==foo->y)
	  	 {
	  	 	foo->x=rand()%(LENGHT-1) +1;
	        foo->y=rand()%(WIDTH-1)  +1;
	        i=-1;
	  	 }
	  }
	a[foo->x][foo->y]=-1;
}

void cond(int **a,int i,int j)
{
	
	if(i==0 || i==LENGHT-1 || j==0 || j==WIDTH-1)
	  	  	           printf("0");
	else 
	  {
		if(a[i][j]==2)
	  	   printf("+");   // cap
	  	else if(a[i][j]==-1)
	  	   printf("$");   // mancare
	  	else if(a[i][j]==1)
	  	   printf("*");   //corp
	  	else printf(" ");
	  }
}

void move()
{	
     int i;
     
     for(i=snake.GetBody()-1;i>0 ;i--)
	     {
		   snake.SetX( snake.GetX(i-1) , i );
		   snake.SetY( snake.GetY(i-1) , i );
	     }
     
	 if(snake.GetDir() == RIGHT)
	 {
	 	if(snake.GetY(0)==WIDTH-1)
	 	   {
	 	   	snake.SetY(1,0);
	 	   }
	 	else
	 	snake.SetY(snake.GetY(0)+1 , 0);
	 }
	  
	else if(snake.GetDir() == LEFT)
	 {
	 	if(snake.GetY(0)==1)
	 	   {
	 	   	snake.SetY(WIDTH-2,0);
	 	   }
	 	else
	 	snake.SetY(snake.GetY(0)-1 , 0);
	 }
	 
	else if(snake.GetDir() == UP)
	 {
	 	if(snake.GetX(0)==1)
	 	   {
	 	   	snake.SetX(LENGHT-2,0);
	 	   }
	 	else
	 	snake.SetX(snake.GetX(0)-1 , 0);
	 }
	 
	else if(snake.GetDir() == DOWN)
	 {
	 	if(snake.GetX(0)==LENGHT-2)
	 	   {
	 	   	snake.SetX(1,0);
	 	   }
	 	else
	 	snake.SetX(snake.GetX(0)+1 , 0);
	 }
	 
}

void init2()
{
	int i;
	if(eatfood()==true)
	 {
	 	snake.SetBody(snake.GetBody()+1);
	for(i=snake.GetBody()-1;i>0 ;i--)
	     {
		   snake.SetX( snake.GetX(i-1) , i );
		   snake.SetY( snake.GetY(i-1) , i );
	     }
     }
}

bool die()
{
	int i;
	for(i=1;i<snake.GetBody();i++)
	  {
	  	if(snake.GetX(0)==snake.GetX(i) && snake.GetY(0)==snake.GetY(i) && i!=1)
	  	  {
	  	  	return true;
	  	  }
	  }
	  return false;
}

void direct()
{
	if( GetAsyncKeyState( VK_UP ) & 0x8000 )
	 snake.SetDir(UP);
	if( GetAsyncKeyState( VK_DOWN ) & 0x8000 )
	snake.SetDir(DOWN);
	if( GetAsyncKeyState( VK_RIGHT ) & 0x8000 )
	snake.SetDir(RIGHT);
	if( GetAsyncKeyState( VK_LEFT ) & 0x8000 )
	snake.SetDir(LEFT);
}

void score(int *sc,char *nume)
{
	printf("\n  SCORE: %d                     NUME:%s\n",*sc,nume);
	printf("___________________________________________\n");
}

void entry(char *nume)
{
	printf("\n\n\n\n\t\t   Introduceti numele dumneavoastra:");
	fflush(stdin);
	gets(nume);
	getch();
	system("PAUSE");
	system("cls");
}

void clasament(int *sc,char *nume)
{
	FILE *fp;
	fp=fopen("Clasament.txt","at+");
	if(fp==NULL) printf("a");
	fprintf(fp,"NUME: %s\nSCORE: %d\n______________________\n",nume,*sc);
	fclose(fp);
}

void reguli()
{
	printf("\n\n\n\n\n\n\n");
	printf("\tAcesta este jocul Snake!\n\tFolositi sagetile pentru a da comenzi!\n\tDaca apasati o sageata opusa directiei de mers veti pierde\n\tBafta la joc!!\n");
    getch();
    system("PAUSE");
	system("cls");	
}

void afis(int **a)
{
	int i,j,f=0,sc=-1;
	char nume[20];
	reguli();
	entry(nume);
	while(1)
	{
	  ini1(a,snake.GetX(0),snake.GetY(0));
	  if(die()==true)
	    {
	    	printf("\n\n\n\t\tGAME OVER! Scorul tau este:%d\n\n\t\t Te mai asteptam %s",sc,nume);
	    	break;
	    }
	  score(&sc,nume);
	  printf("\n");
	  if(f==0)
	     {
	     	food(a,&foo);
	     	f=1;
	     	sc++;
	     }
	    else a[foo.x][foo.y]=-1;
	for(i=0;i<LENGHT;i++)
	  {
	  	for(j=0;j<WIDTH;j++)
	  	  {
	  	  	  cond(a,i,j);
		 }
		 printf("\n");
	  }
	  direct();
	  move();
	  init2(); 
	  if(eatfood()==true)
	   f=0;
	  system("cls");
    }
    clasament(&sc,nume);
    free(a);
}

int main()
{
	int **a;
	a=init(LENGHT,WIDTH);	
	afis(a);
	
	return 0;
}
