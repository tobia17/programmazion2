#ifndef LISTA_DL_H
#define LISTA_DL_H

#include <iostream>
#include <sstream>
#include "nodo_dl.h"

using namespace std;

template <class T>
class ListaDL {
    private:
        NodoDL<T> *head;    //testa
        NodoDL<T> *tail;    //coda
        int lunghezza;
        bool ascend;        //di default 2, true: crescente, false: decrescente

    public:
        ListaDL(bool ascend) : head(NULL), tail(NULL), lunghezza(0), ascend(ascend) {}
        ListaDL() :ListaDL(true) {}

        bool getOrder() {
            //true: crescente, false: decrescente
            return ascend;
        }

        void insertTail(T value) {
            NodoDL<T> *newNodo = new NodoDL<T>(value);

            if(head == NULL){
                //la lista era vuova
                head = newNodo;
                tail = head;        //la coda corrisponde alla testa al primo inserimento
            }else{
                tail->setLinkToNext(newNodo);
                newNodo->setLinkToPrev(tail);
                tail = newNodo;
            }

            lunghezza++;
        }

        void insertHead(T value) {
            if(head == NULL){
                insertTail(value);
            }else {
                NodoDL<T> *temp = new NodoDL<T>(value);
                temp->setLinkToPrev(NULL);
                temp->setLinkToNext(head);
                head->setLinkToPrev(temp);
                head = temp;
            }

            lunghezza++;
        }

        void removeTail() {
            if(head != NULL){
                NodoDL<T> *toDelete = tail;
                tail = tail->getLinkToPrev();
                tail->setLinkToNext(NULL);
                delete toDelete;
                lunghezza--;
            }
        }

        void removeHead() {
            if(head != NULL){
                NodoDL<T> *toDelete = head;
                head = head->getLinkToNext();
                head->setLinkToPrev(NULL);
                delete toDelete;
                lunghezza--;
            }
        }

        NodoDL<T> *getHead(){
            return head;
        }

        string toString(){
            stringstream ss;

            ss << "Lista di lunghezza " << lunghezza << " indirizzo testa: " << head << "\n";

            NodoDL<T> *tmp = head;
            while(tmp != NULL){
                ss << "\t" << *tmp << "\n";
                tmp = tmp->getLinkToNext();
            }
            ss << "Fine lista\n";

            return ss.str();
        }

        string stringOnlyValues() {
            stringstream ss;

            NodoDL<T> *tmp = head;
            while(tmp != NULL){
                ss << tmp->getValue() << "\t";
                tmp = tmp->getLinkToNext();
            }

            return ss.str();
        }

        friend ostream& operator<<(ostream& out, ListaDL<T> list){
            out << list.toString();

            return out;
        }

        int getLunghezza() {
            return lunghezza;
        }

        void insertAscend(T value) {
            if(ascend == false) { return; }

            if(head == NULL) {
                insertTail(value);
            }else {

                if(head->getValue() > value) {
                    insertHead(value);
                    return;
                }

                if(tail->getValue() < value) {
                    insertTail(value);
                    return;
                }

                NodoDL<T> *tmp = head;
                NodoDL<T> *newNodoDL = new NodoDL<T>(value);
                while(tmp != NULL) {
                    if(tmp->getValue() < value && value < tmp->getLinkToNext()->getValue()){
                        newNodoDL->setLinkToNext(tmp->getLinkToNext());
                        newNodoDL->setLinkToPrev(tmp);
                        lunghezza++;
                        return;
                    }
                }

            }
        }

        void insertDescend(T value) {
            if(ascend == true) { return; }

            if(head == NULL) {
                insertTail(value);
            }else {

                if(head->getValue() <= value) {
                    insertHead(value);
                    return;
                }

                if(tail->getValue() >= value) {
                    insertTail(value);
                    return;
                }

                NodoDL<T> *tmp = head;
                NodoDL<T> *newNodoDL = new NodoDL<T>(value);
                while(tmp != NULL) {
                    if(tmp->getValue() > value && value > tmp->getLinkToNext()->getValue()){
                        newNodoDL->setLinkToNext(tmp->getLinkToNext());
                        newNodoDL->setLinkToPrev(tmp);
                        lunghezza++;
                        return;
                    }
                }

            }
        }

};


#endif