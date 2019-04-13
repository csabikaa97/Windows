#include <cstdlib>
#include <math.h>
#include <fstream>

#define Xsize 100
#define Ysize 100
#define debug 0
#define draw 1
#define save 0
#define windows 1
#define resolution 1
int fuggvenyszam = 3;

using namespace std;

int Xcenter=(Xsize/2);
int Ycenter=(Ysize/2);
int r[Xsize][Ysize];
int g[Xsize][Ysize];
int b[Xsize][Ysize];

char display[Xsize][Ysize];

int fuggveny(int localx,int fuggvenyazonosito) {
    double x=double(localx)/double(resolution);
    double returnvalue;
    switch (fuggvenyazonosito) {

    //fuggvenyek definicioja
    case 0: returnvalue=x; break;                   //piros
    case 1: returnvalue=x*x; break;                 //narancssarga
    case 2: returnvalue=x*x*x; break;               //sarga
    case 3: returnvalue=x*x*x*x; break;             //zold
    case 4: returnvalue=double(1)/x; break;         //turkizkek
    case 5: returnvalue=double(1)/(x*x); break;     //vilagoskek
    case 6: returnvalue=sqrt(x); break;             //lila
    case 7: returnvalue=sqrt(x*x); break;           //vilagoskek2
    case 8: returnvalue=1; break;                   //kek


    }
    return int((-1*returnvalue)*double(resolution));
}

void SetColor(int x,int y,int f) {
    switch (f) {
    case 0: r[x][y]=255; break;                         //piros
    case 1: r[x][y]=255; g[x][y]+=126; break;           //narancssarga
    case 2: r[x][y]=255; g[x][y]=255;break;             //sarga
    case 3: g[x][y]=255; break;                         //zold
    case 4: g[x][y]=255; b[x][y]+=126; break;           //turkizkek
    case 5: g[x][y]=255; b[x][y]=255; break;            //vilagoskek
    case 6: r[x][y]=126; b[x][y]=255; break;            //lila
    case 7: g[x][y]=255; b[x][y]=255; break;            //vilagoskek2
    case 8: r[x][y]=255; b[x][y]=255; break;            //kek
    }
}

void DrawScreen() {
    for(int i=0; i<Ysize; i++) {
        for(int x=0; x<Xsize; x++) {
            printf("%c",display[i][x]);
        }
        printf("\n");
    }
}

int main() {
    try {
        if(fuggvenyszam>9) { fuggvenyszam=9; }
        if(fuggvenyszam<=0) { fuggvenyszam=1; }
        for(int i=0; i<Xsize; i++) {
            for(int x=0; x<Ysize; x++) {
                if(x==Xcenter) {
                    if(save) {
                        r[x][i]=120;
                        g[x][i]=120;
                        b[x][i]=120;
                    }
                    display[i][x]='|';
                } else {
                    if(i==Ycenter) {
                        if(save) {
                            r[x][i]=120;
                            g[x][i]=120;
                            b[x][i]=120;
                        }
                        display[i][x]='-';
                    } else {
                        if(save) {
                            r[x][i]=0;
                            g[x][i]=0;
                            b[x][i]=0;
                        }
                        display[i][x]=' ';
                    }
                }
            }
        }
        for(int i=0; i<Xsize; i++) {
            for(int x=0; x<Ysize; x++) {
                for(int f=0; f<fuggvenyszam; f++) {
                    if(fuggveny(i-Xcenter,f)==(x-Ycenter) && fuggvenyszam>=1) { display[x][i]=f+48; }
                    if(save) {
                        if(fuggveny(i-Xcenter,f)==(x-Ycenter) && fuggvenyszam>=1) { SetColor(x,i,f); }
                    }
                }
            }
        }
        display[Xcenter][Ycenter]='O';
        if(save) {
            ofstream file;
            file.open("graph.ppm");
            file<<"P3"<<"\n"<<Xsize<<" "<<Ysize<<"\n";
            file<<"255"<<"\n";
            for(int x=0; x<Xsize; x++) {
                for(int y=0; y<Ysize; y++) { file<<r[x][y]<<" "<<g[x][y]<<" "<<b[x][y]<<"\n"; }
            }
            file.close();
            if(windows) { system("\"C:/Program Files/GIMP 2/bin/gimp-2.10.exe\" graph.ppm"); }
        }
        if(debug) {
            for(int f=0; f<fuggvenyszam; f++) {
                for(int i=0; i<Xsize; i++) { if(fuggvenyszam>=1) { printf("f%d(%d)=%d\n",f,i-Xcenter,fuggveny(i-Xcenter,f)); } }
                printf("\n");
            }
        }
        if(draw) { DrawScreen(); }
        if(debug || draw) { system("pause"); }
    }
    catch(int kivetel) {
        printf("Kivetel: \"%d\".\n",kivetel);
    }
    return 0;
}
