#include<iostream> 
#include<vector> 
using namespace std; 

void merge(vector<int> &arr, int left, int mid , int right){

}

void mergeSort(vector<int> &arr,int left, int right){
    if(left>=right)return; 
    int mid=left+(right-left)/2; 
    mergeSort(arr,left, mid); 
    mergeSort(arr, mid+1, right);  
    merge(arr, left, mid, right); 
}


int main(){
    vector<int> arr={2,3,434,-2,3,3};  
    mergeSort(arr, 0, arr.size()-1); 
    for(int el:arr)cout<<el<<" "; 
    return 0;
}
