#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");

    string myline;
    while(getline(input, myline)){

        size_t pos;
        int i = 0, j = 0;
        string nomi[3], temp;
        while( (pos = myline.find(' ')) != string::npos ){
            temp = myline.substr(0, pos);

            if(i%2 == 1){
                nomi[j] = temp;
                j++;
            }
            i++;

            myline.erase(0, pos + 1);
        }
        nomi[2] = myline;

        for(int i = 0; i < 3; i++){
            nomi[i][0] = nomi[i][0] - 32;

            if(i < 2){
                output << nomi[i] << " ";
            }else if(i == 2){
                output << nomi[i] << "\n";
            }

        }

    }

    input.close();
    output.close();
    return 0;
}