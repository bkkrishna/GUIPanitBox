#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

union REGS in, out;
int x,y,btn;
int tols, clr,bg,c, flag,  txt = 0, msgl = 0, i = 0, er; // flag = 0;
int tx,ty;
char buff[1024],ctn[2], ch, fname[25];
/* style control */
int ln = 0,fil = 0,lst = 0,fst = 0;
/* style selection enable */
int st = 0;
/* copy cut past control */
int cpy=0, cut=0, paste=0;
/* selection area */
int a,b,c,d;

void info(void);
int graphics();
void tools(void);
void colors(void);
void head(void);
void drawarea(void);
void closebtn(void);
void mouse(void);
int selecttools(void);
int selectcolors(void);
void mainfunc(void);
void end(void);
void cordinate(int *, int *, int *);
void msgbar();
void hmouse();
void smouse();
void fmenu();
void savef();
void openf();
void getstring();
void copyf();
void pastef();
//void bmouse(int, int,int,int)   ;
void selectfmenu();
void htools();
void hcolors();
void styles();
void s_styles();
void sclear();

//get cordinate function
void cordinate(int *mbtn, int *mx, int *my)
{
	in.x.ax = 3;
	int86(0X33, &in, &out);

	*mx = out.x.cx;
	*my = out.x.dx;
	*mbtn = out.x.bx;
}

//start of main function
void main()
{
	clrscr();
	info();

	getch();
}
//end of main function

//start of naming function


void info()
{
	//start of backline border
		int i;
	clrscr();
	gotoxy(15,2);
	 textcolor(GREEN);
	 for (i = 0; i < 50; i++)      //upper boud
	 {
		cprintf("\\");
		delay(100);
	 }
	 for(i = 2; i < 11; i++) // right bound
	 {
		gotoxy(65,i);
		cprintf("/");
		delay(100);
	 }

	 for( i = 64; i > 15; i--) //lower bound
	 {
		gotoxy(i,11);
		cprintf("//");
		delay(100);
	 }

	 for( i = 11; i > 2; i--)     // left bound
	 {
		gotoxy(15,i);
		cprintf("\\" );
		delay(100);
	 }
//end of backline  border

//start of naming
	gotoxy(32,3);
	textcolor(LIGHTCYAN);
	cprintf("Final Project on C");
	gotoxy(35,4);
	textcolor(EGA_LIGHTMAGENTA + BLINK);
	cprintf("GUI PaintBox");
	gotoxy(23,6);
	textcolor(EGA_YELLOW);
	cprintf("Bachelor in Software Engineering (I)");
	gotoxy(33,7);
	cprintf("Pokhara University");
	gotoxy(20,8);
	cprintf("Gandaki College of Engineering and Science");
	gotoxy(33,9);
	cprintf("Lamachaur, Pokhara");

	gotoxy(36,15);
	textcolor(BROWN + BLINK);
	cprintf("Developed By:");

	//name list
	textcolor(LIGHTGREEN);
	gotoxy(33,17);
	cprintf("B. K. Krishna Magar");
	gotoxy(33,18);
	cprintf("Ghan Bahadur Thapa");
	gotoxy(34,19);
	cprintf("Mukesh Bhattarai");
	gotoxy(34,20);
	cprintf("Sushil Ale Magar");
	gotoxy(37,21);
	cprintf("Sushil G.C.");
	gotoxy(34,22);
	cprintf("Sushil Timilshina");

	textcolor(LIGHTBLUE);
	gotoxy(38,24);
	cprintf("Supervisor");
	textcolor(LIGHTGREEN);
	gotoxy(31,25);
	cprintf("Mr. Ram Chandra Acharya");
//end of naming
	delay(3000);

//start of calling function for main porpose
	clrscr();
	graphics();

	drawarea(); // drawing area
	msgbar(); //message bar
		head();      //program name
	closebtn();  //close btn

	tools(); 	//calling tools
	colors();  //calling colors
	fmenu();
	mouse();	//show mouse
	selecttools();
	selectcolors();
	styles();
	mainfunc();

//end of calling function

}
//end of info function


//start of graphics function
int graphics()
{
	int grd = DETECT, grm;
	initgraph(&grd, &grm, "C:\\turboc3\\bgi");
	return 0;
}
// end of graphics funtion
void fmenu()
{

 // setcolor(GREEN);
//  rectangle(10,30,30,50);
  setcolor(WHITE);
 // textheight("New");
 //rectangle(10,25,40,40);
 outtextxy(12,30,"New");
 //rectangle(45,25,85,40);
 outtextxy(50,30,"Save");
 //rectangle(90,25,135,40);
 outtextxy(100,30,"Open");

 setcolor(LIGHTGRAY);
 line(140,30,140,40);

 setcolor(WHITE);
// rectangle(145,25,175,40);
// outtextxy(150,30,"Select");
 outtextxy(150,30,"Cut");
// rectangle(185,25,225,40);
 outtextxy(190,30,"Copy");
// rectangle(235,25,285,40);
 outtextxy(240,30,"Paste");
//rectangle(295,25,340,40);
// outtextxy(298,30,"Paste");
}
//select fmenu()

//start of tools function
void tools()
{

  //tools
 // int i,x1,x2,y1,y2;

  setfillstyle(SOLID_FILL,LIGHTGRAY);
 // floodfill(15,6,WHITE);
	bar(11,50,58,60);
	 setcolor(LIGHTGRAY);
	rectangle(10,50,58,60);
	setcolor(BLACK);
	line(8,48,58,48);
	line(8,48,8,60);

  //setcolor(BLACK);
  outtextxy(15,52,"TOOLS");


    //tool box
   // rectangle(15, 65, 55, 88);      // rectangle
   // setcolor(RED);
   // rectangle(17,67,53,86);
/*    setcolor(LIGHTGRAY);  //lft
    line(15,65,55,65); //horizental
    line(15,65,15,88); //vertical

    setcolor(BLACK);    //right
    line(55,65,55,88);  //vertical
    line(55,88,15,88); //horizental      */
    //setcolor(WHITE);
    setcolor(BLACK);
    rectangle(19,69,51,84);

    //rectangle(15, 93, 55, 116);     // circle
    //rectangle(17,95,53,114);
    circle(35,105,8);

    setcolor(LIGHTGRAY);
    setlinestyle(0,0,2);
    line(15,93,55,93);
    line(15,93,15,116);

    setcolor(BLACK);
    line(55,93,55,116);
    line(55,116,15,116);

    //rectangle(15, 121, 55, 144);    // ellipsE
    //rectangle(17,123,53,142);
    ellipse(35,133,0,360,15,8);
    setcolor(LIGHTGRAY);
    line(15,121,55,121);
    line(15,121,15,144);
    setcolor(BLACK);
    line(55,121,55,144);
    line(55,144,15,144);

    //rectangle(15, 149, 55, 172);   // frhand
    //rectangle(17,151,53,170);
    line(20,154,50,167);
    setcolor(LIGHTGRAY);
    line(15,149,55,149);
    line(15,149,15,172);
    setcolor(BLACK);
    line(55,149,55,172);
    line(55,172,15,172);

    //rectangle(15, 177, 55, 200);    //lneto
   // rectangle(17,179,53,198);
    line(20,195,50,195);
    line(50,195,50,190);
    line(50,190,35,190);
    line(35,190,40,182);
    line(40,182,30,182);
    line(30,182,20,195);

    setcolor(LIGHTGRAY);
    line(15,177,55,177);
    line(15,177,15,200);
    setcolor(BLACK);
    line(55,177,55,200);
    line(55,200,15,200);

    //line
   // rectangle(15, 205, 55, 228);
   // rectangle(17,207,53,226);
    line(20,210,20,223);
    line(23,215,50,215);

    setcolor(LIGHTGRAY);
    line(15,205,55,205);
    line(15,205,15,228);
    setcolor(BLACK);
    line(55,205,55,228);
    line(55,228,15,228);

    //background
    //rectangle(15, 233, 55, 256);
   // rectangle(17,235,53,253);
    setfillstyle(SOLID_FILL,WHITE);
    setcolor(BLACK);
    bar(19,237,51,251);
    rectangle(19,237,51,251);

    setcolor(LIGHTGRAY);
    line(15,233,55,233);
    line(15,233,15,256);
    setcolor(BLACK);
    line(55,233,55,256);
    line(55,256,15,256);

     //eraser
    //rectangle(15, 261, 55, 284);    //
   // rectangle(17,263,57,286);
    setcolor(WHITE);
    rectangle(20,266,45,280);
    bar(27,266,33,280);
    bar(40,266,45,280);
    bar(45,270,48,277);

    setcolor(LIGHTGRAY);
    line(15,261,55,261);
    line(15,261,15,284);
    setcolor(BLACK);
    line(55,261,55,284);
    line(55,284,15,284);

    //ellipsefill
   // rectangle(15, 289, 55, 312);
   /// rectangle(17,291,53,310);
    fillellipse(35,300,15,8);

    setcolor(LIGHTGRAY);
    line(15,289,55,289);
    line(15,289,15,312);
    setcolor(BLACK);
    line(55,289,55,312);
    line(55,312,15,312);

    //text
    //rectangle(15, 317, 55, 340);    // select
   // rectangle(17,319,53,338);
    settextstyle(4,0,0);
    outtextxy(24,306,"A");
    setcolor(LIGHTGRAY);
    line(15,317,55,317);
    line(15,317,15,340);
    setcolor(BLACK);
    line(55,317,55,340);
    line(55,340,15,340);


//  getch();
}
//end of tools function

//start of colors function
void colors()
{
  int i,j,c = 1;
  int x1,x2,y1,y2,cx1,cx2,cy1,cy2;
  //color box
  setfillstyle(SOLID_FILL,LIGHTGRAY);
  bar(75,50,130,60);

  //border
  setcolor(LIGHTGRAY);
  line(66,48,66,getmaxy()-120);
  setcolor(BLACK);
  line(68,48,68,getmaxy()-120);


  setcolor(LIGHTGRAY);
 // rectangle(70,5,125,23);
 rectangle(75,50,130,60);
 setcolor(BLACK);
 line(75,48,130,48);
 line(75,50,75,60);

   // floodfill(73,7,WHITE);
  setcolor(BLACK);
  settextstyle(DEFAULT_FONT,0,0);
  outtextxy(79,52,"COLORS");
  setcolor(WHITE);

  //print colors
    //	cx1 = 72, cx2 = 92, cy1 = 30, cy2 = 50;         //old
       //	cx1 = 72, cx2 = 92, cy1 = 69, cy2 = 87;
		cx1 = 79, cx2 = 99, cy1 = 69, cy2 = 87;
	for(i = 0; i <= 7; i++)
	{
		for(j = 0; j < 2; j++)
		{

				setcolor(c);
				setfillstyle(SOLID_FILL,c);
			 //	rectangle(cx1, cy1, cx2, cy2);
				bar(cx1,cy1,cx2,cy2);
				setcolor(LIGHTGRAY);
				line(cx1-2,cy1-2,cx2+2,cy1-2);
				line(cx1-2,cy1-2,cx1-2,cy2+2);
				setcolor(BLACK);
				line(cx2+2,cy1-2,cx2+2,cy2+2);
				line(cx2+2,cy2+2,cx1-2,cy2+2);
			       //	floodfill(cx1+3,cy1+3,c);
				cx1 += 30, cx2 += 30;

			c++;
		}
		cx1 = 79, cx2 = 99;
		cy1 += 30, cy2 += 30;  //30
	}

	//color option box
	setcolor(LIGHTGREEN);
   //	cx1 = 68, cx2 = 97, cy1 = 25, cy2 = 55;   // old
      //	cx1 = 68, cx2 = 96, cy1 = 65, cy2 = 92;
	cx1 = 75; cx2 = 103, cy1 = 65, cy2 = 92;
	for( i = 0; i <= 7; i++)     //7
	{
		for(j = 0; j < 2; j++)
		{
		 //	if(i == 7 && j ==1)
		   //		continue;
			rectangle(cx1,cy1,cx2,cy2);
		       ///	cx1 = 98, cx2 = 126;
		       cx1 = 105, cx2 = 133;
		}
	       //	cx1 = 68, cx2 = 96;
	       cx1 = 75; cx2 = 103;
	     //	cy1 += 30, cy2 += 29;
		cy1 += 30, cy2 += 30;
	}

	//selected color();
	setcolor(LIGHTGRAY);
	rectangle(75,310,133,350);
	setcolor(BLACK);
	rectangle(76,311,132,349);
	rectangle(90,320,117,340);
}
//close of colors function



//start of head function
void head()
{
	//setcolor(RED);
       //	rectangle(310,5,450,20);

	setfillstyle(6,RED);
	bar(195,7,450,20);



	line(192,4,455,4);
	line(192,5,192,20);
	line(453,5,453,20);
	setcolor(BLACK);
	line(192,3,455,3);
	line(191,5,191,20);
	line(455,5,455,20);
	//floodfill(311,7,RED);
	setcolor(YELLOW);
	outtextxy(275,10,"GUI Paint Box");
}
//end of head function

//start of drawarea function
void drawarea()
{
	//body
	setcolor(LIGHTGRAY);
	rectangle(1,1,getmaxx(), getmaxy());
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(1,1,getmaxx(), getmaxy());

	//fmenu;
	setfillstyle(CLOSE_DOT_FILL,RED);
	bar(7,27,getmaxx()-7,42);
	setcolor(BLACK);
	rectangle(4,24,getmaxx()-4,43);

	//drawing area
	setcolor(LIGHTGRAY);
	rectangle(148,48,getmaxx()-3,getmaxy()-48);

	setfillstyle(SOLID_FILL,WHITE);
	bar(150,50,getmaxx() - 5,getmaxy() - 50);

	 setcolor(BROWN);
	 rectangle(150,50,getmaxx() - 5,getmaxy() - 50);
}
void msgbar()
{
	setcolor(BLACK);
	rectangle(5, getmaxy() - 40, getmaxx()-5, getmaxy()-10);

	setcolor(LIGHTGRAY);
	rectangle(7,getmaxy()-38,getmaxx()-7,getmaxy()-12);

	setfillstyle(CLOSE_DOT_FILL,RED);
	bar(8,getmaxy()-37,getmaxx()-8,getmaxy()-13);
}
//end of drawarea

//start of closebtn function
void closebtn()
{
	setlinestyle(0,0,1);
	setcolor(RED);
	rectangle(615,3,getmaxx()-5,20);
	setfillstyle(SOLID_FILL,RED);
	floodfill(616,6,RED);
	setcolor(LIGHTCYAN);
	line(615,3,getmaxx()-5,20);
	line(getmaxx()-5,3,615,20);
	//chose

       //	setcolor(LIGHTGREEN);
       //	rectangle(615,3,getmaxx() - 5,20);
	setcolor(LIGHTGRAY);
	line(613,1,getmaxx()-3,1);
	line(613,1,613,22);
	setcolor(BLACK);
	line(getmaxx()-3,1,getmaxx()-3,20);
	line(getmaxx()-3,22,613,22);
}
// end of closebtn function

//start of mouse function
void mouse()
{
	union REGS in,out;
	in.x.ax = 1;
	int86(0X33,&in,&out);
}
//end of mouse function

//hide mouse
void hmouse()
{
	in.x.ax = 2;
	int86(0x33, &in, &out);
}

//show mouse();
void smouse()
{
	in.x.ax = 1;
	int86(0x33, &in, &out);
}
//start of select tools
int selecttools()
{
	     /*	in.x.ax = 3;
		int86(0X33, &in, &out);

		x = out.x.cx;
		y = out.x.dx;

		 rectangle(15, 65, 55, 88);
		*/
		cordinate(&btn, &x, &y);

		//rectangle   1
		if(x >= 15 && x <= 55 && y >= 65 && y<= 88)
		{
		      //	setcolor(LIGHTRED);        //selection tools
		       //	rectangle(15, 65, 55, 88); //rectangle(15,25,55,55);      //selection
		      // lft

		       if(btn == 1)
			{
				tols = 1;

				ln = 1;
				fil = 0;
				styles();
			       msgbar();
			       //	setfillstyle(SOLID_FILL,DARKGRAY);
			       /*	setfillstyle(CLOSE_DOT_FILL,RED);
				bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
				*/
				setcolor(WHITE);
				outtextxy(14,450,"Draw Rectangle");
				setcolor(clr);
			}
		}
	      else
		{
		       //	setcolor(LIGHTGREEN);        //selection tools
		       //	rectangle(15, 65, 55, 88);
		      //rectangle(15, 93, 55, 116); //	rectangle(15,25,55,55);      //default
	     }

		//circle       2
		if(x >= 15 && x <= 55 && y >= 93 && y <= 116)
		{
			setcolor(LIGHTRED);				//circle
		    //   rectangle(15, 93, 55, 116);
		       //	rectangle(15,60,55,90);

		   //	if(out.x.bx == 1)
		   if(btn == 1)
		   {
			tols = 2;
			ln = 0;
			fil = 0;
			styles();
		     /*  //	setfillstyle(SOLID_FILL,DARKGRAY);
			setfillstyle(CLOSE_DOT_FILL,RED);
			bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
		     */
			msgbar();
			setcolor(WHITE);
			outtextxy(14,450,"Draw Circle");
			setcolor(clr);

		   }
		}
		else
		{
			setcolor(LIGHTGREEN);				//circle
		   //	rectangle(15, 93, 55, 116);
		       //	rectangle(15,60,55,90);
		}

		//ellipse     3
		if( x >= 15 && x <= 55 && y >= 121 && y <= 144)
		{
		     //	setcolor(LIGHTRED);
		  //	rectangle(15, 121, 55, 144);


		   //	if(out.x.bx == 1)
		   if(btn == 1)
		   {
			tols = 3;
			ln = 0;
			fil = 0;
			styles();
			//setfillstyle(SOLID_FILL,DARKGRAY);
			//setfillstyle(CLOSE_DOT_FILL,RED);
			//bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
			msgbar();
			setcolor(WHITE);
			outtextxy(14,450,"Draw Ellipse");
			setcolor(clr);
		   }
		}
		else
		{
			setcolor(LIGHTGREEN);
		     //	rectangle(15, 121, 55, 144);
		       //rectangle(15,95,55,120);
		}

		//freehand    4
		if(x >= 15 && x <= 55 && y >= 149 && y <= 172)
		{
			setcolor(LIGHTRED);
		       //	 rectangle(15, 149, 55, 172);
		       //rectangle(15,125,55,150);

		      //	if(out.x.bx == 1)
			  if(btn == 1)
			  {
				tols = 4;
				ln = 0;
				fil = 0;
				styles();
			       //	setfillstyle(SOLID_FILL,DARKGRAY);
				//setfillstyle(CLOSE_DOT_FILL,RED);
				//bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
				msgbar();
				setcolor(WHITE);
				outtextxy(14,450,"Draw Freehand");
				setcolor(clr);
			  }
		}
		else
		{
			setcolor(LIGHTGREEN);
		      //	rectangle(15, 149, 55, 172);
		       //rectangle(15,125,55,150);
		}

		//lineto             5
		if(x >= 15 && x <= 55 && y >= 177 && y <= 200)
		{
			setcolor(LIGHTRED);
		       //	rectangle(15, 177, 55, 200);
		       //rectangle(15,155,55,185);

		      //	if(out.x.bx == 1)
				if(btn == 1)
				{
					tols = 5;
					ln = 1;
					fil = 0;
					styles();
				       //	setfillstyle(SOLID_FILL,DARKGRAY);
				       //	setfillstyle(CLOSE_DOT_FILL,RED);
					//bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
					msgbar();
					setcolor(WHITE);
					outtextxy(14,450,"Draw Polygon");
					setcolor(clr);
					flag = 0;
				}
		}
		else
		{
			 setcolor(LIGHTGREEN);
			// rectangle(15, 177, 55, 200);
			// rectangle(15,155,55,185);
		}

		//straight line  6
		if(x >= 15 && x <= 55 && y >= 205 && y <= 228)
		{
			setcolor(LIGHTRED);
		      // rectangle(15, 205, 55, 228);
		      //rectangle(15,190,55,220);

		      //	if(out.x.bx == 1)
		      if(btn == 1)
		      {
			tols = 6;
			ln = 1;
			fil = 0;
			styles();
			//setfillstyle(SOLID_FILL,DARKGRAY);
			//setfillstyle(CLOSE_DOT_FILL,RED);
		   //	bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
			msgbar();
			setcolor(WHITE);
			outtextxy(14,450,"Draw Line");
			setcolor(clr);
		      }
		}
		else
		{
			setcolor(LIGHTGREEN);
		      // rectangle(15, 205, 55, 228);
		       //rectangle(15,190,55,220);
		}

		//background   7
		if( x >= 15 && x <= 55 && y >= 233 && y <= 256 )
		{
			setcolor(LIGHTRED);
			 //rectangle(15, 233, 55, 256);
			//rectangle(15,225,55,260);

		  //	if(out.x.bx == 1)
			     if(btn == 1)
			     {
				tols = 7;
				ln = 0;
				fil = 1;
				styles();
				//setfillstyle(SOLID_FILL,DARKGRAY);
				//setfillstyle(CLOSE_DOT_FILL,RED);
				//bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
				msgbar();
				setcolor(WHITE);
				outtextxy(14,450,"Draw Solid Rectangle");
				setcolor(clr);
			     }
		}
		else
		{
			setcolor(LIGHTGREEN);
			// rectangle(15, 233, 55, 256);
			//rectangle(15,225,55,260);
		}

	  //eraser  8
	  if(x >= 15 && x <= 55 && y >= 261 && y <= 284)
	  {
			setcolor(LIGHTRED);
			//rectangle(15, 261, 55, 284);
		       //rectangle(15,265,55,295);

		  //	if(out.x.bx == 1)
			    if(btn == 1)
			    {
				tols = 8;
				ln = 0;
				fil = 0;
				styles();
			       //	setfillstyle(SOLID_FILL,DARKGRAY);
			       //	setfillstyle(CLOSE_DOT_FILL,RED);
				//bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
				msgbar();
				setcolor(WHITE);
				outtextxy(14,450,"Eraser");
				setcolor(clr);
			    }
	  }
	  else
	  {
			setcolor(LIGHTGREEN);
		       //	rectangle(15, 261, 55, 284);
			//rectangle(15,265,55,295);
	  }

	  //ellipsefill
	  if(x >= 15 && x <= 55 && y >= 289 && y <= 312)
	  {
			setcolor(LIGHTRED);
		       //rectangle(15, 289, 55, 312);
		       //rectangle(15,300,55,330);

		     //	if(out.x.bx == 1)
		     if(btn == 1)
		     {
			tols = 9;
			ln = 0;
			fil = 1;
			styles();
			//setfillstyle(SOLID_FILL,DARKGRAY);
			//setfillstyle(CLOSE_DOT_FILL,RED);
			//bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
			msgbar();
			setcolor(WHITE);
			outtextxy(14,450,"Draw Solid Ellipse");
			setcolor(clr);
		     }
	  }
	  else
	  {
			setcolor(LIGHTGREEN);
			//rectangle(15, 289, 55, 312);
			//rectangle(15,300,55,330);
	  }

	  //close button  10
	  if(x >= 615 && x <= (getmaxx() - 5) && y >= 3 && y <= 20)
	  {
		    /*	setcolor(LIGHTRED);
			rectangle(615,3,getmaxx() - 5,20);
		    */
		       setlinestyle(0,0,1);
		    ///	if(out.x.bx == 1)
		       if(btn == 1)
			{
				setcolor(BLACK);
				line(613,1,getmaxx()-3,1);
				line(613,1,613,22);
				setcolor(DARKGRAY);
				line(getmaxx()-3,1,getmaxx()-3,20);
				line(getmaxx()-3,22,613,22);
				delay(100);
				tols = 10;
			}
			else
			{
		      /*
			setcolor(LIGHTGREEN);
			rectangle(615,3,getmaxx() - 5,20);
		      */
			setcolor(LIGHTGRAY);
			line(613,1,getmaxx()-3,1);
			line(613,1,613,22);
			setcolor(BLACK);
			line(getmaxx()-3,1,getmaxx()-3,20);
			line(getmaxx()-3,22,613,22);
	  }

	  }


	  //text
	  if( x >= 15 && x <= 55 && y >= 317 && y <= 340)
	  {
		setcolor(LIGHTRED);
		//rectangle(15, 317, 55, 340);
		if(btn == 1)
		{
			tols = 11;
			txt = 1;

			ln = 0;
			fil = 0;
			styles();
		    //	setfillstyle(SOLID_FILL,DARKGRAY);
		       //	setfillstyle(CLOSE_DOT_FILL,RED);
			//bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
			msgbar();
			setcolor(WHITE);
			outtextxy(14,450,"Write Text: Press Esc to End");
			setcolor(clr);
		}
	  }
	  else
	  {
	       setcolor(LIGHTGREEN);
	       //rectangle(15, 317, 55, 340);
	  }



	 //file menu
	 if(x >= 10 && x <= 40 && y >= 25 && y <= 40)
  {
     //	setcolor(LIGHTRED);
      //	outtextxy(12,30,"New");

     // setfillstyle(SOLID_FILL,LIGHTGRAY);
      setcolor(LIGHTGREEN);
      setlinestyle(0,0,3);
      line(10,40,38,40);
      setlinestyle(0,0,1);
	if(btn == 1)
	  {
		tols = 12;
		ln = 0;
		fil = 0;
		styles();
		msgbar();
	  }
  }
  else
  {
       //	setcolor(DARKGRAY);
     // setlinestyle(0,0,3);
     // line(10,40,38,40);
     setfillstyle(CLOSE_DOT_FILL,RED);
     bar(10,39,38,42);
      setlinestyle(0,0,1);

	//setcolor(WHITE);
	//setfillstyle(SOLID_FILL, DARKGRAY);
	//bar(10,26,40,40);
       //	outtextxy(12,30,"New");

  }

// if(x >= 50 && x <= 85 y >= 25 && y <= 40)
 if(x >= 45 && x <= 85 && y >= 25 && y <= 40)
 {
   //setcolor(LIGHTRED);
	//rectangle(45,25,85,40);
      //	outtextxy(50,30,"Save");

	setcolor(LIGHTGREEN);
      setlinestyle(0,0,3);

      line(45,40,85,40);
      setlinestyle(0,0,1);
	if(btn == 1)
	{
		tols = 13;

		ln = 0;
		fil = 0;
		styles();

			//setfillstyle(SOLID_FILL,DARKGRAY);
			//bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
			//setcolor(WHITE);
		       //	outtextxy(12,450,"Enter File Name: ");
		setcolor(clr);
	}

  }
  else
  {
       //	setcolor(RED);
       // setlinestyle(0,0,3);
     // line(45,40,85,40);
       setfillstyle(CLOSE_DOT_FILL,RED);
       bar(45,39,85,42);
      setlinestyle(0,0,1);
	//setcolor(WHITE);
	//setfillstyle(SOLID_FILL, DARKGRAY);
	//bar(45,26,85,40);
      //	outtextxy(50,30,"Save");
  }

  if(x >= 90 && x <= 135 && y >= 25 && y <= 40)
  {
	//rectangle(90,25,135,40);
	//setcolor(LIGHTRED);
	//outtextxy(100,30,"Open");
	//setcolor(LIGHTGRAY);

	setcolor(LIGHTGREEN);
      setlinestyle(0,0,3);
      line(94,40,135,40);
      setlinestyle(0,0,1);
	if(btn == 1)
	{
		tols = 14;

		ln = 0;
		fil = 0;
		styles();

		       //	setfillstyle(SOLID_FILL,DARKGRAY);
		       //	bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
			//setcolor(WHITE);
		       //	outtextxy(12,450,"Enter File Name:");
			setcolor(clr);
	}

  }
  else
  {
    //  setcolor(DARKGRAY);
     // setlinestyle(0,0,3);
     // line(94,40,135,40);
     setfillstyle(CLOSE_DOT_FILL,RED);
      bar(94,39,135,42);
      setlinestyle(0,0,1);

      /*
      setcolor(WHITE);
      setfillstyle(SOLID_FILL, DARKGRAY);
	bar(90,26,135,40);
	outtextxy(100,30,"Open");
	*/
  }

   //rectangle(145,25,200,40);
// outtextxy(150,30,"Select");  //cut
 if(x >= 145 && x <= 175 && y >= 25 && y <= 40)
 {
	setcolor(LIGHTGREEN);
	setlinestyle(0,0,3);
	line(145,40,175,40);
	if(btn == 1)
	{
		msgbar();
		setcolor(WHITE);
		outtextxy(14,450,"Select Area");
		tols = 15;
		ln = 0;
		fil = 0;
		styles();

	}
 }
 else
  {
	setfillstyle(CLOSE_DOT_FILL,RED);
	bar(145,39,175,42);
	setlinestyle(0,0,1);
 }

 //rectangle(210,25,237,40);
// outtextxy(213,30,"copy");
 if(x >= 185 && x <= 225 && y >= 25 && y <= 40)
 {
	setcolor(LIGHTGREEN);
	setlinestyle(0,0,3);
	line(185,40,225,40);
	if(btn == 1)
	{
		msgbar();
		setcolor(WHITE);
		outtextxy(14,450,"Select Area");
		tols = 16;
		ln = 0;
		fil = 0;
		styles();
	}
 }
 else
 {
	setfillstyle(CLOSE_DOT_FILL,RED);
	bar(185,39,225,42);
	setlinestyle(0,0,1);
 }

 //rectangle(250,25,286,40);
// outtextxy(253,30,"Copy"); paste
 if(x >= 235 && x <= 285 && y >= 25 && y <= 40)
 {
	setcolor(LIGHTGREEN);
	setlinestyle(0,0,3);
	line(235,40,285,40);
	if(btn == 1)
	{
		msgbar();
		setcolor(WHITE);
		outtextxy(14,450,"Select Region to Paste");
		tols = 17;
		ln = 0;
		fil = 0;
		styles();
	}
 }
 else
 {
	setfillstyle(CLOSE_DOT_FILL,RED);
	bar(235,39,285,42);
	setlinestyle(0,0,1);
 }

 //rectangle(295,25,340,40);
 //outtextxy(298,30,"Paste");
/*
  if(x >= 295 && x <= 340 && y >= 25 && y <= 40)
 {
	setcolor(LIGHTGREEN);
	setlinestyle(0,0,3);
	line(295,40,340,40);
	if(btn == 1)
	{
		tols = 16;
		ln = 0;
		fil = 0;
		styles();
	}
 }
 else
 {
	setfillstyle(CLOSE_DOT_FILL,RED);
	bar(295,39,340,42);
	setlinestyle(0,0,1);
 }

*/

   htools();
  return (tols);
}
//end of selecttools

//highlight selected tools
void htools()
{       setlinestyle(0,0,1);
	setfillstyle(SOLID_FILL,DARKGRAY);
	if(tols== 1 )        //rectangle
	{
		 setlinestyle(0,0,1);
		 setcolor(BLACK);  //lft
		line(15,65,55,65); //horizental
		line(15,65,15,88); //vertical

		setcolor(LIGHTGRAY);    //right
		line(55,65,55,88);  //vertical
		line(55,88,15,88); //horizental

		//setcolor(RED);
		//rectangle(17,67,53,86);
	       ////	outtextxy(10,450,"Rectangle");
	}
	else
	{
		 setcolor(LIGHTGRAY);  //lft
		line(15,65,55,65); //horizental
		line(15,65,15,88); //vertical

		setcolor(BLACK);    //right
		line(55,65,55,88);  //vertical
		line(55,88,15,88); //horizental
		setcolor(DARKGRAY);
		rectangle(17,67,53,86);
		       //
	}

	if(tols == 2)    //circle
	{

	   /* setcolor(RED);
	    rectangle(17,95,53,114);
	   // outtextxy(10,450,"Circle");
	   */
		 setcolor(BLACK);
		 setlinestyle(0,0,2);
		line(15,93,55,93);
		line(15,93,15,116);

		setcolor(LIGHTGRAY);
		line(55,93,55,116);
		line(55,116,15,116);
	}
	else
	{
	      /*	setcolor(DARKGRAY);
		rectangle(17,95,53,114);
	      */
	       setcolor(LIGHTGRAY);
		setlinestyle(0,0,2);
		line(15,93,55,93);
		line(15,93,15,116);

		setcolor(BLACK);
		line(55,93,55,116);
		line(55,116,15,116);
	}

	if(tols == 3 )    //ellipse
	{
	   /* setcolor(RED);
	    rectangle(17,123,53,142);
	    //outtextxy(10,450,"Ellipse");
	   */
		setcolor(BLACK);
		line(15,121,55,121);
		line(15,121,15,144);
		setcolor(LIGHTGRAY);
		line(55,121,55,144);
		line(55,144,15,144);

	}
	else
	{
	   /*setcolor(DARKGRAY);
	    rectangle(17,123,53,142);
	    */
		setcolor(LIGHTGRAY);
		line(15,121,55,121);
		line(15,121,15,144);
		setcolor(BLACK);
		line(55,121,55,144);
		line(55,144,15,144);

	}

	if(tols == 4 ) //freehand
	{
	 /*  setcolor(RED);
	  rectangle(17,151,53,170);
	 // outtextxy(10,450,"Freehand");
	 */
		setcolor(BLACK);
		line(15,149,55,149);
		line(15,149,15,172);
		setcolor(LIGHTGRAY);
		line(55,149,55,172);
		line(55,172,15,172);
	}
	else
	{
	  /*  setcolor(DARKGRAY);
		rectangle(17,151,53,170);
	  */
		setcolor(LIGHTGRAY);
		line(15,149,55,149);
		line(15,149,15,172);
		setcolor(BLACK);
		line(55,149,55,172);
		line(55,172,15,172);
	}

	if(tols == 5 )  //lineto
	{
	  /*  setcolor(RED);
	   rectangle(17,179,53,198);
	   //outtextxy(10,450,"Polygon");
	   */
		setcolor(BLACK);
		line(15,177,55,177);
		line(15,177,15,200);
		setcolor(LIGHTGRAY);
		line(55,177,55,200);
		line(55,200,15,200);

	}
	else
	{
	  /*
	  setcolor(DARKGRAY);
	   rectangle(17,179,53,198);
	   */
		setcolor(LIGHTGRAY);
		line(15,177,55,177);
		line(15,177,15,200);
		setcolor(BLACK);
		line(55,177,55,200);
		line(55,200,15,200);

	}

	if(tols == 6)    //line
	{
	  /*  setcolor(RED);
	    rectangle(17,207,53,226);
	   // outtextxy(10,450,"Line");
	  */
		setcolor(BLACK);
		line(15,205,55,205);
		line(15,205,15,228);
		setcolor(LIGHTGRAY);
		line(55,205,55,228);
		line(55,228,15,228);
	}
	else
	{
	   /* setcolor(DARKGRAY);
	    rectangle(17,207,53,226);
	    */
		setcolor(LIGHTGRAY);
		line(15,205,55,205);
		line(15,205,15,228);
		setcolor(BLACK);
		line(55,205,55,228);
		line(55,228,15,228);
	}

	if(tols == 7 )//  background
	{
	  /*  setcolor(RED);
	    rectangle(17,235,53,253);
	    //outtextxy(10,450,"Solid Rectanlge");
	  */
		 setcolor(BLACK);
		line(15,233,55,233);
		line(15,233,15,256);
		setcolor(LIGHTGRAY);
		line(55,233,55,256);
		line(55,256,15,256);

	}
	else
	{
	   /*  setcolor(DARKGRAY);
	    rectangle(17,235,53,253);
	   */
		 setcolor(LIGHTGRAY);
		line(15,233,55,233);
		line(15,233,15,256);
		setcolor(BLACK);
		line(55,233,55,256);
		line(55,256,15,256);

	}
	if(tols == 8 )    //eraser
	{
	  /*  setcolor(RED);
	   rectangle(17,263,53,282);
	   //outtextxy(10,450,"Eraser");
	   */
		setcolor(BLACK);
		line(15,261,55,261);
		line(15,261,15,284);
		setcolor(LIGHTGRAY);
		line(55,261,55,284);
		line(55,284,15,284);
	 }
	 else
	 {
	  /*  setcolor(DARKGRAY);
	   rectangle(17,263,53,282);
	   */
		setcolor(LIGHTGRAY);
		line(15,261,55,261);
		line(15,261,15,284);
		setcolor(BLACK);
		line(55,261,55,284);
		line(55,284,15,284);
	 }

	if(tols == 9 )   //  ellipse fill
	{
	     /*
		setcolor(RED);
		rectangle(17,291,53,310);
	       //	outtextxy(10,450,"Solid Ellipse");
	     */
		setcolor(BLACK);
		line(15,289,55,289);
		line(15,289,15,312);
		setcolor(LIGHTGRAY);
		line(55,289,55,312);
		line(55,312,15,312);

	}
	else
	{
	 /*  setcolor(DARKGRAY);
		rectangle(17,291,53,310);
	 */
		setcolor(LIGHTGRAY);
		line(15,289,55,289);
		line(15,289,15,312);
		setcolor(BLACK);
		line(55,289,55,312);
		line(55,312,15,312);

	}

	if(tols == 11 )   //text
	{
	 /* setcolor(RED);
	  rectangle(17,319,53,338);
	  */
	  setcolor(BLACK);
	  line(15,317,55,317);
	  line(15,317,15,340);
	  setcolor(LIGHTGRAY);
	  line(55,317,55,340);
	  line(55,340,15,340);
	}
	else
	{

		setcolor(LIGHTGRAY);
		line(15,317,55,317);
		line(15,317,15,340);
		setcolor(BLACK);
		line(55,317,55,340);
		line(55,340,15,340);
	    /* setcolor(DARKGRAY);
	 rectangle(17,319,53,338);*/
	}
	//if(tols == 12 && st == 12)
}
//start of select colors
int selectcolors()
{
		//	int clr;
     /*	 in.x.ax = 3;
	 int86(0X33, &in, &out);
	 x = out.x.cx;
	 y = out.x.dx;  //
	 cordinate(&btn, &x, &y);  */

	 //1. BLUE
	if(x >= 75 && x <= 103 && y >= 65 && y <= 92)
		{
			setcolor(LIGHTRED);
			rectangle(75,65,103,92);
		       //	if(out.x.bx== 1)
			 if(btn == 1)
			 {
				clr = 1;
				c = 1;
			 }
			  //	return (BLUE);
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(75,65,103,92);
		       //rectangle(68,25,97,55);
		}

		//2. GREEN
		if(x >= 105 && x <= 133 && y >= 65 && y <= 92)
		{
			setcolor(LIGHTRED);
			rectangle(105,65,133,92);

		       //	if(out.x.bx == 1)
			if(btn == 1)
			{
				clr = 2;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(105,65,133,92);
			//rectangle(98,25,127,55);
		}

		//3 CYAN
		if(x >= 75 && x <= 103 && y >= 95 && y <= 122)
		{
			setcolor(LIGHTRED);
			rectangle(75,95,103,122);

			//if(out.x.bx == 1)
			    if(btn == 1)
				{
					clr = 3;
					c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(75,95,103,122);
			//rectangle(68,56,97,85);
		}

		//4. RED
		if(x >= 105 && x <= 133 && y >= 95 && y <= 122)
		{
			setcolor(LIGHTRED);
		       rectangle(105,95,133,122);
		       //rectangle(98,56,127,85);

		       //	if(out.x.bx == 1)
			if(btn == 1)
			  {
					clr = 4;
					c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(105,95,133,122);
			//rectangle(98,56,127,85);
		}

		//5. MAGENTA
		if(x >= 75 && x <= 103 && y >= 125 && y <= 152)
		{
			setcolor(LIGHTRED);
			rectangle(75,125,103,152);
			//rectangle(68,86,97,115);

		       //	if(out.x.bx == 1)
		       if(btn == 1)
			  {
				clr = 5;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(75,125,103,152);
			//rectangle(68,86,97,115);
		}

		//6 BROWN
		if(x >= 105 && x <= 133 && y >= 125 && y <= 152)
		{
			setcolor(LIGHTRED);
			rectangle(105,125,133,152);
			//rectangle(98,86,127,115);

		      //	if(out.x.bx == 1)
		       if(btn == 1)
			 {
				clr = 6;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(105,125,133,152);

			//rectangle(98,86,127,115);
		}

		//7 LIGHTGRAY
		if(x >= 75 && x <= 103 && y >= 155 && y <= 182)
		{
			setcolor(LIGHTRED);
			rectangle(75,155,103,182);
			//rectangle(68,116,97,145);

		       //	if(out.x.bx == 1)
		       if(btn == 1)
			 {
				clr = 7;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(75,155,103,182);
			//rectangle(75,125,103,152);
			//rectangle(68,116,97,145);
		}

		//8 DARKGRAY
		if(x >= 105 && x <= 133 && y >= 155 && y <= 182)
		{
			setcolor(LIGHTRED);
			rectangle(105,155,133,182);
			//rectangle(98,116,127,145);

		      //	if(out.x.bx == 1)
		       if(btn == 1)
			 {
			       clr = 8;	//clr = 8;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(105,155,133,182);
			//rectangle(98,116,127,145);
		}

		//9 LIGHTBLUE
		if(x >= 75 && x <= 103 && y >= 185 && y <= 212)
		{
			setcolor(LIGHTRED);
			rectangle(75,185,103,212);
			//rectangle(68,146,97,175);

		   //	if(out.x.bx == 1)
		      if(btn == 1)
			{
				clr = 9;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(75,185,103,212);
			//rectangle(68,146,97,175);
		}

		//10 LIGHTGREEN
		if(x >= 105 && x <= 133 && y >= 185 && y <= 212)
		{
			setcolor(LIGHTRED);
			rectangle(105,185,133,212);
			//rectangle(98,146,127,175);

		    //	if(out.x.bx == 1)
		      if(btn == 1)
			{
				clr = 10;
				c = 1;
			}
		}

		else
		{
			setcolor(LIGHTGREEN);
			rectangle(105,185,133,212);
			//rectangle(98,146,127,175);
		}

		//11 LIGHTCYAN
		if(x >= 75 && x <= 103 && y >= 215 && y <= 242)
		{
			setcolor(LIGHTRED);
			rectangle(75,215,103,242);
			//rectangle(68,176,97,205);

		      //	if(out.x.bx == 1)
		       if(btn == 1)
			{
				clr = 11;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(75,215,103,242);
			//rectangle(68,176,97,205);
		}

		//12 LIGHTRED
		if(x >= 105 && x <= 133 && y >= 215 && y <= 242)
		{
			setcolor(LIGHTRED);
			rectangle(105,215,133,242);
			//rectangle(98,176,127,205);

		     //	if(out.x.bx == 1)
		       if(btn == 1)
			{
				clr = 12;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(105,215,133,242);
			//rectangle(98,176,127,205);
		}

		//13 LIGHTMAGENTA
		if(x >= 75 && x <= 103 && y >= 245 && y <= 272)
		{
			setcolor(LIGHTRED);
			rectangle(75,245,103,272);
			//rectangle(68,206,97,235);

		      //	if(out.x.bx == 1)
		       if(btn == 1)
			{
				clr = 13;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(75,245,103,272);
			//rectangle(68,206,97,235);
		}

		//14 YELLOW
		if(x >= 105 && x <= 133 && y >= 245 && y <= 272)
		{
			setcolor(LIGHTRED);
			rectangle(105,245,133,272);
			//rectangle(98,206,127,235);

		      //	if(out.x.bx == 1)
		       if(btn == 1)
			{
				clr = 14;
				c = 1;

			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(105,245,133,272);
			//rectangle(98,206,127,235);
		}

		//15 WHITE

		if(x >= 75 && x <= 103 && y >= 275 && y <= 302)
		{
			setcolor(LIGHTRED);
			rectangle(75,275,103,302);
			//rectangle(68,236,97,265);

		       //	if(out.x.bx == 1)
		       if(btn == 1)
			{
				clr = 15;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(75,275,103,302);
			//rectangle(68,236,97,265);
		}

		if(x >= 105 && x <= 133 && y >= 275 && y <= 302)
		{
			setcolor(LIGHTRED);
			rectangle(105,275,133,302);
			//rectangle(68,236,97,265);

		       //	if(out.x.bx == 1)
		       if(btn == 1)
			{
				clr = 0;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(105,275,133,302);
			//rectangle(68,236,97,265);
		}


	hcolors();
	return (clr);
}
// end of selectcolors function

void hcolors()
{
	setcolor(BLACK);
	line(88,318,119,318);
	line(88,318,88,342);
	setcolor(LIGHTGRAY);
	line(119,318,119,342);
	line(119,342,88,342);

	if(c == 0)
	{
	setfillstyle(SOLID_FILL,BLACK);
	bar(90,320,117,340);
	}
	else
	{
	setfillstyle(SOLID_FILL,clr);

	if(clr == 0)
	  bar(90,320,117,340);


	if(clr == 1)
		bar(90,320,117,340);

	if(clr == 2)
		bar(90,320,117,340);

	if(clr == 3)
		bar(90,320,117,340);

	if(clr == 4)
		bar(90,320,117,340);

	if(clr == 5)
		bar(90,320,117,340);

	if(clr == 6)
		bar(90,320,117,340);

	if(clr == 7)
		bar(90,320,117,340);

	if(clr == 8)
		bar(90,320,117,340);

	if(clr == 9)
		bar(90,320,117,340);

	if(clr == 10)
		bar(90,320,117,340);

	if(clr == 11)
		bar(90,320,117,340);

	if(clr == 12)
		bar(90,320,117,340);

	if(clr == 13)
		bar(90,320,117,340);
	if(clr == 14)
		bar(90,320,117,340);
	if(clr == 15)
		bar(90,320,117,340);

	}
}
//start of mainfunction
void mainfunc()
{
	char str[20];
	int ox,oy,x1,x2,y1,y2;
	int cx,cy,rx,ry;

	//styles
       //	int est = 0;
	flag = 0;
	c = 0;

	while(1)
	{
	       //	selectfmenu();
		tols =  selecttools(); //selecttools();
		clr = selectcolors();
		/*styles type */
		//styles();

		/*colors */
		if(c == 0)
		{
			setfillstyle(SOLID_FILL,BLACK);
			setcolor(BLACK);
		}
		else
		{
			setfillstyle(SOLID_FILL,clr);
			setcolor(clr);
		}

		if(msgl == 0)
		{
		       //	setfillstyle(SOLID_FILL,DARKGRAY);
		       /*
		       setfillstyle(CLOSE_DOT_FILL,RED);
			bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
			*/
			setcolor(WHITE);
			outtextxy(14,450,"Select Tools First");
			msgl = 1;
			//setfillstyle(SOLID_FILL,clr);

		}
		 s_styles();
		 setlinestyle(lst,0,1);
		 setfillstyle(fst,clr);
		//rectangle(150,50,getmaxx() - 5,getmaxy() - 50);
		switch(tols)
		{
			case 1:  //	if( tol == 1)
			{
			//rectangle
				sclear();
				flag = 0;
			  //  outtextxy(10,450,"Rectangle");
			    cordinate(&btn, &x, &y);

			    //drawig area 5 pixel inside
				if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
				{

					cordinate(&btn, &x, &y);
					if(btn == 1)
					{
						tx = x;
						ty = y;
					       //	bmouse(151,getmaxx()-6,51,getmaxy() - 51);
						hmouse();
						setcolor(WHITE);
						setwritemode(XOR_PUT);
						setlinestyle(DOTTED_LINE,0,1);
						cordinate(&btn, &x, &y);
						while(btn == 1)  //out.x.bx == 1)
						{
						       //if(x >= 155 && x <= getmaxx() - 10 && y >= 55 && y <= getmaxy() - 55)

							cordinate(&btn, &x, &y);
							rectangle(tx,ty,x,y);
							rectangle(tx,ty,x,y);
							//limiting x cordinate

							if(x < 150 || x > getmaxx() - 5 || y < 50 || y > getmaxy() - 50)
							{
							x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;
							break;
							}
							x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;

						}
						//if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)

					      // if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
					       //{
							setcolor(clr);
							setwritemode(COPY_PUT);
							setlinestyle(lst,0,1);
							rectangle(tx,ty,x,y);
						//}
						smouse();
					}
				}
				break;
			}

			case 2:	//	else if( tol==2)
			{
			//circle
				flag = 0;
				sclear();
			    //	outtextxy(10,450,"Circle");
				cordinate(&btn, &x, &y);
			      //	if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
			       if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
				{
					if(btn == 1) //out.x.bx == 1)
					{
						tx = x;
						ty = y;
						hmouse();

						setcolor(WHITE);


						setlinestyle(DOTTED_LINE,0,1);

						cordinate(&btn, &x, &y);
						while(btn == 1) //out.x.bx == 1)
						{

								setwritemode(XOR_PUT);
						   /*	cordinate(&btn, &x, &y);
							line(tx,ty,x,y);
							line(tx,ty,x,y);
							if(x < 150 || x > getmaxx() - 5 || y < 50 || y > getmaxy() - 50)
							{
							break;
							}     */
							cordinate(&btn, &x, &y);
							rectangle(tx,ty,x,y);
							rectangle(tx,ty,x,y);

							//limiting x cordinate

							if(x < 150 || x > getmaxx() - 5 || y < 50 || y > getmaxy() - 50)
							{
							x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;
							break;
							}
							x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;


						}
						setwritemode(COPY_PUT);
						//center
						if(tx < x)
							cx = tx + abs(tx-x)/2;
						else
							cx = x + abs(tx-x)/2;

					       if(ty < y)
							cy = ty + abs(ty-y)/2;
						else
							cy = y + abs(ty-y)/2;

						//radius
						rx = abs(tx-x)/2;
						ry = abs(ty-y)/2;

						setcolor(clr);
						setwritemode(COPY_PUT);
						setlinestyle(lst,0,1);

						if(rx < ry)
							circle(cx,cy,rx);
						else
							circle(cx,cy,ry);

						smouse();
						}
				 }
				 break;
			}

			case 3://else if(tol == 3)
			{
			//ellipse
				sclear();
				flag = 0;
			   //	outtextxy(10,450,"Ellipse");
				cordinate(&btn, &x, &y);
				//if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
				if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
				{
					if( btn == 1)//out.x.bx == 1)
					{
						tx = x;
						ty = y;
						setwritemode(XOR_PUT);
						setcolor(WHITE);
						setlinestyle(DOTTED_LINE,0,1);
						hmouse();
						cordinate(&btn, &x, &y);
						while(btn == 1) //out.x.bx == 1)
						{
						   /*
							cordinate(&btn, &x, &y);

							line(tx,ty,x,y);
							line(tx,ty,x,y);

							if(x < 150 || x > getmaxx() - 5 || y < 50 || y > getmaxy() - 50)
							{
							break;
							}          */

								cordinate(&btn, &x, &y);
							rectangle(tx,ty,x,y);
							rectangle(tx,ty,x,y);

							//limiting x cordinate

							if(x < 150 || x > getmaxx() - 5 || y < 50 || y > getmaxy() - 50)
							{
							x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;
							break;
							}
							x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;


						}

						setwritemode(COPY_PUT);
						//center
						if(tx < x)
							cx = tx + abs(tx-x)/2;
						else
							cx = x + abs(tx-x)/2;

					       if(ty < y)
							cy = ty + abs(ty-y)/2;
						else
							cy = y + abs(ty-y)/2;

						//radius
						rx = abs(tx-x)/2;
						ry = abs(ty-y)/2;

						setcolor(clr);
					     /*	setwritemode(COPY_PUT);
						setlinestyle(SOLID_LINE,0,1);
					       */
						setwritemode(COPY_PUT);
						setlinestyle(lst,0,1);
						setcolor(clr);
					       /*	if( tx - abs(tx-x) >= 150 && tx + abs(tx-x) <= getmaxx() - 5 && ty - abs(ty-y) >= 50 && ty + abs(ty-y) <= getmaxy() - 50)
							ellipse(tx,ty,0,360,abs(tx-x),abs(ty-y));
						*/
						ellipse(cx,cy,0,360,rx,ry);

						smouse();
					}
				}
				break;
			}

			case 4:	//else if(tol == 4)
			{
			//  freehand
				sclear();
				flag = 0;
			     //	outtextxy(10,450,"Freehand");
				cordinate(&btn, &x, &y);
				setlinestyle(SOLID_LINE,0,1);
				//if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
				if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
				{	  //	if(flag == 0)	  //determine current position
				  if(btn == 1) //out.x.bx == 1)
				  {
						moveto(x,y);    //set current position to x,y cordinate

					      //	hmouse();
						 cordinate(&btn, &x, &y);
						while(btn == 1)  //call function when left button is pressed
						{
							//if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
							   //    if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
							      x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;
							     hmouse();

							     setwritemode(XOR_PUT);

							     setcolor(BLACK);
							     line(x,y,x+3,y-10);
							     line(x,y,x+10,y-10);
							     line(x+3,y-10,x+10,y-10);

							     setwritemode(COPY_PUT);

								setcolor(clr);
								lineto(x,y);
							     smouse();

							cordinate(&btn, &x, &y);
						}

					       //	smouse();
					}// end of if
				}

				break;
			}
			case 5://	else if(tol == 5)
			{
			// lineto
		      //	outtextxy(10,450,"Polygon");
			       sclear();
			       cordinate(&btn, &x, &y);

				setlinestyle(lst,0,1);
				//cordinate(&btn, &x, &y);
				 // if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
				  if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
				  {	//	if(flag == 0)       //determine current position
				  if(flag == 0)
					{
						cordinate(&btn, &x, &y);
						moveto(x,y);    //set current position to x,y cordinate
					 }
					if(btn == 1) //out.x.bx == 1)  //call function when left button is pressed
					{
						cordinate(&btn, &x, &y);
						//hmouse();
						//break d function n exit from loop
						if(x < 150 || x > getmaxx() - 5 || y < 50 || y > getmaxy() - 50)
							{
							x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;
							break;
							}

						x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;
						hmouse();
						putpixel(x,y,clr);
						if(flag == 1)
						{
							lineto(x,y);
						}
					       smouse();
					       //	putpixel(x,y,clr);
						//smouse();

						flag = 1;        //sets key to 1;
					}
				}
				break;
			}

			case 6://else if(tol == 6)
			{
			//straightline
				flag = 0;
				sclear();
			//	outtextxy(10,450,"Line");
				cordinate(&btn, &x, &y);
				//if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
				if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
				{
					if(btn == 1) //out.x.bx == 1)
					{
						tx = x;
						ty = y;

						hmouse();

						setcolor(WHITE);
						setwritemode(XOR_PUT);
						setlinestyle(DOTTED_LINE,0,1);

						cordinate(&btn, &x, &y);
						while(btn == 1) //out.x.bx == 1)
						{

							cordinate(&btn, &x, &y);
							line(tx,ty,x,y);
							line(tx,ty,x,y);

							if(x < 150 || x > getmaxx() - 5 || y < 50 || y > getmaxy() - 50)
							{
							x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;
							break;
							}

							x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;


						}
					     // if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
						     setwritemode(COPY_PUT);
						     if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
						     {
							setcolor(clr);
							setwritemode(COPY_PUT);
							setlinestyle(lst, 0, 1);
							line(tx,ty,x,y);
						     }
					       smouse();
					}
				 }
		break;
		 }

		 case 7: //	else if(tol == 7)
			{
				//rectangle fill					  // bar
				flag = 0;
				sclear();
			  //	outtextxy(10,450,"Solid Rectangle");
			  //	setfillstyle(SOLID_FILL,clr);

				cordinate(&btn, &x, &y);
				// if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
				 if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
				 {
				       /*	in.x.ax = 3;
					int86(0X33, &in, &out);   */
					cordinate(&btn, &x, &y);
					if(btn == 1) //out.x.bx == 1)
					{
						tx = x;
						ty = y;

						 hmouse();

						 setcolor(WHITE);
						setwritemode(XOR_PUT);
						setlinestyle(DOTTED_LINE,0,1);

						 cordinate(&btn, &x, &y);
						while(btn == 1) // out.x.bx == 1)
						{

							cordinate(&btn, &x, &y);

							rectangle(tx,ty,x,y);
							rectangle(tx,ty,x,y);

							if(x < 150 || x > getmaxx() - 5 || y < 50 || y > getmaxy() - 50)
							{
							x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;
							break;
							}

						       x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;

						}
					       //	if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
						      //	if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
						       //	{
							     setcolor(clr);
							     setwritemode(COPY_PUT);
							     setlinestyle(SOLID_LINE,0,1);
								bar(tx,ty,x,y);
						     ///	}
						smouse();
					}
				 }
				 break;
			// background
			}
			case 8: //else if(tol == 8)
			{
			//eraser
				sclear();
				flag = 0;
				setcolor(DARKGRAY);

			    //	outtextxy(10,450,"Eraser");
				cordinate(&btn, &x, &y);
				//if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
					if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
					{
					if(btn == 1) //out.x.bx == 1)
					{
					       //	moveto(x,y);    //set current position to x,y cordinate
						hmouse();
						setwritemode(XOR_PUT);
						do  //out.x.bx == 1)  //call function when left button is pressed
						{
						   setcolor(WHITE);
						      rectangle(x,y,x+5,y+5);
						      rectangle(x,y,x+5, y+5);
						   if(x >= 155 && x <= getmaxx() - 10 && y >= 55 && y<= getmaxy() - 55 && x+3 >= 155 && x+3 <= getmaxx() - 10 && y+3 >= 55 && y+3 <= getmaxy() - 55)
						    {	//		lineto(x,y);

						      cordinate(&btn, &x, &y);
						      setfillstyle(SOLID_FILL,WHITE);

						      bar(x,y,x+3,y+3);

						     }
						     else
							break;
						     cordinate(&btn, &x, &y);
						   //  if(btn != 1);
						     //	break;
						 //	flag = 1;        //sets key to 1;
						}while(btn == 1);
						setwritemode(COPY_PUT);
						smouse();
					//	flag = 0;
							 //check for buton and sets key to 0
					 }// endo of while

				}
				setcolor(clr);
				break;
			}
			case 9://else if(tol == 9)
			{
			//ellipse fill
			  flag = 0;
			  sclear();
			 // outtextxy(10,450,"Fill Ellipse");
			  //setfillstyle(SOLID_FILL,clr);

				cordinate(&btn, &x, &y);
				//if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
				if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
				{
					if(btn == 1)//out.x.bx == 1)
					{
						tx = x;
						ty = y;

						hmouse();
						setcolor(WHITE);
						setwritemode(XOR_PUT);
						setlinestyle(DOTTED_LINE,0,1);
						while(btn == 1) //out.x.bx == 1)
						{
						      /*
							cordinate(&btn, &x, &y);
							//ellipse(tx,ty,abs(tx-x),abs(ty-y),0,360);
							//ellipse(tx,ty,abs(tx-x),abs(ty-y),0,360);
							line(tx,ty,x,y);
							line(tx,ty,x,y);
							if(x < 150 || x > getmaxx() - 5 || y < 50 || y > getmaxy() - 50)
							{
							break;
							}
							 */
							 setwritemode(XOR_PUT);
							cordinate(&btn,&x,&y);
							rectangle(tx,ty,x,y);
							rectangle(tx,ty,x,y);

							if(x < 150 || x > getmaxx() - 5 || y < 50 || y > getmaxy() - 50)
							{
							x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;
							break;
							}
							x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;



						}

					  //	setwritemode(COPY_PUT);
						//center
						if(tx < x)
							cx = tx + abs(tx-x)/2;
						else
							cx = x + abs(tx-x)/2;

					       if(ty < y)
							cy = ty + abs(ty-y)/2;
						else
							cy = y + abs(ty-y)/2;

						//radius
						rx = abs(tx-x)/2;
						ry = abs(ty-y)/2;


						setwritemode(COPY_PUT);
						setcolor(clr);
						setlinestyle(SOLID_LINE,0,1);
					      //	if( tx - abs(tx-x) >= 151 && tx + abs(tx-x) <= getmaxx() - 5 && ty - abs(ty-y) >= 50 && ty + abs(ty-y) <= getmaxy() - 50)
							fillellipse(cx,cy,rx,ry);
					}
				}
				smouse();
				break;
			}

			case 10: //else if(tol == 10)
			{

				clrscr();
				cleardevice();
				closegraph();
			    //	end();
			  //	printf("thank you for using!");

				delay(2000);
				exit(0);
			//exit;
			}
			case 11:
			{//text
				sclear();
				cordinate(&btn, &x, &y);

				if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
				{
					 cordinate(&btn, &x, &y);
					if(out.x.bx == 1)
					{
					       tx = x;
						ty = y;

						hmouse();
					while((ch=getche())!=27)
					{
						strcpy(buff[i++],ch);
			       //	 printf("%d",i);
				 // tx=x;
					if(ch==13)
					{
				     // break;

						y+=textheight(buff);
						x=tx;
						continue;
					}

					if(ch==8 && i>0 )
					{
						i--;
						strcpy(ctn[0],buff[i]);
						x-=textwidth(buff);
						x1=x;
						x2=x+textwidth(buff);
						y1=y;
						y2=y+textheight(buff);
			       //		if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)

					      //	if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
						if(x >= 160 && x <= getmaxx() - 15 && y >= 60 && y <= getmaxy() - 60)
						{

						if(x >= tx)
						{
							setfillstyle(SOLID_FILL,WHITE);
							bar(x1,y1,x2,y2);
						}
						else
						break;
						}
						continue;
					}

				      sprintf(buff,"%c",ch);
				       //	if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)

				      if(x >= 160 && x <= getmaxx() - 15 && y >= 60 && y <= getmaxy() - 60)
					outtextxy(x,y,buff);
				      else
					break;

				      x+=textwidth(buff);

				 } //end of while
					buff[i]=NULL;
				}
				}
			       //	est = 0;
				smouse();
				break;
			}



			case 12:
			{       //new
				sclear();
				setfillstyle(SOLID_FILL,DARKGRAY);
				bar(150,50,getmaxx()-5,getmaxy()-50);

				setfillstyle(SOLID_FILL,WHITE);
				bar(150,50,getmaxx() - 5,getmaxy() - 50);

				setcolor(BROWN);
				rectangle(150,50,getmaxx() - 5,getmaxy() - 50);
				setcolor(clr);
				setfillstyle(SOLID_FILL,clr);
				tols = 0;
				msgl = 0;
			       //	mainfunc();
			       break;
			}


			case 13:
			{        //save
			      //	outtextxy(10,450,"Enter File Name:");
			       sclear();
			       cordinate(&btn,&x,&y);
			       if(x >= 45 && x <= 85 && y >= 25 && y <= 40)
				{
				      if(btn == 1)
				      {
					hmouse();
					savef();
				      }
				}
				smouse();
				break;
			}


			case 14:
			{
				sclear();
				if(x >= 90 && x <= 135 && y >= 25 && y <= 40)
				{
					if(btn ==1)
					{
					    hmouse();
						openf();
				   }   //	btn = 0;
				}
				smouse();
				break;
			}

			//cut
			case 15:
			{

				cordinate(&btn,&x,&y);
				if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
				{
				  if(btn==1)
				  {
					tx=x;
					ty=y;
					a = tx;
					b = ty;
					hmouse();
						setcolor(WHITE);
						setwritemode(XOR_PUT);
						setlinestyle(DOTTED_LINE,0,1);
						cordinate(&btn, &x, &y);


					while(btn==1)
					{
					  cordinate(&btn,&x,&y);
					  rectangle(tx,ty,x,y);
					  rectangle(tx,ty,x,y);

					  if(x < 150 || x > getmaxx() - 5 || y < 50 || y > getmaxy() - 50)
					  {
							x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;

							break;
					    }

						       x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;

							c=x;
							d=y;
					}

					 // setcolor(clr);
					  setwritemode(COPY_PUT);
					  cpy = 0;
					  cut = 1;
					  paste = 1;
					  copyf();

				       }
				}
				smouse();
				break;
			}
			//copy
			case 16:
			{

			       cordinate(&btn,&x,&y);
				if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
				{
				  if(btn==1)
				  {
					tx=x;
					ty=y;
					a = tx;
					b = ty;
					hmouse();
						setcolor(WHITE);
						setwritemode(XOR_PUT);
						setlinestyle(DOTTED_LINE,0,1);
						cordinate(&btn, &x, &y);


					while(btn==1)
					{
					  cordinate(&btn,&x,&y);
					  rectangle(tx,ty,x,y);
					  rectangle(tx,ty,x,y);

					  if(x < 150 || x > getmaxx() - 5 || y < 50 || y > getmaxy() - 50)
					  {
							x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;

							break;
					    }

						       x = x<= 155?155:x;
							x = x >= getmaxx()-10?getmaxx()-10:x;
							y = y <= 55 ?55: y;
							y = y >= getmaxy()-55?getmaxy()-55:y;

							c=x;
							d=y;
					}

					 // setcolor(clr);
					  setwritemode(COPY_PUT);
					  cpy = 1;
					  cut = 0;
					  paste = 1;
					  copyf();

				      }

				}
				smouse();
				break;
			}
			//paste
			case 17:
			{

				cordinate(&btn,&x,&y);
				if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
				{
					if(btn==1)
					{
					       if(paste == 1)
					       {

						tx=x;
						ty=y;
						pastef();
						}
						else
						{
							msgbar();
							setcolor(WHITE);
							outtextxy(14,450,"Select Area First !!");
						}

					}
				}

				break;
			}

			default:
			{
					break;
			}
		}//end of switch

	}//end of while loop
}
// end of mainfunc



void openf(void)
{
  FILE * fp;
  //char *fname;
  int i,j;
 // fname=getdata();
 fname[0] = '\0';
 getstring();
 fp = fopen  (fname,"r+");


// initgraph (&gd,&gm,"C:\\turboc3\\bgi");
  if(fp== NULL)
  {

       //	setfillstyle(SOLID_FILL,DARKGRAY);
      // setfillstyle(CLOSE_DOT_FILL,RED);
       //	bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
	msgbar();
	setcolor(WHITE);
	outtextxy(14,450,"File does not exist: ");
	setcolor(clr);
  //printf("doesnot exist");
  }

  else
  {
 // rectangle(10,10,80,150);
	//setfillstyle(SOLID_FILL,DARKGRAY);
	//setfillstyle(CLOSE_DOT_FILL,RED);
       //	bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
	msgbar();
	setcolor(WHITE);
	outtextxy(14,450,"Please Wait... ");
	setcolor(clr);

  //clear drawing area to load saved picture
	setfillstyle(SOLID_FILL,WHITE);
	bar(150,50,getmaxx()-5,getmaxy()-50);
	setcolor(BROWN);
	rectangle(150,50,getmaxx() - 5,getmaxy() - 50);
	setcolor(clr);
	setfillstyle(SOLID_FILL,clr);
  //end

  for(i=153;i<getmaxx()-8;i++)
  {
     for(j=53;j<getmaxy()-53;j++)
	putpixel(i,j,fgetc(fp));
   }
	//setfillstyle(SOLID_FILL,DARKGRAY);
       //	setfillstyle(CLOSE_DOT_FILL,RED);
	//bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
	msgbar();
	setcolor(WHITE);
	outtextxy(14,450,"Ready");
	setcolor(clr);

   }
// getch();
 fclose(fp);
 // fname=NULL;

// closegraph();
  }

  void savef(void)
  {
  FILE * fp;
  int i,j;
  //char * fname;
 // fname=getdata();
 fflush(stdin);
 fname[0] = NULL;
   getstring();
  //outtextxy(200,150,fname);
  if(strlen(fname) == 0)
  {
	//setfillstyle(SOLID_FILL,DARKGRAY);
	//setfillstyle(CLOSE_DOT_FILL,RED);
	//bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
	msgbar();
	setcolor(WHITE);
	outtextxy(14,450,"File Name Required!!");
	setcolor(clr);

       //	getstring();

  }
  else
  {
  fp=fopen(fname,"w+");

	//setfillstyle(SOLID_FILL,DARKGRAY);
     //	setfillstyle(CLOSE_DOT_FILL,RED);
       //	bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
	msgbar();
	setcolor(WHITE);
	outtextxy(14,450,"Please Wait... ");
	setcolor(clr);


  for(i=153;i<getmaxx()-8;i++)
  {
  for(j=53;j<getmaxy()-53;j++)
  {
	fputc(getpixel(i,j),fp);
  }
  }

	//	setfillstyle(SOLID_FILL,DARKGRAY);
	//setfillstyle(CLOSE_DOT_FILL,RED);
	//bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
	msgbar();
	setcolor(WHITE);
	outtextxy(14,450,"Ready");
	setcolor(clr);
  }
  fclose(fp);
  //f=0;

 // strcpy(fname,"\0");

  }


void getstring()
{

	int i = 0; //j = 0; //f = 0;
	int x1, x2, y1,y2;
       //	char t[20];
	fflush(stdin);

       //setcolor(WHITE);
	//setfillstyle(SOLID_FILL,DARKGRAY);
       //	setfillstyle(CLOSE_DOT_FILL,RED);
	//bar(7,getmaxy()-38, getmaxx()-7,getmaxy()-7);
	msgbar();
	setcolor(WHITE);
	outtextxy(14,450,"Enter File Name:");
       //	setcolor(clr);

       //	outtextxy(10,450,"Enter File Name: ");
	x = 150;
	y = 450;
      //	moveto(20,450);
  while(1) //while((ch=getche())!=27)
 {
// strcpy(buff[i++],ch);
			       //	 printf("%d",i);
 ch = getch();				 // tx=x;
 if(ch==13)
 {
    y+=textheight(buff);
    x=tx;
    break;
   // continue;
 }
 if(ch == 27)
	break;

   if(ch==8 && i>0 )
    {

				 i--;
				 fname[i] = '\0';
				 strcpy(ctn[0],buff[i]);
				 x-=textwidth(buff);
				 x1=x;
				 x2=x+textwidth(buff);
				 y1=y;
				 y2=y+textheight(buff);
			       //		if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
				 // if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
				 // {
				 // er = getbkcolor();
				// j--;
				 if(x >= 150)
				 {
				  setfillstyle(CLOSE_DOT_FILL,RED);
				 bar(x1,y1,x2,y2);
				 }
				 else
				    getstring();				 //}

				 continue;
				 }

				// printf("%s",fname);  */
			   /*   if(f == 0)
				 {
				       strcpy(fname,ch);
				       f = 1;
				 }
				 else
				    strcat(fname,ch);     */
   sprintf(buff,"%c",ch);
			     fname[i] = ch;
			     i++;
				       //	if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
				     // if(x >= 150 && x <= getmaxx() - 5 && y >= 50 && y <= getmaxy() - 50)
					outtextxy(x,y,buff);
					//x=x+10;
					 x+=textwidth(buff);
					 if(i >15)
						break;

					}
				       //	outtextxy(20,20,fname);
					buff[i]=NULL;
				       //	f = 0;
 }


void styles()
{
// setcolor(WHITE);
 /* initial no condition */
 if(ln == 0 && fil == 0);
 {
	setfillstyle(SOLID_FILL,DARKGRAY);
	//rectacngle(15,348,55,435);
	bar(15,348,55,435);
	lst = 0;
	fst = 1;

 }
/*line style */
 if(ln == 1 && fil == 0)
 {
	fil = 0;
	st = 1;
	setfillstyle(SOLID_FILL,DARKGRAY);
	setcolor(BLACK);
	//rectangle(15,348,55,435);
	bar(15,348,55,435);

/* solid line 0 */
// rectangle(15,350,55,360);
line(20,355,50,355);
setlinestyle(0,0,1);
 setcolor(LIGHTGRAY);
 line(15,350,55,350);
 line(15,350,15,360);
 setcolor(BLACK);
 line(55,350,55,360);
 line(55,360,15,360);

/* Dotted line 1 */
// rectangle(15,365,55,375);
setlinestyle(1,0,1);
 line(20,370,50,370);
setlinestyle(0,0,1);
 setcolor(LIGHTGRAY);
 line(15,365,55,365);
 line(15,365,15,375);
 setcolor(BLACK);
 line(55,365,55,375);
 line(55,375,15,375);

/*center line 2*/
// rectangle(15,380,55,390);
 setlinestyle(2,0,1);
 line(20,385,50,385);

 setlinestyle(0,0,1);
 setcolor(LIGHTGRAY);
 line(15,380,55,380);
 line(15,380,15,390);
 setcolor(BLACK);
 line(55,380,55,390);
 line(55,390,15,390);

/*dashed line 3*/
/* rectangle(15,395,55,405);
 setlinestyle(3,0,1);
 line(20,400,50,400);
 setlinestyle(0,0,1);
 setcolor(LIGHTGRAY);
 line(15,395,55,395);
 line(15,395,15,405);
 setcolor(BLACK);
 line(55,395,55,405);
 line(55,405,15,405);    */
}

 /* fill pattern */

 if( ln == 0 && fil == 1)
 {
	ln = 0;
	st = 1;
 setlinestyle(0,0,1);
    setfillstyle(SOLID_FILL,DARKGRAY);
    setcolor(WHITE);
    //rectangle(15,348,55,435);
    bar(15,348,55,435);

 /* solid fill 1 */
 //rectangle(18,350,33,365);
 setfillstyle(1,WHITE);
 bar(20,352,32,363);

 setcolor(LIGHTGRAY);
 line(18,350,34,350);
 line(18,350,18,365);
 setcolor(BLACK);
 line(34,350,34,365);
 line(34,365,18,365);

 /* line fill 2 */
 //rectangle(37,350,52,365);
 setfillstyle(LINE_FILL,WHITE);
 bar(39,352,50,363);

 setcolor(LIGHTGRAY);
 line(37,350,52,350);
 line(37,350,37,365);
 setcolor(BLACK);
 line(52,350,52,365);
 line(52,365,37,365);

 /*ltslash 3 */
 //rectangle(18,367,33,382);
 setfillstyle(3,WHITE);
 bar(20,369,31,380);

 setcolor(LIGHTGRAY);
 line(18,367,34,367);
 line(18,367,18,382);
 setcolor(BLACK);
 line(34,367,34,382);
 line(34,382,18,382);


 /*slash 4*/
 setfillstyle(4,WHITE);
 //rectangle(37,367,52,382);
 bar(39,369,50,380);
 //bar(18,384,33,399);

 setcolor(LIGHTGRAY);
 line(37,367,52,367);
 line(37,367,37,382);
 setcolor(BLACK);
 line(52,367,52,382);
 line(52,382,37,382);

/*bkslash 5 */
setfillstyle(5,WHITE);
// rectangle(18,384,33,399);
bar(20,386,31,397);

setcolor(LIGHTGRAY);
 line(18,384,34,384);
 line(18,384,18,399);
 setcolor(BLACK);
 line(34,384,34,399);
 line(34,399,18,399);


/*ltbakslash 6 */
setfillstyle(6,WHITE);
// rectangle(37,384,52,399);
bar(39,386,50,397);

 setcolor(LIGHTGRAY);
 line(37,384,52,384);
 line(37,384,37,399);
 setcolor(BLACK);
 line(52,384,52,399);
 line(52,399,37,399);

/* hatch fill 7*/
setfillstyle(7,WHITE);
// rectangle(18,401,33,416);
bar(20,403,31,414);

setcolor(LIGHTGRAY);
 line(18,401,34,401);
 line(18,401,18,416);
 setcolor(BLACK);
 line(34,401,34,416);
 line(34,416,18,416);


/*xhatch fill 8*/
setfillstyle(8,WHITE);
 //rectangle(37,401,52,416);
 bar(39,403,50,414);

 setcolor(LIGHTGRAY);
 line(37,401,52,401);
 line(37,401,37,416);
 setcolor(BLACK);
 line(52,401,52,416);
 line(52,416,37,416);

/*interlaeave 9 */
setfillstyle(9,WHITE);
// rectangle(18,418,33,433);
 bar(20,420,31,431);

 setcolor(LIGHTGRAY);
 line(18,418,34,418);
 line(18,418,18,433);
 setcolor(BLACK);
 line(34,401,34,433);
 line(34,433,18,433);


 /* closed_dot 11 */
setfillstyle(11,WHITE);
 //rectangle(37,418,52,433);
 bar(39,420,50,431);

 setcolor(LIGHTGRAY);
 line(37,418,52,418);
 line(37,418,37,433);
 setcolor(BLACK);
 line(52,418,52,433);
 line(52,433,37,433);
 }
}
/*select styles */


void s_styles()
{
//line style */
    if(ln == 1 && fil == 0 && st == 1)
    {
		fst = 1;
		cordinate(&btn, &x, &y);
		if(x >= 15 && x <= 55 && y >= 350 && y <= 360)
		{
			if(btn == 1)
				lst = 0;

		}


/* Dotted line 1 */
// rectangle(15,365,55,375);
/*
setlinestyle(1,0,1);
 line(20,370,50,370);
*/
	if( x >= 15 && x <= 55 && y >= 365 && y <= 375)
	{
		if(btn == 1)
			lst = 1;

	}
/*center line 2*/
// rectangle(15,380,55,390);
/*setlinestyle(2,0,1);
 line(20,385,50,385);
*/
	if(x >= 15 && x <= 55 && y >= 380 && y <= 390)
	{
		if(btn == 1)
			lst = 2;

	}


	 //hightlight selectd line type
	      if(lst == 0)      //solid line
	      {
			//lst = 0;
			setlinestyle(0,0,1);
			setcolor(BLACK);
			line(15,350,55,350);
			line(15,350,15,360);
			setcolor(LIGHTGRAY);
			line(55,350,55,360);
			line(55,360,15,360);
			}
			else
			{
			setlinestyle(0,0,1);
			setcolor(LIGHTGRAY);
			line(15,350,55,350);
			line(15,350,15,360);
			setcolor(BLACK);
			line(55,350,55,360);
			line(55,360,15,360);
			}

		if(lst == 1)
		{
			       //	lst = 1;

				setlinestyle(0,0,1);
				setcolor(BLACK);
				line(15,365,55,365);
				line(15,365,15,375);
				setcolor(LIGHTGRAY);
				line(55,365,55,375);
				line(55,375,15,375);
		}
		else
		{
			setlinestyle(0,0,1);
			setcolor(LIGHTGRAY);
			line(15,365,55,365);
			line(15,365,15,375);
			setcolor(BLACK);
			line(55,365,55,375);
			line(55,375,15,375);
		}

	      if(lst == 2)
		{
			//lst = 2;
			setlinestyle(0,0,1);
			setcolor(BLACK);
			line(15,380,55,380);
			line(15,380,15,390);
			setcolor(LIGHTGRAY);
			line(55,380,55,390);
			line(55,390,15,390);
		}
		else
		{
			setlinestyle(0,0,1);
			setcolor(LIGHTGRAY);
			line(15,380,55,380);
			line(15,380,15,390);
			setcolor(BLACK);
			line(55,380,55,390);
			line(55,390,15,390);
		}
		//end of highlight line
}
//END OF LINE STYLE

// fill pattern
 if( ln == 0 && fil == 1 && st == 1)
{
	setlinestyle(0,0,1);
	lst = 0;
    /*
    setfillstyle(SOLID_FILL,DARKGRAY);
    setcolor(WHITE);
    //rectangle(15,348,55,435);
    bar(15,348,55,435);
    */
 /* solid fill 1 */
 //rectangle(18,350,33,365);
/// setfillstyle(1,WHITE);
// bar(20,352,32,363);
	cordinate(&btn,&x,&y);
   if(x >= 18 && x <= 33 && y >= 350 && y <= 365)
   {
	if(btn == 1)
	   fst = 1;
   }
 /* line fill 2 */
 //rectangle(37,350,52,365);
/* setfillstyle(LINE_FILL,WHITE);
 bar(39,352,50,363);
*/
	if(x >= 37 && x <= 52 && y >=350 && y <365)
	{
		if(btn == 1)
			fst = 2;

	}
 /*ltslash 3
 //rectangle(18,367,33,382);
setfillstyle(3,WHITE);
 bar(20,369,31,380);
*/
      if(x >= 18 && x <= 34 && y >= 367 && y <= 382)
      {
		if(btn == 1)
		    fst = 3;
      }

 /*slash 4
 setfillstyle(4,WHITE);
 //rectangle(37,367,52,382);
 bar(39,369,50,380);
 //bar(18,384,33,399);
*/
	if(x >= 37 && x <= 52 && y >= 367 && y <= 382)
      {
		if(btn == 1)
			fst = 4;
      }
/*bkslash 5
/*setfillstyle(5,WHITE);
// rectangle(18,384,33,399);
bar(20,386,31,397);
*/
	if(x >= 18 && x <= 33 && y >= 384 && y <= 399)
      {
		if(btn == 1)
		  fst = 5;
      }
/*ltbakslash 6
/*setfillstyle(6,WHITE);
// rectangle(37,384,52,399);
bar(39,386,50,397);
*/
       if(x >= 37 && x <= 52 && y >= 384 && y <= 399)
      {
		if(btn == 1)
		     fst = 6;
      }
/* hatch fill 7
/*setfillstyle(7,WHITE);
// rectangle(18,401,33,416);
bar(20,403,31,414);
*/
	if(x >= 18 && x <= 33 && y >= 401 && y <= 416)
      {
		if(btn == 1)
			fst = 7;

      }
/*xhatch fill 8
/*setfillstyle(8,WHITE);
 //rectangle(37,401,52,416);
 bar(39,403,50,414);  */

	if(x >= 37 && x <= 52 && y >= 401 && y <= 416)
	{
		if(btn == 1)
			fst = 8;

	}
/*interlaeave 9
/*setfillstyle(9,WHITE);
// rectangle(18,418,33,433);
 bar(20,420,31,431);
*/
	if(x >= 18 && x <= 33 && y >= 418 && y <= 433)
	{
		if(btn == 1)
			fst = 9;

	}
 /* closed_dot 11
/*setfillstyle(11,WHITE);
 //rectangle(37,418,52,433);
 bar(39,420,50,431);
*/
	if(x >= 37 && x <= 52 && y >= 418 && y <= 433)
	{
		if(btn == 1)
			fst = 11;

	}

	//highlight selectd fill style

	if(fst == 1)
	{
	//fst = 1;
	setcolor(BLACK);
	line(18,350,34,350);
	line(18,350,18,365);
	setcolor(LIGHTGRAY);

	line(34,350,34,365);
	line(34,365,18,365);
	}
	else
	{
	setcolor(LIGHTGRAY);
	line(18,350,34,350);
	line(18,350,18,365);
	setcolor(BLACK);
	line(34,350,34,365);
	line(34,365,18,365);
	}

	      if(fst == 2)
	      {
		setcolor(BLACK);
		line(37,350,52,350);
		line(37,350,37,365);
		  setcolor(LIGHTGRAY);
		line(52,350,52,365);
		line(52,365,37,365);
		}
		else
		{
		setcolor(LIGHTGRAY);
		line(37,350,52,350);
		line(37,350,37,365);
		setcolor(BLACK);
		line(52,350,52,365);
		line(52,365,37,365);
		}

		if(fst == 3)
		{
		//fst = 3;
		setcolor(BLACK);
		line(18,367,34,367);
		line(18,367,18,382);

		setcolor(LIGHTGRAY);
		line(34,367,34,382);
		line(34,382,18,382);
		}
		else
		{
		setcolor(LIGHTGRAY);
		line(18,367,34,367);
		line(18,367,18,382);
		setcolor(BLACK);
		line(34,367,34,382);
		line(34,382,18,382);
		}

		if(fst == 4)
		{
		//fst = 4;
		setcolor(BLACK);
		line(37,367,52,367);
		line(37,367,37,382);
		setcolor(LIGHTGRAY);
		line(52,367,52,382);
		line(52,382,37,382);
		}
		else
		{
		setcolor(LIGHTGRAY);
		line(37,367,52,367);
		line(37,367,37,382);
		setcolor(BLACK);
		line(52,367,52,382);
		line(52,382,37,382);
		}
	if(fst == 5)
	{
		//fst = 5;
		setcolor(BLACK);
		line(18,384,34,384);
		line(18,384,18,399);
		setcolor(LIGHTGRAY);
		line(34,384,34,399);
		line(34,399,18,399);
		}
		else
		{
		setcolor(LIGHTGRAY);
		line(18,384,34,384);
		line(18,384,18,399);
		setcolor(BLACK);
		line(34,384,34,399);
		line(34,399,18,399);
		}

		if(fst == 6)
		{

		setcolor(BLACK);
		line(37,384,52,384);
		line(37,384,37,399);
		setcolor(LIGHTGRAY);
		line(52,384,52,399);
		line(52,399,37,399);
		}
		else
		{
		setcolor(LIGHTGRAY);
		line(37,384,52,384);
		line(37,384,37,399);
		setcolor(BLACK);
		line(52,384,52,399);
		line(52,399,37,399);
		}

		if(fst == 7)
		{

		setcolor(BLACK);
		line(18,401,34,401);
		line(18,401,18,416);
		setcolor(LIGHTGRAY);
		line(34,401,34,416);
		line(34,416,18,416);
		}
		else
		{
		setcolor(LIGHTGRAY);
		line(18,401,34,401);
		line(18,401,18,416);
		setcolor(BLACK);
		line(34,401,34,416);
		line(34,416,18,416);
		}

		if(fst == 8)
		{
		setcolor(BLACK);
		line(37,401,52,401);
		line(37,401,37,416);
		setcolor(LIGHTGRAY);
		line(52,401,52,416);
		line(52,416,37,416);
		}
		else
		{
		setcolor(LIGHTGRAY);
		line(37,401,52,401);
		line(37,401,37,416);
		setcolor(BLACK);
		line(52,401,52,416);
		line(52,416,37,416);
		}

		if(fst == 9)
	       {
		setcolor(BLACK);
		line(18,418,34,418);
		line(18,418,18,433);
		setcolor(LIGHTGRAY);
		line(34,401,34,433);
		line(34,433,18,433);
		}
		else
		{
		setcolor(LIGHTGRAY);
		line(18,418,34,418);
		line(18,418,18,433);
		setcolor(BLACK);
		line(34,401,34,433);
		line(34,433,18,433);
		}

		if(fst == 11)
		{
		setcolor(BLACK);
		line(37,418,52,418);
		line(37,418,37,433);
		setcolor(LIGHTGRAY);
		line(52,418,52,433);
		line(52,433,37,433);
		}
		else
		{
		setcolor(LIGHTGRAY);
		line(37,418,52,418);
		line(37,418,37,433);
		setcolor(BLACK);
		line(52,418,52,433);
		line(52,433,37,433);
		}
	//end of highlight fill style
}
//end of fill style
}

//store selected area
void copyf(void)
{
  FILE * fp;
  int i,j;

  fp=fopen("temp","w");

  msgbar();

  setcolor(WHITE);
  outtextxy(14,450,"Please Wait... ");
  setcolor(clr);

  hmouse();

  // store selected region
  for(j=b;j<d;j++)
  for(i=a;i<c;i++)
	fputc(getpixel(i,j),fp);

  smouse();

  msgbar();
	setcolor(WHITE);
	outtextxy(14,450,"Ready to Paste.");
	setcolor(clr);

  fclose(fp);
  //f=0;

 // strcpy(fname,"\0");

}

void pastef(void)
{
  FILE * fp;
  //char *fname;
  int i,j;
 // fname=getdata();
// fname[0] = '\0';
// getstring();
 fp = fopen  ("temp","rb");


// initgraph (&gd,&gm,"C:\\turboc3\\bgi");
cordinate(&btn, &x, &y);
if(btn == 1)
{
  if(fp== NULL)
  {
	msgbar();
	setcolor(WHITE);
	outtextxy(14,450,"Select Area First !!");
	setcolor(clr);
  //printf("doesnot exist");
  }

  else
  {
 // rectangle(10,10,80,150);
	msgbar();
	setcolor(WHITE);
	outtextxy(14,450,"Please Wait... ");
	setcolor(clr);
	hmouse();

	if(ty+abs(d-b) < getmaxy()-55 && tx+abs(c-a) < getmaxx()-10)
	{

		for(j=ty;j<ty+d-b;j++)
			for(i=tx;i<tx+c-a;i++)
			{

				putpixel(i,j,fgetc(fp));
			}

		msgbar();
		setcolor(WHITE);
		outtextxy(10,450,"Done!");
		if(cut == 1)
		{
			setfillstyle(SOLID_FILL,WHITE);
			bar(a,b,c,d);
		}
	}
	else
	{
	  msgbar();
	  outtextxy(14,450,"Select Another Region!!");
	}
 }
	smouse();


	setcolor(clr);

   }
// getch();
 fclose(fp);

}

void sclear()
{
	cut = 0;
	paste = 0;
	cpy = 0;
}