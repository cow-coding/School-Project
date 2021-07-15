#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum direction { MIN = 1, MAX = -1 };

class Heap {
private:
    vector<int> v;
    int heap_size;
    int root_index;
    int direction;
    
public:
    Heap(int direction) {
        v.push_back(-1);
        this->heap_size = 0;
        this->root_index = 1;
        this->direction = direction;
    }
    
    void swap(int idx1, int idx2) {
        int tmp = v[idx1];
        v[idx1] = v[idx2];
        v[idx2] = tmp;
    }
    
    void upHeap(int idx) {
        idx *= direction;
       
            while (v[idx/2] > v[idx]) {
                swap(idx/2, idx);
                upHeap(idx/2);
            }
        
    }
    
    void downHeap(int idx) {
        idx *= direction;
        int right = 2 * idx + 1;
        int left = 2 * idx;
        int small = right;
        
            if (right <= heap_size) {
                if (v[left] <= v[right]) {
                    small = left;
                }
            }else if(left <= heap_size) {
                small = left;
            }else {
                return;
            }
            
            if (v[small] < v[idx]) {
                swap(small, idx);
                downHeap(small);
            }
        
    }
    
    void insert(int e) {
        v.push_back(e);
        heap_size++;
        
        upHeap(heap_size);
    }
    
    int pop() {
        if (empty()) {
            return -1;
        }
        
        int tmp = v[heap_size]; // last node
        int ret = v[root_index];
        
        v.erase(v.begin() + heap_size);
        v[root_index] = tmp;
        heap_size--;
        downHeap(root_index);
        
        return ret;
    }
    
    int top() {
        if (empty()) {
            return -1;
        }
        
        return v[root_index];
    }
    
    int size() {
        return heap_size;
    }
    
    bool empty() {
        return heap_size == 0;
    }
    
    void print() {
        if (empty()) {
            cout << -1 << "\n";
        }else{
            for (int i = 1; i < heap_size + 1; i++) {
                cout << v[i] << " ";
            }
            cout << "\n";
        }
    }
    
    int at(int idx) {
        return v[idx];
    }
    
};

int main() {
    int T;
    string cmd;
    vector<int> hsort;
    Heap h(MIN);
    
    cin >> T;
    
    while (T--) {
        int n, p;
        hsort.push_back(-1);
        cin >> n >> p;
        
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            h.insert(x);
        }
        
        //h.print();
        cout << h.at(p) << "\n";
        
        int  s = h.size();
        for (int i = 0; i <= s; i++) {
            int d = h.pop();
            
            hsort.push_back(d);
        }
        
        /*
        for (int i = 1; i <= hsort.size(); i++) {
            cout << hsort[i] << " ";
        }
        cout << "\n";
        */
        cout << hsort[p] << "\n";
        
        hsort.clear();
    }
}
