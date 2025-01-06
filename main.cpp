#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define MAX_SNAKE_SIZE 50

using namespace std;

HANDLE konsol = GetStdHandle(STD_OUTPUT_HANDLE);
COORD imlecKonumu;

/*  x= x koordinat sistemi
    y= y koordinat sistemini temsil ediyor */

void kordinat(int x, int y){  // x ve y ekseninde koordinat çizecek
    imlecKonumu.X = x; // x koordinat eksenini temsil eder
    imlecKonumu.Y = y; // y koordinat eksenini temsil eder
    SetConsoleCursorPosition(konsol, imlecKonumu); // imlec konumunu konsola atar
}

// ANA CLASS YAPISI
class Object {   // Soyut bir class tanımladım
public:
    // Polymorphism kullandık
    virtual void ciz() = 0;  // Çizmek için gerekli metod
    virtual void sil() = 0;   // Silmek için gerekli metod
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
        govde[0] = new Point1(50, 10);  // Yılanın başı için başlangıç konumu 
        for (int i = 1; i < MAX_SNAKE_SIZE; i++) {
            // Döngü i = 1'den başlıyor ve yılanın yalnızca gövde hücrelerini temizlemek için çalışıyor.
            govde[i] = NULL;  // Diğer parçalar başlangıçta boş
        }
        yon = 'd'; // Yılanın oyun başladığında otomatik olarak sağa doğru hareket etmesini sağlar.
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
        // Yılanın gövdesini baştan kuyruğa doğru hareket ettirir.
        for (int i = size - 1; i > 0; i--) { // Her hücre konumunu bir önceki hücreye atar
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

    void Carpma_kontrolu(Fruit& fruit, int& score) { // Çarpışma Kontrolü
        if (fruit.GetX() == govde[0]->GetX() && fruit.GetY() == govde[0]->GetY()) {
            Hucre_ekle(0, 0);  // Yılanın büyümesini sağlar
            fruit.Yer_degistir();  // Meyve yeni bir konum alır
            score += 10;  // Skoru artırır
        }
    }

    int GetSize() { return size; }
    int GetGovdeX(int index) { return govde[index]->GetX(); }
    int GetGovdeY(int index) { return govde[index]->GetY(); }
};

// Game Control Class
class Game {

private:
    Snake snake;
    Fruit fruit;
    int score;  

public:
    Game() : fruit(rand() % 50, rand() % 25), score(0) {}

    void PrintScore() {
        kordinat(0, 0); 
        cout << "Score: " << score;
    }

    void GameOver() {
        kordinat(20, 12);
        cout << "Game Over! Skorun: " << score << endl;
        kordinat(20, 13);
        cout << "Cikmak icin 'e' ye bas.";
    }

    void SetColor(int textColor, int backgroundColor) {
    // Konsol ekranının handle'ını al
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Renk ayarlarını yap
    SetConsoleTextAttribute(hConsole, (backgroundColor << 4) | textColor);
}

     void Start() {

        char k = NULL;

        do {
              SetColor(7,4); //Arka plan rengini ayarlamak için kullandık 

            if (kbhit()) { /*özel bir fonksiyondur ve genellikle konsol tabanlı oyunlarda, 
                kullanıcıdan gelen tuş girişlerini anlık olarak almak için kullanılır.*/
                k = getch(); //getch() fonksiyonu, tuşu okur ve kullanıcının basmış olduğu tuşun ASCII değerini döner.
                /Bu kombinasyon, özellikle "beklemeden" kullanıcının girişini alabilmek için kullanılır./
            }

            switch (k) {
                case 'w': case 'W': snake.TurnUp(); break;
                case 's': case 'S': snake.TurnDown(); break;
                case 'a': case 'A': snake.TurnLeft(); break;
                case 'd': case 'D': snake.TurnRight(); break;
            }

            snake.Hareket_etme();
            snake.Carpma_kontrolu(fruit, score);
            snake.ciz();
            fruit.ciz();
            PrintScore();

            // Yılanın Kendisiyle Çarpışmasını Kontrol Etme
            for (int i = 1; i < snake.GetSize(); i++) {
                /*Bu döngü, yılanın başının (body[0]) vücudunun geri kalanıyla çarpışıp çarpışmadığını kontrol eder.
                Eğer yılanın başı, vücudundaki herhangi bir parça ile aynı konumda ise, bu bir çarpışma anlamına gelir ve oyun biter.*/
                if (snake.GetGovdeX(0) == snake.GetGovdeX(i) && snake.GetGovdeY(0) == snake.GetGovdeY(i)) {
                    GameOver();
                    return;
                }
            }

            Sleep(800); //Bu satır, her döngüde (her karede) yılanın hareketini biraz yavaşlatır.
            //Daha küçük bir değer, oyunu çok hızlı hale getirir. Daha büyük bir değer ise oyunun hızını düşürür.
        } while (k != 'e');  // Döngü e tuşuna basılana kadar devam eder

    }

};

int main() {
    // Oyun fonksiyonlarını buraya ekleyebilirsiniz.

    return 0;
}
