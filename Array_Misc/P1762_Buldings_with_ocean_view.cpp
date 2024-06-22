/*
Problem 1762: Buldings with ocean view
*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> findBuildings(vector<int>& heights) {
    stack<int> st;
    st.push(0);
    for(int i = 1; i < heights.size(); ++i){
        if(heights[i] >= heights[st.top()]){
            while(!st.empty() && heights[st.top()] <= heights[i]){
                st.pop();
            }
        }
        st.push(i);
    }

    vector<int> result;
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

int main(int argc, char *argv[]){
    vector<int> buildings({4,2,3,1});
    vector<int> result = findBuildings(buildings);
    for(int i = 0; i < result.size(); ++i){
        cout<<result[i]<<" ";
    }
    return 0;
}
