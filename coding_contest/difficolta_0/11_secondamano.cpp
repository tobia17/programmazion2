#include <iostream>
#include <fstream>

using namespace std;

void stampa(int *v, int n){
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

int main(){

    ifstream input("input.txt");
    ofstream output("output.txt");

    const int costo_fumetto = 5;

    string line;
    
    while(getline(input, line)){
        string temp;
        size_t pos;
        int n, m, i = 0, j = 0, sum = 0;
        while( (pos = line.find(' ') ) != string::npos){
            temp = line.substr(0, pos);
            if(i == 0){
                n = stoi(temp);
            }else if(i == 1){
                m = stoi(temp);
                line.erase(0, pos + 1);
                break;
            }
            line.erase(0, pos + 1);
            i++;
        }

        //cout << n << " " << m << endl;

        i = 0, j = 0;
        int N[n], M[m];
        while( (pos = line.find(' ') ) != string::npos){
            temp = line.substr(0, pos);

            if(i < n){
                N[i] = stoi(temp);
                i++;
            }else{
                M[j] = stoi(temp);
                j++;
            }
            
            line.erase(0, pos + 1);
        }
        M[m-1] = stoi(line);

        //stampa(N, n);
        //stampa(M, m);

        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                if(N[x] == M[y]){
                    sum += costo_fumetto;
                    break;
                }
            }
        }

        output << sum << "\n";
    }

    input.close();
    output.close();
    return 0;
}