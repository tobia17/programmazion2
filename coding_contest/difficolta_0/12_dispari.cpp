#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    while(getline(input, line)){

        size_t pos;
        int i = 0, n;
        while( (pos = line.find(" ")) != string::npos){
            string temp = line.substr(0, pos);
            n = stoi(temp);
            line.erase(0, pos + 1);
            break;
        }

        int numeri[n];
        while( (pos = line.find(" ")) != string::npos){
            string temp = line.substr(0, pos);
            numeri[i] = stoi(temp);
            i++;
            line.erase(0, pos + 1);
        }
        numeri[n-1] = stoi(line);

        for(int j = 0; j < n; j++){
            if(numeri[j] % 2 == 1){
                //il numero è dispari
                output << numeri[j] << " ";
            }
        }
        output << "\n";

    }

    input.close();
    output.close();
    return 0;
}