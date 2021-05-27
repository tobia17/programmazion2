#include <iostream>
#include <fstream>

using namespace std;

int main(){

	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){

		size_t pos;
		int i = 0, n;
		string src;
		while( (pos = line.find(' ')) != string::npos ){
			string temp = line.substr(0, pos);

			if(i == 0){
				n = stoi(temp);
			}else if(i == 1){
				src = temp;
				line.erase(0, pos + 1);
				break;
			}

			i++;
			line.erase(0, pos + 1);
		}

		i = 0;
		while( (pos = line.find(' ')) != string::npos){
			 string temp = line.substr(0, pos);

			 if(temp.find(src) != string::npos){
			 	output << temp << " ";
			 }

			 i++;
			 line.erase(0, pos + 1);
		}

		if(line.find(src) != string::npos){
		 	output << line << " ";
		 }

		 output << "\n";

	}

	return 0;
}