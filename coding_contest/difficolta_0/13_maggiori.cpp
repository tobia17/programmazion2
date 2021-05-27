#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    while(getline(input, line)){

        size_t pos;
        int i = 0, n, x;
        while( (pos = line.find(" ")) != string::npos){
            string temp = line.substr(0, pos);
            line.erase(0, pos + 1);
            if(i == 0){
                n = stoi(temp);
                i++;
            }else if(i == 1){
                x = stoi(temp);
                break;
            }
        }

        int numeri[n];
        i = 0;
        while( (pos = line.find(" ")) != string::npos){
            string temp = line.substr(0, pos);
            numeri[i] = stoi(temp);
            i++;
            line.erase(0, pos + 1);
        }
        numeri[n-1] = stoi(line);

        i = 0;
        for(int j = 0; j < n; j++){
            if(numeri[j] > x){
                i++;
            }
        }

        output << i << " ";
        
        for(int j = 0; j < n; j++){
            if(numeri[j] > x){
                output << numeri[j] << " ";
            }
        }

        output << "\n";

    }

    input.close();
    output.close();
    return 0;
}