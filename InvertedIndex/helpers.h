#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include "stopwords.h"
#pragma once

string normalize(string source) {
    transform(source.begin(), source.end(), source.begin(), ::tolower);
    if (ispunct(source[source.length()-1]) == 0) {
       return source; 
    } else {
      int end = source.length() > 1 ? source.length()-1 : 0;
      bool searching = end > 1 ? true : false;
      while (searching) {
      if (ispunct(source[end]) == 0) {
          searching = false;
      } else {
       end--;
       if (end ==0){
	searching = false;
	}   
      }
      }
      if (end == 0) {
          return "";
      } else {
         return source.substr(0, end+1); 
      }
}
}

vector<string> parseSentences (string source) {
   vector<string> results;
   stringstream stringStream(source);
   string token;
   
   while (getline(stringStream, token, '\n')){
       results.push_back(token); 
   } 
    return results;
}

vector<string> parseWords (string source) {
   vector<string> results;
   stringstream stringStream(source);
   string token;
   
   while (getline(stringStream, token, ' ')){
       string normalized = normalize(token);
       if (normalized != "" && (stopWords.find(normalized) == stopWords.end())) {
       results.push_back(normalized);
   } 
}
   return results;
}