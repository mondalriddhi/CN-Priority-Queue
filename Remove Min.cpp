/*  Implement the function RemoveMin for the min priority queue class.
For a minimum priority queue, write the function for removing the minimum element present. 
Remove and return the minimum element.
Note : main function is given for your reference which we are using internally to test the code.
Sample Input 1:
1 3 1 4 1 63 1 21 1 9 2 3 1 7 2 3 2 3 3 -1
Sample Output 1:
3
3
4
4
7
7
9
Sample Input 2:
1 3 1 4 1 63 1 21 1 9 2 3 1 7 2 2 2 3 3 3 -1
Sample Output 2:
3
3
4
4
4
4
7
9


*/

#include <iostream>
#include <climits>
using namespace std;

#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
                childIndex = parentIndex;

            } else {
                break;
            }

        }
    }

    int removeMin() {
        // Write your code here
        if(pq.size()==0) {
            return -1;
        }
        int rem=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();

        int pari=0;
        int mini;
        int child1 = 2 * pari + 1;
        int child2 = 2 * pari + 2;
        while(child1<=pq.size()-1) {
        
            mini=min(pq[pari], min(pq[child1], pq[child2]));
            if(mini==pq[child1]) {
                int temp=pq[pari];
                pq[pari]=mini;
                pq[child1]=temp;
                pari=child1;
            }
            else if (mini==pq[child2]) {
                int temp = pq[pari];
                pq[pari] = mini;
                pq[child2] = temp;
                pari=child2;
            }
            else {
                break;
            }

            child1 = 2 * pari + 1;
            child2 = 2 * pari + 2;
        }
        return rem;
    }
};


int main() {
    PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}


