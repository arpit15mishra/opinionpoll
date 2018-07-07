#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<malloc.h>
#include<dos.h>




	union REGS i, o;
	struct SREGS s ;


	void initmouse()
	{
		i.x.ax = 0;
		int86(0x33, &i, &o);
		if (o.x.ax == 0)
		{
		      cout<<"mouse could not be initialized";
		}

	}

	void show()
	{
		i.x.ax = 1;
		int86(0x33, &i, &o);
	}


	void hide()
	{
		i.x.ax = 2;
		int86(0x33, &i, &o);
	}
	void restrict(int x1, int y1, int x2, int y2)
	{ i.x.ax = 7;
	i.x.cx = x1;
	i.x.dx = x2;
	int86(0x33,&i,&o);

	i.x.ax = 8;
	i.x.cx = y1;
	i.x.dx = y2;
	int86(0x33,&i,&o);
	}


	void getpos(int *button, int *x, int *y)
	{
		i.x.ax = 3;
		int86(0x33, &i, &o);
		*button = o.x.bx;
		*x = o.x.cx;
		*y = o.x.dx;
	}

	void setpos(int x, int y)
	{
		i.x.ax = 4;
		i.x.cx = x;
		i.x.dx = y;
		int86(0x33, &i, &o);
	}






void setbackground()
{
	cleardevice();
	setbkcolor(WHITE);
	int pts[8];
	for (int l = 0; l<640; l += 8)
	{
		for (int k = 0; k<480; k += 8)
		{
			pts[0] = l;
			pts[1] = k;
			pts[2] = l + 8;
			pts[3] = k;
			pts[4] = l + 8;
			pts[5] = k + 8;
			pts[6] = l;
			pts[7] = k + 8;

			if ((l % 16 == 0) && (k % 16 == 0))
			{
				setcolor(8);
				setfillstyle(1, WHITE);
				fillpoly(4, pts);
			}
			else
			{
				setcolor(WHITE);
				setfillstyle(1, 7);
				fillpoly(4, pts);
			}
		}

	}
}

void image(int x, int y, char *s)
{
	ifstream f(s);
	char ch;



	for (int i = 0; i<64 * 2; i += 2)
	{
		for (int j = 0; j<2 * 64 + 1; j += 2)
		{
			f.get(ch);
			if (ch == '0')
			{
				putpixel(x + j, y + i, 8);
				putpixel(x + j + 1, y + i, 8);
				putpixel(x + j, y + i + 1, 8);
				putpixel(x + j + 1, y + i + 1, 8);

			}
			else if (ch == '1')
			{
				putpixel(x + j, y + i, WHITE);
				putpixel(x + j + 1, y + i, WHITE);
				putpixel(x + j, y + i + 1, WHITE);
				putpixel(x + j + 1, y + i + 1, WHITE);

			}

			else if (ch == '\n' || ch == '\r')
			{
				break;
			}

			if (f.eof())
				break;
		}
		if (f.eof())
			break;

	}

	f.close();
}


class circularbox
{
	int x1, y1, x2, y2;
	int x,y;
	char *string;
	void *p;
public:
	circularbox()
	{
	}

	circularbox(int x, int y, char *string)
	{
	this->x=x;
	this->y=y;
		strcpy(this->string, string);
		x1 = x - textwidth(string) / 2 - 20;
		y1 = y - textheight(string) / 2 - 20;
		x2 = x + textwidth(string) / 2 + 20;
		y2 = y + textheight(string) / 2 + 20;

	}


	~circularbox()
	{
		farfree(p);
	}

	void setvalues(int x,int y,char *string);
	void render();
	};


	void circularbox::setvalues(int x, int y, char *string)
	{        this->x=x;
	this->y=y;
		strcpy(this->string, string);
		x1 = x - textwidth(string) / 2 - 20;
		y1 = y - textheight(string) / 2 - 20;
		x2 = x + textwidth(string) / 2 + 20;
		y2 = y + textheight(string) / 2 + 20;

	}

	void circularbox::render()
	{
	settextstyle(1, 0, 1);
	setcolor(8);
	ellipse(x-6, y-6, 0, 360, textwidth(string) / 2 + 20, textheight(string) / 2 + 20);
	fillellipse(x, y, textwidth(string) / 2 + 18, textheight(string) / 2 + 18);

	ellipse(x, y, 0, 360, textwidth(string) / 2 + 20, textheight(string) / 2 + 20);
	ellipse(x, y, 0, 360, textwidth(string) / 2 + 18, textheight(string) / 2 + 18);

	setfillstyle(1, 7);
	fillellipse(x, y, textwidth(string) / 2 + 18, textheight(string) / 2 + 18);

	setcolor(8);
	outtextxy(x - (textwidth(string) / 2), y - ((textheight(string) * 2) / 3), string);




	}







class box
{
	int x1, y1, x2, y2;
	int pts[8];
	void *p;
	char *address;



public:
	box(int x, int y, char *s)
	{

		settextstyle(1, 0, 1);

		address = s;

		x1 = (x - 68);
		y1 = (y - 68);
		x2 = (x + 68);
		y2 = (y + 68);
	}

	void render();
	int check(int button,int dx,int dy);



	~box()
	{
		farfree(p);
	}

	};




	void box::render()
	{
		pts[0] = (x1 - 4);
		pts[1] = y1 + 4;
		pts[2] = x2 - 4;
		pts[3] = y1 + 4;
		pts[4] = x2 - 4;
		pts[5] = y2 + 4;
		pts[6] = x1 - 4;
		pts[7] = y2 + 4;

		setcolor(8);

		setfillstyle(1, 8);
		fillpoly(4, pts);

		pts[0] = (x1);
		pts[1] = (y1);
		pts[2] = (x2);
		pts[3] = (y1);
		pts[4] = (x2);
		pts[5] = (y2);
		pts[6] = (x1);
		pts[7] = (y2);

		setcolor(8);
		rectangle(x1, y1, x2, y2);
		setfillstyle(1, 7);
		fillpoly(4, pts);
		image(x1 + 4, y1 + 4, address);
		unsigned area;
		area = imagesize(x1, y1, x2, y2);

		p = farmalloc(area);
		getimage(x1, y1, x2, y2, p);


	}
	int box::check(int button, int dx, int dy)
	{
		if (dx>x1&&dy>y1&&dx<x2&&dy<y2)
		{
			putimage(x1, y1, p, NOT_PUT);
		if (button == 1)
		{
			return 1;
		}
		}
		else {
			putimage(x1, y1, p, COPY_PUT);
		}

		return 0;
	}



	class rectbox//,int cx,int cy,int b1 )
	{
		int x1, y1, x2, y2;
		int x, y;
		int pts[8];
		char *string;
		void *p;
	public:
		rectbox()
		{
		}
		rectbox(int x, int y, char *s)
		{
			string = s;
			this->x = x;
			this->y = y;
			settextstyle(1, 0, 1);
			x1 = (x - (textwidth(string) / 2) - 20);
			y1 = (y - textheight(string) / 2 - 10);
			x2 = (x + (textwidth(string) / 2 + 20));
			y2 = (y + textheight(string) / 2 + 10);

		}


		~rectbox()
		{
			farfree(p);
		}

		void setvalues(int x, int y, char *s);
		void render();
		int check(int button, int dx, int dy);
	};



	void rectbox::setvalues(int x, int y, char *s)
	{
		string = s;
		this->x = x;
		this->y = y;
		settextstyle(1, 0, 1);
		x1 = (x - (textwidth(string) / 2) - 20);
		y1 = (y - textheight(string) / 2 - 10);
		x2 = (x + (textwidth(string) / 2 + 20));
		y2 = (y + textheight(string) / 2 + 10);

	}
	void rectbox::render()
	{
		pts[0] = (x - (textwidth(string) / 2) - 20 - 6);
		pts[1] = (y - textheight(string) / 2 - 10) + 6;
		pts[2] = (x + (textwidth(string) / 2) + 20) - 6;
		pts[3] = (y - textheight(string) / 2 - 10) + 6;
		pts[4] = (x + (textwidth(string) / 2 + 20)) - 6;
		pts[5] = (y + textheight(string) / 2 + 10) + 6;
		pts[6] = (x - (textwidth(string) / 2) - 20) - 6;
		pts[7] = (y + textheight(string) / 2 + 10) + 6;

		setcolor(8);

		setfillstyle(1, 8);
		fillpoly(4, pts);



		setcolor(8);
		rectangle(x1, y1, x2, y2);
		pts[0] = (x - (textwidth(string) / 2) - 20);
		pts[1] = (y - textheight(string) / 2 - 10);
		pts[2] = (x + (textwidth(string) / 2) + 20);
		pts[3] = (y - textheight(string) / 2 - 10);
		pts[4] = (x + (textwidth(string) / 2 + 20));
		pts[5] = (y + textheight(string) / 2 + 10);
		pts[6] = (x - (textwidth(string) / 2) - 20);
		pts[7] = (y + textheight(string) / 2 + 10);



		setfillstyle(1, 7);
		fillpoly(4, pts);
		setcolor(8);
		outtextxy(x - (textwidth(string) / 2), y - ((textheight(string) * 2) / 3), string);

		unsigned area;
		area = imagesize(x1, y1, x2, y2);

		p = farmalloc(area);
		getimage(x1, y1, x2, y2, p);

	}
	int rectbox::check(int button, int dx, int dy)
	{

		if (dx>x1&&dy>y1&&dx<x2&&dy<y2)
		{
			putimage(x1, y1, p, NOT_PUT);
			if (button == 1)
			{
				return 1;
			}
		}
		else {
			putimage(x1, y1, p, COPY_PUT);
		}

		return 0;
	}










void label(int x, int y, char *s)
{
	line(x - textwidth(s) / 2, y, x + textwidth(s) / 2, y);
	outtextxy(x - textwidth(s) / 2, y, s);
	line(x - textwidth(s) / 2, y + textheight(s) + 2, x + textwidth(s) / 2, y + textheight(s) + 2);

}



class dialogbox
{
	int x1, y1, x2, y2;
	char *s[10];
	int pts[8];
	char **choice;
	char *string;

public:
	dialogbox(char *st, char **ch)
	{

		settextstyle(1, 0, 1);
		x1 = (getmaxx() / 2 - 150);
		y1 = (getmaxy() / 2 - 100);

		x2 = (getmaxx() / 2 + 150);
		y2 = (getmaxy() / 2 + 100);

		string = st;
		choice = ch;


	}
	int render();

};

int dialogbox::render()
{



	pts[0] = (getmaxx() / 2 - 150);
	pts[1] = (getmaxy() / 2 - 100);
	pts[2] = (getmaxx() / 2 + 150);
	pts[3] = (getmaxy() / 2 - 100);
	pts[4] = (getmaxx() / 2 + 150);
	pts[5] = (getmaxy() / 2 + 100);
	pts[6] = (getmaxx() / 2 - 150);
	pts[7] = (getmaxy() / 2 + 100);

	setfillstyle(1, 7);
	fillpoly(4, pts);
	setcolor(8);
	char chr[10][30];
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<29; j++)
		{
			if (string[i * 29 + j] == '\0')
			{
				chr[i][j] = '\0';
				break;
			}
			else
				chr[i][j] = string[i * 29 + j];
		}
		chr[i][j] = '\0';

		if (string[i * 29 + j] == '\0')
			break;
	}

	for (int l = 0; l<i; l++)
	{
		outtextxy(x1 + 8, y1 + 10 + l * textheight(chr[l]), chr[l]);
	}
	rectbox b1(x1 + 50 + 0 * (300 / 2), y1 + i * textheight(chr[i - 1]) + ((180 - i * textheight(chr[i - 1])) * 2) / 3, choice[0]);

	rectbox b2(x1 + 50 + 1 * (300 / 2), y1 + i * textheight(chr[i - 1]) + ((180 - i * textheight(chr[i - 1])) * 2) / 3, choice[1]);
	b1.render();
	b2.render();
	int button, dx, dy;
	::show();
	while (1)
	{
		::getpos(&button, &dx, &dy);
		if (b1.check(button, dx, dy) == 1)
		{
			return 1;
		}
		if (b2.check(button, dx, dy) == 1)
		{
			return 0;
		}
	}
}

class textbox
{
	char string[80];
	int x1, y1, x2, y2;
	int pts[8];
	void *p;

public:
	textbox(int x, int y)
	{
		settextstyle(1, 0, 1);
		x1 = x;
		y1 = y;

		x2 = (x + 300);
		y2 = (y + 5 + textheight("P"));

		strcpy(string, "\0");
	}


	char* gettext();

	void render()
	{

		pts[0] = x1 - 4;
		pts[1] = y1 + 4;
		pts[2] = x2 - 4;
		pts[3] = y1 + 4;
		pts[4] = x2 - 4;
		pts[5] = y2 + 4;
		pts[6] = x1 - 4;
		pts[7] = y2 + 4;

		setcolor(8);

		setfillstyle(1, 8);
		fillpoly(4, pts);

		pts[0] = x1;
		pts[1] = y1;
		pts[2] = x2;
		pts[3] = y1;
		pts[4] = (x2);
		pts[5] = (y2);
		pts[6] = (x1);
		pts[7] = (y2);



		setcolor(8);
		rectangle(x1, y1, x2, y2);



		setfillstyle(1, WHITE);
		fillpoly(4, pts);
		unsigned area;
		area = imagesize(x1, y1, x2, y2);

		p = farmalloc(area);
		getimage(x1, y1, x2, y2, p);


	}

	int check(int button,int dx,int dy);

	~textbox()
	{
		farfree(p);
	}

	};

	int textbox::check(int button, int dx, int dy)
	{

		if (dx>x1&&dy>y1&&dx<x2&&dy<y2)
		{
			putimage(x1, y1, p, NOT_PUT);
		if (button == 1)
		{
			return 1;
		}
		}
		else {
			putimage(x1, y1, p, COPY_PUT);
		}

		 return 0;

	}



char* textbox::gettext()
{
	char ch;
	char chr[2] = " \0";

	settextstyle(1, 0, 1);
	setcolor(8);
	rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
	rectangle(x1, y1, x2, y2);

	setfillstyle(1, WHITE);
	floodfill(x1 + 3, y1 + 3, 8);
	outtextxy(x1 + 1, y1 + 1, string);
	ch = getch();
	while (ch != '\r')
	{
		chr[0] = ch;
		strcat(string, chr);
		setcolor(8);
		rectangle(x1 - 1, y1 - 1, x2, y2);
		rectangle(x1, y1, x2, y2);
		setfillstyle(1, WHITE);
		floodfill(x1 + 3, y1 + 3, 8);
		outtextxy(x1 + 1, y1 + 1, string);
		ch = getch();
	}
	getimage(x1, y1, x2, y2, p);
	return(string);
}

void messagebox(int x1, int y1, int x2, int y2, char *string)
{
	char s[10][100];
	int pts[8];
	rectangle(x1, y1, x2, y2);
	setcolor(8);
	pts[0] = x1;
	pts[1] = y1;
	pts[2] = x2;
	pts[3] = y1;
	pts[4] = x2;
	pts[5] = y2;
	pts[6] = x1;
	pts[7] = y2;
	setfillstyle(1, 7);
	fillpoly(4, pts);
	int len;
	len = (x2-x1) / (textwidth("D"));


	int i = 0;
	int k = 0, j = 0;
	while (string[k] != '\0')
	{

		if (j == len)
		{
			i++;
			s[i][j] = '\0';
			j = 0;
		}
		else {
			s[i][j] = string[k];
			j++;
			k++;
		}

	}

	s[i][j] = '\0';

	for (int l = 0; l <= i; l++)
	{
		outtextxy(x1 + 5, y1 + 5 + textheight("P")*l, s[l]);
	}
}
