#include <iostream>
#include <fstream>

using namespace std;

/*
int m(string s, int da, int a){

    int x;
    if(da>a)return 0;
    if(da==a)return 1;
    if (s[a]==s[da]){
        x=m(s,da+1, a-1);
        if(x==a-da-1)return x+2;
    }
    int r=m(s,da+1,a);
    int l=m(s,da,a-1);
    x=r-l;
    if(x>0)
        return r;
    else
        return l;
}
*/

/*
int m_d(char s[], int da, int a,int n,int k, int v[][k]){

    int x;
    if(da>a)return 0;
    if(da==a)return 1;
    if (s[a]==s[da]){
        x=v[da+1][a-1];
        if(x==a-da-1)return x+2;
    }
    int r=v[da+1][a];
    int l=v[da][a-1];
    x=r-l;
    if(x>0)
        return r;
    else
        return l;
}
 
int m_iterativa(string stringa){

    int len=stringa.length();
    int **v=(int**)malloc(sizeof(int)*len*len);
    int i,j;
    for(i=0;i<len;i++){
        for(j=0;j<(len-i);j++){
            int pal=m_d(stringa,j,i+j,len,len,v);
            v[j*len+(i+j)]=pal;
        }
    }
    len=v[len-1];
    free(v);
    return len;
}
*/

int innerTest(string str, int min, int max) {
	//if (min - max == 0) return 0;
	int i = min;
	int j = max;
	while(i<=j) {
		if (str[i] != str[j]) return 0;
		++i;
		--j;
	}
	return 1;
}

int lenPalFind(string str, int strlen) {
	int forward = 0;
	int backward = strlen;
	int spool;

	int lenMax = 0;

	for(forward=0; forward<strlen; forward++) {
		for(backward=strlen-1; backward>forward; backward--) {
			if(str[forward]==str[backward]) {
				if(innerTest(str, forward, backward) ) {
					/*
					for(spool = forward; spool<=backward; spool++) {
						cout << str[spool];
					} 
					cout << ": ";
					cout << backward - forward + 1 << endl;
					*/
					if(backward - forward + 1 > lenMax){
						lenMax = backward - forward + 1;
					}

					break;
				}
			}
		}
	}

	return lenMax;
}

int main(){

	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){

		output << lenPalFind(line, line.length()) << "\n";

		//int r = m(line, 0, line.length());
		//cout << r << endl;
		//output << r << "\n";
	}

	output.close();
	input.close();
	return 0;
}
