#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#pragma GCC optimize("03")
using namespace std;
int a;
int kinput;
int x;
int score;
int y;
int applx;
int apply;
int applespw;
int mapx;
int mapy;
void input()
{
    kinput=_getch();
    switch(kinput)
    {
    case 72:
        if(y!=1)
        {
            y=y-1;
        }
        break;
    case 80:
        if(y!=mapy)
        {
            y=y+1;
        }
        break;
    case 75:
        if(x!=1)
        {
            x=x-1;
        }
        break;
    case 77:
        if(x!=mapx)
        {
            x++;
        }
        break;
    case 113:
        a=1;
        break;
    }
}
void draw()
{
    COORD zero;
    zero.X=0;
    zero.Y=0;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), zero);
    for(int i=0; i<mapx+2; i++)
    {
        cout<<"#";
    }
    cout<<endl;
    for(int i=1; i<mapy+1; i++)
    {
        if(i==y && apply!=i)
        {
            cout<<"#";
            for(int b=0; b<x-1; b++)
            {
                cout<<" ";
            }
            cout<<"@";
            for(int b=0; b<mapx-x; b++)
            {
                cout<<" ";
            }
        }
        if(i==y && apply==y)
        {
            cout<<"#";
            if(x<applx)
            {
                for(int i=0; i<x-1; i++)
                {
                    cout<<" ";
                }
                cout<<"@";
                for(int d=0; d<applx-x-1; d++)
                {
                    cout<<" ";
                }
                cout<<"A";
                for(int i=0; i<mapx-applx; i++)
                {
                    cout<<" ";
                }
            }
            if(x>applx)
            {
                for(int i=0; i<applx-1; i++)
                {
                    cout<<" ";
                }
                cout<<"A";
                for(int i=0; i<x-applx-1; i++)
                {
                    cout<<" ";
                }
                cout<<"@";
                for(int i=0; i<mapx-x; i++)
                {
                    cout<<" ";
                }
            }
        }
        if(apply==i && y!=i)
        {
            cout<<"#";
            for(int c=0; c<applx-1; c++)
            {
                cout<<" ";
            }
            cout<<"A";
            for(int i=0; i<mapx-applx; i++)
            {
                cout<<" ";
            }
        }
        if(apply!=i && y!=i)
        {
            cout<<"#";
            for(int i=0; i<mapx; i++)
            {
                cout<<" ";
            }
        }
        cout<<"#"<<endl;
    }
    for(int i=0; i<mapx+2; i++)
    {
        cout<<"#";
    }
    cout<<endl;
    cout<<"X: "<<x<<"         ";
    cout<<endl<<"Y: "<<y<<"        ";
    cout<<endl<<"Apple Y: "<<apply<<"            ";
    cout<<endl<<"Apple X: "<<applx<<"            ";
    cout<<endl<<"Score: "<<score<<"          ";
}
void logic()
{
    if(x==applx && y==apply)
    {
        score++;
        applx=rand()%(mapx-1)+1;
        apply=rand()%(mapy-1)+1;
    }
}
int main()
{
    srand(time(0));
    a=0;
    score=0;
    mapx=100;
    mapy=40;
    x=mapx/2;
    y=mapy/2;
    applx=rand()%(mapx-1)+1;
    apply=rand()%(mapy-1)+1;
    logic();
    while(true)
    {
        input();
        logic();
        draw();
    }
    return 0;
}
