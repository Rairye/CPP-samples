#include <string>
#include <unordered_set>
#include <bits/stdc++.h>
#include "node.h"
#pragma once
using namespace std;

class Trie {
    private:
        map<char, Node*> trieMap;
        unordered_set<string> results;
    public:
        Trie() {}
        void add(string word) {
            char name = word[0];
            int wordLength = word.length();
            if (trieMap.find(name) == trieMap.end()){
                trieMap[name] = new Node(name);
            }
            Node* currentNode = trieMap[name];
            if (wordLength == 1) {
                currentNode->setWordEnd();
                return;
            }
            int i = 1;
            while (i < wordLength -1) {
                if (!currentNode->hasChild(word[i])) {
                    currentNode->addChild(word[i]);  
                  } 
                 currentNode = currentNode->getChild(word[i]);
                 i++;
                }
                
                if (!currentNode->hasChild(word[i])) {
                    currentNode->addChild(word[i]);
                }
                currentNode = currentNode->getChild(word[i]);
                currentNode->setWordEnd();
            }
        bool find(string word) {
            int wordLength = word.length();
            if (trieMap.find(word[0]) == trieMap.end()) {
                return false;
            }
            Node* currentNode = trieMap.find(word[0])->second;
            if (wordLength == 1 && currentNode->isWordEnd()) {
                return true;
            }
            int i = 1;
            while (i < wordLength - 1) {
                char name = word[i];
                if (!currentNode->hasChild(word[i])) {
                    return false; }         
                currentNode = currentNode->getChild(word[i]);
                i++;
                }
                try {
                    currentNode = currentNode->getChild(word[i]);
                } catch (exception& e) {
                    return false;
                }
                if (currentNode->isWordEnd()) {
                    return true;
                }
            return false;  }
      };
