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

// Point Class - Snake için
class Point1 : public Object {
private:
    int x, y;  // X ve Y koordinatları
public:
    Point1(int x = 30, int y = 30) : x(x), y(y) {}

    int GetX() { return x; }  // X koordinatını al
    int GetY() { return y; }  // Y koordinatını al

    void SetPoint(int x, int y) { this->x = x; this->y = y; }  

    void ciz() override {  // X ve Y koordinatlarında bir * çizer
        kordinat(x, y);
        cout << "*";
    }

    void sil() override {  // X ve Y koordinatındaki *'yi siler
        kordinat(x, y);
        cout << " ";
    }

    void MoveUp() { y--; }    // Yılanı yukarı hareket ettir
    void MoveDown() { y++; }  // Yılanı aşağı hareket ettir
    void MoveLeft() { x--; }  // Yılanı sola hareket ettir
    void MoveRight() { x++; } // Yılanı sağa hareket ettir

    void Pozisyon_kopyalama(Point1* p) {
        p->x = x;
        p->y = y;
    }
};

// Point2 Class - Meyve için
class Point2 : public Object {
private:
    int x, y;  // X ve Y koordinatları
public:
    Point2(int x = 30, int y = 30) : x(x), y(y) {}

    int GetX() { return x; }  // X koordinatını al
    int GetY() { return y; }  // Y koordinatını al

    void SetPoint(int x, int y) { this->x = x; this->y = y; }  // X ve Y'yi ayarla

    void ciz() override {  // Meyveyi X ve Y koordinatında çizer
        kordinat(x, y);
        cout << "*";
    }

    void sil() override {  // Meyveyi X ve Y koordinatındaki *'yi siler
        kordinat(x, y);
        cout << " ";
    }

};

int main() {



    return 0;
}