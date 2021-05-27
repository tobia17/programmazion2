#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream input("input.txt");
    ofstream output("output.txt");

    string line, temp_line;
    
    while(getline(input, line)){

        size_t pos;
        string temp;
        temp_line = line;
        int i = 0;
        while( (pos = temp_line.find(' ') ) != string::npos){
            temp = temp_line.substr(0, pos);
            i++;
            temp_line.erase(0, pos + 1);
        }

        int array[i];
        int j = 0;
        while( (pos = line.find(' ') ) != string::npos){
            temp = line.substr(0, pos);
            array[j] = stoi(temp);
            line.erase(0, pos + 1);
            j++;
        }

        int min = array[0];
        for(int x = 1; x < i; x++){
            if(array[x] < min){
                min = array[x];
            }
        }
        output << min << "\n";
    }

    input.close();
    output.close();
    return 0;
}