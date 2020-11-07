# include "iGraphics.h"
int g = 0,p=0,ins=0,ab=0,e=0;
int gameflag = 0;

int dx = 100;
int dy = 50;
int MM, pl, ex, abo, in, po, Point, Ins, cap, bac, ground, c1, c2, c3, c4, c5, c6;
int charground;
int CharPos_x = 50, CharPos_y = 50;
int flag = 0, mflag = 0;
int i = 0;
int j = 0;
int x = 0;
int y = 0;
int k[5];
int ghushi[5];
int pk[5];
int pp[5];
int M[2];
/*
function iDraw() is called again and again by the system.
*/

void back()
{
	
	iShowImage(40, 650, dx+25, dy+10,bac);
	
}
void playButton()
{
	iSetColor(255, 255, 255);
	iShowImage(100, 500, dx, dy,pl);
	//iSetColor(0, 0, 0);
	//iText(125, 515, "Play", GLUT_BITMAP_TIMES_ROMAN_24);

}
void ptButton()
{
	iSetColor(255, 255, 255);
	iShowImage(100, 400, dx + 140, dy,po);
	//iSetColor(0, 0, 0);
	//iText(125, 415, "Point Table", GLUT_BITMAP_TIMES_ROMAN_24);

}
void insButton()
{
	iSetColor(255, 255, 255);
	iShowImage(100, 300, dx + 150, dy,in);
	//iSetColor(0, 0, 0);
	//iText(125, 315, "Instruction", GLUT_BITMAP_TIMES_ROMAN_24);

}
void aButton()
{
	iSetColor(255, 255, 255);
	iShowImage(100, 200, dx + 20, dy,abo);
	//iSetColor(0, 0, 0);
	//iText(125, 215, "About", GLUT_BITMAP_TIMES_ROMAN_24);
}
void eButton()
{
	iSetColor(255, 255, 255);
	iShowImage(100, 100, dx , dy,ex);
	//iSetColor(0, 0, 0);
	//iText(125, 115, "Exit", GLUT_BITMAP_TIMES_ROMAN_24);
}

void play()
{
	iSetColor(255, 0, 0);
	iText(500, 600, "Game will start here", GLUT_BITMAP_TIMES_ROMAN_24);

}
void pointTable()
{
	iShowImage(0, 0, 1280, 720, Point);
}
void instruction()
{
	iShowImage(0, 0, 1280, 720, Ins);
}
void about()
{
	iShowImage(0, 0, 1280, 720, cap);
}
void CharChoice()
{
	iClear();
	iShowImage(0, 0, 1280, 720, charground);
	iShowImage(20, 10, 400, 230, c1);
	iShowImage(440, 10, 400, 230, c2);
	iShowImage(860, 10, 400, 230, c3);
	iShowImage(20, 250, 400, 230, c4);
	iShowImage(440, 250, 400, 230, c5);
	iShowImage(860, 250, 400, 230, c6);
	
}

void Kick()
{



	i++;
	if (i >4)
	{
		i = 0;
		flag = 0;
		iPauseTimer(0);
	}





}
void punch()
{
	j++;
	if (j > 4){
		j = 0;
		flag = 0;
		iPauseTimer(0);
	}

}
void PKick()
{



	x++;
	if (x > 4)
	{
		x = 0;
		flag = 0;
		iPauseTimer(0);
	}

}
void Ppunch()
{
	y++;
	if (y > 4)
	{
		y = 0;
		flag = 0;
		iPauseTimer(0);
	}
}

void	a()
{
	PKick();
	Kick();
	punch();
	Ppunch();
}

void DrawGame()
{
	iClear();
	iShowImage(0, 0, 1280, 720, ground);
	iSetColor(255, 255, 255);
	iShowImage(CharPos_x, CharPos_y, 316, 272, k[0]);
	if (mflag == 1)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, M[0]);

	}
	if (mflag == 2)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, M[1]);

	}

	if (flag == 1)
	{

		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, k[i]);
	}

	if (flag == 2)
	{


		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, ghushi[j]);

	}
	if (flag == 3)
	{
		
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, pk[x]);

	}
	if (flag == 4)
	{

		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, pp[y]);

	}
}

void iDraw()
{

	//place your drawing codes here
	iClear();
	
	iSetColor(255, 255, 255);
	iShowImage(0,0, 1280, 720, MM);
	playButton();
	ptButton();
	insButton();
	aButton();
	eButton();

	if (g == 1){
		iClear();
		CharChoice();
		back();
		
	}
	if (p == 1){
		iClear();
		pointTable();
		back();
	}
	if (ins == 1){
		iClear();
		instruction();
		back();
	}
	if (ab == 1){
		iClear();
		about();
		back();
	}
	if (gameflag == 1)
		DrawGame();


}
		
	


	
	


	
	

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}
/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		//place your codes here
		if (mx >= 100 && mx <= 100 + dx && my >= 500 && my <= 500 + dy)
		{
			g = 1;
			
		}

		else if (mx >= 100 && mx <= 100 + dx + 140 && my >= 400 && my <= 400 + dy)
		{
			p = 1;
			
		}
		else if (mx >= 100 && mx <= 100 + dx + 150 && my >= 300 && my <= 300 + dy)
			ins = 1;
		else if (mx >= 100 && mx <= 100 + dx + 20 && my >= 200 && my <= 200 + dy)
			ab = 1;
		else if (mx >= 100 && mx <= 100 + dx && my >= 100 && my <= 100 + dy)
			exit(0);
		else if (mx >= 40 && mx <= 40+dx+25  && my >= 650 && my <= 650+dy+10){
			g = 0;
			p = 0;
			ins = 0;
			ab = 0;
		}
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}
/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (flag == 0)
	{

		{
			if (key == 'a')
			{

				flag = 1;
				i = 0;
				iResumeTimer(0);

			}
		}
		if (key == 's')
		{


			flag = 2;
			j = 0;
			iResumeTimer(0);
		}
		if (key == 'd')
		{

			flag = 3;
			x = 0;
			iResumeTimer(0);
		}
		if (key == 'w')
		{

			flag = 4;
			y = 0;
			iResumeTimer(0);
		}
	}
	if (key == 27)
	{
		g = 0;
		p = 0;
		ins = 0;
		ab = 0;
	}
	if (key == 13)
		gameflag = 1;
	
	//place your codes for other keys here
}
/*
function iSpecialKeyboard() is called whenver user hits special keys likefunction keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11,
GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN,
GLUT_KEY_PAGE UP, GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END,
GLUT_KEY_INSERT */
void iSpecialKeyboard(unsigned char key)
{
	if (flag == 0)
	{

		if (key == GLUT_KEY_RIGHT)
		{

			CharPos_x += 20;
			mflag = 1;
		}
		if (key == GLUT_KEY_LEFT)
		{
			CharPos_x -= 20;
			mflag = 2;
		}
	}
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}
int main()
{
	iSetTimer(200, a);

	
	
	//place your own initialization codes here.
	iInitialize(1280, 720, "demooo");
	ground = iLoadImage("char\\background.jpg");
	k[0] = iLoadImage("char\\s1.png");
	k[1] = iLoadImage("char\\k1.png");
	k[2] = iLoadImage("char\\k2.png");
	k[3] = iLoadImage("char\\k3.png");
	k[4] = iLoadImage("char\\k4.png");

	ghushi[0] = iLoadImage("char\\s1.png");
	ghushi[1] = iLoadImage("char\\p2.png");
	ghushi[2] = iLoadImage("char\\p3.png");
	ghushi[3] = iLoadImage("char\\p4.png");
	ghushi[4] = iLoadImage("char\\p6.png");

	pk[0] = iLoadImage("char\\pk2.png");
	pk[1] = iLoadImage("char\\pk3.png");
	pk[2] = iLoadImage("char\\pk4.png");
	pk[3] = iLoadImage("char\\pk5.png");
	pk[4] = iLoadImage("char\\pk7.png");

	pp[0] = iLoadImage("char\\pp1.png");
	pp[1] = iLoadImage("char\\pp2.png");
	pp[2] = iLoadImage("char\\pp4.png");
	pp[3] = iLoadImage("char\\pp5.png");
	pp[4] = iLoadImage("char\\pp6.png");

	M[0] = iLoadImage("char\\b1.png");
	M[1] = iLoadImage("char\\f1.png");
	MM = iLoadImage("char\\main_menu.jpg");
	pl = iLoadImage("char\\play.png");
	ex= iLoadImage("char\\exit.png");
	abo= iLoadImage("char\\about.png");
	in = iLoadImage("char\\instructions.png");
	po= iLoadImage("char\\point_table.png");
	Point = iLoadImage("char\\PointTable.png");
	Ins = iLoadImage("char\\instructions1.png");
	cap = iLoadImage("char\\capture.png");
	bac = iLoadImage("char\\back.png");
charground =iLoadImage("char\\charground.png");
	c1 = iLoadImage("char\\char1.png");
	c2 = iLoadImage("char\\char2.png");
	c3 = iLoadImage("char\\char3.png");
	c4 = iLoadImage("char\\char4.png");
	c5 = iLoadImage("char\\char5.png");
	c6 = iLoadImage("char\\char6.png");
	iStart();
	
	return 0;
}