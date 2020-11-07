#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#include "iGraphics.h"
#include"level.h"

using namespace std;

Level gamelevel;

char list[][15]= {"home","levelchoose","about","help","game","winpage","losepage"};
char filename[][230]=
{
    "images/showpages/minesweeper2.bmp","images/showpages/levelfinal.bmp",
    "images/showpages/credits.bmp","images/showpages/newhelp.bmp","",
    "images/showpages/winpage.bmp","images/showpages/losegame.bmp"
};

int current;
bool result;
time_t st,fin;

void home_do(int mx,int my)
{
    if(820<=mx && mx<=942)
    {
        if(428<=my && my<=464)exit(0);
        else if (475<=my && my<=512)current=2;
        else if(529<=my && my<=565)current=3;
        else if(580<=my && my<=618)current=1;

    }

    return;

}


void levelchoose_do(int mx,int my)
{
    if(250<=mx && mx<=370)
    {
        if(420<my &&my<=450)
        {
            gamelevel=hard;
        }
        else if(540<=my && my<=578)
        {
            gamelevel=medium;
        }
        else if(660<=my && my<=700)
        {
            gamelevel=easy;
        }

        current=4;

    }
    else if(405<=mx && mx<=617 && 318<=my && my<=368)current=0;
    if(current==4)gamelevel.newgame();

}

void help_do(int mx,int my)
{
    if(338<=mx && mx<=597 && 170<=my && my<=230)current=0;
    return;

}


void game_do(int mx,int my)
{
    if(result==false)
    {

        if(830<=mx && mx<=980)
        {
            if(335<=my && my<=385)exit(0);
            else if(430<=my && my<=480)
            {
                current=0;
                return;

            }
        }
        gamelevel.mouseclick(mx,my);
        if(gamelevel.lost || gamelevel.won)
        {
            result=true;
            time(&st);
        }

    }
    return;
}

void losepage_do(int mx,int my)
{

    if(365<=my && my<=415)
    {
        if(87<=mx && mx<=302)
        {
            gamelevel.restartgame();
            current=4;
        }
        else if(348<=mx && mx<=599)
        {
            gamelevel.newgame();
            current=4;
        }
        else if(640<=mx && mx<=898)current=0;
    }
    result=false;

    return;

}

void winpage_do(int mx,int my)
{

    if(265<=mx && mx<=708 && 297<=my && my<=384)current=0;
    result=false;
    return;
}
void about_do(int mx,int my)
{

    if(822<=mx && mx<=980 && 212<=my && my<=260)current=0;
    return;

}
void iDraw()
{
    if(current!=4)iShowBMP(0,0,filename[current]);
    if(result)
    {

        time(&fin);
        if(difftime(fin,st)>3)
        {
            current=(gamelevel.lost)?6:5;
        }

    }
    if(current==4)
    {
        gamelevel.showtime();
        gamelevel.draw();

    }

}


void iMouseMove(int mx, int my)
{
}





void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

        switch(current)
        {

        case 0:
            home_do(mx,my);
            break;
        case 1:
            levelchoose_do(mx,my);
            break;
        case 2:
            about_do(mx,my);
            break;
        case 3:
            help_do(mx,my);
            break;
        case 4:
            game_do(mx,my);
            break;
        case 5:
            winpage_do(mx,my);
            break;
        case 6:
            losepage_do(mx,my);
            break;
        }
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        if(current==4 && result==false)
        {

            gamelevel.giveflag(mx,my);
            if(gamelevel.lost || gamelevel.won)
            {
                result=true;
                time(&st);
            }

        }
    }






}

void iKeyboard(unsigned char key)
{


}

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
    iInitialize(1000, 800, "Minesweeper");
	iStart();
    return 0;
}
