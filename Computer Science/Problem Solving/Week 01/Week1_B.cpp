#include <iostream>
#include <stack>
#include <utility>
using namespace std;

typedef pair<int, int> P;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    const int MAX = -987654321;
    const int MIN = 987654321;
    
    int T;
    
    cin >> T;
    
    while (T--) {
        int N;
        int cmd;
        int max = MAX;
        int min = MIN;
        stack<int> blocks;
        stack<int> min_info;
        stack<int> max_info;
        
        cin >> N;
        
        for (int i = 0; i < N; i++) {
            cin >> cmd;
            
            if (cmd == 1) {
                int block;
                
                cin >> block;
                
                if (block >= max) {
                    max = block;
                    max_info.push(block);
                }
                
                if (block <= min) {
                    min = block;
                    min_info.push(block);
                }
                
                blocks.push(block);
                
                cout << min << " " << max << "\n";
                
            }else if (cmd == 2) {
                
                if (!blocks.empty()) {
                    int curr = blocks.top();
                    
                    if (curr == max_info.top()) {
                        max_info.pop();
                        
                        if (!max_info.empty()) max = max_info.top();
                        else max = MAX;
                    }
                    
                    if (curr == min_info.top()) {
                        min_info.pop();
                        
                        if (!min_info.empty()) min = min_info.top();
                        else min = MIN;
                    }
                    
                    blocks.pop();
                }
            }
        }
    }
}
