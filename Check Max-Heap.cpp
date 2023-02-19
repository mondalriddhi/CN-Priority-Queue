/*  Given an array of integers, check whether it represents max-heap or not.
 Return true if the given array represents max-heap, else return false.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array.
 Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains true if it represents max-heap and false if it is not a max-heap.

Sample Input 1:
8
42 20 18 6 14 11 9 4
Sample Output 1:
true
*/

#include <iostream>
using namespace std;


bool isMaxHeap(int arr[], int n) {
    // Write your code here
    int parenti=0;
    int child1=parenti*2+1;
    int child2=parenti*2+2;
    while(child1<n) {
        if(arr[parenti]<arr[child1]) {
            return false;
        }
        if(arr[parenti]<arr[child2]&&child2<n) {
            return false;
        }
        parenti++;
        child1 = parenti * 2 + 1;
        child2 = parenti * 2 + 2;
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}
