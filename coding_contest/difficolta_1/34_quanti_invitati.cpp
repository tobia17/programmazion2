#include <iostream>
#include <fstream>

using namespace std;

int n_nomi(string s){
	size_t pos = s.find(' ');
	if(pos == string::npos){
		return 1;
	}
	return n_nomi(s.substr(pos+1, s.length()-1)) + 1;
}

int main(){
	
	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){
		output << n_nomi(line) << "\n";
	}

	output.close();
	input.close();
	return 0;
}