#include<factors.h>
class student
{
public:
	char name[80];
	char password[30];
	char rollno[30];
	char position[30];
	char department[30];


	student()
	{
		name[0] = '\0';
		password[0] = '\0';
		rollno[0] = '\0';
		position[0] = '\0';
		department[0] = '\0';
	}

	int check();
	int compare(student &temp)
	{
		if ((!strcmp(rollno, temp.rollno)) && (!strcmp(password, temp.password)))
		{
			return 1;
		}

		return 0;
	}

};

int student::check()
{
	ifstream f;
	f.open("students.txt");
	student temp;
	while (f.read((char*)&temp, sizeof(temp)))
	{
		if (compare(temp))
		{
			return 1;
		}
	}

	return 0;

}


struct question
{ public:
	char ques[80];
	char choice[4][20];



};


class surveysheet
{

	question q[5];
	int size;



public:

	surveysheet() { size = 0; }
	void getsurveysheet(char *string);


	int surveyinterface(question &Question);


	void getsurveyinterface(question *qu);


	void takesurvey(char *s, char *a);

};

void surveysheet::getsurveysheet(char *string)
	{
		int i = 0;
		int choice = 1;
		fstream file;
		file.open(string,ios::out|ios::binary);
		char *ch[20]={"yes","no"};
		while (choice)
		{        cleardevice();
			 getsurveyinterface(&q[i]);
			file.write((char*)&q[i],sizeof(q[i]));
			size++;

			dialogbox d("do you want to enter more questions:", ch);
			choice = d.render();
			i++;


		}
		file.close();
	}

	int surveysheet::surveyinterface(question &Question)
	{
		int choice;
		int maxx = getmaxx();
		cleardevice();
		setbkcolor(WHITE);
		setcolor(8);
		rectangle(0 + 40, 20, maxx - 40, 50);
		setfillstyle(1,7);
		floodfill(43, 23,8);
		settextstyle(0, 0, 3);
		char ch;
		outtextxy(maxx / 2 - 90, 22, "QUESTION NO:");

		rectbox questions(maxx / 2, 80, Question.ques);
		questions.render();

		circularbox c[4];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{

				c[i*2+j].setvalues((getmaxx()/ 4)*(i*2 + 1), ((getmaxy() - 100)/ 4)*(j*2 + 1) + 100, Question.choice[j + i*2]);
				c[i*2+j].render();
			}
		}

		 ::show();
		while (1)
		{

				if(kbhit())
				{ch=getch();
				if(ch=='1')
				{
				return 1;
				}
				if(ch=='2')
				{
				return 2;
				}
				if(ch=='3')
				{
				return 3;
				}
				if(ch=='4')
				{
				return 4;
				}
				}



		}




	}

	void surveysheet::getsurveyinterface(question *qu)
	{
		cleardevice();
		int choice;
		char ch;
		char chr[2] = " \0";
		char string[180] ;
		strcpy(string," ");

		int maxx = getmaxx();
		cleardevice();
		setbkcolor(WHITE);
		setcolor(8);
		rectangle(0 + 40, 20, maxx - 40, 50);
		setfillstyle(1,7);
		floodfill(42,22,8);
		settextstyle(0, 0, 3);
		outtextxy(maxx / 2 - 90, 22, "QUESTION NO:");
		rectbox questions(maxx / 2, 80, " ");
		questions.render();
		ch = getch();
		while (ch != '\r')
		{
			chr[0] = ch;
			strcat(string, chr);
			questions.setvalues(maxx / 2, 80, string);
			questions.render();
			ch = getch();
		}
		strcpy(qu->ques, string);

		circularbox c[4];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				strcpy(string, " ");


				c[i*2+j].setvalues((getmaxx() / 4)*(i*2 + 1), ((getmaxy() - 100) / 4)*(j*2 + 1) + 100,string);
				c[i*2+j].render();
				ch = getch();
				while (ch != '\r')
				{
					chr[0] = ch;
					strcat(string, chr);
					c[i*2+j].setvalues((getmaxx() / 4)*(i*2 + 1), ((getmaxy() - 100) / 4)*(j*2 + 1) + 100, string);
					c[i*2+j].render();
					ch = getch();
				}
				strcpy(qu->choice[2 * i + j], string);

			}
		}
		setcolor(8);



	}


	void surveysheet::takesurvey(char *s, char *a)
	{
		question q;
		fstream surveyfile;
		surveyfile.open(s,ios::binary|ios::in);
		surveyfile.seekg(0,ios::beg);
		a[0]='\0';

		while (!surveyfile.eof())
		{       surveyfile.read((char*)&q,sizeof(q));
			surveyinterface(q);



		}

	}

