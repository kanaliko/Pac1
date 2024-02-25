#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <vector>
//klavesy
#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77

using namespace std;

void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_Pos = {x, y};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}

using namespace std;

class Pacman
{
    private:
          int x;
          int y;
         char tvar;

    public:
//konstruktor bezparametricky
       Pacman()
       {

       }
//konstruktor parametricky
       Pacman(int vX, int vY, char vtvar)
       {
            x=vX;
            y=vY;
            tvar=vtvar;
       }

// zmeny suradnic
        void PohybDoPrava()
        {
            x++;
        }
        void PohybDoLava()
        {
            x--;
        }
        void PohybHore()
        {
            y--;
        }
        void PohybDole()
        {
            y++;
        }
        void zmazPacman()
        {
            gotoxy(x, y);
            cout << " ";
        }
        void nakresliPacman()
        {
           gotoxy(x,y);
           cout <<tvar;
        }

    //pohyb Pacman
       void pohybPackmana(bool &koniec)
	   {
            int klaves;
            zmazPacman();

            if(kbhit())
            {
                klaves = getch();
            }
            switch(klaves)
            {
              case KB_RIGHT: PohybDoPrava();
                             break;
              case KB_LEFT:  PohybDoLava();
                             break;
              case KB_UP:    PohybHore();
                             break;
              case KB_DOWN:  PohybDole();
                             break;
              case 'e':      koniec=true;
              default:       break;
            }
            nakresliPacman();
        }

};

int main()
{
   bool jekoniec=false;

   cout << "Vitaj u Pacmana" << endl;
   Pacman *p = new Pacman(5,5,'<');
 // p->nakresliPacman();
   cout<<"Zadaj klavesu e - koniec"<<endl;

   while(jekoniec!=true)
   {

     p->pohybPackmana(jekoniec);
     Sleep(80);

   }

    return 0;
}
