#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int m;
  PComparator comp;

  void heapifyUp(size_t child) {
      while (child > 0) {
          size_t parent = (child - 1) / m;
          if (comp(data[child], data[parent])) {
              std::swap(data[child], data[parent]);
              child = parent;
          } else {
              break; // iff the current child is greater than the parent, then heap is correct
          }
      }
  }


  void heapifyDown(size_t parent) {
    while (true) {
        size_t child = m * parent + 1;
        if (child >= data.size()) break; //parent has no children, break

        // find the highest priority child
        size_t priority = child;
        for (size_t i = 1; i < m && child + i < data.size(); ++i) {
            if (comp(data[child + i], data[priority])) {
                priority = child + i;
            }
        }

        // Swap if the highest priority child has higher priority than the parent
        if (comp(data[priority], data[parent])) {
            std::swap(data[parent], data[priority]);
            parent = priority; // Update parent to continue heapifying down
        } else {
            break; // Correct heap property achieved
        }
    }
}


};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int ary, PComparator c) : m(ary), comp(c)
{

}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {

}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
      throw std::underflow_error("Empty heap.");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data.front();


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");
  }

  data[0] = data.back();
  data.pop_back();
  if(!empty()) {
    heapifyDown(0);
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  data.push_back(item);
  heapifyUp(data.size()-1);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return data.empty();
}


template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return data.size();
}


#endif

