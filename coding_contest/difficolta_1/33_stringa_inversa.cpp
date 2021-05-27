#include <iostream>
#include <fstream>

using namespace std;

string stringa_inversa(string s){
	string inversa;
	for(int i = s.length()-1; i >= 0; i--){
		inversa += s[i];
	}

	return inversa;
}

int main(){
	
	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){

		line.erase(0, line.find(' ')+1);
		size_t pos;
		while((pos = line.find(' ')) != string::npos){
			output << stringa_inversa(line.substr(0, pos)) << " ";
			line.erase(0, pos + 1);
		}
		output << stringa_inversa(line) << "\n";

	}

	input.close();
	output.close();
	return 0;
}