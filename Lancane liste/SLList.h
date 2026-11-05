#pragma once
#include <iostream>

// 1. Klasa koja predstavlja jedan čvor u listi
template <class T>
class SLLNode {
public:
    T info;               // Podatak koji čvor čuva
    SLLNode<T>* next;     // Pokazivač na sljedeći čvor

    // Konstruktori za kreiranje čvora
    SLLNode() { next = nullptr; }
    SLLNode(T i) { info = i; next = nullptr; }
    SLLNode(T i, SLLNode<T>* n) { info = i; next = n; }
};

// 2. Klasa koja predstavlja samu listu
template <class T>
class SLList {
protected:
    SLLNode<T>* head;     // Pokazivač na prvi čvor u listi
    SLLNode<T>* tail;     // Pokazivač na posljednji čvor u listi

public:
    // Konstruktor: na početku je lista prazna, pa pokazivači ne pokazuju nigdje
    SLList() { head = tail = nullptr; }

    // Gotova funkcija za dodavanje na početak kako bi mogao testirati
    void addToHead(T el) {
        head = new SLLNode<T>(el, head);
        if (tail == nullptr) tail = head;
    }

    // OVDJE ĆEŠ PISATI SVOJE FUNKCIJE

    void printList(){
        SLLNode<T>*tren=head;

        while(tren!=nullptr){

            cout<<tren->info<<" ";
            tren=tren->next;
        }
    }
    

    bool postoji(T trazeniBroj){
        SLLNode<T>* tren=head;

        while(tren!=nullptr){
            if(tren->info==trazeniBroj){
                return true;
            }
            
            tren=tren->next;
        }
        return false;
    }

    int prebrojiVeceOd(T granica){
        SLLNode<T>*tren=head;
        int brojac=0;

        while(tren!=nullptr){
            if(tren->info>granica){
                brojac++;
            }
            tren=tren->next;
        }

        return brojac;
    }

    void dodajIza(T novaVrednost, T ciljanjaVrednost){
        SLLNode<T>* tren=head;

        while(tren!=nullptr){
            if(tren->info==ciljanjaVrednost){
                SLLNode<T>*novi=new SLLNode<T>(novaVrednost);
                novi->next=tren->next;
                tren->next=novi;   

                if(tren==tail){
                    tail=novi;
                }

                return;
            }
            tren=tren->next;
        }
    }

    void obrisi(T vrednost){
            
        //ako je lista potpuno prazna
            if(head==nullptr){
                return;
            }
            //slucaj kada brisemo cvor koji je na pocetku liste tj head
            else if(head->info==vrednost){
                SLLNode<T>*ZaBrisanje=head;
                head=head->next;

                if(head==nullptr){
                    tail=nullptr;
                }

                delete ZaBrisanje;
                return;
            }
            else{
                //slucaj kada brisemo sa sredine ili kraja
                SLLNode<T>* pred=head; //ovo gleda prvi cvor npr imamo 10->20->30
                //pred ce gledati na 10
                SLLNode<T>* tren=head->next; // a tren ce gledati na 20

               while(tren!=nullptr){
                if(tren->info==vrednost){
                    pred->next=tren->next; //nasli smo koji hocemo da obrisemo u ovom slucaju 20
                    //i zbog toga sa 10 skacemo na 30 da bi lista ostala povezana


                    if(tren==tail){
                        tail=pred;
                    }

                    delete tren;
                    return;
                }

                pred=pred->next;
                tren=tren->next;
               }
            
            }
            
        }

    SLLNode<T>* MergeTwo(SLLNode<T>* h1, SLLNode<T>* h2){

        SLLNode<T> dummy;
        dummy->next=nullptr;
        SLLNode<T>* tail=&dummy;

        while(h1!=nullptr && h2!=nullptr){
            if(h1->info <=h2->info){
                tail->next=h1;
                h1=h1->next;
            }else{
                tail->next=h2;
                h2=h2->next;
            }

            tail=tail->next;
        }

        if(h1!=nullptr){
            tail->next=h1;
        }else{
            tail->next=h2;
        }

        return dummy.next;
    }

    SLLNode<T>* MergeThree(SLLNode<T>* h1, SLLNode<T>* h2, SLLNode<T>* h3){
        SLLNode<T> dummy;
        dummy.next=nullptr;
        SLLNode<T> * tail=&dummy;

        while(h1!=nullptr || h2!=nullptr || h3!=nullptr){
            if(h1->info<=h2->info && h1->info<=h3->info){
                tail->next=h1;
                h1=h1->next;
            }
            else if (h2->info<=h3->info)
            {
                    tail->next=h2;
                    h2=h2->next;
            }else{
                tail->next=h3;
                h3=h3->next;
            }
            
            tail=tail->next;
        }

        if(h1!=nullptr){
            tail->next=h1;
        }else{
            tail->next=h2;
        }
        
        return dummy.next;
    }
};