#ifndef NODO_DL_H
#define NODO_DL_H

#include <iostream>
#include <sstream>

using namespace std;

template <class T>
class NodoDL {
    private:
        NodoDL<T> *linkToNext;
        NodoDL<T> *linkToPrev;
        T value;

    public:
        NodoDL(T value, NodoDL<T> *linkToNext, NodoDL<T> *linkToPrev) : value(value), linkToNext(linkToNext), linkToPrev(linkToPrev) {}
        NodoDL(T value): NodoDL(value, NULL, NULL) {}

        NodoDL<T> *getLinkToNext (){
            return linkToNext;
        }

        NodoDL<T> *getLinkToPrev (){
            return linkToPrev;
        }

        void setLinkToNext(NodoDL<T> *next) {
            linkToNext = next;
        }

        void setLinkToPrev(NodoDL<T> *prev) {
            linkToPrev = prev;
        }

        string toString() {
            stringstream ss;
            ss << "value: " << value << " prev: " << linkToPrev << " next: " << linkToNext;
            return ss.str();
        }

        T getValue() {
            return value;
        }

        friend ostream& operator<<(ostream& out, NodoDL<T> nodo) {
            out << nodo.toString();
            return out;
        }

};


#endif