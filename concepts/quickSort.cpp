#include<iostream> 
#include<vector> 
using namespace std; 
using Array = vector<int>;  

int partition(Array &arr, int low, int high){
    int pivot=arr[high]; 
    int i=low-1; 
    for(int j=low; j<high;j++){
        if(arr[j]<pivot){
            i++; 
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i+1], arr[high]);  

    return i+1; 
}


void quickSort(Array &arr,int low, int high){
    if(low>=high)return; 
    int pivotIndex=partition(arr,low, high); 
    quickSort(arr, low,pivotIndex-1); 
    quickSort(arr,pivotIndex+1,high); 
}

void printArray(const Array&a){
    for(int i=0; i<a.size(); i++)cout<<a[i]<<" "; 
    cout<<endl; 
}


int main(){
    Array arr={2,3,4,-1,3,-2,3,4}; 
    quickSort(arr,0,arr.size()-1); 
    printArray(arr); 
    return 0; 
}
