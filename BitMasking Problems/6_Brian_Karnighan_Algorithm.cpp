#include<iostream>
using namespace std;

int BrainKarnighan(int n){
    int cnt = 0;
    while(n > 0){
        cnt++;
        n &= (n-1);
    }
    return cnt;
}

int main(){
    cout << BrainKarnighan(15) << endl;
    return 0;
}