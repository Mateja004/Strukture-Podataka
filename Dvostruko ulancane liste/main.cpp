#include <iostream>
#include "DLList.h" // Uključujemo naš templejt fajl

using namespace std;

int main() {
    // Kreiramo instancu dvostruko ulančane liste sa celim brojevima (int)
    DLList<int> lista;

    // Punimo listu vrednostima kako bismo imali test podatke
    lista.addToTail(10);
    lista.addToTail(20);
    lista.addToTail(30);
    lista.addToTail(40);
    lista.addToTail(50);
    lista.addToTail(60);
    lista.addToTail(70);

    cout << "Originalna lista:" << endl;
    lista.printAll();

    // Testiramo zadatak sa blanketa: Obrni sve izmedju 20 i 60
    // Ocekivani rezultat izmedju njih: 50 40 30
    lista.reverseSegment(20, 60);

    cout << "Lista nakon reverseSegment(20, 60):" << endl;
    lista.printAll();

    return 0;
}