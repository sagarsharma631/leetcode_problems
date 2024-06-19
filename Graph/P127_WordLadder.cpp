/*
Problem 127: Word Ladder
*/
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<climits>

//#define DEBUG

using namespace std;

bool is_string_diff_one(const string& first, const string& second){
    int count = 0;
    for (int i = 0; i < first.size(); ++i) {
        if (first[i] != second[i]) {
            ++count;
            if (count > 1) {
                break;
            }
        }
    }
    return (count == 1);
}

vector<vector<int>>&
generate_adjacency_list(const vector<string>& word_list) {
    vector<vector<int>>* adjacency_list = new vector<vector<int>>;

    for (int i = 0; i < word_list.size(); ++i) {
        vector<int>* vec = new vector<int>;
        for (int j = i + 1; j < word_list.size(); ++j) {
            if(is_string_diff_one(word_list[i], word_list[j])){
                vec->push_back(j);
            }
        }
        adjacency_list->push_back(*vec);
    }
    
    return *adjacency_list;
}

int depth_first_search(vector<vector<int>>& adjacency_list, int curr_index, const string& end_word, 
                vector<string>& word_list){
    
    if(word_list[curr_index] == end_word){
        return 1;
    }
    
    if(adjacency_list[curr_index].empty()){
        return -1;
    }
    
    int result = INT_MAX;
    for(int i = 0; i < adjacency_list[curr_index].size(); ++i){
        int local_result = depth_first_search(adjacency_list, adjacency_list[curr_index][i], end_word, word_list);
        if(local_result != -1){
            result = min(result, local_result + 1);
        }
    }
    return result;
}

int ladderLength(const string& beginWord, const string& endWord,
                 vector<string>& word_list) {
    
    vector<vector<int>> adjacency_list = generate_adjacency_list(word_list);
    
    // Now DFS on the graph.
    int result = INT_MAX;
    for(int i = 0; i < word_list.size(); ++i){
        if(is_string_diff_one(word_list[i], beginWord)){
            result = depth_first_search(adjacency_list, i, endWord, word_list) + 1;
        }
    }
    return (result == INT_MAX)? 0 : result;
}

int main(int argc, char *argv[]){
    vector<string> word_list({"hot","dog","dot"});
    int result = ladderLength("hot", "dog", word_list);
    cout<<result<<endl;
#ifdef DEBUG
    for(int i = 0; i < adjacency_list.size(); ++i){
        cout<<word_list[i]<<" -> ";
        //cout<<i<<" -> ";
        for(int j = 0; j < adjacency_list[i].size(); ++j){
            cout<<word_list[adjacency_list[i][j]]<<" ";
            //cout<<adjacency_list[i][j]<<" ";
        }
        cout<<endl;
    }
#endif 
    return 0;
}
