#include"base.cpp"
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<malloc.h>
#include<dos.h>

void feedback();

void end();
void login();
void portal();

	void issuemenu(char *s)
	{
		cleardevice();

		setbackground();
		int pts[8];
		int midy = getmaxy() / 2;
		int midx = getmaxx() / 2;
		rectbox opinion(midx, 25, "OPINION POLE                                     ");
		rectbox logout(300, 25, "logout");

		opinion.render();
		logout.render();
		pts[0] = 50 - 6;
		pts[1] = 50 + 6;
		pts[2] = 590 - 6;
		pts[3] = 50 + 6;
		pts[4] = 590 - 6;
		pts[5] = 2 * midy + 6 - 30;
		pts[6] = 50 - 6;
		pts[7] = 2 * midy + 6 - 30;


		setfillstyle(1, 8);
		fillpoly(4, pts);

		pts[0] = 50;
		pts[1] = 50;
		pts[2] = 590;
		pts[3] = 50;
		pts[4] = 590;
		pts[5] = 2 * midy - 30;
		pts[6] = 50;
		pts[7] = 2 * midy - 30;

		setcolor(8);
		setfillstyle(1, 0);
		fillpoly(4, pts);



		label(getmaxx() / 2, 60, s);
		messagebox(70, 90, 560, 250, "this department include various authorities of the institute involed in the effective functioning of the institute. ");

		box feedbacks(120,300 , "feed.txt");
		label(120,300,"FEEDBACK");
		box back(300, 300, "BACK.txt");
		label(300,300,"BACK");
		box survey(480, 300, "survey.txt");
		label(500,300,"SURVEY");
		int button, dx, dy;
		char ch;
		survey.render();
		feedbacks.render();
		back.render();
		::show();
		while (1)
		{
			getpos(&button, &dx, &dx);
			if (feedbacks.check(button, dx, dy))
			{
				feedback();
				portal();

			}
			else
			if (back.check(button, dx, dy))
			{
				portal();
			}
			else
			if (logout.check(button, dx, dy))
			{
				login();
			}
			else
			if (survey.check(button, dx, dx))
			{
			       surveysheet v;
			       v.getsurveysheet("document,dat");
			       v.takesurvey("document.dat","analysis.dat");
			       portal();
			}
			else if(kbhit())
			{
			ch=getch();
			if(ch=='1')
			{feedback();
			portal();
			}
			if(ch=='2')
			{	portal();
			}
			if(ch=='3')
			{ surveysheet v;
			       v.getsurveysheet("document,dat");
			       v.takesurvey("document.dat","analysis.dat");
			       portal();
			}
			if(ch=='0')
			{end();}

			 }
		}


	}





	void feedback()
	{

		cleardevice();
		setbackground();
		int pts[8];
		int midy = getmaxy() / 2;
		int midx = getmaxx() / 2;
		rectbox opinion(midx, 25, "OPINION POLE                                     ");
		opinion.render();
		pts[0] = 50 - 6;
		pts[1] = 50 + 6;
		pts[2] = 590 - 6;
		pts[3] = 50 + 6;
		pts[4] = 590 - 6;
		pts[5] = 2 * midy + 6 - 30;
		pts[6] = 50 - 6;
		pts[7] = 2 * midy + 6 - 30;


		setfillstyle(1, 8);
		fillpoly(4, pts);

		pts[0] = 50;
		pts[1] = 50;
		pts[2] = 590;
		pts[3] = 50;
		pts[4] = 590;
		pts[5] = 2 * midy - 30;
		pts[6] = 50;
		pts[7] = 2 * midy - 30;

		setcolor(8);
		setfillstyle(1, 0);
		fillpoly(4, pts);
		label(midx, 120, "FEEDBACK");
		settextstyle(1, 0, 1);

		ofstream fout;
		fout.open("feedback.txt");
		int i = 0;
		int l = 0;
		char ch;
		char chr[2] = " \0";
		char frag[20][55];
		for (int s = 0; s < 20; s++)
		{

			frag[s][0] = '\0';

		}
		settextstyle(1, 0, 1);
		outtextxy(70, 460, "use '#' to submit the feedback");
		ch = getch();
		while (ch != '#')
		{

			if (ch == '\r' || ch == '\n')
			{
				l++;
				i = 0;
				fout.put(ch);
			}
			else {

				fout.put(ch);
				chr[0] = ch;
				strcat(frag[l], chr);
				setcolor(8);
				outtextxy(70 + 1, 160 + 1 + l * textheight("p"), frag[l]);
				i = textwidth(frag[l]);
				i++;
				if (i >= 500)
				{
					l++;
					i = 0;
				}
			}


			ch = getch();


		}

		fout.close();

	}

	void introduction()
	{
		int choice;
		setbkcolor(8);
		int pts[8];
		int    midx = getmaxx() / 2;
		int    midy = getmaxy() / 2;
		setbackground();
		for (int i = 0; i<midy; i = i + 10)
		{
			settextstyle(1, 0, 6);
			setcolor(1);
			int pts[8];

			pts[0] = 50;
			pts[1] = 0;
			pts[2] = 590;
			pts[3] = 0;
			pts[4] = 590;
			pts[5] = 2 * midy;
			pts[6] = 50;
			pts[7] = 2 * midy;



			setfillstyle(1, 3);
			fillpoly(4, pts);



			pts[0] = (midx - (textwidth("POLLING SOFTWARE") / 2) - 20);
			pts[1] = (i - 10);
			pts[2] = (midx + (textwidth("POLLING SOFTWARE") / 2) + 20);
			pts[3] = i - 10;
			pts[4] = (midx + (textwidth("POLLING SOFTWARE") / 2 + 20));
			pts[5] = (i + 2 * textheight("P") + 20);
			pts[6] = (midx - (textwidth("POLLING SOFTWARE") / 2) - 20);
			pts[7] = (i + 2 * textheight("P") + 20);;




			setfillstyle(1, YELLOW);
			fillpoly(4, pts);
			setcolor(8);


			outtextxy(midx - textwidth("POLL SOFTWARE") / 2, i + textheight("P"), "POLL SOFTWARE");
			outtextxy(midx - textwidth("UIET OPINION") / 2, i, "UIET OPINION");
			delay(300);
		}
		settextstyle(1, 0, 1);
		outtextxy(midx + 20, midy + 200, "Press any key to continue.");
		getch();



	}

	void portal();
	void end();
	     void mainmenu();

		void login()
		{
			cleardevice();
			setbackground();
			int pts[8];
			int midy = getmaxy() / 2;
			int midx = getmaxx() / 2;
			rectbox opinion(midx, 25, "OPINION POLE                                     ");
			opinion.render();
			pts[0] = 50 - 6;
			pts[1] = 50 + 6;
			pts[2] = 590 - 6;
			pts[3] = 50 + 6;
			pts[4] = 590 - 6;
			pts[5] = 2 * midy + 6 - 30;
			pts[6] = 50 - 6;
			pts[7] = 2 * midy + 6 - 30;


			setfillstyle(1, 8);
			fillpoly(4, pts);

			pts[0] = 50;
			pts[1] = 50;
			pts[2] = 590;
			pts[3] = 50;
			pts[4] = 590;
			pts[5] = 2 * midy - 30;
			pts[6] = 50;
			pts[7] = 2 * midy - 30;

			setcolor(8);
			setfillstyle(1, 0);
			fillpoly(4, pts);
			student studentlogin;
			char *ch[30]={"re-enter","return"};
			box account(getmaxx() / 2, 150, "account.txt");
			label(110, 250, "ROLLNO");
			textbox rollno(180, 250);
			label(110, 300, "PASSWORD");
			textbox password(180, 300);
			rectbox logins(getmaxx() / 2, 370, "LOGIN");
			rectbox exits(getmaxx() / 2, 420, "EXIT");
			logins.render();
			rollno.render();
			account.render();
			password.render();
			exits.render();
			int button, dx, dy;
			show();
			while (1)
			{
				getpos(&button, &dx, &dy);
				if (rollno.check(button, dx, dy))
				{
						strcpy(studentlogin.rollno, rollno.gettext());

				}
				if (password.check(button, dx, dy))
				{
					strcpy(studentlogin.password, password.gettext());
				}
				if (logins.check(button, dx, dy))
				{
				       /*	if (studentlogin.password[0] == '\0'||studentlogin.rollno[0] == '\0')
					{
						dialogbox d("None of the fields can be left empty!!", ch);
						if (d.render())
						{
							login();
						}
						else
						{
							mainmenu();
						}
					}
					else {
						if (studentlogin.check())
						{
							portal();
							studentlogin.name[0] = '\0';
							studentlogin.password[0] = '\0';
							studentlogin.rollno[0] = '\0';
							studentlogin.position[0] = '\0';
							studentlogin.department[0] = '\0';
						}
					} */

					portal();

				}
				if (exits.check(button, dx, dy))
				{
					end();
				}
			}
		}


	void registration()
	{
		setbackground();
		int pts[8];
		int midy = getmaxy() / 2;
		int midx = getmaxx() / 2;
		rectbox(midx, 25, "OPINION POLE                                     ");
		pts[0] = 50 - 6;
		pts[1] = 50 + 6;
		pts[2] = 590 - 6;
		pts[3] = 50 + 6;
		pts[4] = 590 - 6;
		pts[5] = 2 * midy + 6 - 30;
		pts[6] = 50 - 6;
		pts[7] = 2 * midy + 6 - 30;


		setfillstyle(1, 8);
		fillpoly(4, pts);

		pts[0] = 50;
		pts[1] = 50;
		pts[2] = 590;
		pts[3] = 50;
		pts[4] = 590;
		pts[5] = 2 * midy - 30;
		pts[6] = 50;
		pts[7] = 2 * midy - 30;

		setcolor(8);
		setfillstyle(1, 0);
		fillpoly(4, pts);
		char *s[20] = { "ROLLNO:","NAME:","DEPARMENT:","PASSWORD","POSITION" };

		for (int i = 0; i < 5; i++)
		{
			label(120, (getmaxy() - 100) / 7 * (i+1)+80, s[i]);
		}
		textbox rollno(200, (getmaxy() - 100) / 7 * (1) + 80);
		textbox name(200, (getmaxy() - 100) / 7 * (2) + 80);
		textbox department(200, (getmaxy() - 100) / 7 * (3) + 80);
		textbox password(200, (getmaxy() - 100) / 7 * (4) + 80);
		textbox position(200, (getmaxy() - 100) / 7 * (5) + 80);
		rectbox submit(getmaxx() / 2, (getmaxy() - 100) / 7 * (6) + 80,"submit");
		char*ch[30]={"re-enter","return"};
		int button,dx,dy;
		student studentregis;
		rollno.render();
		name.render();
		department.render();
		password.render();
		position.render();
		submit.render();
		show();

		while (1)
		{
			 ::getpos(&button,&dx,&dy);
			if (rollno.check(button,dx,dy))
			{
				strcpy(studentregis.rollno, rollno.gettext());
			}
			if (name.check(button,dx,dy))
			{
				strcpy(studentregis.name, name.gettext());
			}
			if (department.check(button,dx,dy))
			{
				strcpy(studentregis.department, department.gettext());
			}
			if (password.check(button,dx,dy))
			{
				strcpy(studentregis.password, password.gettext());
			}
			if (position.check(button,dx,dy))
			{
				strcpy(studentregis.position, position.gettext());
			}
			if (submit.check(button,dx,dy))
			{
				if (studentregis.rollno[0] == '\0' || studentregis.name[0] == '\0' || studentregis.department[0] == '\0', studentregis.password[0] == '\0' || studentregis.position[0] == '\0')
				{
					dialogbox d("None of the fields can be empty", ch);
					if (d.render())
					{
						registration();
					}
					else {
						mainmenu();
					}

				}
				else {
					messagebox(getmaxx() / 4, getmaxy() / 4, getmaxx() * 3 / 4, getmaxy() / 4 * 3, "the account is created succesfully");
					getch();
					mainmenu();
				}
			}
		}
		}



		void mainmenu()
	{
		cleardevice();
		setbackground();
		int pts[8];
		int midy = getmaxy() / 2;
		int midx = getmaxx() / 2;
		rectbox(midx, 25, "OPINION POLE                                     ");
		pts[0] = 50 - 6;
		pts[1] = 50 + 6;
		pts[2] = 590 - 6;
		pts[3] = 50 + 6;
		pts[4] = 590 - 6;
		pts[5] = 2 * midy + 6 - 30;
		pts[6] = 50 - 6;
		pts[7] = 2 * midy + 6 - 30;


		setfillstyle(1, 8);
		fillpoly(4, pts);

		pts[0] = 50;
		pts[1] = 50;
		pts[2] = 590;
		pts[3] = 50;
		pts[4] = 590;
		pts[5] = 2 * midy - 30;
		pts[6] = 50;
		pts[7] = 2 * midy - 30;

		setcolor(8);
		setfillstyle(1, 0);
		fillpoly(4, pts);
		char *s[20] = { "register","login your account" };
		char *p[80] = { "student who have not registerd for the polling their views may register with this link","student who have already registered may this link to login their account" };
		char *sdir[20] = { "setting.txt","account.txt" };
		for (int j = 0; j<4; j += 2)
		{

			label(50 + ((getmaxx() - 100) / 4), ((getmaxy() - 100) / 4)*(j + 1) + 140, s[j / 2]);
			messagebox(((getmaxx() - 100) / 2), ((getmaxy() - 100) / 4)*(j)+100, (getmaxx() - 100), ((getmaxy() - 100) / 4)*(j + 1) + 100, p[j / 2]);

		}
		int button, dx, dy;
		rectbox exits(440, 440, "EXIT");

		box regist(50 + ((getmaxx() - 100) / 4), ((getmaxy() - 100) / 4)*(1) + 60, sdir[0]);
		box logins(50 + ((getmaxx() - 100) / 4), ((getmaxy() - 100) / 4)*(2 + 1) + 60, sdir[1]);
		regist.render();
		logins.render();
		char ch;
		exits.render();
		show();
		while (1)
		{
			getpos(&button, &dx, &dy);
			if (regist.check(button, dx, dy))
			{
				registration();
			}
			else
			if (logins.check(button, dx, dy))
			{
				login();
			}
			else
			if (exits.check(button, dx, dy))
			{
				end();
			}else
			if(kbhit())
			{ ch=getch();
			if (ch=='1')
			{
				registration();
			}
			else
			if (ch=='2')
			{
				login();
			}
			else
			if (ch=='3')
			{
				end();
			}




			}

		}

	}


	void portal()
	{


		cleardevice();
		setbackground();
		int pts[8];
		int midy = getmaxy() / 2;
		int midx = getmaxx() / 2;
		rectbox opinion(midx, 25, "OPINION POLE                                     ");
		opinion.render();
		rectbox logout(400, 25, "logout");
		logout.render();

		pts[0] = 50 - 6;
		pts[1] = 50 + 6;
		pts[2] = 590 - 6;
		pts[3] = 50 + 6;
		pts[4] = 590 - 6;
		pts[5] = 2 * midy + 6 - 30;
		pts[6] = 50 - 6;
		pts[7] = 2 * midy + 6 - 30;


		setfillstyle(1, 8);
		fillpoly(4, pts);

		pts[0] = 50;
		pts[1] = 50;
		pts[2] = 590;
		pts[3] = 50;
		pts[4] = 590;
		pts[5] = 2 * midy - 30;
		pts[6] = 50;
		pts[7] = 2 * midy - 30;

		setcolor(8);
		setfillstyle(1, 0);
		fillpoly(4, pts);
		label(getmaxx()/2, 60, "ISSUES");
		char *s[20] = { "administration","library","finance","openhouse" };

		char *sdir[20] = { "admin.txt","library.txt","finance.txt","house.txt" };


		box admin(50 + ((getmaxx() - 120) / 4), ((getmaxy() - 120) / 4)*(1) + 60, sdir[0]);
		label(50 + ((getmaxx() - 120) / 4), ((getmaxy() - 120) / 4)*(1) + 150, s[0]);
		box library(50 + ((getmaxx() - 120) / 4), ((getmaxy() - 120) / 4)*(1 + 2) + 60, sdir[1]);
		label(50 + ((getmaxx() - 120) / 4)*(1), ((getmaxy() - 120) / 4)*(1 + 2) + 150, s[1]);
		box finance(50 + ((getmaxx() - 120) / 4) * 3, ((getmaxy() - 120) / 4)*(1) + 60, sdir[2]);
		label(50 + ((getmaxx() - 120) / 4) * 3, ((getmaxy() - 120) / 4)*(1) + 150, s[2]);
		box openhouse(50 + ((getmaxx() - 120) / 4) * 3, ((getmaxy() - 120) / 4)*(1 + 2) + 60, sdir[3]);
		label(50 + ((getmaxx() - 120) / 4)*(3), ((getmaxy() - 120) / 4)*(1 + 2) + 150, s[3]);

		admin.render();
		library.render();
		finance.render();
		openhouse.render();

		 char ch;
		int button, dx, dy;


		::show();
		while (1)
		{
			getpos(&button, &dx, &dy);
			if (admin.check(button, dx, dy))
			{

			   issuemenu("ADMINISTRATION ISSUES");

			}
			else
			if (library.check(button, dx, dy))
			{
			 issuemenu("LIBRARY ISSUE");

			}
			else
			if (finance.check(button, dx, dy))
			{
			 issuemenu("FINANCE ISSUE");

			}
			else
			if (openhouse.check(button, dx, dy))
			{
			     issuemenu("OPENHOUSE ISSUE");

			}
			else
			if (logout.check(button, dx, dy))
			{
				mainmenu();
			}
			else
			if(kbhit())
			{
			  ch=getch();
			  if (ch=='1')
			{

			   issuemenu("ADMINISTRATION ISSUES");

			}
			else
			if (ch=='3')
			{
			 issuemenu("LIBRARY ISSUE");

			}
			else
			if (ch=='2')
			{
			 issuemenu("FINANCE ISSUE");

			}
			else
			if (ch=='4')
			{
			     issuemenu("OPENHOUSE ISSUE");

			}
			else
			if (ch=='9')
			{
				mainmenu();
			}
			else
			if(ch=='0')
			{end();}


			}


		}

	}







		void end()
		{
			setbackground();

				int    midx = getmaxx() / 2;
				int    midy = getmaxy() / 2;
				for (int i = -(midx - 20); i<0; i = i + 10)
				{
					cleardevice();
					settextstyle(1, 0, 6);
					setcolor(RED); rectangle(0, midy - 120, 2 * midx, midy + 60);
					setfillstyle(1, YELLOW);
					floodfill(3, midy, RED);
					setcolor(1);

					outtextxy(midx + i, midy - 90, "END");
					delay(300);
				}
				settextstyle(1, 0, 1);
				outtextxy(midx + 20, midy + 200, "thank you for using the opinionpoll.");
				getch();
				exit(0);


			}






void main()
{
  int GDriver = DETECT; int Gmode;
		initgraph(&GDriver, &Gmode, "C:\\TURBOC3\\BGI");
		initmouse();


		 introduction();
		 mainmenu();







}