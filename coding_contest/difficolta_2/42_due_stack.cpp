/*
Una Coda (in inglese Queue) è una struttura dati di tipo FIFO (First In First Out). Una Pila (in inglese Stack) è invece una struttura dati di tipo LIFO (Last In First Out).
Si implementi una classe Coda per composizione, utilizzando esclusivamente due oggetti Stack. All'interno della classe Coda non dovranno quindi essere definiti altri oggetti al di fuori delle due istanze della classe Stack.

Specifiche
Si implementi lo Stack e la Coda attraverso l'utilizzo dei template, con elementi di tipo generico H. La classe Coda dovrà implementare la procedura enqueue, la procedura dequeue, e la procedura di stampa degli elementi in essa contenuti. La stampa dovrà essere effettuata procedendo dalla testa della Coda fino all'elemento che si trova nella sua ultima posizione.

Dati in input
L'input è suddiviso in 100 task, uno per ogni riga. Ogni riga del file di input è formata da 2+N elementi. Il primo elemento è una stringa che identifica il tipo di dato (H) che dovrà essere contenuto all'interno della Coda. Il secondo elemento è un valore intero N, il quale rappresenta l'insieme delle operazioni che dovranno essere eseguite nella struttura dati (enqueue e dequeue). Seguono N elementi che rappresentano, nell'ordine dato, le operazioni che dovranno essere eseguite all'interno della Coda. Un'operazione di inserimento (enqueue) di un elemento, "v", di tipo H è rappresentata dal carattere "i" concatenato con il valore di "v". Un'operazione di cancellazione (dequeue) è invece rappresentata dalla stringa "dequeue".

Dati in output
L'output dovrà essere formato da 100 righe, una per ogni task. Ogni riga contiene una lista di valori, i quali rappresentano gli elementi contenuti nella Coda dopo l'esecuzione delle operazioni enqueue e dequeue (nell'ordine dato in input), dall'elemento di testa fino all'elemento che si trova alla sua base.

Note
N è un numero intero compreso tra 10 e 200.
Il tipo H può essere uno desi seguenti tipi di dato: int, double, bool, char.

Esempio
Il seguente esempio presenta un file di input, contenente 3 task, ed il corrispondente file di output.

input.txt:
int 11 i3 i20 dequeue dequeue i19 dequeue i16 i14 i18 i8 i11
double 11 i0.08 i1.61 i1.35 dequeue i1.76 i0.39 i1.31 dequeue i0.72 dequeue i1.84
bool 11 i1 i1 i0 i1 i1 i0 dequeue i1 dequeue i0 i1

output.txt
16 14 18 8 11
1.76 0.39 1.31 0.72 1.84
0 1 1 0 1 0 1
*/

#include <iostream>
#include <fstream>

using namespace std;

class Pila {
	public:
        Pila(){
            size = 0;
        }

		Pila(int _size){
			this->size = _size;
			array = new string[this->size];
			lastPos = this->size - 1;
		}

        void setSize(int _size){
            this->size = _size;
			array = new string[this->size];
			lastPos = this->size - 1;
        }

		bool push(string element){
			bool inserito = false;
			if(lastPos >= 0){
				array[lastPos] = element;
				inserito = true;
			}
			
			if(lastPos > 0){
				lastPos--;
				inserito = true;
			}

			return inserito;
		}

		bool pop(){
			if(lastPos < size-1){
                lastPop = array[lastPos+1];
				lastPos++;
				return true;
			}

			return false;
		}

        string getLastPop(){
            return lastPop;
        }

		void print(){
			for(int i = lastPos+1; i < size; i++){
				cout << array[i] << " ";
			}
			cout << endl;
		}

        bool isEmpty(){
            if(lastPos == size-1){
                return true;
            }

            return false;
        }

	private:
		int size;
		string *array;
		int lastPos;
        string lastPop;
};

class Coda {
	public:
		Coda(int _size){
            this->size = _size;
            slave.setSize(this->size);
            master.setSize(this->size);
        }

        bool enqueue(string element){
            return slave.push(element);
        }

        bool dequeue(){

            if(master.isEmpty()){
                while(slave.pop()){
                    master.push(slave.getLastPop());
                }
            }

            if(master.isEmpty()){
                return false;
            }else{
                master.pop();
                setLastDequeue(master.getLastPop());

                while(!master.isEmpty()){
                    master.pop();
                    slave.push(master.getLastPop());
                }

                return true;
            }
        }

        void setLastDequeue(string temp){
            lastDequeue = temp;
        }

        string getLastDequeue(){
            return lastDequeue;
        }

        string toString(){
            string str;

            if(master.isEmpty()){
                while(slave.pop()){
                    master.push(slave.getLastPop());
                }
            }

            while(master.pop()){
                str = str + master.getLastPop() + " ";
            }

            return str;
        }

	private:
		int size;
        Pila slave;
        Pila master;
        string lastDequeue;
};

int main(){

    /*
	Coda c(10);

    c.enqueue("ciao");
    c.enqueue("come");
    c.enqueue("stai");
    c.dequeue();
    c.enqueue("bene");

    cout << c.toString() << "\n";
    */

    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    while(getline(input, line)){
        string type = line.substr(0, line.find(' '));
        line.erase(0, line.find(' ') + 1);

        int n = stoi(line.substr(0, line.find(' ')));
        line.erase(0, line.find(' ') + 1);

        Coda c(n);

        size_t pos;
        while( (pos = line.find(' ')) != string::npos){
            string temp = line.substr(0, pos);
            if(temp == "dequeue"){
                c.dequeue();
            }else{
                c.enqueue(temp.substr(1, temp.length()-1));
            }
            line.erase(0, pos + 1);
        }
        if(line == "dequeue"){
            c.dequeue();
        }else{
            c.enqueue(line.substr(1, line.length()-1));
        }

        output << c.toString() << "\n";
        
    }


	return 0;
}