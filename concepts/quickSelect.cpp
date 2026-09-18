#include<iostream> 
#include<vector> 
using namespace std; 

int partition(vector<int> &arr, int low , int high){
    int pivot=arr[high]; 
    int i=low-1; 
    for(int j=low; j<high; j++){
        if(arr[j]<pivot){
            i++; 
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i+1], arr[high]); 
    return i+1; 

}
int findKthsmallest(vector<int> &arr, int k){
    int n=arr.size(); 
    int low=0; 
    int high=n-1; 
    k--; 
    while(low<=high){
        int pivotindex=partition(arr, low, high); 
        if(pivotindex==k)return arr[pivotindex]; 
        if(pivotindex>k)high=pivotindex-1; 
        else low=pivotindex+1; 
    }
    return -1; 
}
int findKthLargest(vector<int> &arr, int k){
    int n=arr.size();  
    int target=n-k;  
    int low=0; 
    int high=n-1; 
    while(low<=high){
        int pivotIndex=partition(arr, low, high); 
        if(pivotIndex==target)return arr[pivotIndex]; 
        if(target<pivotIndex){
            high=pivotIndex-1; 
        }else{
            low=pivotIndex+1; 
        }
    }
    return -1; 
}


int main(){
    vector<int> arr={2,2,3,-1,5,6}; 
    int k=3; 
    cout<<k<<" largest element"<<findKthLargest(arr,k)<<endl; 
    cout<<k<<"th smallest element: "<<findKthsmallest(arr, k); 
    


    return 0; 
}
