#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    while(getline(input, line)){
        output << line << line << "\n";
    }

    input.close();
    output.close();
    return 0;
}