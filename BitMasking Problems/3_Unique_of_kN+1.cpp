//Unique number of form kN+1: An array consists of kN+1 numbers 
//where there is only one unique element
//and rest N number appear exactly k times each. 
//Find the unique number.
#include<iostream>
#include<vector>
using namespace std;

int Binary2Decimal(int x){
    int ans = 0;
    int pow = 1;
    while(x > 0){
        ans += (x%10)*pow;
        x = x/10;
        pow = pow*2;
    }
    return ans;
}

int Decimal2Binary(int x){
    int ans = 0;
    int pow = 1;
    while(x > 0){
        ans += (x%2)*pow;
        x = x>>1;
        pow = pow*10;
    }
    return ans;
}

int Unique3(vector<int> arr, int k){
    int ans = 0;
    for(auto x: arr){
        ans += Decimal2Binary(x);
    }
    int new_ans = 0;
    int pow = 1;
    while(ans > 0){
        new_ans += ((ans%10)%k)*pow;
        ans = ans/10;
        pow = pow*10;
    }
    cout << new_ans << endl;
    return Binary2Decimal(new_ans);

}

int main(){
    vector<int> v = {5,2,5,3,5,2,2};
    cout << Unique3(v, 3) << endl;
    return 0;
}