#include <iostream>
#include <fstream>

using namespace std;

double palindroma(string s){
	if(s.length() < 2) return (s.length()==1?0.5:0);
	return (s[0] == s[s.length()-1]?1.0:0) + palindroma(s.substr(1, s.length()-2));
}

int main(){

	ifstream input("input.txt");
	ofstream output("output.txt");

	string line;
	while(getline(input, line)){
		int cnt = 0;
		size_t pos;
		bool get_n = false;
		string parole;
		while( (pos = line.find(' ')) != string::npos){

			string temp = line.substr(0, pos);
			if(get_n == false){
				int n = stoi(temp);
				get_n = true;
			}else{
				if(palindroma(temp)*2 == temp.length() || palindroma(temp)*2 == temp.length()-2){
					cnt++;
					parole += temp;
					parole += " ";
				}			
			}

			line.erase(0, pos+1);
		}
		
		if(palindroma(line)*2 == line.length() || palindroma(line)*2 == line.length()-2){
			cnt++;
			parole += line;
			parole += " ";
		}

		output << cnt << " " << parole << "\n";

	}

	output.close();
	input.close();

	//cout << palindroma("yamamay") << endl;
	//cout << palindroma("yomamay") << endl;
	return 0;
}