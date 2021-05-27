#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    
    while(getline(input, line)){
        line.erase(0, line.length()/2);
        output << line << "\n";
    }

    input.close();
    output.close();
    return 0;
}