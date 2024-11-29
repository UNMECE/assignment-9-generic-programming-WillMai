#include <iostream>
#include <stdexcept>
#include <limits>

template <typename T>
class DynamicArray {
private:
    T* elements;        // Pointer to the dynamically allocated array
    int currentSize;    // Current number of elements in the array

public:
    // Constructor
    DynamicArray() : elements(nullptr), currentSize(0) {}

    // Destructor
    ~DynamicArray() {
        delete[] elements;
    }

    // Append a new element to the array
    void append(T value) {
        T* newArray = new T[currentSize + 1];
        for (int i = 0; i < currentSize; ++i) {
            newArray[i] = elements[i];
        }
        newArray[currentSize] = value;
        delete[] elements;
        elements = newArray;
        ++currentSize;
    }

    // Access an element at a specific position
    T get(int position) const {
        if (position < 0 || position >= currentSize) {
            throw std::out_of_range("Index is out of bounds.");
        }
        return elements[position];
    }

    // Return the number of elements in the array
    int length() const {
        return currentSize;
    }

    // Compute the total sum of the elements
    T total() const {
        T result = 0;
        for (int i = 0; i < currentSize; ++i) {
            result += elements[i];
        }
        return result;
    }

    // Find the largest element
    T largest() const {
        if (currentSize == 0) {
            throw std::runtime_error("Array is empty.");
        }
        T maxElement = std::numeric_limits<T>::lowest();
        for (int i = 0; i < currentSize; ++i) {
            if (elements[i] > maxElement) {
                maxElement = elements[i];
            }
        }
        return maxElement;
    }

    // Find the smallest element
    T smallest() const {
        if (currentSize == 0) {
            throw std::runtime_error("Array is empty.");
        }
        T minElement = std::numeric_limits<T>::max();
        for (int i = 0; i < currentSize; ++i) {
            if (elements[i] < minElement) {
                minElement = elements[i];
            }
        }
        return minElement;
    }

    // Extract a portion of the array
    T* subarray(int start, int end) const {
        if (start < 0 || end >= currentSize || start > end) {
            throw std::out_of_range("Invalid range for subarray.");
        }
        int subSize = end - start + 1;
        T* resultArray = new T[subSize];
        for (int i = 0; i < subSize; ++i) {
            resultArray[i] = elements[start + i];
        }
        return resultArray;
    }
};

int main() {
    DynamicArray<int> intList;

    // Add elements to the array
    intList.append(11);
    intList.append(2);
    intList.append(4);
    intList.append(21);
    intList.append(10700);

    // Display the size of the array
    std::cout << "Size of array: " << intList.length() << std::endl;

    // Display the sum of the elements
    std::cout << "Sum of array: " << intList.total() << std::endl;

    // Display the maximum and minimum values
    std::cout << "Maximum value: " << intList.largest() << std::endl;
    std::cout << "Minimum value: " << intList.smallest() << std::endl;

    // Access an element at a specific index
    std::cout << "Element at index 2: " << intList.get(2) << std::endl;

    // Get a subarray and display its contents
    int* sliced = intList.subarray(2, 4);
    std::cout << "Sliced array: ";
    for (int i = 0; i < 3; ++i) { // Subarray has 3 elements
        std::cout << sliced[i] << " ";
    }
    std::cout << std::endl;

    // Free memory allocated for the subarray
    delete[] sliced;

    return 0;
}
