/*
Una Pila (in inglese Stack) è una struttura dati di tipo LIFO (Last In First Out). 
L'operazione di inserimento in una Pila è detta "push", mentre l'operazione di cancellazione dalla struttura è detta "pop".

Specifiche
Si implementi una classe Pila, attraverso l'utilizzo dei template, contenente elementi di tipo generico H. 
La classe dovrà implementare la procedura di inserimento di un nuovo elemento e la procedura di stampa degli elementi in essa contenuti. 
La stampa dovrà essere effettuata procedendo dalla testa della Pila fino all'elemento che si trova in base ad essa.

Dati in input
L'input è suddiviso in 100 task, uno per ogni riga. Ogni riga del file di input è formata da 2+N elementi. 
Il primo elemento è una stringa che identifica il tipo di dato (H) che dovrà essere contenuto all'interno della Pila. 
Il secondo elemento è un valore intero N, il quale rappresenta l'insieme degli elementi che dovranno essere inseriti nella struttura dati. 
Seguono N numeri interi che rappresentano, nell'ordine dato, gli elementi di tipo H che dovranno essere inseriti all'interno della Pila.

Dati in output
L'output dovrà essere formato da 100 righe, una per ogni task. 
Ogni riga contiene una lista di N valori, i quali rappresentano gli elementi contenuti nella Pila, dall'elemento di testa fino all'elemento che si trova alla sua base.

Note
N è un numero intero compreso tra 10 e 200.
Il tipo H può essere uno desi seguenti tipi di dato: int, double, bool, char.

Esempio
Il seguente esempio presenta un file di input, contenente 3 task, ed il corrispondente file di output.

input.txt:
int 5 4 7 8 12 32
char 7 g h t a e d j
double 4 2.78 3.73 4.12 31.92

output.txt
32 12 8 7 4
j d e a t h g
31.92 4.12 3.73 2.78

*/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


class Pila {
	private:
		int size;
		string *pila;
		int pos;

	public:
		Pila(int _size){
			this->size = _size;
			pila = new string[size];
			this->pos = this->size-1;
		}

		string pop(){
			if(pos < this->size){
				pos++;
				return this->pila[pos];
			}
			
			return "";
		}

        bool isEmpty(){
            if(pos == size-1){
                return true;
            }

            return false;
        }

		void push(string element){
			if(this->pos >= 0){
				this->pila[pos] = element;
				pos--;
			}
		}

		string toString(){
			stringstream s;

			for(int i = this->pos+1; i < this->size; i++){
				s << pila[i] << " ";
			}

			return s.str();
		}

		void print(){
			for(int i = this->pos+1; i < this->size; i++){
				cout << i+1 << ")" << pila[i] << endl;
			}
		}
};


int main(){

    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    while(getline(input, line)){
        size_t pos = line.find(' ');
        string type = line.substr(0, pos);
        line.erase(0, pos+1);

        pos = line.find(' ');
        int n = stoi(line.substr(0, pos));
        line.erase(0, pos+1);

        Pila p(n);

        while((pos = line.find(' ')) != string::npos){
            p.push(line.substr(0, pos));
            line.erase(0, pos+1);
        }
        p.push(line);

        output << p.toString() << "\n";
    }

    output.close();
    input.close();
    return 0;
}