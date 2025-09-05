//Unique Number 2N+1 form
#include<iostream>
#include<vector>
using namespace std;

int Unique1(vector<int> arr){
    int ans = 0;
    for(int i = 0; i < arr.size(); i++){
        ans ^= arr[i];
    }
    return ans;
}

int main(){
    vector<int> v = {1,1,2,2,3,3,4,4,5,6,6,7,7};
    cout << Unique1(v) << endl;
    return 0;
}