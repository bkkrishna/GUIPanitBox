#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

union REGS in, out;
int x,y;
int tols, clr,bg,c; // flag = 0;
int tx,ty;

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
	cprintf("Bachelor in Software Engineering (I/I)");
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
//end of naming
	delay(2000);

//start of calling function for main porpose
	clrscr();
	graphics();
	head();      //program name
	closebtn();  //close btn
	drawarea(); // drawing area

	tools(); 	//calling tools
	colors();  //calling colors
	mouse();	//show mouse
	selecttools();
	selectcolors();
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

//start of tools function
void tools()
{
  //tools
  setcolor(WHITE);
  rectangle(10,5,60,23);
  setfillstyle(SOLID_FILL,WHITE);
  floodfill(15,6,WHITE);
  setcolor(BLACK);
  outtextxy(16,12,"TOOLS");

  setcolor(WHITE);
  rectangle(20,30,50,50);      //rectangle
  setcolor(LIGHTGREEN);        //selection tools
  rectangle(15,25,55,55);      //selection

  setcolor(WHITE);
  circle(35,75,10);
  setcolor(LIGHTGREEN);				//circle
  rectangle(15,60,55,90);

  setcolor(WHITE);
  ellipse(35,107,0,360,10,7);  // ellipse
  setcolor(LIGHTGREEN);
  rectangle(15,95,55,120);

  setcolor(WHITE);
  line(20,130,50,145);         //freehand
  setcolor(LIGHTGREEN);
  rectangle(15,125,55,150);

  //lineto
  setcolor(WHITE);
  line(25,160,35,160);        //lineto
  line(25,160,20,180);
  line(20,180,50,180);
  line(50,180,50,173);
  line(50,173,32,173);
  line(32,173,35,160);
  setcolor(LIGHTGREEN);
  rectangle(15,155,55,185);

  //freehand
  setcolor(WHITE);
  line(20,195,20,215);
  line(25,205,50,205);
  setcolor(LIGHTGREEN);
  rectangle(15,190,55,220);

  //background
	setcolor(WHITE);
	ellipse(35,235,0,360,10,2);
	line(25,235,25,250);
	line(45,235,45,250);
	ellipse(35,243,180,360,10,2);
	ellipse(35,242,180,360,10,2);
	ellipse(35,241,180,360,10,2);
	ellipse(35,240,180,360,10,2);
	ellipse(35,250,180,360,10,2);
	setcolor(LIGHTGREEN);
	rectangle(15,225,55,260);

	//earaser
	rectangle(15,265,55,295);
	setcolor(WHITE);
	rectangle(22,270,42,290);
	rectangle(42,273,45,288);
 //	setfillstyle(SOLID_FILL,BLUE);
	floodfill(43,275,WHITE);
	rectangle(30,270,35,290);
	floodfill(33,273,WHITE);

	//text
	setcolor(LIGHTGREEN);
	rectangle(15,300,55,330);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	fillellipse(35,315,12,10);
  //	settextstyle(SANS_SERIF_FONT,0,0);
  //	outtextxy(27,293,"A");

//  getch();
}
//end of tools function

//start of colors function
void colors()
{
  int i,j,c = 1;
  int x1,x2,y1,y2,cx1,cx2,cy1,cy2;
  //color box
  setcolor(WHITE);
  rectangle(70,5,125,23);
  setfillstyle(SOLID_FILL,WHITE);
  floodfill(73,7,WHITE);
  setcolor(BLACK);
  settextstyle(DEFAULT_FONT,0,0);
  outtextxy(75,12,"COLORS");
  setcolor(WHITE);

  //print colors
	cx1 = 72, cx2 = 92, cy1 = 30, cy2 = 50;
	for(i = 0; i <= 7; i++)
	{
		for(j = 0; j < 2; j++)
		{  setcolor(c);
			setfillstyle(SOLID_FILL,c);
			rectangle(cx1, cy1, cx2, cy2);
			floodfill(cx1+3,cy1+3,c);
			cx1 += 30, cx2 += 30;
			c++;
		}
		cx1 = 72, cx2 = 92;
		cy1 += 30, cy2 += 30;
	}

	//color option
	setcolor(LIGHTGREEN);
	cx1 = 68, cx2 = 97, cy1 = 25, cy2 = 55;
	for( i = 0; i < 7; i++)
	{
		for(j = 0; j < 2; j++)
		{
			rectangle(cx1,cy1,cx2,cy2);
			cx1 = 98, cx2 = 127;
		}
		cx1 = 68, cx2 = 97;
		cy1 += 30, cy2 += 30;
	}
}
//close of colors function

//start of head function
void head()
{
	setcolor(RED);
	rectangle(310,5,450,20);
	setfillstyle(CLOSE_DOT_FILL,RED);
	floodfill(311,7,RED);
	setcolor(YELLOW);
	outtextxy(333,10,"GUI PaintBox");
}
//end of head function

//start of drawarea function
void drawarea()
{
	 setcolor(BROWN);

	rectangle(150,25,getmaxx() - 5,getmaxy() -5);
}
//end of drawarea

//start of closebtn function
void closebtn()
{
	setcolor(RED);
	rectangle(615,3,getmaxx()-5,20);
	setfillstyle(SOLID_FILL,RED);
	floodfill(616,6,RED);
	setcolor(LIGHTCYAN);
	line(615,3,getmaxx()-5,20);
	line(getmaxx()-5,3,615,20);
	//chose
	setcolor(LIGHTGREEN);
	rectangle(615,3,getmaxx() - 5,20);
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

//start of select tools
int selecttools()
{
		in.x.ax = 3;
		int86(0X33, &in, &out);

		x = out.x.cx;
		y = out.x.dx;

		//rectangle   1
		if(x >= 15 && x <= 55 && y >= 25 && y<= 55)
		{
			setcolor(LIGHTRED);        //selection tools
			rectangle(15,25,55,55);      //selection

			if(out.x.bx == 1)
				tols = 1;
		}
		else
		{
			setcolor(LIGHTGREEN);        //selection tools
			rectangle(15,25,55,55);      //default
		}

		//circle       2
		if(x >= 15 && x <= 55 && y >= 60 && y <= 90)
		{
			setcolor(LIGHTRED);				//circle
			rectangle(15,60,55,90);

			if(out.x.bx == 1)
				tols = 2;
		}
		else
		{
			setcolor(LIGHTGREEN);				//circle
			rectangle(15,60,55,90);
		}

		//ellipse     3
		if( x >= 15 && x <= 55 && y >= 95 && y <= 120)
		{
			setcolor(LIGHTRED);
			rectangle(15,95,55,120);

			if(out.x.bx == 1)
				tols = 3;
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(15,95,55,120);
		}

		//freehand    4
		if(x >= 15 && x <= 55 && y >= 125 && y <= 150)
		{
			setcolor(LIGHTRED);
			rectangle(15,125,55,150);

			if(out.x.bx == 1)
				tols = 4;
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(15,125,55,150);
		}

		//lineto             5
		if(x >= 15 && x <= 55 && y >= 155 && y <= 185)
		{
			setcolor(LIGHTRED);
			rectangle(15,155,55,185);

			if(out.x.bx == 1)
				tols = 5;
		}
		else
		{
			 setcolor(LIGHTGREEN);
			 rectangle(15,155,55,185);
		}

		//straight line  6
		if(x >= 15 && x <= 55 && y >= 190 && y <= 220)
		{
			setcolor(LIGHTRED);
			rectangle(15,190,55,220);

			if(out.x.bx == 1)
				tols = 6;
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(15,190,55,220);
		}

		//background   7
		if( x >= 15 && x <= 55 && y >= 225 && y <= 260 )
		{
			setcolor(LIGHTRED);
			rectangle(15,225,55,260);

			if(out.x.bx == 1)
				tols = 7;
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(15,225,55,260);
		}

	  //eraser  8
	  if(x >= 15 && x <= 55 && y >= 265 && y <= 295)
	  {
			setcolor(LIGHTRED);
			rectangle(15,265,55,295);

			if(out.x.bx == 1)
				tols = 8;
	  }
	  else
	  {
			setcolor(LIGHTGREEN);
			rectangle(15,265,55,295);
	  }

	  //text    9
	  if(x >= 15 && x <= 55 && y >= 300 && y <= 330)
	  {
			setcolor(LIGHTRED);
			rectangle(15,300,55,330);

			if(out.x.bx == 1)
				tols = 9;
	  }
	  else
	  {
			setcolor(LIGHTGREEN);
			rectangle(15,300,55,330);
	  }

	  //close button  10
	  if(x >= 615 && x <= (getmaxx() - 5) && y >= 3 && y <= 20)
	  {
			setcolor(LIGHTRED);
			rectangle(615,3,getmaxx() - 5,20);

			if(out.x.bx == 1)
				tols = 10;
	  }
	  else
	  {
			setcolor(LIGHTGREEN);
			rectangle(615,3,getmaxx() - 5,20);
	  }
  return (tols);
}
//end of selecttools

//start of select colors
int selectcolors()
{
		//	int clr;
	 in.x.ax = 3;
	 int86(0X33, &in, &out);
	 x = out.x.cx;
	 y = out.x.dx;

	 //1. BLUE
	if(x >= 68 && x <= 97 && y >= 25 && y <= 55)
		{
			setcolor(LIGHTRED);
			rectangle(68,25,97,55);
			if(out.x.bx== 1)
			 {
				clr = 1;
				c = 1;
			 }
			  //	return (BLUE);
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(68,25,97,55);
		}

		//2. GREEN
		if(x >= 98 && x <= 127 && y >= 25 && y <= 55)
		{
			setcolor(LIGHTRED);
			rectangle(98,25,127,55);

			if(out.x.bx == 1)
			{
				clr = 2;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(98,25,127,55);
		}

		//3 CYAN
		if(x >= 68 && x <= 97 && y >= 56 && y <= 85)
		{
			setcolor(LIGHTRED);
			rectangle(68,56,97,85);

			if(out.x.bx == 1)
				{
					clr = 3;
					c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(68,56,97,85);
		}

		//4. RED
		if(x >= 98 && x <= 127 && y >= 56 && y <= 85)
		{
			setcolor(LIGHTRED);
			rectangle(98,56,127,85);

			if(out.x.bx == 1)
			  {
					clr = 4;
					c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(98,56,127,85);
		}

		//5. MAGENTA
		if(x >= 68 && x <= 97 && y >= 86 && y <= 115)
		{
			setcolor(LIGHTRED);
			rectangle(68,86,97,115);

			if(out.x.bx == 1)
			  {
				clr = 5;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(68,86,97,115);
		}

		//6 BROWN
		if(x >= 98 && x <= 127 && y >= 86 && y <= 115)
		{
			setcolor(LIGHTRED);
			rectangle(98,86,127,115);

			if(out.x.bx == 1)
			 {
				clr = 6;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(98,86,127,115);
		}

		//7 LIGHTGRAY
		if(x >= 68 && x <= 97 && y >= 116 && y <= 145)
		{
			setcolor(LIGHTRED);
			rectangle(68,116,97,145);

			if(out.x.bx == 1)
			 {
				clr = 7;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(68,116,97,145);
		}

		//8 DARKGRAY
		if(x >= 98 && x <= 127 && y >= 116 && y <= 145)
		{
			setcolor(LIGHTRED);
			rectangle(98,116,127,145);

			if(out.x.bx == 1)
			 {
				clr = 8;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(98,116,127,145);
		}

		//9 LIGHTBLUE
		if(x >= 68 && x <= 97 && y >= 146 && y <= 175)
		{
			setcolor(LIGHTRED);
			rectangle(68,146,97,175);

			if(out.x.bx == 1)
			{
				clr = 9;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(68,146,97,175);
		}

		//10 LIGHTGREEN
		if(x >= 98 && x <= 127 && y >= 146 && y <= 175)
		{
			setcolor(LIGHTRED);
			rectangle(98,146,127,175);

			if(out.x.bx == 1)
			{
				clr = 10;
				c = 1;
			}
		}

		else
		{
			setcolor(LIGHTGREEN);
			rectangle(98,146,127,175);
		}

		//11 LIGHTCYAN
		if(x >= 68 && x <= 97 && y >= 176 && y <= 205)
		{
			setcolor(LIGHTRED);
			rectangle(68,176,97,205);

			if(out.x.bx == 1)
			{
				clr = 11;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(68,176,97,205);
		}

		//12 LIGHTRED
		if(x >= 98 && x <= 127 && y >= 176 && y <= 205)
		{
			setcolor(LIGHTRED);
			rectangle(98,176,127,205);

			if(out.x.bx == 1)
			{
				clr = 12;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(98,176,127,205);
		}

		//13 LIGHTMAGENTA
		if(x >= 68 && x <= 97 && y >= 206 && y <= 235)
		{
			setcolor(LIGHTRED);
			rectangle(68,206,97,235);

			if(out.x.bx == 1)
			{
				clr = 13;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(68,206,97,235);
		}

		//14 YELLOW
		if(x >= 98 && x <= 127 && y >= 206 && y <= 235)
		{
			setcolor(LIGHTRED);
			rectangle(98,206,127,235);

			if(out.x.bx == 1)
			{
				clr = 14;
				c = 1;

			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(98,206,127,235);
		}

		//15 WHITE

		if(x >= 68 && x <= 97 && y >= 236 && y <= 265)
		{
			setcolor(LIGHTRED);
			rectangle(68,236,97,265);

			if(out.x.bx == 1)
			{
				clr = 15;
				c = 1;
			 }
		}
		else
		{
			setcolor(LIGHTGREEN);
			rectangle(68,236,97,265);
		}

	return (clr);
}
// end of selectcolors function

//start of mainfunction
void mainfunc()
{
	int flag = 0;
	c = 0;
	while(1)
	{
		tols =  selecttools(); //selecttools();
		clr = selectcolors();
		if(c == 0)
		{
			setfillstyle(SOLID_FILL,WHITE);
			setcolor(WHITE);
		}
		else
		{
			setfillstyle(SOLID_FILL,clr);
			setcolor(clr);
		}

		switch(tols)
		{
			case 1:  //	if( tol == 1)
			{
			//rectangle
				flag = 0;
				in.x.ax = 3;
				int86(0X33, &in, &out);
				x = out.x.cx;
				y = out.x.dx;

				if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
				{
					in.x.ax = 3;
					int86(0X33, &in, &out);
					if(out.x.bx == 1)
					{
						tx = x;
						ty = y;
						while( out.x.bx == 1)
						{
							in.x.ax = 3;
							int86(0X33, &in, &out);
							x = out.x.cx;
							y = out.x.dx;
						}
						if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
							rectangle(tx,ty,x,y);
					}
				}
				break;
			}

			case 2:	//	else if( tol==2)
			{
			//circle
				flag = 0;
				in.x.ax = 3;
				int86(0X33, &in, &out);
				x = out.x.cx;
				y = out.x.dx;
				if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
				{
					if(out.x.bx == 1)
					{
						tx = x;
						ty = y;
						while( out.x.bx == 1)
						{
							in.x.ax = 3;
							int86(0X33, &in, &out);
							x = out.x.cx;
							y = out.x.dx;
						}
						if( tx - abs(tx-x) >= 151 && tx + abs(tx-x) <= getmaxx() - 6 && ty - abs(tx-x) >= 26 && ty + abs(tx-x) <= getmaxy() - 6)
							circle(tx,ty,abs(x-tx));
						}
				 }
				 break;
			}

			case 3://else if(tol == 3)
			{
			//ellipse
				flag = 0;
				in.x.ax = 3;
				int86(0X33, &in, &out);
				x = out.x.cx;
				y = out.x.dx;
				if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
				{
					if(out.x.bx == 1)
					{
						tx = x;
						ty = y;
						while( out.x.bx == 1)
						{
							in.x.ax = 3;
							int86(0X33, &in, &out);
							x = out.x.cx;
							y = out.x.dx;
						}
						if( tx - abs(tx-x) >= 151 && tx + abs(tx-x) <= getmaxx() - 6 && ty - abs(ty-y) >= 26 && ty + abs(ty-y) <= getmaxy() - 6)
							ellipse(tx,ty,0,360,abs(tx-x),abs(ty-y));
					}
				}
				break;
			}

			case 4:	//else if(tol == 4)
			{
			//  freehand
				flag = 0;
				in.x.ax = 3;
				int86(0x33, &in, &out);
				x = out.x.cx;      //current x cordinate
				y = out.x.dx;      //current y cordinate
				if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
					 {	  //	if(flag == 0)	  //determine current position
				  if(out.x.bx == 1)
				  {
						moveto(x,y);    //set current position to x,y cordinate

						while(out.x.bx == 1)  //call function when left button is pressed
						{
							if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
								lineto(x,y);
							in.x.ax = 3;
							int86(0X33, &in, &out);
							x = out.x.cx;
							y = out.x.dx;
						}
					}// end of if
				}
				break;
			}
			case 5://	else if(tol == 5)
			{
			// lineto

				in.x.ax = 3;
				int86(0x33, &in, &out);
				x = out.x.cx;      //current x cordinate
				y = out.x.dx;      //current y cordinate
				  if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
					 {	//	if(flag == 0)       //determine current position
					if(flag == 0)
					{
						moveto(x,y);    //set current position to x,y cordinate
					 }
				if( out.x.bx == 1)  //call function when left button is pressed
				{
					putpixel(x,y,clr);
					lineto(x,y);
					flag = 1;        //sets key to 1;
				}
					}
				break;
			}

			case 6://else if(tol == 6)
			{
			//straightline
				flag = 0;
				in.x.ax = 3;
				int86(0X33, &in, &out);
				x = out.x.cx;
				y = out.x.dx;
				if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
				{
					if(out.x.bx == 1)
					{
						tx = x;
						ty = y;
						while( out.x.bx == 1)
						{
							in.x.ax = 3;
							int86(0X33, &in, &out);
							x = out.x.cx;
							y = out.x.dx;
						}
						if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
							line(tx,ty,x,y);
					}
				 }
		break;
		 }

		 case 7: //	else if(tol == 7)
			{
				//rectangle fill					  // bar
				flag = 0;

			  //	setfillstyle(SOLID_FILL,clr);
				in.x.ax = 3;
				int86(0x33, &in, &out);
				x = out.x.cx;      //current x cordinate
				y = out.x.dx; 	 //current y cordinate
				 if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
				 {
					in.x.ax = 3;
					int86(0X33, &in, &out);
					if(out.x.bx == 1)
					{
						tx = x;
						ty = y;
						while( out.x.bx == 1)
						{
							in.x.ax = 3;
							int86(0X33, &in, &out);
							x = out.x.cx;
							y = out.x.dx;
						}
						if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
							bar(tx,ty,x,y);

					}
				 }
				 break;
			// background
			}
			case 8: //else if(tol == 8)
			{
			//eraser
				flag = 0;
				setcolor(BLACK);

				in.x.ax = 3;
				int86(0x33, &in, &out);
				x = out.x.cx;      //current x cordinate
				y = out.x.dx; 	 //current y cordinate
				if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
				{
					if(out.x.bx == 1)
					{
						moveto(x,y);    //set current position to x,y cordinate
						while( out.x.bx == 1)  //call function when left button is pressed
						{
							if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
								lineto(x,y);
							in.x.ax = 3;
							int86(0X33, &in, &out);
							x = out.x.cx;
							y = out.x.dx;

						 //	flag = 1;        //sets key to 1;
						}
					//	flag = 0;
							 //check for buton and sets key to 0
					 }// endo of while

				}
				setcolor(clr);
				break;
			}
			case 9://else if(tol == 9)
			{
			// text
			  flag = 0;
			  //setfillstyle(SOLID_FILL,clr);
				in.x.ax = 3;
				int86(0X33, &in, &out);
				x = out.x.cx;
				y = out.x.dx;
				if(x >= 151 && x <= getmaxx() - 6 && y >= 26 && y <= getmaxy() - 6)
				{
					if(out.x.bx == 1)
					{
						tx = x;
						ty = y;
						while( out.x.bx == 1)
						{
							in.x.ax = 3;
							int86(0X33, &in, &out);
							x = out.x.cx;
							y = out.x.dx;
						}
						if( tx - abs(tx-x) >= 151 && tx + abs(tx-x) <= getmaxx() - 6 && ty - abs(ty-y) >= 26 && ty + abs(ty-y) <= getmaxy() - 6)
							fillellipse(tx,ty,abs(tx-x),abs(ty-y));
					}
				}
				break;
			}

			case 10: //else if(tol == 10)
			{
				clrscr();
				closegraph();
				end();
			  //	printf("thank you for using!");
				delay(2000);
				exit(0);
			//exit;
			}
			default:
			{
					break;
			}
		}//end of switch

	}//end of while loop
}
// end of mainfunc

void end()
{
	int i;
	clrscr();
	textcolor(RED);
	textbackground(LIGHTCYAN);
	gotoxy(5,4);
	cprintf("<=============================>DEVELOPED BY<============================>");
	delay(1000);
	gotoxy(13,7);
	delay(1000);
	cprintf("B.K.");
  //	delay(1000);
	cprintf("Krishna ");
  //	delay(1000);
	cprintf("Magar");
	delay(1000);
	gotoxy(50,9);
	delay(1000);
	cprintf("Ghan ");
  //	delay(1000);
	cprintf(" Bahadur ");
  //	delay(1000);

	cprintf(" Thapa");
	delay(1000);
	gotoxy(13,11);

	cprintf("Mukesh");
  //	delay(1000);//
	cprintf("  Bhattarai");
	delay(1000);
	gotoxy(50,13);
	cprintf("Sushil ");
  //	delay(1000);
	cprintf(" Ale ");
  //	delay(1000);
	cprintf(" Magar");
	delay(1000);
	gotoxy(13,15);
	cprintf("Sushil");
  //	delay(1000);
	cprintf("  G.C.  ");

	delay(1000);
	gotoxy(50,17);

	cprintf("Sushil");
	//delay(1000);
	cprintf(" Timilshina");
	delay(100);

	gotoxy(19,20);
	cprintf("Bachelor in Software Engineering (I/I)");
	delay(100);
	gotoxy(17,22);
	cprintf("Gandaki College of Engineering and Science");
	 textcolor(RED);
	 textbackground(BLACK);
	gotoxy(3,2);
	 for (i = 0; i < 76; i++)      //upper boud
	 {
	  //	gotoxy(i,1);

		cprintf("\\");
		delay(100);
	 }
	 for(i = 2; i < 24; i++) // right bound
	 {
		gotoxy(79,i);
		cprintf("/");
		delay(100);
	 }

	 for( i = 78; i > 3; i--) //lower bound
	 {
		gotoxy(i,24);
		cprintf("//");
		delay(100);
	 }

	 for( i = 24; i > 2; i--)     // left bound
	 {
		gotoxy(3,i);
		cprintf("\\" );
		delay(100);
	 }
	 clrscr();
	 gotoxy(3,2);
	 textcolor(WHITE);
	 cprintf("THANK");
	 delay(100);
	 cprintf("  U ");
	 delay(100);
	 cprintf("  FOR ");
	 delay(100);
	 cprintf("  USING");
	 delay(100);
	 cprintf(" OUR  ");
	 delay(100);
	  cprintf(" SOFTWARE ");
	  gotoxy(60,24);
	  cprintf("BEST  ");
	  delay(100);
	  cprintf(" OF ");
	  delay(100);
	  cprintf(" LUCK ");
 }



