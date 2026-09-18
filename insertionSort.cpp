#include<iostream> 
#include <unordered_map>
#include<vector> 
#include<string> 
using namespace std; 


unordered_map<string, int>  insertionSort(vector<int> &arr){
    int shifts=0; 
    int comparisons=0; 
    unordered_map<string,int> mp; 
    for(int i=1; i<arr.size(); i++){
        int key=arr[i]; 
        int j=i-1; 
        while(j>=0){
            comparisons++; 
            if(arr[j]>key){
                arr[j+1]=arr[j]; 
                shifts++; 
                j--; 
            }else break; 
        }
        arr[j+1]=key; 

    }
    
    mp["shifts"]=shifts; 
    mp["comparisons"]=comparisons; 
    return mp; 
}
void printArray(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" "; 
    }
    cout<<endl; 
}


int main(){
    vector<int> arr={2,3,5,-1,3,5}; 
    unordered_map<string,int> result=insertionSort(arr); 
    cout<<"shifts: "<<result["shifts"]<<endl; 
    cout<<"comparisons: "<<result["comparisons"]<<endl; 
    printArray(arr); 




    return 0; 
}
