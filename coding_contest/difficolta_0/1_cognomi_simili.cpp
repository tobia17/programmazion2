#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");

    string myline = "";
    size_t pos = 0;
    while(getline(input, myline)){
        string cognomi[3], temp;
        int n;

        //ciclo per smistare i cognomi e ottenere in numero n
        int i = 0;
        while( (pos = myline.find(' ')) != string::npos ){
            temp = myline.substr(0, pos);

            if(i==0){
                n = stoi(temp);
            }else{
                cognomi[i-1] = temp;
            }
            i++;

            myline.erase(0, pos + 1); //metto 1 perché lo stazio ' ' occupa solo un posto
        }
        cognomi[2] = myline;


        if(cognomi[0].substr(0, n) == cognomi[1].substr(0, n)){
            output << cognomi[0] << " " << cognomi[1];
            if(cognomi[0].substr(0, n) == cognomi[2].substr(0, n)){
                output << " " << cognomi[2];
            }
            output << "\n";
        }else if(cognomi[0].substr(0, n) == cognomi[2].substr(0, n)){
            output << cognomi[0] << " " << cognomi[2];
            output << "\n";
        }else if(cognomi[1].substr(0, n) == cognomi[2].substr(0, n)){
            output << cognomi[1] << " " << cognomi[2];
            output << "\n";
        }
        
        
    }

    input.close();
    output.close();
    return 0;
}