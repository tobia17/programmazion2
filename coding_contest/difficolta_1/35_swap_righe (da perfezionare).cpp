#include <iostream>
#include <fstream>

using namespace std;

void init_v(int *v, int n){
	for(int i = 0; i < n; i++){
		v[i] = 0;
	}
}

int *temp_foo(string s, int &n){
	string temp;
	size_t pos;

	int dim = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == ' '){
			dim++;
		}
	}
	dim++;

	int *vettore = new int[dim];
	int i = 0;
	while( (pos = s.find(' ')) != string::npos){
		vettore[i] = stoi(s.substr(0, pos));
		s.erase(0, pos + 1);
		i++;
	}
	vettore[dim-1] = stoi(s);

	int r = vettore[0];
	n = r;
	int c = vettore[1];

	int *somme = new int[r];
	init_v(somme, r);

	int x = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			somme[i] += vettore[x+2];
			x++;
		}
	}

	return somme;
}

void stampa_v(int *v, int n){
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int selectionSort(int a[], int n) {
	int i, j, min, temp, cnt = 0;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++){
			if (a[j] < a[min]){
				min = j;
				cnt++;
			}
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	return cnt;
}

int main(){
	
	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){
		int n;
		int *somme = temp_foo(line, n);
		//stampa_v(somme, n);
		output << selectionSort(somme, n) << "\n";
		//stampa_v(somme, n);
	}

	output.close();
	input.close();
	return 0;
}