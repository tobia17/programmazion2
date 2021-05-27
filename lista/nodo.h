#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <sstream>

using namespace std;

template <class T>
class Nodo {
    private:
        Nodo<T> *linkToNext;
        T value;
        
    public:
        Nodo(T value, Nodo<T> *linkToNext) : value(value), linkToNext(linkToNext) {}
        Nodo(T value) : Nodo(value, NULL) {}

        void setLinkToNext(Nodo<T> *link) {
            linkToNext = link;
        }

        Nodo<T> *getLinkToNext() {
            return linkToNext;
        }

        string toString() {
            stringstream ss;
            ss << value;
            return ss.str();
        }

        T getValue(){
            return value;
        }

        friend ostream& operator<<(ostream& out, Nodo<T> nodo) {
            out << nodo.toString();
            return out;
        }

};

#endif