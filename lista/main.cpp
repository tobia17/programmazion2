#include <iostream>
#include "lista.h"
#include "lista_dl.h"

using namespace std;

class Transazione {
    private:
        int prezzo;
        int numero;

    public:
        Transazione(int numero, int prezzo) : numero(numero), prezzo(prezzo) {}

    friend ostream& operator<<(ostream& out, const Transazione trz){
        out << "transazione n." << trz.numero << " di prezzo " << trz.prezzo;
        return out;
    }
};

int main(){

    /*    
    Lista<int> l;
    l.insertTail(3);
    l.insertTail(13);
    l.insertTail(7);
    l.insertTail(0);
    l.insertTail(12);
    l.insertTail(1);
    l.insertTail(5);

    cout << endl << "stampa della lista" << endl << endl;
    l.print();

    cout << endl << endl;
    l.deleteTail();
    l.print();

    cout << endl << endl;
    l.deleteHead();
    l.print();

    cout << endl << endl;
    */

    Lista<int> l2(true);        //lista in ordine crescente
    l2.insertAscend(4);
    l2.insertAscend(2);
    l2.insertAscend(7);
    l2.insertAscend(5);
    l2.print();

    

    /*
    Lista<Transazione> trl;
    Transazione tr1(1, 32);
    Transazione tr2(2, 3122);
    trl.newElement(tr1);
    trl.newElement(tr2);
    trl.print();
    */

   /*
    ListaDL<int> lista2;
    lista2.insertTail(5);
    lista2.insertTail(6);
    lista2.insertTail(3);
    lista2.insertTail(8);
    lista2.insertTail(1);
    cout << lista2 << endl;
    cout << "Valori: " << lista2.stringOnlyValues() << endl;

    lista2.removeHead();
    cout << "Valori: " << lista2.stringOnlyValues() << endl;

    lista2.removeTail();
    cout << "Valori: " << lista2.stringOnlyValues() << endl;
    */

   ListaDL<int> lista_dl_2(false);
   lista_dl_2.insertDescend(4);
   lista_dl_2.insertDescend(1);
   lista_dl_2.insertDescend(-3);
   lista_dl_2.insertDescend(13);
   cout << lista_dl_2 << endl;

    return 0;
}