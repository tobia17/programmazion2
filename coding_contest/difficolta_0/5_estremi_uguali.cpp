#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    while(getline(input, line)){

        string temp, word[3];
        size_t pos;
        int i = 0;
        while( (pos = line.find(' ')) != string::npos ){
            temp = line.substr(0, pos);

            if(i == 1){
                word[0] = temp;
            }else if(i == 3){
                word[1] = temp;
            }

            i++;
            line.erase(0, pos + 1);
        }
        word[2] = line;

        int cnt = 0;
        for(int j = 0; j < 3; j++){
            if(word[j][0] == word[j][ word[j].length()-1 ]){
                cnt++;
            }
        }
        output << to_string(cnt) << "\n";

    }

    output.close();
    input.close();
    return 0;
}