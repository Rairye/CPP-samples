#include <cstdlib>
#include <string>
#include <sstream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

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

double cosineSim(string first, string second){
    
   map<string, pair<int, int>> counts;

   stringstream ss1(first);
   stringstream ss2(second);
   string token;

   while (getline(ss1, token, ' ')){
       string normalized = normalize(token);
       if (normalized != "") {
       if (counts.find(normalized) == counts.end()){
           pair<int,int> initialValues{1,0};
	   counts.insert({normalized, initialValues}); 
	} else {
          pair<int, int> values = counts.find(normalized)->second;
	  int count = values.first + 1;
	  values.first = count;
	  counts[normalized] = values;	
	}
     }
   }
       
   while (getline(ss2, token, ' ')){
       string normalized = normalize(token);
       if (normalized != "") {
       if (counts.find(normalized) == counts.end()){
           pair<int,int> initialValues{0,1};
	   counts.insert({normalized, initialValues}); 
	} else {
          pair<int, int> values = counts.find(normalized)->second;
	  int count = values.second + 1;
	  values.second = count;
	  counts[normalized] = values;	
	}
     }
  }
   
   int dotProductInt = 0;
   int firstDotProduct = 0;
   int secondDotProduct = 0;
   
   for (pair<string, pair<int, int>> count : counts) {
       pair<int, int> numbers = count.second;
       dotProductInt += (numbers.first * numbers.second);
       firstDotProduct += (numbers.first * numbers.first);
       secondDotProduct += (numbers.second * numbers.second);
   }
   
   double dotProductDouble = (double) dotProductInt;
   double magnitudeOne = sqrt((double) firstDotProduct);
   double magnitudeTwo = sqrt((double) secondDotProduct);
   return dotProductDouble/(magnitudeOne * magnitudeTwo);
}

int main(int argc, char** argv) {
    
    cout << "Result: " << cosineSim("Hello, friend.", "Hello, buddy.") << endl;
    cout << "Result: " << cosineSim("Hello, friend.", "Hello, friend.") << endl;
    cout << "Result: " << cosineSim("Hello, friend.", "See you later.") << endl;
   
    return 0;
}

