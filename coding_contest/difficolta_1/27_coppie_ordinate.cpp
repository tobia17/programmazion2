#include <iostream>
#include <fstream>

using namespace std;

int main(){

	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){

		int strpos = 0;
		for(int i = 0; i < line.length()-1; i++){
			if(line[i] == ' '){
				strpos = 0;
			}else{
				if(line[i] < line[i+1]){
					output << strpos << " ";
				}
				strpos++;
			}
		}
		output << "\n";
	}

	input.close();
	output.close();
	return 0;
}