#include <iostream>
#include <fstream>

using namespace std;

int main(){

	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){

		line.erase(0, (line.find(' '))+1);

		for(int i = 0; i < line.length(); i++){
			if(line[i] != 'a' && line[i] != 'e' && line[i] != 'i' && line[i] != 'o' && line[i] != 'u'){
				output << line[i];
			}
		}
	output << "\n";

	}

	output.close();
	input.close();
	return 0;
}