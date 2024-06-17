#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size = 0;

    void insert(int val){
        size++;
        arr[size] = val;
        int idx = size;
        int temp = size;
        while(idx  > 1){
            temp = idx;
            idx = idx / 2;
            if (arr[idx]<arr[temp]){
                swap(arr[idx], arr[temp]);
            }else{
                return ;
            }
        }
    }

    void print(){
        int idx = 1;
        for(int idx = 1; idx <= size; idx++){
            cout << arr[idx] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap(){
        if (size == 0){
            cout << "Heap is Empty" << endl;
        }
        swap(arr[1], arr[size]);
        size--;
        int i = 1;
        while(i < size){
            int left = 2*i;
            int right = 2*+1;

            if (left < size && arr[left] > arr[i]){
                swap(arr[left], arr[i]);
                i = left;
            }else if (right < size && arr[right] > arr[i]){
                swap(arr[right], arr[i]);
                i = right;
            }else{
                return ;
            }

        }

    }

    void sort(){
        int temp = size;
        while(size >= 0){
            deleteFromHeap();
        }
        size = temp;
        print();
    }
};

 void heapify(int *arr[],int n, int i ){
        int left = i * 2+1;
        int largest = i;
        int right = i * 2 + 2;
    
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest]){
            largest = right;
        }else{
    
        }
    
        if (largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }



int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    // h.sort();


    int arr[6] = {-1, 54, 55, 53, 52, 50};
    int n = 5;
        for(int i = n/2-1; i >= 0; i--){
            heapify(arr, n, i);
        }
    cout << "prrinting the array" << endl;

    int idx = 1;
        for(int idx = 1; idx <= n; idx++){
            cout << arr[idx] << " ";
        }
        cout << endl;


    return 0;
}