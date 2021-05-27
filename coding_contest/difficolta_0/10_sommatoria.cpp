#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    
    while(getline(input, line)){
        string temp;
        int i = 0;
        double sum = 0;
        size_t pos;
        while( (pos = line.find(' ') ) != string::npos){
            temp = line.substr(0, pos);

            if(i > 0){
                sum += stod(temp);
            }
            i++;
            
            line.erase(0, pos + 1);
        }
        sum += stod(line);

        output << sum << "\n";
    }

    input.close();
    output.close();
    return 0;
}