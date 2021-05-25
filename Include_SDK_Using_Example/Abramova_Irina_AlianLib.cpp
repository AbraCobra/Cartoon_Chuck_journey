//==============================================================================================//
//   A MAGIG MUSHROOM  (Example of  using alien SDK)
//
//   Author Abramova Irina, Krasnodar, 2021
//==============================================================================================//

#include "TXLib.h"
#include "..\LibIraSDK\LibIra.h"
#include "DetkovaLALib.h"
#include <cmath>


void SunnyDayFon();
void RainScene();
void WalkingScene();
void EndRainScene();
void MagicScene();
void NirvanaScene();
void Input_array();
void Cluster_draw (int x, int y, double sizeX, double sizeY, COLORREF outline, COLORREF star);
void Rain_draw    (int x, int y);


const int Max_fireworks = 515;
const int Max_rainDrops = 900;
const int Wscreen = 1000;
const int Hscreen = 900;


int X0Circle[Max_fireworks] = {};
int Y0Circle[Max_fireworks] = {};
COLORREF Color[Max_fireworks] = {};


int main()
    {
     txCreateWindow (Wscreen, Hscreen);
     Input_array();

     RainScene();
     EndRainScene();
     WalkingScene();
     MagicScene();
     NirvanaScene();

     return 0;
     }

int randInt (int a, int b)
    {
    return a + rand() % (b - a + 1);
    }

COLORREF randColor()
    {
    return RGB(randInt (0, 255), randInt (0, 255), randInt (0, 255));
    }

void Input_array()
    {

    for (int i = 0; i < Max_fireworks; i++)
        {
        X0Circle[i] = randInt(0, Wscreen);
        Y0Circle[i] = randInt(0, Hscreen);
        Color[i] = randColor();
        }
    }

void SunnyDayFon()
    {
    SpringFonBegining();
    }

void RainScene()
    {
    txBegin();

    int t = 0;
    int swing = 40;
    while (t <= 55)
        {
        txClear();
        SunnyDayFon();

        DrawTree (50,   250, 1.1, 1.1, RGB ( 0,  51 +  3*t, 58), abs(t%swing - swing/2) - swing/4);
        DrawTree (200,  250, 1.1, 1.1, RGB ( 0,  51 +  4*t, 58), abs(t%swing - swing/2) - swing/4);
        DrawTree (350,  250, 1.1, 1.1, RGB ( 0,  51 +  5*t, 58), abs(t%swing - swing/2) - swing/4);
        DrawTree (500,  250, 1.1, 1.1, RGB (51, 255 -  8*t, 52), abs(t%swing - swing/2) - swing/4);
        DrawTree (650,  250, 1.1, 1.1, RGB (51, 255 - 12*t, 52), abs(t%swing - swing/2) - swing/4);
        DrawTree (800,  250, 1.1, 1.1, RGB (51, 255 - 14*t, 52), abs(t%swing - swing/2) - swing/4);
        DrawTree (950,  250, 1.1, 1.1, RGB (51, 255 - 16*t, 52), abs(t%swing - swing/2) - swing/4);

        for (int i = 0; i < Max_rainDrops; i++)
            {
            Rain_draw  (X0Circle[i]*t/12, 20 + Y0Circle[i]*t/13);
            Rain_draw  (X0Circle[i]*t/12, 20 + Y0Circle[i]*t/13);
            Rain_draw  (X0Circle[i]*t/12, 20 + Y0Circle[i]*t/13);
            Rain_draw  (X0Circle[i]*t/12, 20 + Y0Circle[i]*t/13);
            Rain_draw  (X0Circle[i]*t/12, 20 + Y0Circle[i]*t/13);
            Rain_draw  (X0Circle[i]*t/12, 20 + Y0Circle[i]*t/13);
            Rain_draw  (X0Circle[i]*t/12, 20 + Y0Circle[i]*t/13);
            Grass_draw (X0Circle[i], 450 + 5*i, RGB (74, 152, 41), 0.5, 0.5);
            }

        Cloud_draw (  0 + 10*t, - 50, 1.2, 1.2, RGB(153 - 12*t, 153 - 12*t, 153 - 12*t));
        Cloud_draw (700 + 10*t,   20, 0.5, 0.5, RGB( 11, 141, 160));

        txSleep (50);
        t++;
        }

    txEnd();
    }

void EndRainScene()
    {
    txBegin();

    int t = 0;
    int swing = 40;
    while (t <= 50)
        {
        txClear();
        SunnyDayFon();

        DrawTree ( 50,  250, 1.1, 1.1, RGB ( 0,  51 +  3*t, 58), abs(t%swing - swing/2) - swing/4);
        DrawTree (200,  250, 1.1, 1.1, RGB ( 0,  51 +  4*t, 58), abs(t%swing - swing/2) - swing/4);
        DrawTree (350,  250, 1.1, 1.1, RGB ( 0,  51 +  5*t, 58), abs(t%swing - swing/2) - swing/4);
        DrawTree (500,  250, 1.1, 1.1, RGB (51, 255 -  8*t, 52), abs(t%swing - swing/2) - swing/4);
        DrawTree (650,  250, 1.1, 1.1, RGB (51, 255 - 12*t, 52), abs(t%swing - swing/2) - swing/4);
        DrawTree (800,  250, 1.1, 1.1, RGB (51, 255 - 14*t, 52), abs(t%swing - swing/2) - swing/4);
        DrawTree (950,  250, 1.1, 1.1, RGB (51, 255 - 16*t, 52), abs(t%swing - swing/2) - swing/4);

        DrawSun  (100 + 10*t/100,  100,  0.8, 0.8, TX_YELLOW, 10 + t%2*50, 1, 1, 1, 1);

        for (int i=0; i< Max_rainDrops; i++)
            {
            Grass_draw (X0Circle[i], 450 + 5*i, RGB (95, 236, 0), 0.5 + 0.001*t, 0.5 + 0.001*t);
            Grass_draw (X0Circle[i], 450 + 5*i, RGB (95, 236, 0), 0.5 + 0.001*t, 0.5 + 0.001*t);
            DrawGrib   (X0Circle[i], 450 + 5*i, 0.1 + 0.01*t, 0.1 + 0.01*t , RGB (177, 100, 100), TX_WHITE);
            }

        DrawGrib   (555, 560, 0.1 + 0.01*2*t, 0.1 + 0.01*2*t, TX_LIGHTRED, TX_WHITE);
        Cloud_draw (  0 + 10*t,  50, 0.6, 0.6, TX_WHITE);
        Cloud_draw (700 + 10*t, 120, 0.5, 0.5, TX_WHITE);

        txSleep (50);
        t++;
        }

    txEnd();
    }

void WalkingScene()
    {
    txBegin();

    int t = 0;
    int swing = 40;
    while (t <= 100)
        {
        txClear();
        SunnyDayFon();

        DrawTree ( 50,  250, 1.1, 1.1, RGB ( 0,  51 +  3*t, 58), abs(t%swing - swing/2) - swing/4);
        DrawTree (200,  250, 1.1, 1.1, RGB ( 0,  51 +  4*t, 58), abs(t%swing - swing/2) - swing/4);
        DrawTree (350,  250, 1.1, 1.1, RGB ( 0,  51 +  5*t, 58), abs(t%swing - swing/2) - swing/4);
        DrawTree (500,  250, 1.1, 1.1, RGB (51, 255 -  8*t, 52), abs(t%swing - swing/2) - swing/4);
        DrawTree (650,  250, 1.1, 1.1, RGB (51, 255 - 12*t, 52), abs(t%swing - swing/2) - swing/4);
        DrawTree (800,  250, 1.1, 1.1, RGB (51, 255 - 14*t, 52), abs(t%swing - swing/2) - swing/4);
        DrawTree (950,  250, 1.1, 1.1, RGB (51, 255 - 16*t, 52), abs(t%swing - swing/2) - swing/4);

        DrawSun  (100 + 10*t/100,  100,  0.8, 0.8, TX_YELLOW, 1, 1, 1, 1, 1);

        for (int i=0; i< Max_rainDrops; i++)
            {
            Grass_draw (X0Circle[i], 450 + 5*i, RGB (95, 236, 0), 0.5 , 0.5 );
            Grass_draw (X0Circle[i], 450 + 5*i, RGB (95, 236, 0), 0.5 , 0.5 );
            DrawGrib   (X0Circle[i], 450 + 5*i, 0.5, 0.5, RGB (177, 100, 100), TX_WHITE);
            }

        Cloud_draw (600 + 2*t,  60, 0.6, 0.6, TX_WHITE);
        Cloud_draw (400 + 2*t, 120, 0.5, 0.5, TX_WHITE);


        DrawGirl   (525 + t, 330 + t, 1, 1, RGB(221, 160, 221), RGB(218, 105, 30),
                    RGB(255, 0, 255), 0, 0, t%10, 0, 5, 1, 0, 0, 0, 0, 0);

        DrawGrib   (555, 560, 1.2, 1.2, RGB (153 - t, 100, 253 - t), TX_WHITE);

        DrawBoy    (675 + t, 330 + t, 1, 1, RGB(221, 160, 221), RGB(218, 105, 30),
                    RGB(0, 0, 255), 0, 0, t%10, 0, 0, 1, 0, 0, 0, 0, 0);

        DrawGrib   (720 + t, 360 + t, 1.2, 1.2, TX_ORANGE ,  TX_YELLOW);

        txSleep (50);
        t++;
        }

    txEnd();
    }


void MagicScene()
    {
    txBegin();

    int t = 0;
    int swing = 40;
    while (t <= 50)
        {
        txClear();
        SunnyDayFon();

        DrawTree ( 50,  250, 1.1, 1.1, RGB ( 0,  51 +  3*t, 58), abs(t%swing - swing/2) - swing/4);
        DrawTree (200,  250, 1.1, 1.1, RGB ( 0,  51 +  4*t, 58), abs(t%swing - swing/2) - swing/4);
        DrawTree (350,  250, 1.1, 1.1, RGB ( 0,  51 +  5*t, 58), abs(t%swing - swing/2) - swing/4);
        DrawTree (500,  250, 1.1, 1.1, RGB (51, 255 -  8*t, 52), abs(t%swing - swing/2) - swing/4);
        DrawTree (650,  250, 1.1, 1.1, RGB (51, 255 - 12*t, 52), abs(t%swing - swing/2) - swing/4);
        DrawTree (800,  250, 1.1, 1.1, RGB (51, 255 - 14*t, 52), abs(t%swing - swing/2) - swing/4);
        DrawTree (950,  250, 1.1, 1.1, RGB (51, 255 - 16*t, 52), abs(t%swing - swing/2) - swing/4);

        DrawSun  (100 + 10*t/100,  100,  0.8, 0.8, TX_YELLOW, 1, 1, 1, 1, 1);

        for (int i = 0; i < Max_rainDrops; i++)
            {
            Grass_draw   (X0Circle[i], 450 + 5*i, RGB (95, 236, 0), 0.5 , 0.5 );
            Grass_draw   (X0Circle[i], 450 + 5*i, RGB (95, 236, 0), 0.5 , 0.5 );
            DrawGrib     (X0Circle[i], 450 + 5*i, 0.5, 0.5, RGB (177, 100, 100), TX_WHITE);
            }

        for (int i = 0; i < Max_fireworks; i++)
            {
            Cluster_draw (X0Circle[i]*t/12, 20 + Y0Circle[i]*t/13, 0.1, 0.1, Color[i], Color[i]);
            Cluster_draw (X0Circle[i]*t/12, 20 + Y0Circle[i]*t/13, 0.1, 0.1, Color[i], Color[i]);
            Cluster_draw (X0Circle[i]*t/12, 20 + Y0Circle[i]*t/13, 0.1, 0.1, Color[i], Color[i]);
            Cluster_draw (X0Circle[i]*t/12, 20 + Y0Circle[i]*t/13, 0.1, 0.1, Color[i], Color[i]);
            Cluster_draw (X0Circle[i]*t/12, 20 + Y0Circle[i]*t/13, 0.1, 0.1, Color[i], Color[i]);
            Cluster_draw (X0Circle[i]*t/12, 20 + Y0Circle[i]*t/13, 0.1, 0.1, Color[i], Color[i]);
            Cluster_draw (X0Circle[i]*t/12, 20 + Y0Circle[i]*t/13, 0.1, 0.1, Color[i], Color[i]);
            }

        Cloud_draw (600 + 2*t,  60, 0.6, 0.6, TX_WHITE);
        Cloud_draw (400 + 2*t, 120, 0.5, 0.5, TX_WHITE);


        DrawGirl   (625, 430, 1, 1, RGB(221, 160, 221), RGB(218, 105, 30),
                    RGB(255, 0, 255), 0, 0, t%10, 0, 5, 1, 0, 0, 0, 0, 0);

        DrawGrib   (555, 460, 1.2, 1.2, RGB (153 - t, 100, 253 - t), TX_WHITE);

        DrawBoy    (775, 430, 1, 1, RGB(221, 160, 221), RGB(218, 105, 30),
                    RGB(0, 0, 255), 0, 0, t%10, 0, 0, 1, 0, 0, 0, 0, 0);

        DrawGrib   (820, 460, 1.2, 1.2, TX_ORANGE ,  TX_WHITE);

        txSleep (50);
        t++;
        }

    txEnd();
    }

void NirvanaScene()
    {
     HDC  background_Cartoon = txLoadImage ("SPACE.bmp");

    int t = 0;
    int swing = 60;
    int twitch = 20;
    while (t <= 150)
        {
        txBitBlt   (txDC(), 0, 0, 1000, 900, background_Cartoon, 0, 0);

        DrawGirl   (200 + ROUND(100*cos(t*0.1)), 200 + ROUND(100*sin(t*0.1)), 1, 1, RGB(221, 160, 221),
                    RGB(218, 105, 30), RGB(255, 0, 255), -20 + t%3*10, -20 + t%3*10, 0, 0, 5, 1, 0, 0, 0, 0, 0);

        DrawBoy    (700 + ROUND( 100*cos(t*0.1)), 200 + ROUND(100*sin(t*0.1) + 180), 1, 1, RGB(221, 160, 221),
                    RGB (218, 105, 30), RGB(0, 0, 255), 0, 0, -20 + t%3*10, 0, 0, 1, 0, 0, 0, 0, 0);

        DrawGrib   (300 + ROUND(200*cos(t*0.1)), 300 + ROUND(100*sin(t*0.1)), 0.7, 0.7, RGB (rand()%255, rand()%255, rand()%255), RGB (210, 209, 151));
        DrawGrib   (500 + ROUND(200*cos(t*0.1)), 500 + ROUND(100*sin(t*0.1)), 1.7, 1.7, RGB (rand()%255, rand()%255, rand()%255), RGB (210, 209, 151));

        DrawGrib   (800 + ROUND(200*cos(t*0.1)), 700 + ROUND(100*sin(t*0.1)), 0.7, 0.7, RGB (rand()%255, rand()%255, rand()%255), RGB (210, 209, 151));
        DrawGrib   (700 + ROUND(200*cos(t*0.1)), 100 + ROUND(100*sin(t*0.1)), 1.7, 1.7, RGB (rand()%255, rand()%255, rand()%255), RGB (210, 209, 151));

        txSleep (50);
        t++;
        }

    txDeleteDC (background_Cartoon);
    }

void Cluster_draw (int x, int y, double sizeX, double sizeY, COLORREF outline, COLORREF star)
    {
    txSetColor (outline);
    txSetFillColor (star);

    POINT cluster1[8] = {{                  x, y - ROUND(80*sizeY)}, {x + ROUND(20*sizeX), y - ROUND(20*sizeY)}, {x + ROUND(70*sizeX), y},
                         {x + ROUND(20*sizeX), y + ROUND(20*sizeY)}, {                  x, y + ROUND(70*sizeY)},
                         {x - ROUND(20*sizeX), y + ROUND(20*sizeY)}, {x - ROUND(70*sizeX), y}, {x - ROUND(20*sizeX), y - ROUND(20*sizeY)}};
    txPolygon (cluster1, 8);

   }

void Rain_draw (int x, int y)
    {
    txSetColor (TX_GREY,2);
    txLine (x, y, x + 20, y + 30);
    }


