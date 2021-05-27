#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <sstream>
#include "nodo.h"

using namespace std;

template <class T>
class Lista {
    private:
        Nodo<T> *head;
        int lunghezza;
        Nodo<T> *tail;
        bool ascend;        //true: crescente, false: decrescente

    public:
        Lista(bool ascend) : head(NULL), tail(NULL), lunghezza(0), ascend(ascend) {}
        Lista() : Lista(true) {}

        int getLunghezza() {
            return lunghezza;
        }

        int getOrder() {
            return ascend;
        }

        bool deleteElement(unsigned int pos) {
            if(head != NULL){
                //la lista non è vuota
                int cnt = 0;

                Nodo<T> *temp = head;
                Nodo<T> *temp2 = NULL;

                while(temp != NULL){
                    if(pos == cnt){
                        if(pos == 0){
                            head = head->getLinkToNext();
                        }else{
                            temp2->setLinkToNext(temp->getLinkToNext());
                        }

                        delete temp;
                        lunghezza--;
                        return true;
                    }

                    temp2 = temp;
                    temp = temp->getLinkToNext();
                    cnt++;
                }
                
            }

            return false;
        }

        void print() {
            Nodo<T> *temp = head;

            cout << "Lista di lunghezza " << lunghezza << " (head:" << head << ")"<< endl;

            while(temp != NULL) {
                cout << "value: " << temp->toString() << " address:" << temp << " linkToNext: " << temp->getLinkToNext() << endl;
                temp = temp->getLinkToNext();
            }

        }

        void insertHead(T value) {
            //inserimento in testa
            if(head == NULL) {
                insertTail(value);
            }else {
                Nodo<T> *temp = new Nodo<T>(value);
                temp->setLinkToNext(head);
                head = temp;
            }

            lunghezza++;
        }

        void insertTail(T value) {
            //inserimento in coda
            Nodo<T> *temp = new Nodo<T>(value);

            if(head == NULL){
                head = temp;
                tail = temp;
            }else{
                tail->setLinkToNext(temp);
                tail = temp;
            }

            lunghezza++;
        }

        void deleteHead() {
            if(head != NULL){
                Nodo<T> *toDelete = head;
                head = head->getLinkToNext();
                delete toDelete;

                lunghezza--;
            }
        }

        void deleteTail() {
            if(head != NULL){
                Nodo<T> *newTail = head;

                while(newTail->getLinkToNext() != tail){
                    newTail = newTail->getLinkToNext();
                }
                newTail->setLinkToNext(NULL);
                delete tail;
                tail = newTail;

                lunghezza--;
            }
        }

        void insertAscend(T value) {
            if(ascend != true) { return; }

            if(head == NULL) {
                insertTail(value);
            }else {

                if(value <= head->getValue()){
                    insertHead(value);
                    return;
                }

                if(value >= tail->getValue()) {
                    insertTail(value);
                    return;
                }

                Nodo<T> *temp = new Nodo<T>(value);
                Nodo<T> *actual = head->getLinkToNext();
                Nodo<T> * prev = head;

                while(actual != NULL) {
                    if(prev->getValue() < temp->getValue() && temp->getValue() < actual->getValue()){
                        temp->setLinkToNext(prev->getLinkToNext());
                        prev->setLinkToNext(temp);
                        lunghezza++;
                        return;
                    }
                    prev = actual;
                    actual = actual->getLinkToNext();
                }

            }

        }

        void insertDescend(T value) {
            if(ascend != false) { return; }

            if(head == NULL) {
                insertTail(value);
            }else {

                if(value >= head->getValue()){
                    insertHead(value);
                    return;
                }

                if(value <= tail->getValue()) {
                    insertTail(value);
                    return;
                }

                Nodo<T> *temp = new Nodo<T>(value);
                Nodo<T> *actual = head->getLinkToNext();
                Nodo<T> * prev = head;

                while(actual != NULL) {
                    if(prev->getValue() > temp->getValue() && temp->getValue() > actual->getValue()){
                        temp->setLinkToNext(prev->getLinkToNext());
                        prev->setLinkToNext(temp);
                        lunghezza++;
                        return;
                    }
                    prev = actual;
                    actual = actual->getLinkToNext();
                }
            }

        }

};

#endif