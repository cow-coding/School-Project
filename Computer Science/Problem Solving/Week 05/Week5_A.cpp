#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        vector<int> freq;
        int N;
        
        cin >> N;
        
        for (int i = 0; i < N; i++) {
            int n;
            
            cin >> n;
            
            freq.push_back(n);
        }
        
        bool find;
        int answer = 0;
        
        for (int i = 1; i < N; i++) {
            find = true;
            
            for (int j = i; j < N; j++) {
                int front_idx = j % i;
                
                if (freq[front_idx] != freq[j]) {
                    find = false;
                    break;
                }
            }
            
            if (find) {
                answer = i;
                break;
            }
        }
        
        if (!find) answer = N;
        
        for (int i = 0; i < answer; i++) {
            cout << freq[i] << " ";
        }
        
        cout << "\n";
    }
}
