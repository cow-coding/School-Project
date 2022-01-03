#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        int N;
        vector<int> index;
        vector<int> LIS;
        
        cin >> N;
        
        for (int i = 0; i < N; i++) {
            int curr;
            
            cin >> curr;
            
            if (LIS.size() == 0) {
                LIS.push_back(curr);
                continue;
            }
            
            int pos = lower_bound(LIS.begin(), LIS.end(), curr) - LIS.begin();
            
            if (LIS[LIS.size()-1] < curr) {
                LIS.push_back(curr);
            }else {
                LIS[pos] = curr;
            }
        }
        
        cout << LIS.size() << "\n";
    }
}
