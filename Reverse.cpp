//Reverse Lab
#include <iostream>
//simple vector class with forward and reverse iterators
using namespace std;
//stores dynamic array of integers
class vec {
private:
    int* arr; // pointer to dynamic array
    int arr_size; // current number of elements
    int arr_capacity; // max capacity of array

public:

    // constructors
    vec(int size) {
        arr_size = size;
        arr_capacity = size;
        arr = new int[size];
    }

    int& operator[](int index) {
        return arr[index];
    }

    // iterator moves from beginning to end, forward through the array
    class iterator {
        int* ptr;

    public:
    //sets starting position of the iterator in the array
        iterator(int* p) {
            ptr = p;
        }

        bool operator!=(iterator other) {
            return ptr != other.ptr;
        }

        int& operator*() {
            return *ptr;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ptr++;
            return temp;
        }
    };
//start of vector
    iterator begin() {
        return iterator(arr);
    }
//end of vector, last element
    iterator end() {
        return iterator(arr + arr_size);
    }

    // reverse iterator
    class reverse_iterator {
        int* ptr;

    public:
        reverse_iterator(int* p) {
            ptr = p;
        }
//returns current value
        int& operator*() {
            return *ptr;
        }
// prefix and post fixes
        reverse_iterator operator++() {
            ptr--;
            return *this;
        }
        reverse_iterator operator++(int){
            reverse_iterator temp = *this;
            ptr--;
            return temp;
        }
        bool operator!=(reverse_iterator other) {
            return ptr != other.ptr;
        }
    };

    //start and end of reverse loop
    reverse_iterator rbegin() {
        return reverse_iterator(arr + arr_size - 1);
    }

    reverse_iterator rend() {
        return reverse_iterator(arr - 1);
    }
};
//test and print out the foward and reverse iterators
int main(){
    vec v(5);

    for(int i = 0; i < 5; i++){
        v[i] = i + 1;
    }
    cout << "Forward: ";
    for (vec::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    //reverse iterator test
    cout << "Reverse: ";
    for (vec::reverse_iterator it = v.rbegin(); it != v.rend(); it++){
        cout << *it << " ";
    }
    cout << endl;

   return 0; 
}