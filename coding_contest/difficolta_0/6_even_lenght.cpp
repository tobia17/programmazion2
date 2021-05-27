#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    while(getline(input, line)){
        if(line.length() % 2 == 1){
            line.erase(line.end()-1, line.end());
        }
        output << line << "\n";
    }

    return 0;
}