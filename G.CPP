#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
int ballx=41,ctr=0,scr1=0,scr2=0,py[2][2]={{12,12},{12,12}};
float spdx=1,spdy=0,bally=12;
char p1[10],p2[10];
void board();
void draw();
void move();
int gamovr();
void hit();
void begin();
void reset();
void end();
void main()
{
 begin();
 _setcursortype(_NOCURSOR);
 while(scr1<10&&scr2<10)
 {
  ctr=1;
  getch();
  board();
  while(gamovr()==0)
  {
   draw();
   move();
   delay(50);
   hit();
  }
  reset();
 }
 end();
}
void draw()
{
 cout<<(char)8<<(char)32;
 for(int i=0;i<=1;i++)
 {
  int j;
  if(i==0)
   j=2;
  else
   j=79;
  if(py[i][1]-py[i][0]==-1)
  {
   gotoxy(j,py[i][0]+2);
   cout<<(char)32;
   gotoxy(j,py[i][0]+1);
   cout<<(char)223;
   gotoxy(j,py[i][0]-2);
   cout<<(char)219;
   gotoxy(j,py[i][0]-3);
   cout<<(char)220;
  }
  if(py[i][1]-py[i][0]==1)
  {
   gotoxy(j,py[i][0]-2);
   cout<<(char)32;
   gotoxy(j,py[i][0]-1);
   cout<<(char)220;
   gotoxy(j,py[i][0]+2);
   cout<<(char)219;
   gotoxy(j,py[i][0]+3);
   cout<<(char)223;
  }
  py[i][0]=py[i][1];
 }
 if(spdx==0.5)
  if(ctr==1)
  {
   gotoxy(ballx,bally);
   cout<<(char)220;
   ctr--;
  }
  else
  {
   gotoxy(ballx,bally);
   cout<<(char)223;
  }
 else
 gotoxy(ballx,bally);
 cout<<(char)254;
}
void move()
{
 char inp;
 int ctr1=0,ctr2=0;
 while(kbhit())
 {
  inp=getch();
  if(inp=='w'&&ctr1==0&&py[0][1]>3)
  {
   py[0][1]--;
   ctr1++;
  }
  if(inp=='s'&&ctr1==0&&py[0][1]<22)
  {
   py[0][1]++;
   ctr1++;
  }
  if(inp=='o'&&ctr2==0&&py[1][1]>3)
  {
   py[1][1]--;
   ctr2++;
  }
  if(inp=='l'&&ctr2==0&&py[1][1]<22)
  {
   py[1][1]++;
   ctr2++;
  }
 }
 ballx+=spdx;
 bally+=spdy;
}
int gamovr()
{
 if(ballx==1)
 {
  scr2++;
  return 2;
 }
 else if(ballx==80)
 {
  scr1++;
 return 1;
 }
 else
 return 0;
}
void hit()
{
 int bally=::bally;
 if (bally<=2||bally>=23)
  spdy=0-spdy;
 if(ballx==3)
 {
  if(bally==py[0][1]-2)
  {
   spdy=-1;
   spdx=0-spdx;
  }
  else if(bally==py[0][1]-1)
   {
    spdy=-(1.0/2);
    spdx=0-spdx;
   }
  else if(bally==py[0][1])
  {
   spdy=0;
   spdx=0-spdx;
  }
  else if(bally==py[0][1]+1)
  {
   spdy=(1.0/2);
   spdx=0-spdx;
  }
  else if(bally==py[0][1]+2)
  {
   spdy=1;
   spdx=0-spdx;
  }
 }
 if(ballx==78)
 {
  if(bally==py[1][1]-2)
  {
   spdy=-1;
   spdx=0-spdx;
  }
  else if(bally==py[1][1]-1)
  {
   spdy=-1.0/2;
   spdx=0-spdx;
  }
  else if(bally==py[1][1])
  {
   spdy=0;
   spdx=0-spdx;
  }
  else if(bally==py[1][1]+1)
  {
   spdy=1.0/2;
   spdx=0-spdx;
  }
  else if(bally==py[1][1]+2)
  {
   spdy=1;
   spdx=0-spdx;
  }
 }
}
void begin()
{
 textmode(BW80);
 clrscr();
 cout<<"Get ready to play ping pong";
 delay(1000);
  getch();
 clrscr();
 cout<<"Player 1 enter your name:";
 cin>>p1;
 clrscr();
 cout<<"Player 2 enter your name:";
 cin>>p2;
 clrscr();
 gotoxy(28,12);
 for(int l=0;l<10;l++)
  if(p1[l]!=0)
   cout<<p1[l];
  else
   break;
 delay(700);
 cout<<" VS ";
 delay(700);
 for(l=0;l<10;l++)
  if(p2[l]!=0)
   cout<<p2[l];
  else
   break;
 delay(700);
 textmode(BW40);
 textcolor(BLACK);
 textbackground(WHITE);
 clrscr();
 gotoxy(17,8);
 cout<<"SHOWDOWN";
 delay(1000);
 textmode(BW80);
 textcolor(BLACK);
 textbackground(WHITE);
 clrscr();
}
void reset()
{
 if(gamovr()==2)
 {
  ballx=40;
  spdx=-1;
 }
 else
 {
  ballx=41;
  spdx=1;
 }
 bally=12;
 py[0][1]=12;
 py[1][1]=12;
 spdy=0;
}
void end()
{
 clrscr();
 int i=0;
 gotoxy(29,12);
 if(scr1>scr2)
  for(int l=0;l<10;l++)
  if(p1[l]!=0)
   cout<<p1[l];
  else
   break;
 else
  for(int l=0;l<10;l++)
  if(p2[l]!=0)
   cout<<p2[l];
  else
   break;
 cout<<" Won the game";
 getch();
}
void board()
{
 clrscr();
 gotoxy(12,25);
 for(int l=0;l<10;l++)
  if(p1[l]!=0)
   cout<<p1[l];
  else
   break;
 cout<<':'<<scr1/2;
 gotoxy(52,25);
 for(l=0;l<10;l++)
 if(p2[l]!=0)
  cout<<p2[l];
 else
  break;
 cout<<':'<<scr2/2;
 gotoxy(1,1);
 for(int i=1;i<=80;i++)
  cout<<(char)193;
 for(i=2;i<=23;i++)
 {
  gotoxy(40,i);
  cout<<(char)176<<(char)176;
 }
 gotoxy(1,24);
 for(i=1;i<=80;i++)
  cout<<(char)194;
 for(i=2;i<=79;i+=77)
 {
  gotoxy(i,10);
  cout<<(char)220;
  for(int j=11;j<=13;j++)
  {
   gotoxy(i,j);
   cout<<(char)219;
  }
  gotoxy(i,14);
  cout<<(char)223;
 }
}