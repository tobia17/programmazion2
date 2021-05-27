#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream input("input.txt");
    ofstream output("output.txt");

    string temp_line;
    while(getline(input, temp_line)){
        char a, b;
        string nomi[3], temp;
        size_t pos;

        int i = 0;
        while( (pos = temp_line.find(' ')) != string::npos ){
            temp = temp_line.substr(0, pos);

            if(i == 0){
                a = temp[0];
            }else if(i == 1){
                b = temp[0];
            }else if(i == 3){
                nomi[0] = temp;
            }else if(i == 5){
                nomi[1] = temp;
            }

            i++;
            temp_line.erase(0, pos + 1);
        }
        nomi[2] = temp_line;


        for(int i = 0; i < 3; i++){
            if( ( (nomi[i][0] == a)  || (nomi[i][ nomi[i].length()-1 ] == a) ) && ( (nomi[i][0] != b)  && (nomi[i][ nomi[i].length()-1 ] != b) ) ){
                output << nomi[i];
            }

            if(i == 2){
                output << "\n";
            }else{
                output << " ";
            }
        }

    }

    return 0;
}