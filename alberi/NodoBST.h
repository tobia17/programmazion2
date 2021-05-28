#ifndef NODO_BST_H
#define NODO_BST_H

#include <iostream>

using namespace std;

template <class T>
class NodoBST {
    private:
        NodoBST<T> *parent;
        NodoBST<T> *dx;
        NodoBST<T> *sx;
        T value;

    public:
        NodoBST(T value) : parent(NULL), dx(NULL), sx(NULL), value(value) {}
        NodoBST() : NodoBST(0) {}

        void setDx(NodoBST<T> *value) {
            dx = value;
        }

        void setSx(NodoBST<T> *value) {
            sx = value;
        }

        void setParent(NodoBST<T> *value) {
            parent = value;
        }

        NodoBST<T> *getDx() {
            return dx;
        }

        NodoBST<T> *getSx() {
            return sx;
        }

        NodoBST<T> *getParent() {
            return parent;
        }

        void setValue(T newValue) {
            value = newValue;
        }

        T getValue() {
            return value;
        }

        friend ostream& operator<<(ostream& out, const NodoBST<T>& nodo) {
            out << "NodoBST\tvalue:" << nodo.value << "\tparent: " << nodo.parent << "\tdx: " << nodo.dx << "\tsx: " << nodo.sx;
            return out;
        }
    
};

#endif