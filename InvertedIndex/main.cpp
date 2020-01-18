#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include <string>
#include <unordered_set>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#include "helpers.h"

using namespace std;
vector<string> paragraphs;
map <string, vector<pair<int, int>>> invertedIndex;
int documentIndex = 0;

void addToInvertedIndex(vector<string> words){
    map<string, int> wordCounts;   
    for (string word : words) {
         if (wordCounts.find(word) == wordCounts.end()) {
            wordCounts.insert({word, 1});
         } else {
            int counts = wordCounts.at(word);
            wordCounts.at(word) = counts + 1;
         }
    }
    for (pair<string, int> entry : wordCounts){
        string key = entry.first;
        if (invertedIndex.find(key) == invertedIndex.end()) {
            vector<pair<int, int>> newVec;
            pair<int, int> values;
            values.first = documentIndex;
            values.second = wordCounts.find(key)->second;
            newVec.push_back(values); 
            invertedIndex.insert({key, newVec});
            
        } else {
          pair<int, int> value;
          vector<pair<int, int>> counts = invertedIndex.at(key);
          value.first = documentIndex;
          value.second = wordCounts.find(key)->second;
          counts.push_back(value);
          invertedIndex.at(key) = counts;
        }   
    }   
   }

void searchString(string input) {
    
    if (input.length() < 1) {
        cout << "Error: Empty search string." << endl;
        return;
    }
    
    set<int> indicies1;
    vector<string> results;
    vector<string> searchWords = parseWords(input);
    
    if (searchWords.size() == 0) {
        cout << "Error: No results found." << endl;
        return;
    } else {
        set<int> indicies2;
        for (string word : searchWords){
            if (invertedIndex.find(word) == invertedIndex.end()) {
                cout << "No results." << endl;
                return;
            } else {
                vector<pair<int, int>> indexVec = invertedIndex.find(word)->second;
                for (pair<int, int> values : indexVec) {
                    indicies2.insert(values.first);
                }
                if (indicies1.size() == 0) {
                    indicies1 = indicies2;
                } else {
                    set<int> result; 
                    merge(indicies1.begin(), indicies1.end(),
                          indicies2.begin(), indicies2.end(), inserter(result, result.begin())
                          );
                    if (result.size() == 0) {
                        cout << "No results." << endl;
                        return;
                    } else {
                        indicies1 = result;
                    }  
                }
             }     
           }
        }
    
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    for (int num : indicies1) {
        string sourceText = paragraphs[num];
        transform(sourceText.begin(), sourceText.end(), sourceText.begin(), ::tolower);
        if (sourceText.find(input) != string::npos) {
            string result = "Line " + to_string(num + 1) + "\n" + paragraphs[num];
            results.push_back(result);
        }
    }
    if (results.size() == 0) {
        cout << "No results." << endl;
    } else {
        cout << "Results: \n\n";
        for (string result : results) {
            cout << result << "\n\n";
        }
    }
    }

int main(int argc, char** argv) {
    ifstream inputText;
    //inputText.open("");
    string line;
    while(!inputText.eof()){
       getline(inputText, line);
       paragraphs.push_back(line);
       vector<string> words = parseWords(line);       
       addToInvertedIndex(words);
       documentIndex++;
    }
    inputText.close();
    searchString("line");
    return 0;
}
