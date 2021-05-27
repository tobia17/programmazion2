#include <iostream>
#include <fstream>

using namespace std;

int main(){

	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){

		int n, f, i = 1;
		size_t pos;
		bool found = false;
		while( (pos = line.find(' ')) != string::npos){

			if(i == 1){
				n = stoi(line.substr(0, pos));
			}else if(i == 2){
				f = stoi(line.substr(0, pos));
			}else if(i > 2){
				if(found == false && stoi(line.substr(0, pos)) == f){
					output << (i-2) << "\n";
					found = true;
					break;
				}
			}

			i++;
			line.erase(0, pos+1);
		}

		if(found == false && stoi(line) == f){
			output << (i-2) << "\n";
			found = true;
		}

		if(found == false){
			output << "0" << "\n";
		}

	}

	output.close();
	input.close();
	return 0;
}