#include <iostream>
#include <fstream>

using namespace std;

void print_matrix(int **matrix, int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void print_vector(int *matrix, int n){
	for(int i = 0; i < n; i++){
		cout << matrix[i] << " ";
	}
	cout << endl;
}

void sort(int *v, int n){
	for(int i = 0; i < n-1; i++){
		int min = i;
		for(int j = i+1; j<n; j++){
			if(v[j] < v[min]){
				min = j;
			}
		}
		int temp = v[min];
		v[min] = v[i];
		v[i] = temp;
	}
}


int main(){

	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){
		int n, m;

		n = stoi(line.substr(0, line.find(' ')));
		line.erase(0, line.find(' ') + 1);
		m = stoi(line.substr(0, line.find(' ')));
		line.erase(0, line.find(' ') + 1);

		int** matrix = new int*[n];
		for(int i = 0; i<n; i++){
			matrix[i] = new int[m];
		}
		int results[n+m-1];

		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				matrix[i][j] = stoi(line.substr(0, line.find(' ')));
				line.erase(0, line.find(' ') + 1);
 			}
		}

		//print_matrix(matrix, n, m);

		if(n == 1 || m == 1){
			if(n == 1){
				for(int i = 0; i < m; i++){
					results[i] = matrix[0][i];
				}
			}else if(m == 1){
				for(int i = 0; i < n; i++){
					results[i] = matrix[i][0];
				}
			}
		}else{

			int x, y, xt, yt;	//indici di partenza
			int pos = 0;
			int sum;

			//cout << "parte superiore" << endl;
			//parte superiore della matrice
			y = m-1, x = 0, xt = 0;
			while(y > 0){
				sum = 0;
				yt = y;
				for(int x = 0; x <= xt; x++){
					sum += matrix[x][yt];
					//cout << "(" << x << "," << yt << ")";
					yt++;
				}
				y--;
				results[pos] = sum;
				pos++;
				if(xt != n-1){
					xt++;
				}
			}

			//cout << "diagonale" << endl;
			//diagonale principale
			sum = 0;
			for(int i = 0; i < n; i++){
				sum += matrix[i][i];
			}
			results[pos] = sum;
			pos++;

			//cout << "parte inferiore" << endl;
			//parte inferiore della matrice
			x = 1, yt = n-2;
			while(x != n){
				sum = 0;
				xt = x;
				for(int y = 0; y <= yt; y++){
					sum += matrix[xt][y];
					xt++;
				}
				yt--;
				results[pos] = sum;
				pos++;
				x++;
			}
			

		}

		sort(results, n+m-1);
		//cout << "ordino" << endl << endl;

		//print_vector(results, n+m-1);
		for(int i = 0; i < n+m-1; i++){
			output << results[i] << " ";
		}
		output << "\n";
	}


	output.close();
	input.close();
	return 0;
}