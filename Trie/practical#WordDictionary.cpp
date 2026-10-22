#include<iostream> 
using namespace std; 

struct TrieNode{
    TrieNode *children[26]; 
    bool isEnd; 
    TrieNode(){
        isEnd=false; 
        for(int i=0; i<26; i++){
            children[i]=nullptr; 
        }
    }
}; 
class Trie{
private:
    TrieNode *root; 
public: 
    Trie(){
        root=new TrieNode(); 
    }
    void insert(string word){
        TrieNode *curr=root; 
        for(char ch:word){
            int index=ch-'a'; 
            if(curr->children[index]==nullptr)curr->children[index]=new TrieNode();  
            curr=curr->children[index]; 
        }
        curr->isEnd=true; 
    }
    bool search(string word){
        TrieNode *curr=root; 
        for(char ch:word){
            int index=ch-'a'; 
            if(curr->children[index]==nullptr)return false; 
            curr=curr->children[index]; 

        }
        return curr->isEnd; 
    }
    bool startsWith(string word){
        TrieNode *curr=root; 
        for(char ch:word){
            int index=ch-'a'; 
            if(curr->children[index]==nullptr)return false; 
            curr=curr->children[index]; 
        }

        return true; 
    }

}; 


int main(){
    Trie trie;  
    trie.insert("angad"); 
    trie.insert("angada");      
    trie.insert("angadanda"); 
    trie.insert("angaddarling"); 
    cout<<trie.search("angad")<<endl; 
    cout<<trie.search("darling")<<endl; 
    cout<<trie.startsWith("darling")<<endl; 


    return 0; 
}





