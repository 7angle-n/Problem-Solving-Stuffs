//Unique of form 2N+2
#include<iostream>
#include<vector>
using namespace std;

int SetBit(int x){
    int ans=0;
    while(x>0){
        if((x&1) == 1){
            return ans;
        }
        ans++;
        x>>=1;
    }
    return 0;
}

pair<int, int> Unique2(vector<int> arr){
    int ans = 0;
    for(auto x: arr){
        ans ^= x;
    }
    int set = SetBit(ans);
    vector<int> group1;
    for(auto x: arr){
        if((x>>set)&1){
            group1.push_back(x);
        }
    }
    int no1 = 0;
    for(auto x: group1){
        no1 ^= x;
    }
    int no2 = no1^ans;
    return {no1, no2};

}

int main(){
    vector<int> v = {2,3,4,5,4,3,7,2,6,6};
    auto res = Unique2(v);
    cout << res.first << " " << res.second << endl;
    return 0;
}