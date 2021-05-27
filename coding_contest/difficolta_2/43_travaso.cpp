/*
Una Coda (in inglese Queue) è una struttura dati di tipo FIFO (First In First Out). 
Una Pila (in inglese Stack) è invece una struttura dati di tipo LIFO (Last In First Out).
L'operazione di "travaso" da uno Stack in una coda cosiste nell'estrarre, uno dopo l'altro, tutti gli elementi dalla Stack e, contestualmente, nell'inserirli all'interno della Coda. 
La procedura di travaso termina solo quando lo Stack diventa vuoto.

Specifiche
    Si implementino due classi, Coda e Stack, attraverso l'utilizzo dei template, con elementi di tipo generico H. 
    La classe Coda dovrà implementare la procedura enqueue, la procedura dequeue, e la procedura di stampa degli elementi in essa contenuti (a partire dall'elemento di testa). 
    In modo simile, la classe Stack dovrà implementare la procedura push, la procedura pop, e la procedura di stampa degli elementi in essa contenuti (a partire dall'elemento top). 
    La classe Stack dovrà inoltre contenere una procedura, denominata "travasa", che prenda una Coda in input e permetta di travasare tutti gli elementi dello Stack.
    Si realizzi infine un programma che sia in grado di eseguire una sequenza di N operazioni di inserimento, cancellazione e travaso, su di una Coda ed uno Stack, inizialmente vuote, fornendo il giusto output.

Dati in input
    L'input è suddiviso in 100 task, uno per ogni riga. 
    Ogni riga del file di input è formata da 2+N elementi. 
    Il primo elemento è una stringa che identifica il tipo di dato (H) che dovrà essere contenuto all'interno della Coda e dello Stack. 
    Il secondo elemento è un valore intero N, il quale rappresenta l'insieme delle operazioni che dovranno essere eseguite nelle due strutture dati (enqueue, dequeue, push e pop). 
    Seguono N elementi che rappresentano, nell'ordine dato, le operazioni che dovranno essere eseguite all'interno delle strutture. 
    Un'operazione di enqueue (da effettuare nella Coda) di un elemento, "v", di tipo H è rappresentata dalla stringa "e:" concatenata con il valore di "v". 
    Un'operazione di push (da effettuare nello Stack) di un elemento, "v", di tipo H è rappresentata dalla stringa "p:" concatenata con il valore di "v". 
    Un'operazione di cancellazione (dequeue o pop) è invece rappresentata dalla stringa "dequeue" o dalla stringa "pop", a seconda che debba essere realizzata nell Coda o nello Stack.

Dati in output
    L'output dovrà essere formato da 100 righe, una per ogni task. 
    Ogni riga contiene una lista di valori, i quali rappresentano gli elementi contenuti nella Coda dopo l'esecuzione delle N operazioni di input (nell'ordine dato), 
    dall'elemento di testa fino all'elemento che si trova alla sua base.

Note
    N è un numero intero compreso tra 10 e 200.
    Il tipo H può essere uno desi seguenti tipi di dato: int, double, bool, char.

Esempio
    Il seguente esempio presenta un file di input, contenente 4 task, ed il corrispondente file di output.

input.txt:
bool 10 e:0 p:0 p:1 travasa p:1 e:1 pop e:1 dequeue e:0
char 10 e:g p:k e:j e:h travasa p:f p:o e:n pop p:e
char 10 p:c travasa p:n dequeue travasa p:p e:o dequeue e:p travasa
int 10 e:7 p:88 p:42 pop pop e:82 e:12 p:54 e:49 travasa

output.txt
1 0 1 1 0
g j h k n
o p p
7 82 12 49 54

Nel primo caso di esempio, dopo le prime tre operazioni, la configurazione della coda, Q, e dello stack, S, Ã¨ la seguente:
Q : [0]
S : [1 0]
Dopo l'operazione travasa, la configurazione Ã¨ la seguente:
Q : [0 1 0]
S : []
Dopo le successive operazioni sulle strutture dati si giunge alla seguente configurazione:
Q : [1 0 1 1 0]
S : []
*/

#include <iostream>
#include <fstream>

using namespace std;


class Coda {
	private:
		string *coda_pointer;
		int last_pos;		//last_pos contiene
		int size;

	public:
		Coda(int _size){
			this->size = _size;
			this->last_pos = 0;
			this->coda_pointer = new string[size];
		}

		void enqueue(string new_element){
			if(this->last_pos < this->size){

				for(int i = last_pos-1; i >= 0; i--){
					this->coda_pointer[i+1] = this->coda_pointer[i];
				}

				this->coda_pointer[0] = new_element;
				this->last_pos++;
			}
		}

		void dequeue(){
			if(this->last_pos > 0){
				this->last_pos--;
			}
		}

		void print(){
			for(int i = last_pos-1; i >=0; i--){
				cout << this->coda_pointer[i] << "\t";
			}
			cout << endl;
		}

		string toString(){
			string to_str = "";
			for(int i = last_pos-1; i >= 0; i--){
				to_str = to_str + this->coda_pointer[i] + " ";
			}
			return to_str;
		}
};


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

        void travaso(Coda& coda){
            while(!this->isEmpty()){
                coda.enqueue(this->pop());
            }
        }
};


int main(){

    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    while(getline(input, line)){
        size_t pos;
        pos = line.find(' ');

        string type = line.substr(0, pos);
        line.erase(0, pos+1);

        pos = line.find(' ');
        int n = stoi(line.substr(0, pos));
        line.erase(0, pos+1);

        Coda c(n);
        Pila p(n);

        while( (pos = line.find(' ')) != string::npos ){
            string op = line.substr(0, pos);

            if(op == "travasa"){
                p.travaso(c);
            }else if(op == "pop"){
                p.pop();
            }else if(op == "dequeue"){
                c.dequeue();
            }else{
                if(op[0] == 'e'){
                    //enqueue
                    c.enqueue(op.substr(op.find(':')+1, op.length()-1));
                }else if(op[0] == 'p'){
                    //push
                    p.push(op.substr(op.find(':')+1, op.length()-1));
                }
            }

            line.erase(0, pos+1);
        }

        string op = line;
        if(op == "travasa"){
            p.travaso(c);
        }else if(op == "pop"){
            p.pop();
        }else if(op == "dequeue"){
            c.dequeue();
        }else{
            if(op[0] == 'e'){
                //enqueue
                c.enqueue(op.substr(op.find(':')+1, op.length()-1));
            }else if(op[0] == 'p'){
                //push
                p.push(op.substr(op.find(':')+1, op.length()-1));
            }
        }

        output << c.toString() << "\n";

    }

    output.close();
    input.close();
    return 0;
}
