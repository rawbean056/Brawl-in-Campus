
#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED
#include<time.h>

struct Level
{  int photo[50][50],board[50][50],numOfBombs[50][50], done[50][50],discoveredSoFar[50][50];
    int discovered,count,score;
    int ROW,COLUMN,BOMBS;
    time_t time1,time2;
    bool lost,won,mainmenuclicked;

    /*MEMBER FUNCTIONS*/
    Level(int R=0,int C=0,int B=0);
    bool in_board(int r,int c);
    void CLeargame();
    void generate();
    int findbomb(int R,int C);
    void buildNOB();
    void newgame();
    void restartgame();
    void bfs(int R,int C);
    /*MOUSE FUNCTIONS*/
    void boardclick(int mx,int my);
    void newgameclick(int mx,int my);
    void backtomenuclick(int mx,int my);
    void restartclick(int mx,int my);
    void exitclick(int mx,int my);
    void mouseclick(int mx,int my);
    void giveflag(int mx,int my);
    /*DRAW FUNCTIONS*/
    void draw();
    void Showscore();
    void showtime();
    };

int dr[]= {-1,-1,-1,0,0,1,1,1};
int dc[]= {-1,0,1,-1,1,-1,0,1 };


#define CLear(arr) memset(arr,0,sizeof(arr))
#define enter printf("\n")


Level::Level(int R,int C,int B)
{
    ROW=R;
    COLUMN=C;
    BOMBS=B;
    won=lost=false;
    mainmenuclicked=true;
    count=discovered=score=0;
}


Level easy(10,10,20),medium(16,16,40),hard(16,20,50);


bool Level::in_board(int r,int c)
{

    return (1<=r && r<=ROW && 1<=c && c<=COLUMN);
}

void Level::CLeargame()
{
    memset(photo,49,sizeof(photo));
    CLear(discoveredSoFar);
    CLear(board);
    CLear(done);
    CLear(numOfBombs);
    lost=false;
    won=false;
    score=count=discovered=0;
}

void Level::generate()
{
    int tot=0;
    while(tot!=BOMBS)
    {
        int mod=ROW*COLUMN;
        int pos=rand()%mod;
        if(done[pos/ROW+1][pos%COLUMN+1]==0)
        {
            board[pos/ROW+1][pos%COLUMN+1]=done[pos/ROW+1][pos%COLUMN+1]=1;
            tot++;
        }
    }

}

int Level::findbomb(int R,int C)
{
    if(board[R][C])return 9;
    int i,count=0;
    for(i=0; i<8; i++)
        if(in_board(R+dr[i],C+dc[i]) && board[R+dr[i ]][ C+dc[ i] ] )count++;
    return count;
}
void Level::buildNOB()
{
    int i,j;
    for(i=1; i<=ROW; i++)
        for(j=1; j<=COLUMN; j++)
            numOfBombs[i][j]=findbomb(i,j);
}

void Level::newgame()
{
    srand(time(NULL));
    iClear();
    CLeargame();
    generate();
    buildNOB();
    time(&time1);
    return;
}

void Level::restartgame()
{
    iClear();
    memset(photo,49,sizeof(photo));
    CLear(discoveredSoFar);
    lost=false;
    won=false;
    count=discovered=score=0;
    time(&time1);

}
void Level::bfs(int R,int C)
{
    int queue[560][2],top=0,bot=0,size=0,i,j;
    int visited[50][50];
    memset(visited,0,sizeof(visited));
    queue[bot][0]=R;
    queue[bot][1]=C;
    size++;
    bot++;
    visited[R][C]=1;

    while(size)
    {
        int topR=queue[top][0],topC=queue[top][1];
        photo[topR][topC]=0;
        top++;
        size--;
        // printf("%d %d\n",topR,topC);
        for(i=0; i<8; i++)
            if(in_board(topR+dr[i ] ,topC+dc[i]) && visited[topR+dr[ i]][topC+dc[i] ]==0 &&discoveredSoFar[ topR+dr[ i]][ topC+dc[i]]==0)
            {
                if(numOfBombs[ topR+dr[i ] ][topC+dc[i ] ]>0 && numOfBombs[ topR+dr[i ] ][topC+dc[i ] ]!=9 )
                {
                    photo[topR+dr[i ] ][topC+dc[i ] ]=(numOfBombs[topR+dr[i ] ][topC+dc[i ] ]);
//                    discovered++;
                    discoveredSoFar[topR+dr[i]][topC+dc[i]]=1;
                }
                else if(numOfBombs[ topR+dr[i ] ][topC+dc[i ] ]==9)continue;
                else
                {
                    queue[bot][0]=topR+dr[i];
                    queue[bot][1]=topC+dc[i];
                    bot++;
                    size++;
                    //                  discovered++;
                    discoveredSoFar[topR+dr[i]][topC+dc[i]]=1;
                    visited[topR+dr[ i]][topC+dc[i] ]=1;

                }
            }
    }
}

void Level::draw()
{
    int i,j,k,p=50,q=150;
    char str[30];
    strcpy(str,"images/boardphotoes/1 (3).bmp");
    for(i=ROW; i>=1; i--)
    {
        for(j=1; j<=COLUMN; j++)
        {
            if(lost==false )k=photo[i][j];
            else if(lost==true)k=numOfBombs[i][j];
            str[20]=k+'0';
            iShowBMP(p,q,str);
            p+=38;
        }
        q+=38;
        p=50;
    }


}

void Level:: boardclick(int mx,int my)
{
    int limx=50+COLUMN*38,limy=150+ROW*38;
    if(50<=mx && mx<=limx && 150<=my && my<=limy)
    {
        // time(&time2);
        printf("%.lf seconds\n",difftime(time2,time1));
        int row=(int)ceil(double((my-150)/38))+1;
        int col=(int)ceil(double((mx-50)/38))+1;
        row=ROW+1-row;

        if(numOfBombs[row][col]>0 && numOfBombs[row][col]!=9)
        {
            photo[row][col]=numOfBombs[row][col];
        }
        else if(numOfBombs[row][col]==9)
        {
            lost=true;
        }
        else
        {
            bfs(row,col);

        }
        discoveredSoFar[row][col]=true;
        //if(lost==false)discovered++;
    }

    //if(discovered==BOMBS && lost==false)won=true;
    return;
}

void Level::mouseclick(int mx,int my)
{
    boardclick(mx,my);


}

void Level::giveflag(int mx,int my)
{
    int limx=50+COLUMN*38,limy=150+ROW*38;
    if(50<=mx && mx<=limx && 150<=my && my<=limy)
    {

        int row=(int)ceil(double((my-150)/38))+1;
        int col=(int)ceil(double((mx-50)/38))+1;
        row=ROW+1-row;
        if(discoveredSoFar[row][col]==0)
        {
            photo[row][col]=(((photo[row][col]-49)+1)%3)+49;

            if(photo[row][col]==50 && numOfBombs[row][col]==9 )
            {
                count++;
                score+=5;
                if(lost==false)discovered++;
                if(discovered==BOMBS && lost==false)won=true;
//    cout<<"DISC"<<discovered<<endl;
                //		discovered++;
                Showscore();
            }

            else if(photo[row][col]==51 && numOfBombs[row][col]==9 )
            {
                count--;
                score-=5;
                discovered--;
                Showscore();
            }

        }



    }

}


void Level::Showscore()
{
    iSetColor(1,0,0);
    int scorenow=score;
    char showscore[1000]="0";
    if(score)sprintf_s(showscore,"%d",scorenow);


    iText(895,670,showscore,GLUT_BITMAP_TIMES_ROMAN_24);

}

void Level::showtime()
{
    char second[10000];
    iClear();
    iShowBMP(0,0,"images/showpages/boardfinal.bmp");
    iSetColor(1,0,0);
    if(lost==false) time(&time2);
    sprintf_s(second,"%.lf",difftime(time2,time1));


    iText(895,515,second,GLUT_BITMAP_TIMES_ROMAN_24);
    Showscore();


}

#endif // LEVEL_H_INCLUDED
