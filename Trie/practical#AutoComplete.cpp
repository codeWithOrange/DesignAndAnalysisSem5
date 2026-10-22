#include<iostream> 
#include<vector> 
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
public:
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

void collectWords(TrieNode * node, string current, vector<string> &result){
    if(node->isEnd)result.push_back(current); 
    for(int i=0; i<26; i++){
        if(node->children[i]!=nullptr){
            char ch='a'+i; 
            collectWords(node->children[i], current+ch, result); 
        }
    }
}

vector<string> autocomplete(TrieNode * root, string prefix){
    TrieNode *curr=root; 
    for(char ch:prefix){
        int index=ch-'a'; 
        if(curr->children[index]==nullptr)return {}; 
        curr=curr->children[index]; 
    }
    vector<string> result; 
    collectWords(curr,prefix, result); 
    return result; 
}

int main(){
    Trie trie; 
    trie.insert("angad"); 
    trie.insert("angada"); 
    trie.insert("angadandan"); 
    trie.insert("angadaarling");  
    trie.insert("kartik"); 
    trie.insert("kartika"); 
    vector<string> ans=autocomplete(trie.root,"kar") ; 

    for(string text:ans)cout<<text<<" "; 
    cout<<endl;



    return 0; 
}











