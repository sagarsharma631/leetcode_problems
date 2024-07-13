/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
*/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<int, unordered_map<int, int>> memoization;

int numTreesUtil(int lo, int hi) {
    if (memoization.find(lo) != memoization.end() &&
        memoization[lo].find(hi) != memoization[lo].end()) {
        return memoization[lo][hi];
    }
    if (lo >= hi) {
        return 1;
    }
    if (hi - lo == 1) {
        return 2;
    }
    int result = 0;
    for (int i = lo; i <= hi; ++i) {
        int left_trees = numTreesUtil(lo, i - 1);
        int right_trees = numTreesUtil(i + 1, hi);
        result += left_trees * right_trees;
    }
    memoization[lo][hi] = result;
    return result;
}
int numTrees(int n) { 
    return numTreesUtil(1, n); 
}

int main(int argc, char *argv[]){
    cout<<numTrees(5);
    return 0;
}
