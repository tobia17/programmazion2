#include <iostream>
#include <fstream>

using namespace std;

int main(){

	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){

		size_t pos = line.find(' ');
		string temp = line.substr(0, pos);
		int n_op = stoi(temp);
		line.erase(0, pos + 1);

		string *operazioni = new string[n_op];
		int i = 0;
		while( (pos = line.find(' ')) != string::npos){
			operazioni[i] = line.substr(0, pos);
			i++;
			line.erase(0, pos + 1);
		}
		operazioni[n_op-1] = line;

		for(int j = 0; j < n_op; j++){
			int n1, n2;
			if((pos = operazioni[j].find('+')) != string::npos){
				n1 = stoi( operazioni[j].substr(0, pos) );
				n2 = stoi( operazioni[j].substr(pos+1, operazioni[j].length()-1) );
				output << n1+n2 << " ";
			}else if((pos = operazioni[j].find('-')) != string::npos){
				n1 = stoi( operazioni[j].substr(0, pos) );
				n2 = stoi( operazioni[j].substr(pos+1, operazioni[j].length()-1) );
				output << n1-n2 << " ";
			}else if((pos = operazioni[j].find('*')) != string::npos){
				n1 = stoi( operazioni[j].substr(0, pos) );
				n2 = stoi( operazioni[j].substr(pos+1, operazioni[j].length()-1) );
				output << n1*n2 << " ";
			}
		}

		output << "\n";
		delete[] operazioni;
	}

	input.close();
	output.close();
	return 0;
}