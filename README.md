# groupAnagrams
In this post you would lean step by step implementation of my solution to groupAnagrams.
The techniques applied here are simple use of HashTable for fast and effiecient lookup and pass by reference and move semantics as it relates to c++ 11 and beyond to save memory.

* The Problem :
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

* The Algorithm :
The algorithm is broken into three steps
* create a simple lookup table of key as string, and value as vector<string>
* for each word have a unique mapping of array of anagrams in the lookup table 
* groups anagrams of given words from the lookup table  

include the following:

```
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
```

* create a simple lookup table of key as string, and value as vector<string> :
  In this tutorial we would be using unordered_map. Unordered map is an associative container that contains key-value pairs with unique keys. learn more on this link https://en.cppreference.com/w/cpp/container/unordered_map.
```bash
 unordered_map<string,vector<string>> lookup; //simple lookup table
```

* for each word have a unique mapping of array of anagrams in the lookup table : 
This is our expected Output: [["bat"],["nat","tan"],["ate","eat","tea"]].
This entails that we can have a unique representation of each word and compare subsequent words, if it is present we append it to the array of words pointed to by the uniq version of that word, if it is not presence we insert it in our lookup array and push in the word into the array as value and have the unique version as key.
Now you might be confuse with unique version of the word, please look our the problem definition above to fully understand what anagrams are before you move on with the rest of the implementation.


```
//for each word have a unique mapping of array of anagrams in the lookup table
    for(const auto &word:strs)
    {
        string temp {word};
        //sort to get a unique version as key
        sort(temp.begin(),temp.end());
        //append to the anagram list pointing to by that key
        lookup[temp].push_back(word);
    }
```
to maintain a unique version of each word we use the sorted version as key as shown on line 43. line 45 collects anagrams of each word into into an array stored as value pair to the word as key pair in the lookup table.


* groups anagrams of given words from the lookup table :
  to collect the result in the required format we create a 2 dimensional array of strings to groups anagrams of given words.
```
vector<vector<string>> group;
```
We want to move each values in the lookup table, this forms our grouped anagrams. we make use of move semeantics for memory efficiency.
```
 for(auto &wrd:lookup) 
    	group.push_back(move(wrd.second));//note use of move semeantics for memory efficiency
```

* Here is the full function code :
```
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
```

*Full implementation is found on the main.cpp file.

