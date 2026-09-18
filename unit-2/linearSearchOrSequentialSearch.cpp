#include<iostream> 
using namespace std; 
int sequentialSearch(string text,char c){
    for(int i=0; i<text.length(); i++){
        if(text[i]==c)return i; 
    }

    return -1; 
}

int main(){

    string txt="angad kumar maurya"; 
    int ans=sequentialSearch(txt, 'k'); 
    cout<<ans; 

    return 0;  
}
