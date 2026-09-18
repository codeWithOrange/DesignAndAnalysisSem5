#include<iostream> 
#include<string> 
#include<math.h>

using namespace std; 

int rabin_karp(string text, string pattern){
    int m=text.length(); 
    int n=pattern.length(); 
    // hash of pattern
    
    int pattern_hash=0; 
    int base=10; 
    // hash value of pattern 
    
    int power=pow(10, n-1); 


    for(int i=1; i<n;i++){
        pattern_hash=pattern_hash*base+(pattern[i]-'a'); 
    }
    // hash value of first window
    int text_hash=0; 
    for(int i=0; i<m;i++){
        text_hash=text_hash*base+(text[i]-'a'); 
    }


    return 0; 

}

int main(){


    return 0; 
}
