// Online C++ compiler to run C++ program online
#include <iostream>

void printSumArr(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                std::cout << arr[k]<<",";
                
                
            }
            std::cout<<std::endl;
            
        }
    }
    
     
}
int main() {
    // Write C code here
    int arr[] = {-10, 20, 30, -40, 50, 60};
    int n = sizeof(arr)/sizeof(int);
    
    printSumArr(arr, n);

    return 0;
}
