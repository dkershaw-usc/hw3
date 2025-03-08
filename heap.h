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
  size_t m_;
  std::vector<T> data;
  /// @brief Rearranges data to satisfy PComparator
  /// @param idx index where operation occurred
  void heapify(size_t idx);
  void swap(size_t a, size_t b);
};

// Add implementation of member functions here
//############################################

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{

}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::swap(size_t a, size_t b)
{
  if(a >= size() || b >= size()) return;
  if(empty()) throw std::underflow_error("Heap is empty.");

  T temp = data[a];
  data[a] = data[b];
  data[b] = temp;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(size_t idx)
{
  if(idx >= size()) return;

  for(size_t i = 1; i <= m_; i++)
  {
    if(idx+i >= size()) break;
    // if any children "less than" their parent node
    size_t childIdx = (m_*idx)+i;
    if(PComparator()(data[childIdx], data[idx])){
      // swap 
      swap(idx, childIdx);
      heapify(childIdx);
    }
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  data.push_back(item);
  heapify(data.size()-1);
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

/// @brief returns the top element
/// @tparam T 
/// @tparam PComparator 
/// @return 
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty.");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];
}

/// @brief Removes the top element
/// @tparam T 
/// @tparam PComparator 
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty.");
  }
  swap(0,(size()-1));
  data.pop_back();
  heapify(0);
}



#endif

