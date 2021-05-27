#include <iostream>
#include <fstream>

using namespace std;

void initialization(int *v, int n){
	for(int i = 0; i < n; i++){
		v[i] = 0;
	}
}

void initialization_chr(char *v, int n){
	for(int i = 0; i < n; i++){
		v[i] = (char)(i+97);
	}
}

void swap(int *v, int i, int j){
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void swap(char *v, int i, int j){
	char temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void sort(int *v, char *vc, int n){
	for(int i = 1; i < n; i++){
		int j = i;
		while(j > 0 && v[j] >= v[j-1]){
			swap(v, j, j-1);
			swap(vc, j, j-1);
			j--;
		}
	}
}


int main(){

	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){

		int *caratteri = new int[26];
		char *prl = new char[26];
		initialization(caratteri, 26);
		initialization_chr(prl, 26);

		for(int i = 0; i < line.length(); i++){
			if(line[i] != ' '){
				caratteri[((int)line[i])-97]++;
			}
		}

		sort(caratteri, prl, 26);

		for(int i = 0; i < 26; i++){
			if(caratteri[i] != 0){
				output << prl[i] << ":" << caratteri[i] << " ";
			}
		}
		output << endl;

		delete[] caratteri;
		delete[] prl;
	}

	input.close();
	output.close();
	return 0;
}