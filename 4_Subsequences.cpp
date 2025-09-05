//Prints all subsequences of a given string
#include<iostream>
#include<string>
using namespace std;

string Num2String(int num, string st){
    string s = "";
    int index = 0;
    while(num > 0){
        if(num&1){
            s += st[index];
        }
        num >>= 1;
        index++;
    }
    return s;
}

void SubSequences(string st){
    for(int i = 0; i < (1<<st.length()); i++){
        cout << Num2String(i, st) << endl;
    }
}

int main(){
    string s;
    cin >> s;  
    SubSequences(s);
    return 0;
}