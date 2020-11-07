# include "iGraphics.h"

int pic_x, pic_y;
int dx, dy;

int image1, image2;


/*
function iDraw() is called again and again by the system.
*/

void objectChange() {
	pic_x += dx;
	pic_y += dy;

	if (pic_x >= 400 || pic_x <= 0)
		dx = -dx;
	if (pic_y >= 400 || pic_y <= 0)
		dy = -dy;
}


void iDraw()
{
	//place your drawing codes here

	iClear();
	//iSetColor(135, 206, 250);
	//iFilledRectangle(0, 0, 400, 400);

	iSetColor(255, 255, 255);
	iShowImage(0, 0, 400, 400, image2);

	iSetColor(255, 255, 255);
	iShowImage(pic_x, pic_y, 100, 100, image1);

	iSetColor(0, 0, 0);
	iText(10, 10, "Press p for pause, r for resume, END for exit.");
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
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if (key == 'r')
	{
		iResumeTimer(0);
	}
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}



int main()
{
	//place your own initialization codes here.

	iSetTimer(20, objectChange);
	
	iInitialize(400, 400, "Animation with image");

	dx = 5;
	dy = 6;

	image1 = iLoadImage("images\\bird.png");
	image2 = iLoadImage("images\\forest.jpg");


	iStart();

	return 0;
}

