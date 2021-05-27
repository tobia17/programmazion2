/*
Una lista implementata con due vettori combinati è una struttura dati, 
utilizzata per l'implementazione di un insieme di elementi, 
simile ad una lista ma i cui elementi sono tutti memorizzati all'interno di un array.

Nello specifico, per l'implementazione di questa struttura dati si utilizzano due array: 
il primo array, K, mantiene le informazioni relative alle chiavi degli elementi dell'insieme, 
mentre il secondo, N, mantiene le informazioni relative alla posizione nell'array K dell'elemento successivo. 

In altre parole, se K[i] è un elemento della struttura dati, 
l'elemento successivo si trova nella posizione N[i] dell'array K.

Si suppone che, se i è l'ultimo elemento della lista, 
allora N[i] è uguale a -1. 

Si utilizza inoltre il valore H per indicare la posizione del primo elemento della lista.


Specifiche
    Si scriva un programma di C++ che implementi una lista mediante l'uso di vettori combinati e che, 
    partendo da una struttura dati vuota, permetta di effettuare su di essa N operazioni di inserimento e cancellazione. 

    Si chiede di restituire, alla fine delle N operazioni, la sequenza degli indici memorizzati all'interno dell'array N. Si considerino i seguenti vincoli:
        - ogni elemento inserito va memorizzato nella prima posizione vuota dell'array K;
        - la struttura dati rappresenta un insieme di elementi ordinato in ordine non decrescente;
        - quando un elemento viene cancellato la posizione da esso lasciata vuota deve essere occupata dall'elemento che si trova nell'ultima posizione del vettore K, e i riferimenti in N modificati di conseguenza;
        - se, al momento dell'inserimento di un elemento x, sono presenti nell struttura elementi uguali ad x, il nuovo elemento va inserito in coda a quelli già presenti.
        - se, al momento della cancellazione di un elemento x, sono presenti nella struttura più elementi uguali ad x, viene cancellato solo il primo di questi.


Dati in input
    L'input è costituito da 100 righe, una per ogni task. Ogni riga del file di input contiene N+1 elementi. 
    Il primo elemento rappresenta il numero N di operazioni da eseguire all'interno della lista, partendo da una struttura dati vuota. 
    Segue la sequenza delle N operazioni da eseguire, separati da uno spazio. 

    Nello specifico l'inserimento dell'elemento x è identificato da una lettera "i" seguita dal valore di x (senza spazi), 
    mentre la cancellazione dell'elemento x è identificato da una lettera "c" seguita dal valore di x (senza spazi).


Dati in output
    Il file di output è composto da 100 righe, una per ogni task presente nel file di input.

    Ogni riga del file di output contiene una sequenza di numeri interi corrispondenti agli indici memorizzati all'interno dell'array N, 
    utilizzato per l'implementazione della lista, alla fine delle N operazioni richieste in input.


Note
    Il valore di N è sempre compreso tra 1 e 2000.
    I numeri contenuti all'interno dell'array sono sempre interi compresi tra 1 e 10000.
    Viene richiesta la cancellazione solo di elementi presenti nella struttura dati.
    Un determinato valore può essere presente più volte tra i valori da inserire.
    Il valore della testa della lista, H, non deve essere stampata in output.

Esempio
Il seguente esempio presenta un file di input, contenente 3 task, ed il corrispondente file di output.

input.txt:
4 i8 i2 i3 c3
5 i5 i9 i10 c10 c5
8 i3 i2 i4 i14 i6 i1 i9 i2

output.txt
-1 0
-1
2 7 4 -1 6 1 3 0

*.Spiegazione dell'esempio.*
Nel primo caso d'esempio vengono richieste 4 operazioni nella lista, la quale subisce la sequente evoluzione:
- inserimento di 8:
K : [8]
N : [-1]
- inserimento di 2:
K : [8 2]
N : [-1 0]
- inserimento di 3:
K : [8 2 3]
N : [-1 2 0]
- cancellazione di 3:
K : [8 2]
N : [-1 0]

Nel secondo caso d'esempio vengono inseriti 5 elementi nella lista, la quale subisce la sequente evoluzione:
- inserimento di 5:
K : [5]
N : [-1]
- inserimento di 9:
K : [5 9]
N : [1 -1]
- inserimento di 10:
K : [5 9 10]
N : [1 2 -1]
- cancellazione di 10:
K : [5 9]
N : [1 -1]
- cancellazione di 5:
K : [9]
N : [-1]
*/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class ListaCombinata {
    private:
        int size;
        int *K;
        int *N;
        int numberOfElement;

    public:
        ListaCombinata(int _size) {
            this->size = _size;
            K = new int[size];
            N = new int[size];
            numberOfElement = 0;
        }

        void inserisci(int number){

        }

        void cancella(int number){

        }

        string toStringN() {
            stringstream ss;

            for(int i = 0; i < numberOfElement; i++){
                ss << N[i] << " ";
            }

            return ss.str();
        }
}

int main(){




    return 0;
}