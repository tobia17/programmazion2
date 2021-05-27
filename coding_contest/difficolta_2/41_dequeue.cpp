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
			for(int i = last_pos-1; i >=0; i--){
				to_str = to_str + this->coda_pointer[i] + " ";
			}
			return to_str;
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
		Coda p(size);
		while( (pos = line.find(' ')) != string::npos){
			string temp = line.substr(0, pos);
			//cout << temp << " ";

			if(temp == "dequeue"){
				p.dequeue();
			}else{
				temp.erase(0, 1);
				p.enqueue(temp);
			}

			line.erase(0, pos + 1);
		}

		if(line == "dequeue"){
			p.dequeue();
		}else{
			line.erase(0, 1);
			p.enqueue(line);
		}

		output <<  p.toString() << "\n";
		//p.print();
	}

	input.close();
	output.close();
	return 0;
}