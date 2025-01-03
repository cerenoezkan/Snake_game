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
// Fruit Class - Meyve
class Fruit : public Object {
private:
    Point2 point2;  // Point2 sınıfı burada bir üye değişken olarak tanımlanıyor
public:
    Fruit(int x, int y) : point2(x, y) {}

    void ciz() override { point2.ciz(); }
    void sil() override { point2.sil(); }

    int GetX() { return point2.GetX(); }
    int GetY() { return point2.GetY(); }

    void Yer_degistir() {
        point2.SetPoint(rand() % 50, rand() % 25);  // Meyveyi rastgele bir yere taşır 
    }
};

// Snake Class - Yılan
class Snake : public Object {
private:
    Point1* govde[MAX_SNAKE_SIZE];  // Yılanın vücut kısmı
    int size;  // Yılanın boyutu
    char yon;  // Yılanın yönü

public:
    Snake() {
        size = 1;  // Yılanın başlangıç boyutu
        govde[0] = new Point1(50, 10);  // Yılanın başı için kullanılan başlangıç konumu 
        for (int i = 1; i < MAX_SNAKE_SIZE; i++) {
            //döngü i = 1'den başlıyor ve yılanın yalnızca gövde hücrelerini temizlemek için çalışıyor. Gövde henüz olmadığı için bu elemanlara başlangıçta NULL atanıyor.
            govde[i] = NULL;  // Diğer parçalar başlangıçta boş
        }
        yon = 'd'; //yılanın oyun başladığında otomatik olarak sağa doğru hareket etmesini sağlar.
    }

    void Hucre_ekle(int x, int y) {
        if (size < MAX_SNAKE_SIZE) {
            govde[size++] = new Point1(x, y);  // Yılanın boyutunu artır
        }
    }


    void TurnUp() { yon = 'w'; }
    void TurnDown() { yon = 's'; }
    void TurnLeft() { yon = 'a'; }
    void TurnRight() { yon = 'd'; }

void Hareket_etme() {
        system("cls");
        //yılanın gövdesini baştan kuyruğa doğru hareket ettirir.
        for (int i = size - 1; i > 0; i--) { //her hücre konumunu bir önceki hücreye atar Örneğin, body[1] (ikinci hücre) pozisyonunu body[0] (ilk hücre) yapar.
            govde[i - 1]->Pozisyon_kopyalama(govde[i]);
        }

        // Yılanın başını yönüne göre hareket ettir
        switch (yon) {
            case 'w': govde[0]->MoveUp(); break;
            case 's': govde[0]->MoveDown(); break;
            case 'a': govde[0]->MoveLeft(); break;
            case 'd': govde[0]->MoveRight(); break;
        }
    }

    void ciz() override {
        for (int i = 0; i < size; i++) {
            govde[i]->ciz();  // Yılanın her parçasını çizer
        }
    }

    void sil() override {
        for (int i = 0; i < size; i++) {
            govde[i]->sil();  // Yılanın her parçasını siler
        }
    }
int main() {



    return 0;
}