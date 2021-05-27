/*
Implementare una classe he simuli il comportamento di una array in maniera dinamica.
L'array conterrà solo interi
*/

#include <iostream>

using namespace std;

template <class T>
class Punto {
    private:
        T x, y;

    public:

        //Punto() : x(0), y(0) {}   //questa è l'alternativa del costruttore senza parametri

        Punto() {
            //costruttore di default senza parametri
            x = 0; 
            y = 0;
        }

        Punto(T _x, T _y) : x(_x), y(_y) {}

        friend ostream& operator<<(ostream& out, const Punto& p) {
            //overload dell'operatore <<
            out << "(" << p.x << ", " << p.y << ")";
            return out;
        }
};

template <class T>
class ArrayDinamico {
    private:
        int numeroElementi;
        int dimensioneMassima;
        T *array;

    public:
        ArrayDinamico (int _dimensioneMassima) : dimensioneMassima(_dimensioneMassima) {
            numeroElementi = 0;
            array = new T[dimensioneMassima];
        }

        void print() {
            for(int i = 0; i < numeroElementi; i++) {
                cout << array[i] << " ";
            }
            cout << endl;
        }

        int getDimensioneMassima() {
            return dimensioneMassima;
        }

        void setDimensioneMassima(int _dimensioneMassima) {
            dimensioneMassima = _dimensioneMassima;
        }

        void inserisci(T n) {
            if(numeroElementi == dimensioneMassima){
                dimensioneMassima *= 2;
                T *tmp = new T[dimensioneMassima];
                for(int i = 0; i < numeroElementi; i++){
                    tmp[i] = array[i];
                }

                T *toDelete = array;
                array = tmp;

                delete []toDelete;
            }
            array[numeroElementi++] = n;
        }

        void cancella(int i){
            if(i >= numeroElementi){
                return;
            }

            for(int j = i; j < numeroElementi-1; j++){
                array[j] = array[j+1];
            }
            numeroElementi--;

            if(numeroElementi < dimensioneMassima/2){
                T *tmp = new T[dimensioneMassima/2];
                for(int j = 0; j < numeroElementi; j++){
                    tmp[j] = array[j];
                }
                dimensioneMassima /= 2;

                T *toDelete = tmp;
                array = tmp;
                delete []toDelete;
            }
        }

        T& operator[] (int i) {
            if(i >= 0 && i < numeroElementi) {
                return array[i];
            }

            cout << "Errore: l'indice " << i << " non è corretto." << endl;
            exit(0);
        }

        T& operator[] (int i) const {
            if(i >= 0 && i < numeroElementi) {
                return array[i];
            }

            cout << "Errore: l'indice " << i << " non è corretto." << endl;
            exit(0);
        }
};

int main(){

    ArrayDinamico<int> ar(10);

    for(int i = 0; i < 20; i++){
        ar.inserisci(i);
    }
    ar.print();
    ar.cancella(7);
    ar[4] = 1;
    ar.print();

    ArrayDinamico<Punto<int> > array_punti(5);

    Punto<int> p1(1, 4);
    Punto<int> p2(3, 6);

    array_punti.inserisci(p1);
    array_punti.inserisci(p2);

    array_punti.print();

    return 0;
}