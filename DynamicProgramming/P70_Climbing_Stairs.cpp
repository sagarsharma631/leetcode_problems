/*
Problem 70: Climbing Stairs
*/

#include<iostream>
#include<vector>

using namespace std;

int climbStairs(int n) {
    if(n == 1){
        return 1;
    }
    vector<int> dp_vec(n,0);
    dp_vec[0] = 1;
    dp_vec[1] = 1;
    for(int i = 0; i < n - 1; ++i){
        if(i != n - 2){
            dp_vec[i + 2] += dp_vec[i];
        }
        dp_vec[i + 1] += dp_vec[i];
    }

    for(auto i : dp_vec){
        cout<<i<<endl;
    }

    return dp_vec[n - 1];
}

int main(int argc, char *argv[]){
    climbStairs(4);
    return 0;
}
