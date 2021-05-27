#include <iostream>
#include <fstream>

using namespace std;

/*
void arraySort(int *v, int n){
	for(int i = 0; i < n-1; i++){
		int min = i;
		for(int j = i+1; j < n; j++){
			if(v[j] < v[min]){
				min = j;
			}
		}
		int temp = v[min];
		v[min] = v[i];
		v[i] = temp;
	}
}
*/

int binarySearch(int *v, int n, int x){
	//ci serve quante volte l'array viene diviso
	//come richiesto dalla consegna
	if(n == 0) return 0;
	if(n == 1) return 0;					//return (v[0] == x);
	int m = n/2;
	if(v[m] > x){
		return binarySearch(v, m, x) + 1;	//aggiungiamo uno per capire quante volte l'array viene diviso
	}else{
		return binarySearch(v+m, n-m, x) + 1;
	}
}

int main(){

	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){
		int n, x;
		n = stoi(line.substr(0, line.find(' ')));
		line.erase(0, line.find(' ') + 1);

		int array[n];
		int i = 0;
		size_t pos;
		while( (pos = line.find(' ')) != string::npos){
			array[i] = stoi(line.substr(0, pos));
			line.erase(0, pos + 1);
			i++;
		}
		x = stoi(line);

		int result = binarySearch(array, n, x);
		output << result << "\n";
	}


	output.close();
	input.close();
	return 0;
}