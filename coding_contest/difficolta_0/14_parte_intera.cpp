#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream input("input.txt");
    ofstream output("output.txt");

    string line, temp;
    while(getline(input, line)){
        
        int i = 0, n;
        size_t pos;
        while( (pos = line.find(' ')) != string::npos){
            temp = line.substr(0, pos);
            n = stoi(temp);
            line.erase(0, pos + 1);
            break;
        }

        double numeri[n];
        while( (pos = line.find(' ')) != string::npos){
            temp = line.substr(0, pos);
            numeri[i] = stod(temp);
            i++;
            line.erase(0, pos + 1);
        }
        numeri[n-1] = stod(line);

        for(int j = 0; j < n; j++){
            output << (int) numeri[j] << " ";
        }
        output << "\n";

    }

    input.close();
    output.close();
    return 0;
}