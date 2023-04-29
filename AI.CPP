#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <string.h>
#include <math.h>
class ttt
{
  int xmax,ymax,p;
  char arr[10],as[7],bs[7];
  char txt[80];
  char a[80];
  char ch;
  int gmode,errorcode,gdriver;
  public:
  ttt()
  {
    bs[0]=bs[1]=bs[2]=bs[3]=bs[4]=bs[5]=bs[6]='\0';
    as[0]=as[1]=as[2]=as[3]=as[4]=as[5]=as[6]='\0';
    arr[0]=arr[1]=arr[2]=arr[3]=arr[4]=arr[5]=arr[6]=arr[7]=arr[8]=arr[9]='\0';
    p=0;
    gdriver=DETECT;
    gmode=0,errorcode=0;
    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
    errorcode=graphresult();
    if(errorcode!=grOk)
    {
      printf("Graphics error : %s\n",grapherrormsg(errorcode));
      printf("Press any key to exit\n");
      getch();
      exit(0);
    }
    xmax=getmaxx();
    ymax=getmaxy();
    setfillstyle(1,7);
    setcolor(RED);
  }
  int winner(char *);
  int winnermove(char,char *);
  int winner2(char,char *);
  int winnerpossibility2();
  int checkenter(char);
  void placemark(char,int);
  void input();
  int winningmove();
  int stopwinner();
  void detail();
  void box();
  int any();
  void anyeven();
  void anyodd();
  void play();
  ~ttt()
  {
  }
};
void ttt::detail()
{
  printf("Input your name player \n");
  scanf("%[^\n]",a);
  fflush(stdin);
  clrscr();
  a[0]=toupper(a[0]);
}
int ttt::checkenter(char ch)
{
  int i=0;
  int l=strlen(arr);
  for(i=0;i<l;i++)
  {
    if(arr[i]==ch)
      return 0;
  }
  return 1;
}
int ttt::any()
{
    for(int i=1;i<=9;i++)
    {
  if(checkenter((char)(48+i))==1)
    {
      bs[strlen(bs)]=(char)(48+i);
      placemark((char)(48+i),1);
      return 0;
    }
    }
    return 1;
}

int ttt::winnerpossibility2()
{
  int k=0,o=0;
  for(int i=1;i<=9;i++)
  {
    for(int j=1;j<=9;j++)
    {
       if(checkenter((char)(48+j))==1&&checkenter((char)(48+i))==1)
       {
	 bs[strlen(bs)]=(char)(48+i);
	 o=winner2((char)(48+j),bs);
	 bs[strlen(bs)-2]=bs[strlen(bs)-1];
	 bs[strlen(bs)-1]='\0';
	 if(o==2)
	     {
		placemark((char)(48+j),1);
		return 1;
	     }
	     else if(k==0&&o==1)
	     {
		k=j;
	     }
	 bs[strlen(bs)-1]='\0';
       }
    }
  }
  if(k!=0)
    {
      placemark((char)(48+k),1);
      bs[strlen(bs)]=(char)(48+k);
      return 1;
    }
    return 0;
}
int ttt::winner2(char ch,char *q)
{
  int count=0;
  q[strlen(q)]=ch;
  char *ptr5=strchr(q,'5');
  char *ptr1=strchr(q,'1');
  char *ptr9=strchr(q,'9');
  if(ptr5!=NULL)
  {
    if(ptr1!=NULL&&ptr9!=NULL)
    {
      count++;
    }
    if(strchr(q,'4')!=NULL&&strchr(q,'6')!=NULL)
    {
      count++;
    }
    if(strchr(q,'2')!=NULL&&strchr(q,'8')!=NULL)
    {
      count++;
    }
    if(strchr(q,'7')!=NULL&&strchr(q,'3')!=NULL)
    {
      count++;
    }
  }
  if(ptr9!=NULL)
  {
    if(strchr(q,'3')!=NULL&&strchr(q,'6')!=NULL)
    {
      count++;
    }
    if(strchr(q,'7')!=NULL&strchr(q,'8')!=NULL)
    {
      count++;
    }
  }
  if(ptr1!=NULL)
  {
    if(strchr(q,'2')!=NULL&&strchr(q,'3')!=NULL)
    {
      count++;
    }
    if(strchr(q,'7')!=NULL&&strchr(q,'4')!=NULL)
    {
      count++;
    }
  }
  if(count==0)
  return 0;
  else if(count==1)
  return 1;
  else
  return 2;
}

int ttt::stopwinner()
{
  for(int i=1;i<=9;i++)
  {
     if(checkenter((char)(48+i))==1)
     {
       if(winner2((char)(48+i),as)!=0)
       {
	 as[strlen(as)-1]='\0';
	     placemark((char)(48+i),1);
	 bs[strlen(as)-1]=(char)(48+i);
	 return 1;
       }
       as[strlen(as)-1]='\0';
     }
  }
  return 0;
}
void ttt::placemark(char ch,int q)
{
int x=0,y=0;
    arr[strlen(arr)]=ch;
    bar(0,380,xmax,ymax);
    switch(ch)
    {
      case '1':
      x=0,y=0;
      break;
      case '2':
      x=1,y=0;
      break;
      case '3':
      x=2,y=0;
      break;
      case '4':
      x=0,y=1;
      break;
      case '5':
      x=1,y=1;
      break;
      case '6':
      x=2,y=1;
      break;
      case '7':
      x=0,y=2;
      break;
      case '8':
      x=1,y=2;
      break;
      case '9':
      x=2,y=2;
      break;
    }
  if(q==0)
  {
    line(190+100*x,70+100*y,190+60+100*x,70+60+100*y);
    line(190+60+100*x,70+100*y,190+100*x,70+60+100*y);
  }
  else
    circle(220+100*x,100+100*y,30);

}
void ttt::box()
{
  bar(0,0,xmax,ymax);
  outtextxy(xmax/2-60,10,"TIC TAC TOE GAME");
  line(170,50,170,350);
  line(170,350,470,350);
  line(470,350,470,50);
  line(470,50,170,50);
  line(270,50,270,350);
  line(370,50,370,350);
  line(170,150,470,150);
  line(170,250,470,250);
  outtextxy(180,140,"1");
  outtextxy(280,140,"2");
  outtextxy(380,140,"3");
  outtextxy(180,240,"4");
  outtextxy(280,240,"5");
  outtextxy(380,240,"6");
  outtextxy(180,340,"7");
  outtextxy(280,340,"8");
  outtextxy(380,340,"9");
}
void ttt::input()
{
    strcpy(txt,a);
    strcat(txt,", Input where you want to place cross(X) from 1-9");
    outtextxy(10,400,txt);
    while(1)
    {
      ch=getch();
      bar(0,380,xmax,ymax);
      if((int)ch<49||(int)ch>57)
      {
	outtextxy(10,400,"Wrong input !!!");
	outtextxy(10,415,"Please try again.");
	    outtextxy(10,430,txt);
      }
      else if(checkenter(ch)==0)
      {
	    outtextxy(10,400,"Already filled !!!");
	outtextxy(10,415,"Please try again.");
	outtextxy(10,430,txt);
      }
      else
	    break;
    }
    placemark(ch,0);
    as[strlen(as)]=ch;
    if(winner(as)==0)
	{
	    bar(0,380,xmax,ymax);
		strcpy(txt,"GAME IS WON BY ");
		strcat(txt,a);
		outtextxy(10,400,txt);
		getch();
		closegraph();
		exit(0);
	}
}
int ttt::winner(char *q)
{
  char *ptr5=strchr(q,'5');
  char *ptr1=strchr(q,'1');
  char *ptr9=strchr(q,'9');
  if(ptr5!=NULL)
  {
    if(ptr1!=NULL&&ptr9!=NULL)
    {
      line(190,70,450,330);
      return 0;
    }
    else if(strchr(q,'4')!=NULL&&strchr(q,'6')!=NULL)
    {
      line(190,200,450,200);
      return 0;
    }
    else if(strchr(q,'2')!=NULL&&strchr(q,'8')!=NULL)
    {
      line(320,70,320,330);
      return 0;
    }
    else if(strchr(q,'7')!=NULL&&strchr(q,'3')!=NULL)
    {
      line(450,70,190,330);
      return 0;
    }
  }
  else if(ptr9!=NULL)
  {
    if(strchr(q,'3')!=NULL&&strchr(q,'6')!=NULL)
    {
      line(420,70,420,330);
      return 0;
    }
    else if(strchr(q,'7')!=NULL&strchr(q,'8')!=NULL)
    {
      line(190,300,450,300);
      return 0;
    }
  }
  else if(ptr1!=NULL)
  {
    if(strchr(q,'2')!=NULL&&strchr(q,'3')!=NULL)
    {
      line(190,100,450,100);
      return 0;
    }
    else if(strchr(q,'7')!=NULL&&strchr(q,'4')!=NULL)
    {
      line(220,70,220,330);
      return 0;
    }
  }
  return 1;
}
int ttt::winningmove()
{
    for(int i=1;i<=9;i++)
    {
	if(checkenter((char)(48+i))==1&&winner2((char)(48+i),bs)!=0)
	   {
	       placemark((char)(48+i),1);
	       return 1;
	   }
	   bs[strlen(as)-1]='\0';
    }
    return 0;
}
void ttt::anyeven()
{
    for(int i=2;i<=9;i+=2)
    {
    if(checkenter((char)(48+i))==1)
    {
      bs[strlen(bs)]=(char)(48+i);
      placemark((char)(48+i),1);
      return;
    }
}
}
void ttt::anyodd()
{
    for(int i=1;i<=9;i+=2)
    {
    if(checkenter((char)(48+i))==1)
    {
      bs[strlen(bs)]=(char)(48+i);
      placemark((char)(48+i),1);
      return;
    }
    }
}
void ttt::play()
{
    int tmp=0;
    input();
    if(ch=='5')
    {
	bs[strlen(bs)]='1';
	placemark('1',1);
	while(1)
	{
	input();
	if(winningmove()==0&&stopwinner()==0&&winnerpossibility2()==0)
	 {
	     tmp=any();
	    if(tmp==1)
	    {
	    bar(0,380,xmax,ymax);
	    outtextxy(10,400,"GAME IS DRAW");
	    getch();
	    closegraph();
	    exit(0);
	    }
	 }
	if(winner(bs)==0)
	{
	    bar(0,380,xmax,ymax);
		strcpy(txt,"GAME IS WON BY A.I.");
		outtextxy(10,400,txt);
		getch();
		closegraph();
		exit(0);
	}
	}
    }
    else if(((int)ch-48)%2!=0)//odd
    {
	bs[strlen(bs)]='5';
	placemark('5',1);
	input();
	if((stopwinner()==0&&(int)as[strlen(as)-1]-48)%2!=0)
	{
	    anyeven();
	}
	while(1)
	{
	input();
	if(winningmove()==0&&stopwinner()==0&&winnerpossibility2()==0)
	 {
	     tmp=any();
	    if(tmp==1)
	    {
	    bar(0,380,xmax,ymax);
	    outtextxy(10,400,"GAME IS DRAW");
	    getch();
	    closegraph();
	    exit(0);
	    }
	 }
	else if(winner(bs)==0)
	{
	    bar(0,380,xmax,ymax);
		strcpy(txt,"GAME IS WON BY A.I.");
		outtextxy(10,400,txt);
		getch();
		closegraph();
		exit(0);
	}
	}
    }
    else
    {
	bs[strlen(bs)]='5';
	placemark('5',1);
	input();
	if(((int)as[strlen(as)-1]-48)%2==0)
	{
		if(strchr(bs,'2')!=NULL&&strchr(bs,'4')!=NULL)
		{
		     placemark('1',1);
		     bs[strlen(as)-1]='1';
		}
		else if(strchr(bs,'8')!=NULL&&strchr(bs,'4')!=NULL)
		{
		     placemark('7',1);
		     bs[strlen(as)-1]='7';
		}
		else if(strchr(bs,'8')!=NULL&&strchr(bs,'6')!=NULL)
		{
		     placemark('9',1);
		     bs[strlen(as)-1]='9';
		}
		else if(strchr(bs,'2')!=NULL&&strchr(bs,'6')!=NULL)
		{
		     placemark('3',1);
		     bs[strlen(as)-1]='3';
		}
		else
		{
		    anyodd();
		}
	}
	else
	{
	    if(stopwinner()==0)
	    {
		anyeven();
	    }
	}
	while(1)
	{
	input();
	if(winningmove()==0&&stopwinner()==0&&winnerpossibility2()==0)
	 {
	     tmp=any();
	    if(tmp==1)
	    {
	    bar(0,380,xmax,ymax);
	    outtextxy(10,400,"GAME IS DRAW");
	    getch();
	    closegraph();
	    exit(0);
	    }
	 }
	else if(winner(bs)==0)
	{
	    bar(0,380,xmax,ymax);
		strcpy(txt,"GAME IS WON BY A.I.");
		outtextxy(10,400,txt);
		getch();
		closegraph();
		exit(0);
	}
	}
    }
}
void main()
{
  ttt z;
  z.detail();
  z.box();
  z.play();
}
