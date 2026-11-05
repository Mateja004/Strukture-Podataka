#pragma once
#include <iostream>

template<class T>
class DLLNode{
    public:
    T info;
    DLLNode<T> *prev, *next;

    DLLNode(){prev=nullptr;next=nullptr;}
    DLLNode(T el){info=el;prev=nullptr;next=nullptr;}
    DLLNode(T el, DLLNode<T>*p, DLLNode<T>*n){info=el;prev=p;next=n;}
    ~DLLNode(){}

    T print(){return info;}
    bool isEqual(T el){return el==info;}
};

template <class T>
class DLList {
protected:
    DLLNode<T> *head, *tail;

public:
    DLList() { head = tail = nullptr; }
    
    ~DLList() {
        while (!isEmpty()) {
            deleteFromHead();
        }
    }

    bool isEmpty() { return head == nullptr; }

    // Dodavanje na kraj liste[cite: 66]
    void addToTail(T el) {
        if (!isEmpty()) {
            tail = new DLLNode<T>(el, tail, nullptr);
            tail->prev->next = tail;
        } else {
            head = tail = new DLLNode<T>(el);
        }
    }

    // Brisanje sa početka liste (potrebno za destruktor)
    T deleteFromHead() {
        if (isEmpty()) throw "Lista je prazna!";
        T el = head->info;
        DLLNode<T>* tmp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete tmp;
        return el;
    }

    // Pomoćna metoda za ispis cele liste na ekran
    void printAll() {
        for (DLLNode<T>* tmp = head; tmp != nullptr; tmp = tmp->next) {
            std::cout << tmp->print() << " ";
        }
        std::cout << std::endl;
    }


    //decembar 2025 prvi zad.
    void reverseSegment(int k, int j){
        DLLNode<T>* cvorK=head;

        while(cvorK!=nullptr && cvorK->info!=k){
            cvorK=cvorK->next;
        }

        DLLNode<T>* cvorJ=cvorK->next;

        while(cvorJ!=nullptr && cvorJ->info!=j){
            cvorJ=cvorJ->next;
        }

        DLLNode<T>* startNode=cvorK->next;
        DLLNode<T>* endNode=cvorJ->prev;

        DLLNode<T>* tren=startNode;
        while(tren!=cvorJ){
            DLLNode<T>* originalniNext=tren->next;

            tren->next=tren->prev;
            tren->prev=originalniNext;

            tren=originalniNext;
        }

        startNode->next=cvorJ;
        cvorJ->prev=startNode;

        cvorK->next=endNode;
        endNode->prev=cvorK;

    }
};