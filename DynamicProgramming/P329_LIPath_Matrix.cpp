/*
Problem 329: Longest Increasing Path in a Matrix
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>

using namespace std;

int longestIncreasingPathUtil(
    vector<vector<int>>& matrix,
    unordered_map<int, unordered_map<int, int>>& dp, const int& i,
    const int& j) {

    if (dp.find(i) != dp.end() && dp[i].find(j) != dp[i].end()) {
        return dp[i][j];
    }
    int left = 0, up = 0, down = 0, right = 0;
    if (i > 0 && matrix[i][j] < matrix[i - 1][j]) {
        up = longestIncreasingPathUtil(matrix, dp, i - 1, j);
    }

    if (j > 0 && matrix[i][j] < matrix[i][j - 1]) {
        left = longestIncreasingPathUtil(matrix, dp, i, j - 1);
    }

    if (j < matrix[0].size() - 1 && matrix[i][j] < matrix[i][j + 1]) {
        right = longestIncreasingPathUtil(matrix, dp, i, j + 1);
    }

    if (i < matrix.size() - 1 && matrix[i][j] < matrix[i + 1][j]) {
        down = longestIncreasingPathUtil(matrix, dp, i + 1, j);
    }

    dp[i][j] = max({up, down, right, left}) + 1;
    return dp[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    unordered_map<int, unordered_map<int, int>> dp;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int result = INT_MIN;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            dp[i][j] = longestIncreasingPathUtil(matrix, dp, i, j);
            result = max(dp[i][j], result);
        }
    }
    return result;
}

int main(int argc, char *argv[]){
    vector<vector<int>> matrix({{3,4,5},
                               {3,2,6},
                               {2,2,1}});
    cout<<longestIncreasingPath(matrix)<<endl;                           
    return 0;
}
