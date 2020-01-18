#include <string> 
#include <bits/stdc++.h>
#pragma once
using namespace std;

class Node {
 private:
 char name;
 map<char, Node*> children;
 bool wordEnd;
 
public:
 Node(char name) {
     this->name = name;
     this->children = {};
     this-> wordEnd = false;
 }
 
 void addChild(char child) {
     this->children[child] = new Node(child);
 }
 
 bool hasChild(char child){
     return this->children.find(child) != children.end();
 }
 
 Node* getChild(char name) {
     return this->children.find(name)->second;
 }
 
 map<char, Node*> getChildren() {
   return this->children;   
 }
 
 int getSize() {
   return this->children.size();   
 }
    
 char getName () {
     return this->name;
}
 void setWordEnd() {
     this->wordEnd = true;
 }
 
 bool isWordEnd() {
     return this->wordEnd;
 }

};