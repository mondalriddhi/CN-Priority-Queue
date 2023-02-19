/*  Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. 
Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.

Note : main function is given for your reference which we are using internally to test the class.


Sample Input 1:
1 3 1 4 1 63 1 21 1 9 2 3 1 7 3 4 5 -1
Sample Output 1:
63
63
21
4
false

Sample Input 2:
1 3 1 4 1 63 1 21 1 9 2 3 1 7 2 2 2 3 -1
Sample Output 2:
63
63
21
21
21
21

*/

#include <iostream>
using namespace std;

#include <climits>
#include <vector>
class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int child = pq.size() - 1;
        int pari;
        while(child>0) {
            
            pari=(child-1)/2;
            if(pq[pari]<pq[child]) {
                int temp=pq[pari];
                pq[pari]=pq[child];
                pq[child]=temp;
                
            }
            else {
                break;
            }
            child = pari;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(pq.size()==0) {
            return INT_MIN;
        }
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty()==true) {
            return INT_MIN;
        }
        int rem = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int pari = 0;
        int maxi;
        int child1 = 2 * pari + 1;
        int child2 = 2 * pari + 2;
        while (child1 <= pq.size() - 1) {

          maxi = max(pq[pari], max(pq[child1], pq[child2]));
          if (maxi == pq[child1]) {
            int temp = pq[pari];
            pq[pari] = maxi;
            pq[child1] = temp;
            pari = child1;
          } 
          else if (maxi == pq[child2]) {
            int temp = pq[pari];
            pq[pari] = maxi;
            pq[child2] = temp;
            pari = child2;
          }
            else {
            break;
          }

          child1 = 2 * pari + 1;
          child2 = 2 * pari + 2;
        }
        return rem;
    }

    

    int getSize() { 
        // Implement the getSize() function here
        if(pq.size()==0) {
            return 0;
        }
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        if(pq.size()==0) {
            return true;
        }
        return false;
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
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
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
