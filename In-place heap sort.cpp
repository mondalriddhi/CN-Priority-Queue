/*  Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. 
The elements of the array in the output are separated by single space.

Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2
*/

#include <iostream>

using namespace std;


void heapSort(int arr[], int n) {
    // Write your code
    int childIndex;
    int i=1;

    while(i<=n-1) {
        childIndex=i;
        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;
            if(arr[parentIndex]>arr[childIndex]) {
                int temp=arr[childIndex];
                arr[childIndex]=arr[parentIndex];
                arr[parentIndex]=temp;
                childIndex=parentIndex;
            }
            else {
                break;
            }
        }
        i++;
    }

    int size=n;

    while(size>1) {
        
        int temp=arr[0];
        arr[0]=arr[size-1];
        arr[size-1]=temp;
        size--;

        int parentIndex=0;
        int child1=parentIndex*2+1;
        int child2=parentIndex*2+2;
        int mini;
        while(child1<size) {
            int minIndex = parentIndex;
            if (arr[child1] < arr[minIndex]) {
                minIndex = child1;
            }
            if (arr[child2] < arr[minIndex] && child2 < size) {
                minIndex = child2;
            }
            if (minIndex == parentIndex) {
                break;
            }
            int temporary = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temporary;
            parentIndex = minIndex;

            child1 = parentIndex * 2 + 1;
            child2 = parentIndex * 2 + 2;
        }
    }


}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}
