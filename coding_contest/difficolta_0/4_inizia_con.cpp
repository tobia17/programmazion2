#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    while(getline(input, line)){

        size_t pos;
        string temp, word[3];
        char f;
        int j = 0;
        while( (pos = line.find(' ')) != string::npos){
            temp = line.substr(0, pos);

            if(j == 0){
                f = temp[0];
            }else if(j == 2){
                word[0] = temp;
            }else if(j == 4){
                word[1] = temp;
            }

            j++;
            line.erase(0, pos + 1);
        }
        word[2] = line;
        cout << line << endl;

        for(int i = 0; i < 3; i++){
            if(word[i][0] == f){
                output << word[i];
                if(i < 2){
                    output << " ";
                }
            }
        }
        output << "\n";

    }

    input.close();
    output.close();
    return 0;
}