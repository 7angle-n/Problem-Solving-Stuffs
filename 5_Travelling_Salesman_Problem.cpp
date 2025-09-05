#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int TSP(vector<vector<int>> dist, int VisitedCities, int CurCity, int n, vector<vector<int>> &dp){
    if(VisitedCities == (1<<n)-1){
        //Return to start
        return dist[CurCity][0];
    }
    if(dp[VisitedCities][CurCity] != -1){
        return dp[VisitedCities][CurCity];
    }
    //We want to minimize the ans, so we initialize with maximum
    int ans = INT_MAX;
    for(int choice = 0; choice<n; choice++){
        //Check whether a city is visited or not
        if((VisitedCities & (1<<choice)) == 0){
            int SubProblem = dist[CurCity][choice] + TSP(dist, VisitedCities | (1<<choice), choice, n, dp);
            ans = min(ans, SubProblem);
        }
    }
    return dp[VisitedCities][CurCity] = ans;
}

int main() {
    vector<vector<int>> dist = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };
    vector<vector<int>> dp(1<<4, vector<int>(4, -1));
    cout << TSP(dist, 0001, 0, 4, dp) << endl;
    return 0;
}
