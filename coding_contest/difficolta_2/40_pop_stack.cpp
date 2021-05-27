/*
Una Pila (in inglese Stack) è una struttura dati di tipo LIFO (Last In First Out). 
L'operazione di inserimento in una Pila è detta "push", mentre l'operazione di cancellazione dalla struttura è detta "pop".

Specifiche
	Si implementi una classe Pila, attraverso l'utilizzo dei template, contenente elementi di tipo generico H. 
	La classe dovrà implementare la procedura push, la procedura pop, e la procedura di stampa degli elementi in essa contenuti. 
	La stampa dovrà essere effettuata procedendo dalla testa della Pila fino all'elemento che si trova in base ad essa.

Dati in input
	L'input è suddiviso in 100 task, uno per ogni riga. Ogni riga del file di input è formata da 2+N elementi. 
	Il primo elemento è una stringa che identifica il tipo di dato (H) che dovrà essere contenuto all'interno della Pila. 
	Il secondo elemento è un valore intero N, il quale rappresenta l'insieme delle operazioni che dovranno essere eseguite nella struttura dati (push e pop). 
	Seguono N elementi che rappresentano, nell'ordine dato, le operazioni che dovranno essere eseguite all'interno della Pila. 
	Un'operazione di inserimento (push) di un elemento, "v", di tipo H è rappresentata dal carattere "i" concatenato con il valore di "v". 
	Un'operazione di cancellazione (pop) è invece rappresentata dalla stringa "pop".

Dati in output
	L'output dovrà essere formato da 100 righe, una per ogni task. 
	Ogni riga contiene una lista di valori, i quali rappresentano gli elementi contenuti nella Pila dopo l'esecuzione delle operazioni push e pop (nell'ordine dato in input), dall'elemento di testa fino all'elemento che si trova alla sua base.

Note
	N è un numero intero compreso tra 10 e 200.
	Il tipo H può essere uno desi seguenti tipi di dato: int, double, bool, char.

Esempio
	Il seguente esempio presenta un file di input, contenente 3 task, ed il corrispondente file di output.

	input.txt:
	bool 10 i1 i0 pop pop i1 i0 i0 i1 i1 i0
	char 10 ij ir pop it iq ir im ik it it
	int 10 i13 i17 i6 pop i15 i2 i9 pop pop i5

	output.txt
	0 1 1 0 0 1
	t t k m r q t j
	5 15 17 13
*/

#include <iostream>
#include <fstream>

using namespace std;

template <typename H>
class Pila {
	private:
		int size;
		H *pila;
		int pos;

	public:
		Pila(int _size){
			this->size = _size;
			this->pila = new H[this->size];
			this->pos = this->size-1;
		}

		H pop(){
			if(pos < this->size){
				pos++;
				return this->pila[pos];
			}
			
			return (H) 0;
		}

		void push(H element){
			if(this->pos >= 0){
				this->pila[pos] = element;
				pos--;
			}
		}

		string toString(){
			string str;

			for(int i = this->pos+1; i < this->size; i++){
				str = str + to_string(pila[i]) + " ";
			}

			return str;
		}

		void print(){
			for(int i = this->pos+1; i < this->size; i++){
				cout << i+1 << ")" << pila[i] << endl;
			}
		}
};

//questa è la pila adattata all'esercizio
//con questa evito il problema di conversione string to int/bool/char/double
class PilaP {
	private:
		int size;
		string *pila;
		int pos;

	public:
		PilaP(int _size){
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

		void push(string element){
			if(this->pos >= 0){
				this->pila[pos] = element;
				pos--;
			}
		}

		string toString(){
			string str;

			for(int i = this->pos+1; i < this->size; i++){
				str = str + pila[i] + " ";
			}

			return str;
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
		string type = line.substr(0, line.find(' '));
		line.erase(0, line.find(' ') + 1);

		int size = stoi(line.substr(0, line.find(' ')));
		line.erase(0, line.find(' ') + 1);

		size_t pos;
		PilaP p(size);
		while( (pos = line.find(' ')) != string::npos){
			string temp = line.substr(0, pos);

			if(temp == "pop"){
				p.pop();
			}else{
				temp.erase(0, 1);
				p.push(temp);
			}

			line.erase(0, pos + 1);
		}

		if(line == "pop"){
			p.pop();
		}else{
			line.erase(0, 1);
			p.push(line);
		}

		output << p.toString() << "\n";
	}

	input.close();
	output.close();
	return 0;
}