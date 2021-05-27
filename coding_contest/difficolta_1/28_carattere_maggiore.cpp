#include <iostream>
#include <fstream>

using namespace std;

void stampa(int *v, int n){
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int posmax(int *v, int n){
	int mxps = 0;
	for(int i = 0; i < n; i++){
		if(v[i] >= v[mxps]) mxps = i;
	}
	return mxps;
}

void initialize(int *v, int n){
	for(int i = 0; i < n; i++){
		v[i] = 0;
	}
}

int main(){

	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){

		int *frq = new int[26];
		initialize(frq, 26);
		for(int i = 0; i < line.length(); i++){
			if(line[i] != ' '){
				frq[((int) line[i]) - 97] += 1;
			}
		}
		//stampa(frq, 26);
		int temp = frq[posmax(frq, 26)];
		output << (char) (posmax(frq, 26)+97) << " " << temp << "\n";

		delete[] frq;
	}

	input.close();
	output.close();
	return 0;
}