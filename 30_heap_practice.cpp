#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(){
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    // Extract elements (largest first)
    cout << "Max Heap: ";
    while (!pq.empty()) {
        cout << pq.top() << " "; // access largest
        pq.pop();
    }
    cout << endl;
}