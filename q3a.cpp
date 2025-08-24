#include <iostream>
using namespace std;

int Missing(int arr[], int n) {
    int totalSum = n * (n + 1) / 2;  
    int arrSum = 0;

    for (int i = 0; i < n - 1; i++) {
        arrSum += arr[i];  
    }

    return totalSum - arrSum;  
}

int main() {
    int n = 5;
    int arr[] = {1, 2, 3, 5};  
    cout << "Missing number is: " << Missing(arr, n);
    return 0;
}
