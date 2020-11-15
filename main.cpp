#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string>& strs)
{
	//simple lookup table
    unordered_map<string,vector<string>> lookup;

    //for each word have a unique mapping of array of anagrams in the lookup table
    for(const auto &word:strs)
    {
        string temp {word};
        //sort to get a unique version as key
        sort(temp.begin(),temp.end());
        //append to the anagram list pointing to by that key
        lookup[temp].push_back(word);
    }

    //assemble the result
    vector<vector<string>> group;

    for(auto &wrd:lookup) 
    	group.push_back(move(wrd.second));//note use of move semeantics for memory efficiency
    return group;
}


int main()
{

    vector<string> input_arr = {"eat","tea","tan","ate","nat","bat"};
    //Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    vector<vector<string>> res_arr = groupAnagrams(input_arr);
    for(auto &arr:res_arr)
    {
        cout << "[" ;
        for(auto &wrd:arr) cout << wrd << " ";
        cout << "]" << endl;
    }

    return 0;
}
