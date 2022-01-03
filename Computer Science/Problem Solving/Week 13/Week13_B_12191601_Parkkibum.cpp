#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        int N, M;
        vector<bool> visit;
        vector<int> ans;
        stack<int> stk;
        
        cin >> N >> M;
        
        visit.resize(N, false);
        
        for (int i = 0; i < M; i++) {
            int n;
            
            cin >> n;
            
            stk.push(n);
        }
        
        while (!stk.empty()) {
            int curr = stk.top();
            stk.pop();
            
            if (!visit[curr]) {
                N--;
                visit[curr] = true;
            }
            
            ans.push_back(N);
        }
        
        for (int i = ans.size()-1; i > -1; i--) {
            cout << ans[i] << "\n";
        }
    }
}
