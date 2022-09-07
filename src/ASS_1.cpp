//============================================================================
// Name        : ASS_1.cpp
// Author      : PIYUSH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================




#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int dp[1001][1001];
void fun()
{
   cout<<"this is changed";
}
int maxValue(int wt[], int val[], int n, int w ) {


    if(n <= 0 || w <= 0) {
       return 0;
    }

    if(dp[n][w] != -1) {
       return dp[n][w];
    }

    else if(wt[n-1] <= w) {
       dp[n][w] = max(val[n-1] + maxValue(wt, val, n-1, w-wt[n-1]), maxValue( wt, val, n-1, w));
       return dp[n][w];
    }
    else {
       dp[n][w] = maxValue(wt, val, n-1, w);
       return dp[n][w];
    }

}

int init(int w, int wt[], int val[], int n) {

    if(n <= 0 || w <= 0)    return 0;
    memset(&dp, -1, sizeof (dp));
    return maxValue(wt, val, n, w);
}

int main() {

    int n, maxWeight;
    cout << "Enter the total number of weights" << endl;
    cin >> n;
    cout << "Enter the maximum allowed weight of the knapsack " << endl;
    cin >> maxWeight;

    int weights[n];
    int values[n];
    cout << "Enter the weights:" << endl;
    for(int i = 0 ; i < n ; ++i) {
       cin >> weights[i];
    }

    cout << "Enter the values:" << endl;
    for(int i = 0 ; i < n ; ++i) {
       cin >> values[i];
    }


    ios_base::sync_with_stdio(false);

    auto start = high_resolution_clock::now;

    cout << "The maximum value of the knapsack is: "<<endl;
    cout << init(maxWeight, weights, values, n);

    auto stop = high_resolution_clock::now;

//    auto duration = duration_cast<microseconds>(stop - start);
//    cout << "The time taken by the function is: " << duration.count() << " microseconds." << endl;


    return 0;
}


