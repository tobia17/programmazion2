#include <iostream>
#include <fstream>

using namespace std;

/*
Il Selection-sort, in italiano ordinamento per selezione, è un algoritmo relativamente semplice per ordinare un array che opera in place. 
L'algoritmo è di tipo non adattivo, ossia il suo tempo di esecuzione non dipende dall'input ma dalla dimensione dell'array. 
L'algoritmo seleziona di volta in volta il numero minore nella sequenza di partenza e lo sposta nella sequenza ordinata; 
di fatto la sequenza viene suddivisa in due parti: la sottosequenza ordinata, che occupa le prime posizioni dell'array, e la sottosequenza da ordinare, che costituisce la parte restante dell'array.

Specifiche
Si supponga che l'algoritmo venga eseguito su di un array di n elementi. 
Alla i-esima iterazione dell'algoritmo Selection-sort l'elemento di posizione k dell'array viene selezionato e viene sostituito con l'elemento di posizione i. 
Si suppone quindi che le iterazioni inizino con un valore i pari a 0 e terminino con il valore i pari a n-1. 
Si supponga inoltre che, nella selezione dell'elemento minimo, l'algoritmo scelga sempre quello più a sinistra qualora fossero presenti più elementi con valore minimo.
Si scriva un programma di C++ che sia in grado di calcolare la somma delle distanza (k-i), per tutte le iterazioni dell'algoritmo, ovvero per i che va da 0 a n-1.
*/

int cnt_selection(int *a, int n){
    int cnt = 0;
    int difference_k_i;

    for(int i = 0; i < n-1; i++){
	    int min = i;
        for(int j = i+1; j < n; j++){
            if (a[j] < a[min]){
                min = j;
            }	     
        }

        difference_k_i = min - i;
        
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;

        cnt += difference_k_i;
    }

    return cnt;
}

/*
Dati in input
Il file di input contiene 100 task, uno per ogni riga. 
Ogni riga del file di input contiene N+1 elementi. 
Il primo elemento rappresenta il numero N di elementi presenti nell'array. 
Seguono gli N elementi dell'array.

Dati in output
Il file di output conterrà 100 righe di testo, una per ogni task contenuto nel file di input. 
Nello specifico, ogni riga del file di output dovrà contenere un unico valore, il quale rappresenta la somma che si vuole calcolare.

Note
Il valore di N è sempre compreso tra 10 e 1000.
I numeri contenuti all'interno dell'array sono sempre interi compresi tra 0 e 100.
Un determinato valore può essere presente più volte all'interno del vettore da ordinare.

Esempio
Il seguente esempio presenta un file di input, contenente 3 task, ed il corrispondente file di output.

input.txt:
7 5 12 20 17 16 19 16
8 5 11 12 14 6 14 9 10
8 9 12 14 8 11 4 19 19

output.txt
7
12
11
*/

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

        output << cnt_selection(v, n) << "\n";
        //stampa_array(v, n);

        delete []v;
    }

    input.close();
    output.close();
    return 0;
}