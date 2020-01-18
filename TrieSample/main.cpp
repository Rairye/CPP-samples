#include <stdio.h>
#include <string>
#include <unordered_set>
#include <bits/stdc++.h>
#include <vector>
#include "trie.h"

using namespace std;

int main(int argc, char** argv) {

    Trie* trieInstance = new Trie();
    
    trieInstance->add("banana");
    trieInstance->add("band");
    trieInstance->add("Canada");
    
    cout << boolalpha;
    cout << trieInstance->find("banana") << endl;
    cout << trieInstance->find("band") << endl;
    cout << trieInstance->find("YO") << endl;
   
    
    
    return 0;
}

