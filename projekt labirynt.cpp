#include <iostream>
#include <string>

using namespace std;

char gracz = '8';
char klawisz;
int l = 5;

const int k = 10;
const int j = 20;
char labirynt[k][j] =

{
    {'#','$','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ','#','#',' ','#','#','#','#','#','#',' ','#','#',' ','#','#','#',' ','#'},
    {'#',' ','#','#',' ','#',' ','#',' ','#','#',' ','#','#',' ','#',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ','#',' ','#','#',' ','#','#',' ','#','#','#',' ','#'},
    {'#',' ','#','#','#','#',' ','#',' ','#',' ',' ','#',' ',' ',' ',' ','#',' ','#'},
    {'#',' ','#',' ',' ',' ',' ',' ',' ','#','#','#','#',' ','#','#',' ','#',' ','#'},
    {'#',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#','#',' ','#',' ','#'},
    {'#',' ','#',' ',' ',' ',' ',' ',' ','@',' ',' ',' ',' ',' ',' ',' ','#',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
};

char labirynt2[k][j] =
{
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#'},
    {'#',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ','#'},
    {'#',' ','#','#','#',' ',' ','#',' ','$',' ',' ',' ',' ',' ',' ',' ','#',' ','#'},
    {'#',' ',' ',' ',' ','#',' ','#','#',' ','#',' ',' ',' ',' ',' ','#','#',' ','#'},
    {'#','#',' ','#','#','#',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ','#',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ','#',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ','#',' ',' ',' ','@',' ',' ',' ',' ',' ',' ',' ','#',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
};

char labirynt3[k][j] =
{
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ','#','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ','#'},
    {'#',' ','#','#','#',' ','#',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#'},
    {'@',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ','$'},
    {'#',' ','#','#','#',' ','#','#','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#'},
    {'#','#',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ','#',' ',' ',' ',' ','#'},
    {'#',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#','#',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
};


char temp = '$';
int gracz_x(0);
int gracz_y(0);


void sciana();
void pozycja();
void ruchy();
void wypisanie();
void wygrana();
void reguly();
void koniec();




int main()
{
    reguly();

    pozycja();
    do
    {
        wypisanie();
        cin >> klawisz;
        ruchy();
        sciana();

    } while (labirynt[gracz_y][gracz_x] != '@');


    return 0;
}



void reguly()
{
    cout << "Witam w grze 'LABIRYNT' " << endl;
    cout << "---------------------\n\n" << endl;
    cout << "Twoim celem jest dotarcie do wyjscia oznaczonego znakiem '@'\n " << endl;
    cout << "---------------------\n" << endl;
    cout << "Do poruszania sie uzywaj klawiszy: " << endl;
    cout << "'g' by isc w gore " << endl;
    cout << "'d' by isc w dol " << endl;
    cout << "'l' by isc w lewo " << endl;
    cout << "'p' by isc w prawo " << endl;
    cout << "---------------------\n\n" << endl;
}

void ruchy()
{
    switch (klawisz)
    {
    case 'g':
        labirynt[gracz_y][gracz_x] = temp;
        gracz_y--;
        temp = labirynt[gracz_y][gracz_x];

        wygrana();
        labirynt[gracz_y][gracz_x] = gracz;
        break;

    case 'd':
        labirynt[gracz_y][gracz_x] = temp;
        gracz_y++;
        temp = labirynt[gracz_y][gracz_x];

        wygrana();
        labirynt[gracz_y][gracz_x] = gracz;
        break;

    case 'l':
        labirynt[gracz_y][gracz_x] = temp;
        gracz_x--;
        temp = labirynt[gracz_y][gracz_x];
        wygrana();
        labirynt[gracz_y][gracz_x] = gracz;
        break;

    case 'p':
        labirynt[gracz_y][gracz_x] = temp;
        gracz_x++;
        temp = labirynt[gracz_y][gracz_x];
        wygrana();
        labirynt[gracz_y][gracz_x] = gracz;
        break;

    default:
        break;
    }

}

void wypisanie()
{
    for (int y = 0; y <= k - 1; y++)
    {
        for (int x = 0; x <= j - 1; x++)
        {
            cout << labirynt[y][x];
        }
        cout << endl;
    }
}

void pozycja()
{
    for (int y = 0; y <= k - 1; y++)
    {
        for (int x = 0; x <= j - 1; x++)
        {
            if (labirynt[y][x] == '$')
            {
                labirynt[y][x] = gracz;
                gracz_x = x;
                gracz_y = y;
                break;
            }
        }
    }
}

void wygrana()
{   
    
    if (labirynt[gracz_y][gracz_x] == '@')
    {
        wypisanie();
        cout << "Gratulacje, udalo ci sie pokonac labirynt!\n\n" << endl;
        koniec();
       
    }

}


void sciana()
{

   temp == labirynt[gracz_y][gracz_x];
    if (temp == '#')
    {
        l -=1;
        cout << "Zostalo ci " << l << "Hp\n" << endl;
        if (l < 1)
        {
            cout << "Zostalo ci 0 HP, koniec gry\n " << endl;
            koniec();
        }

    }
}

void koniec()
{
    char TN;
    cout << "Zagraj ponownie (T) " << endl;
    cout << "Zakoncz program (N) " << endl;
    cin >> TN;

    switch (TN)
    {
    case 't':

        pozycja();
        cout << "---------------------\n" << endl;

        break;
    case 'T':

        pozycja();
        cout << "---------------------\n" << endl;

        break;
    case 'n':

        exit(0);
        break;
    case 'N':

        exit(0);
        break;


    default:
        koniec();
        break;
    }
}
