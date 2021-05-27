#include <iostream>
#include <fstream>

using namespace std;

long fibonacci(int x){

	long n1 = 1, n2 = 1, temp;
	for(int i = 2; i < x; i++){
		temp = n2;
		n2 = n1 + n2;
		n1 = temp;
	}

	return n2;
}

int main(){
	
	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){
		long n = fibonacci(stol(line));
		output << n << "\n";
		cout << line << "=" << n << endl;
	}


	return 0;
}