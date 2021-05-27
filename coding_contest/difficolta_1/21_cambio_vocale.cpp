#include <iostream>
#include <fstream>

using namespace std;

string sostituisci(char *c, string s){

	for(int i = 0; i < s.length(); i++){
		switch(s[i]){
			case 'a':
				s[i] = c[0];
				break;
			case 'e':
				s[i] = c[1];
				break;
			case 'i':
				s[i] = c[2];
				break;
			case 'o':
				s[i] = c[3];
				break;
			case 'u':
				s[i] = c[4];
				break;
		}
	}

	return s;
}

int main(){

	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	char c[5];
	while(getline(input, line)){

		int i = 0;
		size_t pos;
		while((pos = line.find(' ')) != string::npos){
			string temp = line.substr(0, pos);
			switch(i){
				case 0:
				case 1:
				case 2:
				case 3:
				case 4:
					c[i] = temp[2];
					break;
			}
			i++;

			line.erase(0, pos + 1);

			if(i == 5){
				break;
			}
		}
		output << sostituisci(c, line) << "\n";

	}

	return 0;
}