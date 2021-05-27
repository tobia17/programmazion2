#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

int main(){
	
	ifstream input("input.txt");
	ofstream output("output.txt");

	string line, line2, temp;
	while(getline(input, line)){

		size_t pos;
		int i = 0, n = 0;

		line2 = line;
		while( (pos = line2.find(" ")) != string::npos ){
			temp = line2.substr(0, pos);
			line2.erase(0, pos + 1);
			n++;
		}
		n++;

		string numeri[n];
		while( (pos = line.find(" ")) != string::npos ){
			temp = line.substr(0, pos);
			numeri[i] = temp;
			i++;
			line.erase(0, pos + 1);
		}
		numeri[n-1] = line;

		output << n << " ";
		for(int j = 0; j < n; j++){
			unsigned long numero = bitset<8>(numeri[j]).to_ulong(); //to binary
			output << (short) numero << " ";
		}
		output << "\n";

	}

	input.close();
	output.close();
	return 0;
}
