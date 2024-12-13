// Online C++ compiler to run C++ program online
#include <iostream>

void printSumArr(int arr[], int n){
    int sum = 0;
    int maxSum = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                std::cout << arr[k]<<",";
                
                sum = sum + arr[k]; // this is correct
            }
            // this the the mistake we did : sum = sum + arr[j];
            std::cout <<"[" << sum << "]";
            if(sum > maxSum){
                maxSum = sum;
            }
            std::cout<<std::endl;
            
        }
        sum = 0;
    }
    
    std::cout <<"[" << maxSum << "]";
     
}
int main() {
    // Write C code here
    int arr[] = {-10, 20, 30, -40, 50, 60};
    int n = sizeof(arr)/sizeof(int);
    
    printSumArr(arr, n);

    return 0;
}
