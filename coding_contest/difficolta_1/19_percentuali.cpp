#include <iostream>
#include <fstream>

using namespace std;

#define DIM 26

void init_array(int *v, int n, int value){
	for(int i = 0; i < n; i++){
		v[i] = value;
	}
}

void stampa(int *v, int n){
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	
	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){

		int n_lettere[DIM], tot = 0;
		init_array(n_lettere, DIM, 0);

		for(int i = 0; i < line.length(); i++){
			//cout << (int) line[i] - 97 << " ";
			if(line[i] != ' '){
				n_lettere[ (int) line[i] - 97 ]++;
				tot++;
			}
		}

		int t_dim = 0;
		for(int i = 0; i < DIM; i++){
			if(n_lettere[i] != 0){
				t_dim++;
			}
		}

		double percentage_array[t_dim];
		char letters[t_dim];

		int j = 0;
		for(int i = 0; i < DIM; i++){
			if(n_lettere[i] != 0){
				double p_temp = (((n_lettere[i] * 100.00) / tot) + 0.005);
				p_temp *= 100;
				double percentage = ((int) p_temp) / 100.00;

				percentage_array[j] = percentage;
				letters[j] = (char) (i + 97);

				//cout << (char) (i + 97) << ":" << percentage << " ";
				j++;
			}
		}
		//cout << endl;


		int min;
		double temp;
		char c_temp;
		for(int i = 0; i < t_dim-1; i++){
			min = i;
			for(int j = i+1; j < t_dim; j++){
				if(percentage_array[j] < percentage_array[min]){
					min = j;
				}
			}
			temp = percentage_array[min];
			c_temp = letters[min];

			percentage_array[min] = percentage_array[i];
			letters[min] = letters[i];

			percentage_array[i] = temp;
			letters[i] = c_temp;

		}

		for(int i = 0; i < t_dim-1; i++){
			min = i;
			for(int j = i+1; j < t_dim; j++){
				if(letters[j] < letters[min] && percentage_array[j] == percentage_array[min]){
					min = j;
					c_temp = letters[min];
					letters[min] = letters[i];
					letters[i] = c_temp;
					cout << "scambio" << endl;
				}				
			}
		}

		for(int i = 0; i < t_dim; i++){
			output << letters[i] << ":" << percentage_array[i] << " ";
		}
		output << "\n";

	}


	input.close();
	output.close();
	return 0;
}