/*
L'Insertion sort, in italiano ordinamento a inserimento, è un algoritmo relativamente semplice per ordinare un array. 
Non è molto diverso dal modo in cui un essere umano, spesso, ordina un mazzo di carte. 
Esso è un algoritmo in place, cioè ordina l'array senza doverne creare una copia, risparmiando memoria. 
Pur essendo molto meno efficiente di algoritmi più avanzati, può avere alcuni vantaggi: ad esempio, è semplice da implementare ed è efficiente per insiemi di partenza che sono quasi ordinati.

Specifiche
Ogni volta che un nuovo elemento K dell'array viene ordinato, tramite inserimento, 
un certo numero degli elementi che si trovano alla sua sinistra (tutti quelli minori di K) vengono spostati di una posizione a destra per lasciare posto al nuovo elemento.
Si scriva un programma di C++ che sia in grado di calcolare il numero totale di spostamenti che vengono fatti durante l'esecuzione dell'algoritmo InsertionSort.

Dati in input
Il file di input contiene 100 task, uno per ogni riga. 
Ogni riga del file di input contiene N+1 elementi. 
Il primo elemento rappresenta il numero N di elementi presenti nell'array. 
Seguono gli N elementi dell'array.

Dati in output
Il file di output conterrà 100 righe di testo, una per ogni task contenuto nel file di input. 
Nello specifico, ogni riga del file di output dovrà contenere un unico valore, il quale rappresenta l'esatto numero di spostamenti effettuati dall'algoritmo nel corrispondente task.

Note
Il valore di N è sempre compreso tra 10 e 1000.
I numeri contenuti all'interno dell'array sono sempre interi compresi tra 0 e 100.
Un determinato valore può essere presente più volte all'interno del vettore da ordinare.

Esempio
Il seguente esempio presenta un file di input, contenente 3 task, ed il corrispondente file di output.

input.txt:
8 4 5 8 4 10 8 5 20
9 15 4 18 16 20 15 8 16 20
11 4 14 13 2 7 4 4 13 23 26 28

output.txt
6
12
13
*/

#include <iostream>
#include <fstream>

using namespace std;

int foo(int *v, int n){
    int cnt = 0;

    for(int i = 1; i < n; i++){
        int temp = v[i];
        int j = i-1;
        while(v[j] > temp && j >= 0){
            v[j+1] = v[j];
            j--;
            cnt++;
        }
        v[j+1] = temp;
    }

    return cnt;
}

void stampa_array(int *v, int n){
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){

    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    while(getline(input, line)){

        size_t pos = line.find(' ');
        int n = stoi(line.substr(0, pos));
        line.erase(0, pos+1);

        int *v = new int[n];
        int i = 0;
 
        while((pos = line.find(' ')) != string::npos){
            v[i] = stoi(line.substr(0, pos));
            line.erase(0, pos+1);
            i++;
        }
        v[n-1] = stoi(line);

        output << foo(v, n) << "\n";
        //stampa_array(v, n);

        delete []v;

    }

    output.close();
    input.close();
    return 0;
}