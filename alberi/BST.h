#ifndef BST_H
#define BST_H

#include <iostream>
#include "NodoBST.h"

using namespace std;

template <class T>
class BST {
    private:
        NodoBST<T> *root;

        void recursiveInsert(NodoBST<T> *nodo, NodoBST<T> *newNodo) {
            if(newNodo->getValue() <= nodo->getValue() && nodo->getSx() == NULL) {
                //caso base 1
                nodo->setSx(newNodo);
                newNodo->setParent(nodo);
                return;
            }

            if(newNodo->getValue() > nodo->getValue() && nodo->getDx() == NULL) {
                //caso base 2
                nodo->setDx(newNodo);
                newNodo->setParent(nodo);
                return;
            }

            if(newNodo->getValue() <= nodo->getValue()){
                recursiveInsert(nodo->getSx(), newNodo);
            }else{
                recursiveInsert(nodo->getDx(), newNodo);
            }
        }

        void recursivePrintDESC(NodoBST<T> *nodo) {
            if(nodo == NULL) {
                return;
            }
            recursivePrintDESC(nodo->getDx());
            cout << "\t" << *nodo << endl;
            recursivePrintDESC(nodo->getSx());
        }

        void recursivePrintASC(NodoBST<T> *nodo) {
            if(nodo == NULL) {
                return;
            }
            recursivePrintASC(nodo->getSx());
            cout << "\t" << *nodo << endl;
            recursivePrintASC(nodo->getDx());
        }

    public:

        BST() : root(NULL) {}

        void insert(T value) {
            NodoBST<T> *newNodo = new NodoBST<T>(value);

            if(root == NULL) {
                root = newNodo;
            }else {
                recursiveInsert(root, newNodo);
            }
        }

        void printASC() {
            cout << "Binary Search Tree Ascend (root: " << root << ")\n";
            recursivePrintASC(root);
        }

        void printDESC() {
            cout << "Binary Search Tree Descend (root: " << root << ")\n";
            recursivePrintDESC(root);
        }

        NodoBST<T> *minimo() {
            NodoBST<T> *minimo = root;

            if(root == NULL) {
                return NULL;
            }else{
                while(minimo->getSx() != NULL){
                    minimo = minimo->getSx();
                }
                return minimo;
            }
            return NULL;
        }

        NodoBST<T> *massimo() {
            NodoBST<T> *massimo = root;

            if(root == NULL) {
                return NULL;
            }else{
                while(massimo->getDx() != NULL){
                    massimo = massimo->getDx();
                }
                return massimo;
            }
            return NULL;
        }

        NodoBST<T> *search(T value) {
            NodoBST<T> *find = root;

            while(find != NULL) {
                if(find->getValue() == value){
                    return find;
                }else if(value < find->getValue()) {
                    find = find->getSx();
                }else if(value > find->getValue()){
                    find = find->getDx();
                }
            }

            return NULL;
        }

};

#endif