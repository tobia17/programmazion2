#include <iostream>
#include <fstream>

using namespace std;

int doppioni(int *numeri, int n){
	int doppioni = 0, copia[n];

	for(int i = 0; i < n; i++){
		copia[i] = numeri[i];
	}

	for(int i = 0; i < n; i++){

		if(copia[i] != 0){
			for(int j = i+1; j < n; j++){
				if(copia[j] == copia[i]){
					copia[j] = 0;
					doppioni++;
				}
			}
		}

	}

	return doppioni;
}

int main(){

	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){

		size_t pos = line.find(' ');
		int n = stoi(line.substr(0, pos));
		line.erase(0, pos + 1);

		int numeri[n], i = 0;
		while( (pos = line.find(' ')) != string::npos){
			numeri[i] = stoi(line.substr(0, pos));
			line.erase(0, pos + 1);
			i++;
		}
		numeri[n-1] = stoi(line.substr(0, pos));

		output << doppioni(numeri, n) << "\n";
		//cout << doppioni(numeri, n) << "\n";

	}

	return 0;
}