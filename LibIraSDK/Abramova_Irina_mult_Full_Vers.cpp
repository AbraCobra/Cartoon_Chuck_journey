//===========================================================================
//         Abramova Irina, gymnasium 36, Krasnodar 2021
//===========================================================================

#include "TXLib.h"
#include <cmath>
#include "LibIra.h"

//function prototypes

void EntryScene ();
void SpringCountryScene();
void SpringCountrySceneEscape();
void PinkMountainScene();
void NightSavanahScene();
void NightSavanahSceneEnd();
void NightSavanahSceneEndFalling();
void NightSavanahSceneEndFallingResume();
void FinishScene();
void Title_draw    (int  x, int  y);
void TitleEnd_draw (int  x, int  y);
void WorkisDone    (int  x, int  y);
void FinishTitles  (int  x, int  y);


//function calls

int main()
    {
    txCreateWindow (1100, 900);

    EntryScene();
    SpringCountryScene();
    SpringCountrySceneEscape();
    PinkMountainScene ();
    NightSavanahScene ();
    NightSavanahSceneEnd();
    NightSavanahSceneEndFalling();
    NightSavanahSceneEndFallingResume();
    FinishScene();

    return 0;
    }

//functions

void EntryScene()
    {
    txBegin();
    txPlaySound ("SOUNDS//av013.wav", SND_LOOP);

    int t = 0;
    while (t <= 90)
        {
        txClear();
        SpringFonBegining();

        Grass_draw (    0 +  2*t, 400, TX_GREEN, 0.5, 0.5);
        Grass_draw (  100 +  2*t, 400, TX_GREEN, 0.7, 0.7);
        Grass_draw (  150 +  2*t, 400, TX_GREEN, 0.5, 0.5);
        Grass_draw (  250 +  2*t, 400, TX_GREEN, 0.6, 0.6);
        Grass_draw (  350 +  2*t, 400, TX_GREEN, 0.5, 0.5);
        Grass_draw (- 100 +  2*t, 400, TX_GREEN, 0.7, 0.7);
        Grass_draw (- 150 +  2*t, 400, TX_GREEN, 0.5, 0.5);
        Grass_draw (- 250 +  2*t, 400, TX_GREEN, 0.6, 0.6);
        Grass_draw (- 350 +  2*t, 400, TX_GREEN, 0.5, 0.5);
        Grass_draw (  550 +  2*t, 400, TX_GREEN, 0.5, 0.5);
        Grass_draw (  750 +  2*t, 400, TX_GREEN, 0.6, 0.6);
        Grass_draw (  950 +  2*t, 400, TX_GREEN, 0.5, 0.5);

        Title_draw          ( 1100 - 20*t, 100);
        Skateboard_draw     (- 100 + 13*t, 700, 0.8, 0.8);
        Skate_wheels_draw   ( - 50 + 13*t + ROUND (4*cos(t)) + ROUND (3*sin(t)), 730 + ROUND (3*cos(t)) - ROUND (4*sin(t)), 20);
        Chuck_draw          (   20 + 13*t, 600, 0.5, 0.5, (t%2*20) - 10, (t%2*30) + 50);

        txSleep (100);
        t++;
        }

    txEnd();
    }

void SpringCountryScene()
    {
    txBegin();
    txPlaySound (NULL);
    txPlaySound ("SOUNDS//av014.wav", SND_LOOP);

    int t = 1;
    while (t <= 120)
        {
        txClear();
        SpringFon();

        Cloud_draw     (      2*t,  20, 1.2, 1.2, TX_WHITE);
        Cloud_draw     (2*t + 900, 170, 0.5, 0.5, TX_WHITE);

        Millblades_draw (675, 180, ROUND (  100*cos(t*0.1) + 675),        ROUND (  100*sin(t*0.1) + 180));
        Millblades_draw (675, 180, ROUND (- 100*cos(t*0.1) + 675),        ROUND (- 100*sin(t*0.1) + 180));
        Millblades_draw (675, 180, ROUND (- 100*cos(t*0.1  + 1.5) + 675), ROUND (- 100*sin(t*0.1  + 1.5) + 180));
        Millblades_draw (675, 180, ROUND (  100*cos(t*0.1  + 1.5) + 675), ROUND (  100*sin(t*0.1  + 1.5) + 180));

        Butterfly_draw (120 + ROUND (15*(t - sin(t))),   50 + ROUND (50*(1 - cos(t))), RGB (204, 139,  51), 2);
        Butterfly_draw (460 + ROUND (15*(t - sin(t))),  150 + ROUND (50*(1 - cos(t))), RGB (204, 155, 202), 2);
        Butterfly_draw (320 + ROUND (15*(t - sin(t))),  150 + ROUND (50*(1 - cos(t))), RGB (255, 255, 113), 3);

        CatBody_draw   (300 + 2*t, 400 + ROUND (0.1*t), 0.7, 0.6, 20.0, RGB (255, 157, 60), RGB (255, 245, 255));

        Grass_draw     (800, 480, TX_GREEN, 1.1, 1.1);
        Grass_draw     (700, 580, TX_GREEN, 0.9, 0.9);
        Grass_draw     (750, 480, TX_GREEN, 0.9, 0.9);
        Grass_draw     (770, 490, TX_GREEN, 0.9, 0.9);
        Grass_draw     (710, 580, TX_GREEN, 0.9, 0.9);
        Grass_draw     (440, 600, TX_GREEN, 0.9, 0.9);
        Grass_draw     (470, 680, TX_GREEN, 0.9, 0.9);
        Grass_draw     (550, 500, TX_GREEN, 1.1, 1.1);
        MouseBody_draw (750, (t/4%2*50 - 50) + 500, 0.3, 0.3, RGB (116, 143, 141), RGB (255, 128, 128));
        Cheese_draw    (800, 500, 1.0);
        Mouse_twerk    (800, 570, 0.3, 0.3, t/8%2*5 + 10, t%2*10 + 50);
        Mouse_twerk    (840, 570, 0.3, 0.3, t/8%2*5 + 10, t%2*10 + 50);
        Mouse_twerk    (880, 570, 0.3, 0.3, t/8%2*5 + 10, t%2*10 + 50);
        Mouse_twerk    (920, 570, 0.3, 0.3, t/8%2*5 + 10, t%2*10 + 50);
        Mouse_twerk    (960, 570, 0.3, 0.3, t/8%2*5 + 10, t%2*10 + 50);
        Mouse_twerk    (760, 570, 0.3, 0.3, t/8%2*5 + 10, t%2*10 + 50);
        Mouse_twerk    (720, 570, 0.3, 0.3, t/8%2*5 + 10, t%2*10 + 50);
        Mouse_twerk    (680, 570, 0.3, 0.3, t/8%2*5 + 10, t%2*10 + 50);

        Girl_draw      (600 - 4*t, 500 - ROUND (0.5*t), 0.7, 0.7, 120,  ((t/4)%2)*50 - 50,
                       -10, 0, 0, 0, 0, t%2*3, 0, RGB (219, 112, 147));
        Stick_draw     (580 - 4*t, 380 - ROUND (0.5*t), 0.5, 0.5, (t%2*50)/7 - 20);

        Skateboard_draw     (- 100 + 11*t, 700, 0.8, 0.8);
        Skate_wheels_draw   (-  50 + 11*t + ROUND (4*cos(t)) + ROUND (3*sin(t)), 730 + ROUND (3*cos(t)) - ROUND (4*sin(t)), 20);
        Chuck_draw          (   20 + 11*t, 600, 0.5, 0.5, (t%2*20) - 10, (t%2*30) + 50);

        txSleep (100);
        t++;
        }

    txEnd();
    }

void SpringCountrySceneEscape()
    {
    txBegin();

    int t = 0;
    while (t <= 20)
        {
        txClear();
        SpringFon();

        Cloud_draw     (      2*t,  20, 1.2, 1.2, TX_WHITE);
        Cloud_draw     (2*t + 900, 170, 0.5, 0.5, TX_WHITE);

        Millblades_draw (675, 180, ROUND (  100*cos(t*0.1) + 675),        ROUND (  100*sin(t*0.1) + 180));
        Millblades_draw (675, 180, ROUND (- 100*cos(t*0.1) + 675),        ROUND (- 100*sin(t*0.1) + 180));
        Millblades_draw (675, 180, ROUND (- 100*cos(t*0.1  + 1.5) + 675), ROUND (- 100*sin(t*0.1  + 1.5) + 180));
        Millblades_draw (675, 180, ROUND (  100*cos(t*0.1  + 1.5) + 675), ROUND (  100*sin(t*0.1  + 1.5) + 180));

        Butterfly_draw (220 + ROUND (15*(t - sin(t))),   50 + ROUND (50*(1 - cos(t))), RGB (204, 139,  51), 2);
        Butterfly_draw (450 + ROUND (15*(t - sin(t))),  150 + ROUND (50*(1 - cos(t))), RGB (204, 155, 202), 2);
        Butterfly_draw (620 + ROUND (15*(t - sin(t))),  150 + ROUND (50*(1 - cos(t))), RGB (255, 255, 113), 3);

        Grass_draw     (800, 480, TX_GREEN, 1.1, 1.1);
        Grass_draw     (700, 580, TX_GREEN, 0.9, 0.9);
        Grass_draw     (750, 480, TX_GREEN, 0.9, 0.9);
        Grass_draw     (770, 490, TX_GREEN, 0.9, 0.9);
        Grass_draw     (710, 580, TX_GREEN, 0.9, 0.9);
        Grass_draw     (440, 600, TX_GREEN, 0.9, 0.9);
        Grass_draw     (470, 680, TX_GREEN, 0.9, 0.9);
        Grass_draw     (550, 500, TX_GREEN, 1.1, 1.1);

        CatBody_draw   (800, 430, 0.7, 0.6, 20.0, RGB (255, 157, 60), RGB (255, 245, 255));
        MouseBody_draw (750 + 70*t, 500, 0.3, 0.3, RGB (116, 143, 141), RGB (255, 128, 128));
        Cheese_draw    (800, 500, 1.0);
        MouseBody_draw (800 + 50*t, 570 +     t, 0.3, 0.3, RGB (116, 143, 141), RGB (255, 128, 128));
        MouseBody_draw (840 + 50*t, 570 + ROUND (0.1*t), 0.3, 0.3, RGB (116, 143, 141), RGB (255, 128, 128));
        MouseBody_draw (880 + 50*t, 570 + ROUND (0.2*t), 0.3, 0.3, RGB (116, 143, 141), RGB (255, 128, 128));
        MouseBody_draw (920 + 50*t, 570 + ROUND (0.3*t), 0.3, 0.3, RGB (116, 143, 141), RGB (255, 128, 128));
        MouseBody_draw (960 + 50*t, 570 + ROUND (0.3*t), 0.3, 0.3, RGB (116, 143, 141), RGB (255, 128, 128));
        MouseBody_draw (760 + 50*t, 570 + ROUND (0.5*t), 0.3, 0.3, RGB (116, 143, 141), RGB (255, 128, 128));
        MouseBody_draw (680 + 50*t, 570 + ROUND (0.6*t), 0.3, 0.3, RGB (116, 143, 141), RGB (255, 128, 128));

        Girl_draw      (100, 450, 0.7, 0.7, 120,  ((t/4)%2)*50 - 50,
                        -10, 0, 0, 0, 0, t%2*3, 0, RGB (219, 112, 147));
        Stick_draw     ( 70, 330, 0.5, 0.5, (t%2*50)/7 - 20);

        txSleep (100);
        t++;
        }

    txEnd();
    }

void PinkMountainScene()
    {
    txBegin();
    txPlaySound (NULL);
    txPlaySound ("SOUNDS//BY_RIVER.wav", SND_LOOP);

    int t = 0;
    int inclination = 30;
    while (t <= 120)
        {
        txClear();
        MountainsLandscape();

        Water_lily_draw (7*t +  150, 700, 0.8, 0.8);
        Water_lily_draw (  t +  350, 600, 0.5, 0.5);
        Water_lily_draw (  t +   50, 650, 0.3, 0.3);
        Water_lily_draw (  t +  850, 550, 0.7, 0.7);
        Chuck_draw      (7*t +  180, 600, 0.5, 0.5, (t%2*20) - 10, (t%2*30) + 50);

        Reed_draw       (800, 600, 0.8, 0.8, abs (t%inclination - inclination/2) - inclination/4);
        Reed_draw       (100, 550, 1.0, 1.0, abs (t%inclination - inclination/2) - inclination/4);
        Reed_draw       (300, 600, 0.8, 0.8, abs (t%inclination - inclination/2) - inclination/4);
        Reed_draw       (500, 700, 0.5, 0.5, abs (t%inclination - inclination/2) - inclination/4);
        Reed_draw       (700, 600, 0.5, 0.5, abs (t%inclination - inclination/2) - inclination/4);
        Reed_draw       (990, 500, 1.3, 1.3, abs (t%inclination - inclination/2) - inclination/4);

        txSleep (100);
        t++;
        }

    txEnd();
    }

void NightSavanahScene()
    {
    txPlaySound (NULL);
    txPlaySound ("SOUNDS//MARTINET.wav", SND_LOOP);
    txBegin();

    int t = 0;
    while (t < 14)
        {
        txClear();
        SavanahLandscape();

        Flower_draw    ( 850, 565, 0.5, 0.5, RGB (255, 203, 255));
        Flower_draw    ( 835, 465, 0.5, 0.5, RGB (255, 203, 255));
        Flower_draw    ( 885, 410, 0.5, 0.5, RGB (255, 100, 255));
        Flower_draw    ( 930, 510, 0.3, 0.3, RGB (255, 178, 255));
        Flower_draw    ( 780, 620, 0.3, 0.3, RGB (255, 178, 100));
        Chuck_draw     (t*50, 10 + 20*t, 0.5, 0.5, 10, (t%2*30) + 50);

        txSleep (200);
        t++;
        }

    txEnd();
    }

void NightSavanahSceneEnd()
    {
    txPlaySound (NULL);
    txBegin();

    int t = 0;
    while (t < 2)
        {
        txClear();
        SavanahLandscape();

        Flower_draw    ( 850, 565, 0.5, 0.5, RGB (255, 203, 255));
        Flower_draw    ( 835, 465, 0.5, 0.5, RGB (255, 203, 255));
        Flower_draw    ( 885, 410, 0.5, 0.5, RGB (255, 100, 255));
        Flower_draw    ( 930, 510, 0.3, 0.3, RGB (255, 178, 255));
        Flower_draw    ( 780, 620, 0.3, 0.3, RGB (255, 178, 100));
        Chuck_draw     ( 800, 520, 0.5, 0.5, - 30, (t%2*30) + 50);

        txSleep (100);
        t++;
        }

    txEnd();
    }

void NightSavanahSceneEndFalling()
     {
    txPlaySound (NULL);
    txPlaySound ("SOUNDS//BIRDHIT.wav", SND_LOOP);
    txBegin();

    int t = 0;
    while (t < 5)
        {
        txClear();
        SavanahLandscape();

        Flower_draw    ( 850, 565 + 50*t, 0.5, 0.5, RGB (255, 203, 255));
        Flower_draw    ( 835, 465 + 50*t, 0.5, 0.5, RGB (255, 203, 255));
        Flower_draw    ( 885, 410 + 50*t, 0.5, 0.5, RGB (255, 100, 255));
        Flower_draw    ( 930, 510 + 50*t, 0.3, 0.3, RGB (255, 178, 255));
        Flower_draw    ( 780, 620 + 50*t, 0.3, 0.3, RGB (255, 178, 100));
        Chuck_draw     ( 820, 520, 0.5, 0.5, - 30, -20 );

        txSleep (100);
        t++;
        }

    txEnd();
    }

void NightSavanahSceneEndFallingResume()
    {
    txPlaySound (NULL);
    txPlaySound ("SOUNDS//AFRICAN.wav", SND_LOOP);
    txBegin();

    int t = 0;
    while (t < 10)
        {
        txClear();
        SavanahLandscape();

        Flower_draw    ( 850, 790, 0.5, 0.5, RGB (255, 203, 255));
        Flower_draw    ( 835, 780, 0.5, 0.5, RGB (255, 203, 255));
        Flower_draw    ( 885, 800, 0.5, 0.5, RGB (255, 100, 255));
        Flower_draw    ( 930, 800, 0.3, 0.3, RGB (255, 178, 255));
        Flower_draw    ( 780, 800, 0.3, 0.3, RGB (255, 178, 100));
        Chuck_draw     ( 820, 520, 0.5, 0.5, - 30, -20 );

        txSleep (100);
        t++;
        }

    txEnd();
    }

void FinishScene()
    {
    txPlaySound (NULL);
    txPlaySound ("SOUNDS//FB002.wav", SND_LOOP);
    txBegin();

    int t = 0;
    while (t < 330)
        {
        txClear();
        SavanahLandscape();

        BigDipper_draw (  20, 150, 4*t/50);
        BigDipper_draw (  40,  50, 5*t/50);
        BigDipper_draw ( 140, 250, 5*t/50);
        BigDipper_draw (1010, 150, 4*t/50);
        BigDipper_draw (1010, 250, 5*t/50);
        BigDipper_draw (1010,  50, 6*t/50);
        Flower_draw    ( 850, 790, 0.5, 0.5, RGB (255, 203, 255));
        Flower_draw    ( 835, 780, 0.5, 0.5, RGB (255, 203, 255));
        Flower_draw    ( 885, 800, 0.5, 0.5, RGB (255, 100, 255));
        Flower_draw    ( 930, 800, 0.3, 0.3, RGB (255, 178, 255));
        Flower_draw    ( 780, 800, 0.3, 0.3, RGB (255, 178, 100));
        Chuck_draw     ( 820, 520, 0.5, 0.5, - 30, -20 );
        FinishTitles   ( 250,  900 - 4*t);
        WorkisDone     ( 300, 1500 - 4*t);

        txSleep (20);
        t++;
        }

    txEnd();
    }

void Title_draw (int x, int y)
    {
    txSetColor   (RGB (255, 215, 0));
    txSelectFont ("Comic Sans MS", 200);
    txTextOut    (x, y, "CHUCK`S");

    txSetColor   (RGB (255, 215, 0));
    txSelectFont ("Comic Sans MS", 200);
    txTextOut    (x, 300, "JOURNEY");
    }

void FinishTitles (int x, int y)
    {
    txSetColor    (RGB (255, 192, 203));
    txSelectFont  ("Monotype Corsiva", 180);
    txTextOut     (x, y, "THE END");
    }

void WorkisDone  (int x, int y)
    {
    txSetColor   (RGB (255, 215, 0));
    txSelectFont ("Comic Sans MS", 60);
    txTextOut    ( x, y, "The work is done");
    txTextOut    ( x, y + 100, "by teacher of informatics");
    txTextOut    ( x, y + 200, "Abramova Irina");
    txTextOut    ( x, y + 300, "gimnasium 36, Krasnodar");
    }
