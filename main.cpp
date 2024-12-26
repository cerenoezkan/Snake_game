#include <iostream>
#include <conio.h>
#include <windows.h> /* HANDLE konsol = GetStdHandle(STD_OUTPUT_HANDLE); COORD imlecKonumu;*/
#include <time.h>

#define MAX_SNAKE_SIZE 50

using namespace std;

HANDLE konsol = GetStdHandle(STD_OUTPUT_HANDLE);
COORD imlecKonumu;

 /*  x= x kodinatsistemi
     y= y kordinatsistemini   temsil ediyor */

void kordinat(int x, int y){  // x ve y ekseni kodinatini çizicek
   imlecKonumu.X = x; // x kordinat eksenini temsil eder
   imlecKonumu.Y = y; // y kordinat  eksenini temsil eder
   SetConsoleCursorPosition(konsol, imlecKonumu); // imleckonumunu konsola atiyor
}

//ANA CLASS YAPISI 
class Object {   // soyut bir class tanimladim
public:
    //Polymorphism kullandık
    virtual void ciz() = 0;  //çizmek için gerekli metod
    virtual void sil() = 0;   //silmek için gerekli metod
};

int main() {



    return 0;
}