/*
Problem 49: Group Anagrams
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<int> freq_map(26,0);
    unordered_map<string, vector<string>> result_map;
    auto populate_freq_map = [&](const string& s) -> void{
        for(char c : s){
            freq_map[c - 'a'] += 1;
        }
    };

    auto generate_string_freq_map = [&]() -> string{
        string result;
        for(int i = 0; i < 26; ++i){
            result += to_string(freq_map[i]);
            result += '#';
        }
        return result;
    };
    
    for(auto str : strs){
        // Populate freq_map
        populate_freq_map(str);

        // Generate hash from the freq_map
        string hash_string = generate_string_freq_map();

        // Insert it into the unordered_map -> result_map 
        if(result_map.find(hash_string) == result_map.end()){
            result_map[hash_string] = vector<string>();
        }
        result_map[hash_string].push_back(str);

        // Clear the freq_map
        fill(freq_map.begin(), freq_map.end(), 0);
    }

    // Now traverse the result_map and populate the resultant vector
    vector<vector<string>> result;
    for(auto iter : result_map){
        result.push_back(iter.second);
    }
    return result;
}

int main(int argc, char *argv[]){
    
    vector<string> strs({"eat","tea","tan","ate","nat","bat"});
    
    vector<vector<string>> result = groupAnagrams(strs);
    
    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size(); ++j){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
