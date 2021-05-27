#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

int main(){
	
	ifstream input("input.txt");
	ofstream output("output.txt");

	string line, temp;
	while(getline(input, line)){

		size_t pos;
		int i = 0;
		int n;
		while( (pos = line.find(" ")) != string::npos ){
			temp = line.substr(0, pos);
			n = stoi(temp);
			line.erase(0, pos + 1);
			break;
		}

		int numeri[n];
		while( (pos = line.find(" ")) != string::npos ){
			temp = line.substr(0, pos);
			numeri[i] = stoi(temp);
			i++;
			line.erase(0, pos + 1);
		}
		numeri[n-1] = stoi(line);

		for(int j = 0; j < n; j++){
			string binary = bitset<8>(numeri[j]).to_string(); //to binary
			output << binary << " ";
		}
		output << "\n";

	}

	input.close();
	output.close();
	return 0;
}
