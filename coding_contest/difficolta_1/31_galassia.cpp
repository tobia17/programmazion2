#include <iostream>
#include <fstream>

using namespace std;

bool maggiore(string n1, string n2){
	//se n1 > n2 allora true
	//se n1 <= n2 allora false
	bool result = false;

	if(n1.length() > n2.length()){
		//se n1 è più lungo allora sicuramente è più grande
		result = true;
	}else if(n1.length() == n2.length()){
		//n1 ed n2 hanno la stessa lunghezza
		int i = 0;
		while(i < n1.length() && n1[i] == n2[i]){
			i++;
		}

		if(n1[i] > n2[i]){
			result = true;
		}else{
			result = false;
		}

	}

	return result;
}

int main(){

	
	ifstream input("input.txt");
	ofstream output("output.txt");

	string line, temp;
	while(getline(input, line)){

		size_t pos = line.find(' ');
		temp = line.substr(0, pos);
		int n = stoi(temp);
		line.erase(0, pos + 1);

		string numeri[n];

		int i = 0;
		while( (pos = line.find(' ')) != string::npos){
			numeri[i] = line.substr(0, pos);
			i++;
			line.erase(0, pos + 1);
		}
		numeri[n-1] = line;

		string max = numeri[0];
		for(int j = 1; j < n; j++){
			if(maggiore(numeri[j], max)){
				max = numeri[j];
			}
		}

		output << max << endl;
	}
	
	input.close();
	output.close();
	return 0;
}