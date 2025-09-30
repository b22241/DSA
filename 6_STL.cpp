#include <iostream>
#include <algorithm>  // For sort()
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;
#include <numeric> // Required for accumulate (if used)
#include <iterator> // Required for iterators (though often included via <bits/stdc++.h>)

/// VECTORS
// int main(){
//     vector <int> vec={4,2,3,55,323,2,4,5,26,74,34,53};
//     vector <int> vec2={3, 10};                       // {3, 10} - Two elements
//     vector <int> vec3(10, 5);                       // {5, 5, 5, 5, 5, 5, 5, 5, 5, 5} - Size 10, value 5 (Constructor)
//     vector <int> vec4{vec};                         // Copy constructor
//     // --- 1. ELEMENT ACCESS ---
//     cout << vec[0] << endl;                          // Access element by index (No bounds check)
//     cout << vec.at(0) << endl;                       // Access element by index (Throws exception on out-of-bounds)
//     cout << vec.front() << endl;                     // Access the first element
//     cout << vec.back() << endl;                      // Access the last element
//     // --- 2. BASIC ITERATION (Range-based for loop) ---
//     for(int val : vec){
//         cout << val << " ";
//     }
//     cout << endl;
//     // --- 3. MODIFIERS ---
//     vec.push_back(100);                              // Add element to the end. O(1) amortized
//     vec.pop_back();                                  // Remove element from the end. O(1)
//     vec.erase(vec.begin() + 3);                      // Remove element at index 3. O(N)
//     vec.erase(vec.begin(), vec.end() - 1);           // Remove a range [begin, end-1). O(N)
//     vec.insert(vec.begin() + 1, 10);                 // Insert value 10 at index 1. O(N)
//     vec.clear();                                     // Removes all elements, size becomes 0    
//     // --- 4. CAPACITY ---
//     cout << vec.empty() << endl;                     // Check if vector is empty (returns 0 or 1)
//     cout << vec.size() << endl;                      // Returns the number of elements
//     cout << vec.capacity() << endl;                  // Returns storage allocated (Important for efficiency)
//     vec.resize(20);                                  // Resizes to 20 elements (pads with default value)
//     vec.shrink_to_fit();                             // Reduces capacity to match size (C++11)
//     // --- 5. ITERATORS AND TRAVERSAL ---
//     for(auto it = vec.begin(); it != vec.end(); it++) { // Forward traversal
//         cout << *it << " ";
//     }
//     cout << endl;
//     for(auto it = vec.rbegin(); it != vec.rend(); it++) { // Reverse traversal
//         cout << *it << " ";
//     }
//     cout << endl;
//     // --- 6. ALGORITHMS ---
//     cout << *(max_element(vec.begin(), vec.end())) << endl;  // Find maximum element
//     sort(vec.begin(), vec.end());                             // Sort the vector. O(N log N)
//     cout << binary_search(vec.begin(), vec.end(), 3) << endl; // Search (returns 0 or 1)
//     // --- MISSING IMPORTANT FUNCTIONS ---
//     // a) Total Sum
//     long long sum = accumulate(vec.begin(), vec.end(), 0LL); // Calculates sum of elements. Requires <numeric>
//     cout << "Sum: " << sum << endl;
//     // b) Finding an element
//     auto find_it = find(vec.begin(), vec.end(), 55);         // Finds the first occurrence of 55. O(N)
//     if (find_it != vec.end()) {
//         cout << "Found 55." << endl;
//     }
//     // c) Counting Occurrences
//     int count_val = count(vec.begin(), vec.end(), 2);      // Counts how many times '2' appears. O(N)
//     cout << "Count of 2: " << count_val << endl;
//     // d) Swapping two vectors
//     vec.swap(vec2);                                          // Exchanges contents efficiently. O(1)
//     // e) Checking for sorted range
//     bool sorted = is_sorted(vec.begin(), vec.end());         // Checks if the range is sorted. O(N)
//     // f) Reverse the entire vector
//     reverse(vec.begin(), vec.end());                         // Reverses the order of elements. O(N)
// }

//LIST
// int main(){
//     list<int>l1;                                   // Default constructor (empty list)
//     list<int>l2(5, 100);                           // Constructor: 5 elements, all valued 100
//     list<int>l3 = {1, 2, 3, 4, 5};                 // Initialization with initializer list

//     // --- 1. MODIFIERS (Fast O(1) Operations) ---
//     l1.push_back(1);                               // Add element to the end. O(1)
//     l1.push_front(3);                              // Add element to the beginning. O(1)
//     l1.push_back(4);
//     l1.push_front(5);                              // l1 is now {5, 3, 1, 4}
    
//     l1.pop_back();                                 // Remove element from the end. O(1)
//     l1.pop_front();                                // Remove element from the beginning. O(1)
    
//     // --- 2. ITERATION AND DELETION ---
//     // Note: Iterators are ONLY invalidated for the element being erased.
//     l1.erase(l1.begin());                          // Remove the first element. O(1)
    
//     // Insert requires an iterator to specify the position (e.g., insert at the beginning)
//     l1.insert(l1.begin(), 99);                     // Insert 99 at the beginning. O(1)

//     // --- 3. ELEMENT ACCESS & CAPACITY ---
//     cout << l1.front() << endl;                    // Access the first element. O(1)
//     cout << l1.back() << endl;                     // Access the last element. O(1)
//     cout << l1.size() << endl;                     // Returns the number of elements. O(1)
//     cout << l1.empty() << endl;                    // Check if list is empty (returns 0 or 1)
    
//     l1.clear();                                    // Removes all elements

//     // --- 4. TRAVERSAL (Range-based for loop) ---
//     for(int i : l3){
//         cout << i << " ";
//     }
//     cout << endl;
    
//     // --- 5. LIST-SPECIFIC OPERATIONS (Highly Efficient) ---
//     l3.remove(4);                                  // Removes ALL elements with value 4. O(N)
    
//     l2.sort();                                     // Sorts the list efficiently (list-specific merge sort). O(N log N)
    
//     l2.reverse();                                  // Reverses the order of elements. O(N)

//     l2.unique();                                   // Removes consecutive duplicate elements (requires pre-sorting). O(N)
    
//     l3.splice(l3.end(), l2);                       // Transfers ALL elements from l2 to the end of l3. O(1)
//                                                    // l2 becomes empty; l3 gets l2's content.
// }

//DEQUE
// int main(){
//     deque<int> d1;                                 // Default constructor (empty deque)
//     deque<int> d2 = {2, 436, 3, 6, 785, 34, 10};   // Initialization with initializer list
//     deque<int> d3(5, 99);                          // Constructor: 5 elements, all valued 99

//     // --- 1. MODIFIERS (Fast O(1) Operations at ends) ---
//     d1.push_back(10);                              // Add element to the end. O(1)
//     d1.push_front(20);                             // Add element to the beginning. O(1)
//     d1.emplace_back(30);                           // Constructs element at the end (often slightly faster). O(1)
//     d1.emplace_front(40);                          // Constructs element at the front. O(1)
    
//     d1.pop_back();                                 // Remove element from the end. O(1)  
//     d1.pop_front();                                // Remove element from the beginning. O(1)
    
//     // --- 2. ACCESS (Random Access - O(1)) ---
//     cout << d2[1] << endl;                         // Access element by index (No bounds check). O(1)
//     cout << d2.at(0) << endl;                      // Access element by index (Bounds check). O(1)
//     cout << d2.front() << endl;                    // Access first element. O(1)
//     cout << d2.back() << endl;                     // Access last element. O(1)

//     // --- 3. TRAVERSAL AND ALGORITHMS ---
//     for (int val : d2){
//         cout << val << " ";
//     }
//     cout << endl;

//     // Standard algorithms work just like with vector
//     sort(d2.begin(), d2.end());                    // Sort the deque. O(N log N)
//     cout << *(max_element(d2.begin(), d2.end())) << endl; // Find max element. O(N)

//     // --- 4. CAPACITY AND COMPLEX MODIFIERS ---
//     cout << d2.size() << endl;                     // Returns number of elements. O(1)
//     cout << d2.empty() << endl;                    // Check if deque is empty. O(1)
    
//     // Insert/Erase at the middle is slow (O(N)), unlike the ends
//     d2.erase(d2.begin() + 2);                      // Erase element at index 2. O(N)
//     d2.insert(d2.begin() + 1, 55);                 // Insert 55 at index 1. O(N)
    
//     d2.clear();                                    // Removes all elements.

// }

//PAIR
// int main(){
//     // --- 1. DECLARATION AND INITIALIZATION ---
    
//     // Direct Initialization (C++11/17)
//     pair <string, int> p1 = {"Alice", 25};          // p1 is {"Alice", 25}
    
//     // Aggregation Initialization (Braces)
//     pair <string, int> p2 {"Bob", 30};              // p2 is {"Bob", 30}

//     // Using std::make_pair (Pre-C++11 or explicit style)
//     pair <string, int> p3 = make_pair("Charlie", 40); // p3 is {"Charlie", 40}

//     // Copying another pair
//     pair <string, int> p4 = p1;                     // p4 is {"Alice", 25}

//     // --- 2. NESTED PAIRS (As demonstrated in your snippet) ---
//     pair<int, pair<string, int>> nested_p = {1, {"Warehouse", 3}};
    
//     // --- 3. ACCESSING ELEMENTS ---
    
//     // Using .first and .second (Standard way)
//     cout << "p1.first: " << p1.first << endl;       // Output: Alice
//     cout << "p1.second: " << p1.second << endl;     // Output: 25

//     // Accessing elements of the nested pair:
//     cout << "Nested Outer: " << nested_p.first << endl;       // Output: 1
//     cout << "Nested Inner Key: " << nested_p.second.first << endl; // Output: Warehouse
//     cout << "Nested Inner Value: " << nested_p.second.second << endl; // Output: 3

//     // --- 4. MODIFICATION AND SWAP ---
    
//     p1.first = "David";                             // Directly change the first element
//     p1.second = 50;                                 // Directly change the second element
    
//     p2.swap(p3);                                    // Efficiently swap contents of p2 and p3
//                                                     // p2 is now {"Charlie", 40}, p3 is {"Bob", 30}

//     // --- 5. COMPARISON ---
    
//     pair<int, int> a = {10, 20};
//     pair<int, int> b = {10, 30};
    
//     // Pairs are compared lexicographically (first element, then second element)
//     if (a < b) {                                    // (10 < 10) is False, so checks second: (20 < 30) is True
//         cout << "a is less than b" << endl;
//     }
// }

// int main(){
//     stack<int> s;                               // Default constructor (empty stack)
//     // stack<int> s_copy(s2);                   // Copy constructor
    
//     // --- 1. MODIFIERS ---
//     s.push(1);                                  // Add element (1) to the top. O(1)
//     s.push(4);                                  // Add element (4)
//     s.push(432);                                // Add element (432)
//     s.push(12);                                 // Add element (12)
//     s.push(9);                                  // Add element (9) - This is the current top
    
//     s.pop();                                    // Remove the top element (9). O(1)
//                                                 // New top is 12
    
//     // --- 2. SWAPPING ---
//     stack<int> s2;
//     s2.push(99);
//     s2.swap(s);                                 // Efficiently exchanges the contents of s and s2. O(1)
//                                                 // s now contains {99}; s2 contains {1, 4, 432, 12}
    
//     // --- 3. ACCESS & CAPACITY ---
    
//     // CHECK 1: s is now {99} (from the swap)
//     cout << "Top of s: " << s.top() << endl;    // Access the top element (99). O(1)
    
//     cout << "Size of s: " << s.size() << endl;  // Returns the number of elements (1). O(1)
//     cout << "s is empty: " << s.empty() << endl; // Check if stack is empty (returns 0 or 1). O(1)
    
//     // CHECK 2: s2 is {1, 4, 432, 12}
//     cout << "Top of s2: " << s2.top() << endl;  // Access the top element of s2 (12). O(1)

//     // --- 4. TRAVERSAL/EMPTYING (Crucial Logic) ---
//     // You cannot iterate through a stack directly. You must pop elements to access them.
    
//     cout << "Emptying s2: ";
//     while (!s2.empty()) {
//         cout << s2.top() << " ";                // Access the top element
//         s2.pop();                               // Remove the top element
//     }
//     cout << endl; // Output: 12 432 4 1 (LIFO order)
// }


// Queue   //FIFO  allfunctions are same as stack
// int main() {
    // queue<int> q1;                                // Default constructor (empty queue)
    
    // // --- 1. MODIFIERS ---
    // q1.push(10);                                  // Add element (10) to the back. O(1)
    // q1.push(20);                                  // Add element (20)
    // q1.emplace(30);                               // Constructs element at the back (similar to push). O(1)
    
    // // Current state (Front -> Back): 10, 20, 30
    
    // // --- 2. ACCESS & CAPACITY ---
    // cout << "Front: " << q1.front() << endl;      // Access the front element (10). O(1)
    // cout << "Back: " << q1.back() << endl;        // Access the back element (30). O(1)
    // cout << "Size: " << q1.size() << endl;        // Returns the number of elements (3). O(1)
    
    // q1.pop();                                     // Remove the front element (10). O(1)
    
    // cout << "After pop, front: " << q1.front() << endl; // New front is 20
    // cout << "Is empty? " << (q1.empty() ? "Yes" : "No") << endl; // No (0)

    // // --- 3. SWAPPING ---
    // queue<int> q2;
    // q2.push(999);
    // q1.swap(q2);                                  // Exchanges contents of q1 ({20, 30}) and q2 ({999}). O(1)
    // cout << "After swap, q1 front: " << q1.front() << endl; // 999
    
    // // --- 4. TRAVERSAL/EMPTYING (Crucial Logic) ---
    // // You must repeatedly check, access (front), and remove (pop) elements.
    
    // cout << "Emptying the queue q2 (original content of q1): ";
    // // q2 is now {20, 30}
    // while (!q2.empty()) {
    //     cout << q2.front() << " ";                // Access the front element (20, then 30)
    //     q2.pop();                                 // Remove the front element
    // }
    // cout << endl; // Output: 20 30 (FIFO order)
// }

//Dequeue
//  int main(){
//     deque<int> d;                                 // Default constructor (empty deque)
//     deque<int> d_init = {5, 6, 7};                 // Initialization with initializer list
    
//     // --- 1. FAST END MODIFIERS (O(1)) ---
//     d.push_back(1);                               // Add 1 to the back. d: {1}
//     d.push_back(2);                               // Add 2 to the back. d: {1, 2}
//     d.push_front(0);                              // Add 0 to the front. d: {0, 1, 2}
//     d.push_back(3);                               // Add 3 to the back. d: {0, 1, 2, 3}
    
//     d.pop_front();                                // Remove front element (0). d: {1, 2, 3}
//     d.pop_back();                                 // Remove back element (3). d: {1, 2}

//     // --- 2. ACCESS (Random Access - O(1)) ---
//     cout << "Element at [0]: " << d[0] << endl;   // Access element by index (No bounds check). Output: 1
//     cout << "Element at .at(1): " << d.at(1) << endl; // Access element with bounds check. Output: 2
//     cout << "Front: " << d.front() << endl;      // Access the first element. Output: 1
//     cout << "Back: " << d.back() << endl;        // Access the last element. Output: 2

//     // --- 3. CAPACITY ---
//     cout << "Size: " << d.size() << endl;         // Returns number of elements (2). O(1)
//     cout << "Is Empty: " << d.empty() << endl;    // Check if deque is empty.

//     // --- 4. DELETION (O(N) for range) ---
//     // Re-initialize d for deletion test
//     d = {10, 20, 30, 40, 50};                     
//     d.erase(d.begin());                           // Erase the first element (10). O(1) amortized
//     d.erase(d.begin(), d.begin() + 2);            // Erase a range [20, 30). Removes 20 and 30. O(N)
    
//     // d is now {40, 50}
//     cout << "Size after erase: " << d.size() << endl; // Output: 2

//     // --- 5. TRAVERSAL ---
//     cout << "Final elements: ";
//     for(int i : d){
//         cout << i << " ";
//     }
//     cout << endl; // Output: 40 50 

//     // --- 6. ALGORITHMS ---
//     d.insert(d.begin(), 35);                      // Insert 35 at the start. O(N)
//     sort(d.begin(), d.end());                     // Sort the deque. O(N log N)
    
// }


//priority queue   data is stored in maxheap or minheap format. it's stored in storted order  complexity-O(logn)
// int main(){
    // --- 1. MAX HEAP (Default) ---
    // priority_queue<int> max_q; // Default: std::priority_queue<int, std::vector<int>, std::less<int>>
    
    // // MODIFIERS
    // max_q.push(2);                                 // Insert element. O(log N)
    // max_q.push(4);
    // max_q.push(21);
    // max_q.push(-1);
    
    // // ACCESS & CAPACITY
    // cout << "Max Heap Size: " << max_q.size() << endl; // Returns number of elements (4)
    // cout << "Max Heap Empty: " << max_q.empty() << endl; // Check if empty (0)
    // cout << "Max Heap Top: " << max_q.top() << endl;   // Access the largest element (21). O(1)
    
    // max_q.pop();                                   // Remove the largest element (21). O(log N)
    // cout << "Max Heap New Top: " << max_q.top() << endl; // New top is 4

    // // --- 2. MIN HEAP (To store smallest element at the top) ---
    // // Requires custom template arguments: vector for container, greater for comparison
    // priority_queue<int, vector<int>, greater<int>> min_q; 

    // min_q.push(10);
    // min_q.push(5);
    // min_q.push(15);
    // cout << "Min Heap Top: " << min_q.top() << endl;   // Access the smallest element (5). O(1)

    // // --- 3. TRAVERSAL/EMPTYING (Crucial Logic) ---
    // // Accessing elements requires repeated pop() calls.
    
    // cout << "Emptying Max Heap: ";
    // // Use the original max_q (which now contains: 4, 2, -1)
    // while (!max_q.empty()) {
    //     cout << max_q.top() << " ";                // Access top
    //     max_q.pop();                               // Remove top
    // }
    // cout << endl; // Output: 4 2 -1 (Always prints elements in descending/sorted order)
// }


//map  sort by key values
//time complexity O(logn);
// int main(){
// map<string, int> m;                               // Default constructor (empty map)
//     map<string, int> m_copy = {{"old", 1}, {"recent", 2}}; // Initialization with initializer list

//     // --- 1. INSERTION METHODS (All O(log N)) ---
//     m["tv"] = 50;                                     // 1. Array-style insertion/update (creates if key DNE, updates if key exists)
//     m["laptop"] = 100;
//     m["headphone"] = 20;
//     m["tab"] = 30;
//     m.insert({"camera", 23});                         // 2. Using insert with an initializer list/std::pair
//     m.emplace("camera1", 23);                         // 3. Using emplace (often slightly more efficient for complex types)
    
//     // Attempting to update an existing key:
//     m["laptop"] = 120;                                // Updates laptop's value from 100 to 120

//     // --- 2. ACCESS METHODS ---
    
//     // a) Array Access (Creates key with default value (0) if not found)
//     cout << "Value of 'tab': " << m["tab"] << endl;   // Access value (30). O(log N)
//     cout << "Value of 'new_key': " << m["new_key"] << endl; // Creates "new_key" with value 0!

//     // b) Safe Access (Throws exception if key not found)
//     // cout << m.at("laptop") << endl;                 // Output: 120

//     // --- 3. SEARCH AND CHECK (O(log N)) ---
    
//     // a) Count (Used to check presence, always returns 0 or 1 for std::map)
//     cout << "Is 'tv' present (count): " << m.count("tv") << endl; // Output: 1
    
//     // b) Find (Preferred way to check presence without creating a new key)
//     if(m.find("camera") != m.end()){
//         cout << "Camera found via find()." << endl;
//     }

//     // --- 4. DELETION (O(log N)) ---
//     m.erase("tv");                                    // Erase by key. (Output: 1 if deleted, 0 otherwise)
//     m.erase(m.find("new_key"));                       // Erase by iterator (from find())

//     // --- 5. ITERATION (In Sorted Order) ---
//     cout << "--- Map Contents (Sorted by Key) ---" << endl;
//     for(auto p : m){
//         // p is a std::pair<const string, int>
//         cout << p.first << " -> " << p.second << endl;
//     }
    
//     // --- 6. CAPACITY ---
//     cout << "Size: " << m.size() << endl;             // Returns number of elements
//     m.clear();            
// }

//multimap ===allows duplicate values of a attribute,everything is same as map, b
// int main(){
//     multimap<string,int>m;
//     m.emplace("tv",23);
//     m.emplace("tv",24);
//     m.emplace("tv",22);
//     m.emplace("tv",4345);
//     m.erase("tv");   sari values khali ho jaegi
//       m.erase(m.find("tv"));   phli value hi clear hogi
//     for(auto p:m){
//                 cout<<p.first<<" "<<p.second<<endl;
//             }
        // }

//unordered_map , arranges data in random order
//time complexity O(1);
//search time for ordered map is O(logn) and for unorderd map is O(1),every operation happens in constast time in unordered map
// int main(){
//  unordered_map<string, int> m;                     // Default constructor (empty map)

//     // --- 1. INSERTION METHODS (Average O(1)) ---
    
//     // a) Emplace (Generally preferred for efficiency)
//     m.emplace("tv", 23);                              // Key "tv" is created with value 23
//     m.emplace("tv", 24);                              // This is IGNORED, key must be unique
//     m.emplace("tab", 24);
//     m.emplace("phone", 22);
//     m.emplace("mobile", 4345);
    
//     // b) Insert
//     m.insert({"ram", 20});                            // Using insert with initializer list
    
//     // c) Array-style insertion/update
//     m["shyam"] = 30;
//     m["shiv"] = 40;
//     m["tab"] = 50;                                    // Updates "tab" from 24 to 50

//     // --- 2. ACCESS METHODS (Average O(1)) ---
    
//     // a) Array Access (Creates key with default value (0) if not found)
//     cout << "Value of 'ram': " << m["ram"] << endl;   // Access value (20)
    
//     // b) Safe Access (Throws std::out_of_range if key not found)
//     cout << "Value of 'shiv' via at(): " << m.at("shiv") << endl; // Access value (40)
//     // cout << m.at("missing") << endl;               // Uncommenting this line causes an exception

//     // --- 3. SEARCH AND DELETION (Average O(1)) ---
    
//     // a) Count (Used to check presence, always returns 0 or 1)
//     cout << "Is 'phone' present (count): " << m.count("phone") << endl; // Output: 1
    
//     // b) Deletion
//     m.erase("tv");                                    // Erase by key. (Output: 1 if deleted, 0 otherwise)
//     // m is now missing "tv"

//     // c) Find (Preferred way to check presence without modifying the map)
//     if(m.find("shyam") != m.end()){
//         cout << "shyam found via find()." << endl;
//     }

//     // --- 4. ITERATION ---
//     cout << "--- Map Contents (Unsorted) ---" << endl;
//     for(auto p : m){
//         // Order is determined by the hash function, not by key value
//         cout << p.first << "-" << p.second << endl;
//     }
    
//     // --- 5. CAPACITY ---
//     cout << "Size: " << m.size() << endl;             // Returns number of elements
//     m.clear();                                        // Clears all elements

// }

//set ==>stores only uniques values in sorted order
//unordered_set ==>stores only uniques values in random order
//multiset==> stores duplicate values as well
//time complexity O(logn)
// Stores unique elements in SORTED order (internally uses a Self-Balancing BST).
// Operations (insert, erase, find) take O(log N) time.
int main(){
    // set<int> s;                                   // Default constructor (empty set)
    // set<int> s_init = {10, 20, 30, 40};           // Initialization with initializer list

    // // --- 1. MODIFIERS (O(log N)) ---
    // s.insert(4);                                  // Insert element. Set automatically sorts.
    // s.insert(2);
    // s.insert(3);
    // s.insert(23);
    // s.insert(4);                                  // Duplicate inserts are ignored.
    // // s is now: {2, 3, 4, 23}

    // // --- 2. CHECK AND CAPACITY (O(log N)) ---
    
    // // a) Count (Used to check presence, always returns 0 or 1 for std::set)
    // cout << "Count of 2: " << s.count(2) << endl; // Output: 1 (2 is present)
    // cout << "Count of 5: " << s.count(5) << endl; // Output: 0 (5 is not present)
    
    // cout << "Size: " << s.size() << endl;         // Returns number of elements (4)
    // cout << "Is Empty: " << s.empty() << endl;    // Check if set is empty

    // // --- 3. BOUNDS (O(log N)) ---
    
    // // a) Lower Bound: Returns iterator to the FIRST element NOT LESS than the key.
    // auto lb = s.lower_bound(5);
    // cout << "Lower bound for 5: " << *lb << endl; // Output: 23 (The smallest element >= 5)
    
    // // b) Upper Bound: Returns iterator to the FIRST element STRICTLY GREATER than the key.
    // auto ub = s.upper_bound(3);
    // cout << "Upper bound for 3: " << *ub << endl; // Output: 4 (The smallest element > 3)
    
    // // If lower_bound/upper_bound returns s.end(), the value is not found/not in range.
    // if (s.lower_bound(30) == s.end()) {
    //     cout << "30 not found or is outside the upper range." << endl;
    // }
    
    // // --- 4. TRAVERSAL (Always in Sorted Order) ---
    // cout << "Elements: ";
    // for(int i : s){
    //     cout << i << " ";
    // }
    // cout << endl; // Output: 2 3 4 23 

    // // --- 5. DELETION (O(log N)) ---
    
    // // a) Erase by Value
    // cout << "Erase 2 result: " << s.erase(2) << endl; // Returns 1 (was deleted)
    // cout << "Erase 5 result: " << s.erase(5) << endl; // Returns 0 (not found)
    
    // b) Erase by Range (As demonstrated in your snippet)
    // set<int> range_s = {10, 20, 30, 40, 50};
    // auto first = range_s.find(20);
    // auto last = range_s.find(50); 
    // cout<<*first;
    // range_s.erase(first, last);                     // Deletes [20, 30, 40]
    // range_s is now {10, 50}
    
    // s.clear();                                      // Clears all elements

}

//sorting
// int main(){
    // int arr[] = {2, 143, 53, 2, 1, 5, 6};           // C-style array
    // int n = sizeof(arr) / sizeof(arr[0]);           // Calculate array size

    // // Use a vector for more modern STL practice
    // std::vector<int> vec = {2, 143, 53, 2, 1, 5, 6};
    
    // // Helper function for printing ranges
    // auto print_range = [](const auto& container) {
    //     for (int val : container) {
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    // };

    // // --- 1. REVERSE (O(N)) ---
    // std::reverse(arr, arr + n);                      // Reverse C-style array
    // std::reverse(vec.begin(), vec.end());            // Reverse a vector
    // std::cout << "Reversed Arr: ";
    // print_range(arr); // Output: 6 5 1 2 53 143 2

    // // --- 2. SORT (O(N log N)) ---
    
    // // a) Ascending Order (Default)
    // std::sort(arr, arr + n);                         // Sort C-style array in ascending order
    // std::cout << "Sorted Asc: ";
    // print_range(arr); // Output: 1 2 2 5 6 53 143

    // // b) Descending Order (Using std::greater)
    // std::sort(vec.begin(), vec.end(), std::greater<int>()); // Sort vector in descending order
    // std::cout << "Sorted Desc: ";
    // print_range(vec); // Output: 143 53 6 5 2 2 1

    // // --- 3. FINDING EXTREME VALUES (O(N)) ---
    // std::cout << "Max Element: " << *std::max_element(arr, arr + n) << std::endl; // Max value (143)
    // std::cout << "Min Element: " << *std::min_element(arr, arr + n) << std::endl; // Min value (1)

    // // --- 4. SEARCHING (Requires Sorted Range for Efficiency) ---
    // int target = 53;
    
    // // a) Binary Search (Requires sorted range, returns true/false)
    // bool found = std::binary_search(arr, arr + n, target);
    // std::cout << "Binary Search for " << target << ": " << (found ? "Found" : "Not Found") << std::endl;

    // // b) Lower Bound (Smallest element >= target)
    // auto lb = std::lower_bound(arr, arr + n, 5);
    // std::cout << "Lower Bound (5): " << *lb << std::endl; // Output: 5

    // // c) Upper Bound (Smallest element > target)
    // auto ub = std::upper_bound(arr, arr + n, 5);
    // std::cout << "Upper Bound (5): " << *ub << std::endl; // Output: 6

    // // --- 5. SWAP AND ROTATE ---
    // int x = 10, y = 20;
    // std::swap(x, y);                                 // Swap two variables. O(1)
    
    // // std::rotate(vec.begin(), vec.begin() + 1, vec.end()); // Shifts elements. O(N)

    // // --- 6. UNIQUE & PARTITION ---
    // // Remove consecutive duplicates (requires sort beforehand)
    // auto new_end = std::unique(vec.begin(), vec.end()); // Moves unique elements to front. O(N)
    // vec.erase(new_end, vec.end());                   // Must be followed by erase to resize the container

// }

//next_permutation  next_permutation(vec.begin(),vec.end());
//previouse_permutation    previous_permutation(vec.begin(),vec.end());
//swap   swap(a,b);
//min   *min_element(vec.begin(),vec.end())
//max   *max_element(vec.begin(),vec.end())
//builtin_popcount  cout<<__builtin_popcountll(15);   4(number of bits)