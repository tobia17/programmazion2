#include <iostream>
#include <fstream>

using namespace std;

int main(){

	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){

		int pos = 0;
		char lettera = line[0];
		line.erase(0, 1);
		bool found = false;

		for(int i = 0; i < line.length(); i++){

			if(line[i] == ' '){
				pos = 0;
			}else{
				if(line[i] == lettera){
					output << pos << " ";
					found = true;
				}
				pos++;
			}

		}

		if(found == false){
			output << "none";
		}

		output << "\n";
	}

	input.close();
	output.close();
	return 0;
}