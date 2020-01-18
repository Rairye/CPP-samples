#pragma once
#include <iostream>
#include <unordered_set>

using namespace std;
unordered_set <string> stopWords{"i", "me", "my", "myself", "we", 
        "our", "ours", "ourselves", "you", "you're", "you've", "you'll", 
        "you'd", "your", "yours", "however", "therefore", "therefor", "therefrom", "thereto"
        "yourself", "yourselves", "he", "him", "every",  "his", "himself", "she", 
        "she's", "her", "hers", "herself", "it", "it's", "its", "throughout", 
        "itself", "they", "them", "their", "theirs", "themselves", "what", "whence"
        "which", "who", "whom", "this", "that", "that'll", "these", "those", 
        "am", "is", "are", "was", "were", "be", "been", "being", "have", "has", "whose",
        "had", "having", "do", "does", "did", "doing", "a", "an", "the", "and", 
        "but", "if", "or", "because", "as", "until", "while", "of", "at", "by", 
        "for", "with", "about", "against", "between", "into", "through", "during", 
        "before", "after", "above", "below", "to", "from", "up", "down", "in", 
        "out", "on", "off", "over", "under", "again", "further", "then", "once", 
        "here", "there", "when", "where", "why", "how", "all", "any", "both", 
        "each", "few", "more", "most", "other", "some", "such", "no", "nor", 
        "not", "only", "own", "same", "so", "than", "too", "very", "can", "will", 
        "just", "don", "don't", "should", "should've", "now", "aren't", "couldn't", 
        "didn't", "doesn't", "hadn", "hadn't", "hasn't", "haven't", 
        "isn't", "mightn't", "mustn't", "needn't", "shan't", "shouldn't", 
        "wasn't", "weren't", "won", "won't", "wouldn't"};
