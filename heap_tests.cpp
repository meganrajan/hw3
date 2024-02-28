#include "heap.h"
#include <iostream>
#include <string>
#include <functional>

int main() {
    // Create a min-heap for integers
    Heap<int, std::less<int>> minHeap;
    minHeap.push(50);
    std::cout<<"here"<<std::endl;
    minHeap.push(20);
    minHeap.push(70);
    minHeap.push(10);
    
    std::cout << "Min-Heap (integers): ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << "\n";



}