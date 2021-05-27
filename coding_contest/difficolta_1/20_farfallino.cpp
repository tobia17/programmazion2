#include <iostream>
#include <fstream>

using namespace std;

string farfallino(string s);

int main(){
	
	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){

		size_t pos;
		while((pos = line.find(' ')) != string::npos){
			string temp = line.substr(0, pos);
			output << farfallino(temp) << " ";
			line.erase(0, pos + 1);
		}
		output << farfallino(line) << "\n";

	}

	return 0;
}

string farfallino(string s){
	string ff = "";

	for(int i = 0; i < s.length(); i++){

		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
			ff += (char) s[i];
			ff += (char) 'f';
			ff += (char) s[i];
		}else{
			ff += s[i];
		}
	}

	return ff;
}