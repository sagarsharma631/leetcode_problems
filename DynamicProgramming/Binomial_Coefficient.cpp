#include<iostream>

using namespace std;

int compute_combination(int n, int k){
    if(n == k){
        return 1;
    }
    
    if(k == 1){
        return n;
    }
    
    int k_minus_1 = compute_combination(n - 1, k - 1);
    
    int k_as_it_is = compute_combination(n - 1, k);
    
    return k_minus_1 + k_as_it_is;
}

int compute_combination_dp(int n, int k){
    
    int dp[n][k];
    
    // Fill in the base cases
    for(int i = 0; i < k; ++i){
        dp[i][i] = 1;
    }
    
    for(int i = 1; i < n; ++i){
        dp[i][0] = i + 1;
    }
    
    // Fill in the dp matrix now
    for(int i = 2; i < n; ++i){
        for(int j = 1; j < min(i,k); ++j){
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return dp[n - 1][k - 1];
}

int main(int argc, char *argv[]){
    cout<<compute_combination(69, 43)<<endl;
    cout<<compute_combination_dp(69,43);
    return 0;
}
