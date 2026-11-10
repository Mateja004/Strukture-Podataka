#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Promeni ime ako se tvoj header drugačije zove
#include "SLList.h"

// Pomoćna klasa koja nasleđuje tvoju listu da bi mogla da pročita head/tail (protected)
class TestList : public SLList<int> {
public:
    // Ispis liste sa zaštitom od beskonačne petlje (ako napraviš ciklus)
    string toString() {
        ostringstream oss;
        SLLNode<int>* tren = head;
        int brojac = 0;
        while (tren != nullptr && brojac < 100) {
            oss << tren->info << " ";
            tren = tren->next;
            brojac++;
        }
        if (tren != nullptr) oss << "... (ciklus?)";
        return oss.str();
    }

    // Proverava da li tail zaista pokazuje na poslednji čvor
    bool tailOk() {
        if (head == nullptr) return tail == nullptr;
        SLLNode<int>* tren = head;
        int brojac = 0;
        while (tren->next != nullptr && brojac < 100) {
            tren = tren->next;
            brojac++;
        }
        return tren == tail;
    }
};

int ukupno = 0;
int prosao = 0;

// Svaki test pravi svežu listu 1 2 3 4 5 6 7
void test(const string& naziv, int segStart, int segEnd, int element, const string& ocekivano) {
    TestList l;
    for (int i = 7; i >= 1; i--) l.addToHead(i);

    l.moveSegmentBeforeElement(segStart, segEnd, element);

    string dobijeno = l.toString();
    bool listaOk = (dobijeno == ocekivano + " ");
    bool tailOk = l.tailOk();

    ukupno++;
    if (listaOk && tailOk) prosao++;

    cout << (listaOk && tailOk ? "[PROSAO] " : "[PAO]    ") << naziv << endl;
    cout << "   poziv:      moveSegmentBeforeElement(" << segStart << ", " << segEnd << ", " << element << ")" << endl;
    if (!(listaOk && tailOk)) {
        cout << "   ocekivano:  " << ocekivano << endl;
        cout << "   dobijeno:   " << dobijeno << endl;
        cout << "   tail:       " << (tailOk ? "ok" : "POGRESAN") << endl;
    }
    cout << endl;
}

int main() {
    cout << "Pocetna lista: 1 2 3 4 5 6 7" << endl << endl;

    test("1. Element iza segmenta, segment u sredini", 3, 5, 7, "1 2 6 3 4 5 7");
    test("2. Element ispred segmenta", 3, 5, 2, "1 3 4 5 2 6 7");
    test("3. Element odmah iza segEnd (nista se ne menja)", 3, 5, 6, "1 2 3 4 5 6 7");
    test("4. Segment pocinje na head-u", 1, 3, 6, "4 5 1 2 3 6 7");
    test("5. Segment na head-u, element nije odmah iza", 1, 3, 5, "4 1 2 3 5 6 7");
    test("6. Element je head", 3, 5, 1, "3 4 5 1 2 6 7");
    test("7. Segment zavrsava na tail-u (proveri tail!)", 5, 7, 2, "1 5 6 7 2 3 4");
    test("8. Element je tail", 2, 3, 7, "1 4 5 6 2 3 7");
    test("9. Segment od dva cvora", 3, 4, 7, "1 2 5 6 3 4 7");
    test("10. Element ne postoji u listi", 3, 5, 99, "1 2 3 4 5 6 7");
    test("11. segStart ne postoji u listi", 99, 5, 7, "1 2 3 4 5 6 7");
    test("12. segEnd ne postoji u listi", 3, 99, 7, "1 2 3 4 5 6 7");

    cout << "Rezultat: " << prosao << " / " << ukupno << " testova proslo" << endl;
    return 0;
}