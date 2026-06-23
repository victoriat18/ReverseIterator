//Reverse Lab

#include <iostream>

using namespace std;
class vec {
    private:
    int* arr;
    int arr_size;
    int arr_capacity;

    public:
    iterator(int* p){
        ptr = p;
    }
    //check if they are at the same place
    bool operator ==(iterator other){
        return ptr == other.ptr;
    }
    //check if they are not equal
    bool operator!=(iterator other){
        return ptr != other.ptr;
    }
    //get value at current position
    int& operator*(){
        return *ptr;
    }
    //move forward
    iterator operator++(int){
        return iterator(ptr++);
    }
    //start of vector
    iterator begin(){
        return iterator(arr);
    }
    //end of vector, one past last element
    iterator end(){
        return iterator(arr + arr_size);
    }
    //iterator that moves backwards through the vector
    class reverse_iterator {
        int* ptr;
        public:
        reverse_iterator(int* p){
            ptr = p;
        }
        int& operator*(){
            return *ptr;
        }
        //move backward
        reverse_iterator operator++(){
            ptr--;
            return temp;
        }
        //compare positions
        bool operator !=(reverse_iterator other){
            return ptr != other.ptr;
        }
        bool operator==(reverse_iterator other){
            return ptr == other.ptr;
        }
    };
    reverse_iterator rbegin(){
        return reverse_iterator(arr + arr_size - 1);
    }
    reverse_iterator rend(){
        return reverse_iterator(arr - 1);
    }


}
int main(){
    vec v = vec(5);
    
    for (int i = 0; i < 5; i++){
        v[i] = i + 1;
    }
    //Normal iterator test
    cout << "Forward: ";
    for (vec::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    //reverse iterator test
    cout << "Reverse: ";
    for(vec::reverse_iterator it = v.rbegin(); it !=v.rend(); it++){
        cout << *it << " ";
    }
    cout << endl;


    return 0;

}