/*
Una Coda (in inglese Queue) è una struttura dati di tipo FIFO (First In First Out). 
L'operazione di inserimento in una Pila è detta "enqueue", mentre l'operazione di cancellazione dalla struttura è detta "dequeue".

Specifiche
	Si implementi una classe Coda, attraverso l'utilizzo dei template, contenente elementi di tipo generico H. 
	La classe dovrà implementare la procedura di inserimento di un nuovo elemento e la procedura di stampa degli elementi in essa contenuti. 
	La stampa dovrà essere effettuata procedendo dalla testa della Coda fino all'elemento che si trova nella sua ultima posizione.

Dati in input
	L'input è suddiviso in 100 task, uno per ogni riga. Ogni riga del file di input è formata da 2+N elementi. 
	Il primo elemento è una stringa che identifica il tipo di dato (H) che dovrà essere contenuto all'interno della Coda. 
	Il secondo elemento è un valore intero N, il quale rappresenta l'insieme degli elementi che dovranno essere inseriti nella struttura dati. 
	Seguono N valori che rappresentano, nell'ordine dato, gli elementi di tipo H che dovranno essere inseriti all'interno della Coda.

Dati in output
	L'output dovrà essere formato da 100 righe, una per ogni task. 
	Ogni riga contiene una lista di N valori, i quali rappresentano gli elementi contenuti nella Coda, dall'elemento di testa fino al suo ultimo elemento.

Note
	N è un numero intero compreso tra 10 e 200.
	Il tipo H può essere uno desi seguenti tipi di dato: int, double, bool, char.

Esempio
	Il seguente esempio presenta un file di input, contenente 3 task, ed il corrispondente file di output.

input.txt:
	double 10 1.24 1.96 1.3 1.03 1.22 0.66 1.49 0.24 0.01 0.53
	int 10 9 9 14 19 2 16 14 6 15 4
	char 10 f j p o j b r p f e

output.txt
	1.24 1.96 1.3 1.03 1.22 0.66 1.49 0.24 0.01 0.53
	9 9 14 19 2 16 14 6 15 4
	f j p o j b r p f e

*/

#include <iostream>
#include <fstream>

using namespace std;

bool stob(string s){
	if(s == "1"){
		return true;
	}else if(s == "0"){
		return false;
	}

	return false;
}

template <typename H>
class Coda {
	private:
		H *coda_pointer;
		int last_pos;		//last_pos contiene
		int size;

	public:
		Coda(int _size){
			this->size = _size;
			this->last_pos = 0;
			this->coda_pointer = new H[size];
		}

		void enqueue(H new_element){
			if(this->last_pos < this->size){
				this->coda_pointer[this->last_pos] = new_element;
				this->last_pos++;
			}
		}

		void print(){
			for(int i = 0; i < this->last_pos; i++){
				cout << this->coda_pointer[i] << "\t";
			}
			cout << endl;
		}

		
		string toString(){
			string to_str;
			for(int i = 0; i < this->last_pos; i++){
				to_str = to_str + to_string(this->coda_pointer[i]) + " ";
			}
			return to_str;
		}
		

};

int main(){

	/*
	Coda<int> c(10);
	c.enqueue(1);
	c.enqueue(3);
	cout << c.toString() << endl;
	c.print();
	*/

	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){
		string type = line.substr(0, line.find(' '));
		line.erase(0, line.find(' ') + 1);

		int size = stoi(line.substr(0, line.find(' ')));
		line.erase(0, line.find(' ') + 1);

		output << line << "\n";

		/*

		size_t pos;
		if(type == "int"){
			Coda<int> c(size);

			while( (pos = line.find(' ')) != string::npos){
				c.enqueue(stoi(line.substr(0, pos)));
				line.erase(0, pos + 1);
			}
			c.enqueue(stoi(line));
			cout << c.toString() << "\n";

		}else if(type == "double"){
			Coda<double> c(size);

			while( (pos = line.find(' ')) != string::npos){
				c.enqueue(stod(line.substr(0, pos)));
				line.erase(0, pos + 1);
			}
			c.enqueue(stod(line));
			cout << c.toString() << "\n";

		}else if(type == "char"){
			Coda<char> c(size);

			while( (pos = line.find(' ')) != string::npos){
				c.enqueue(line.substr(0, pos)[0]);
				line.erase(0, pos + 1);
			}
			c.enqueue(line[0]);
			cout << c.toString() << "\n";

		}else if(type == "bool"){
			Coda<bool> c(size);

			while( (pos = line.find(' ')) != string::npos){
				c.enqueue(stob(line.substr(0, pos)));
				line.erase(0, pos + 1);
			}
			c.enqueue(stob(line));
			cout << c.toString() << "\n";

		}
		*/

	}

	input.close();
	output.close();
	return 0;
}