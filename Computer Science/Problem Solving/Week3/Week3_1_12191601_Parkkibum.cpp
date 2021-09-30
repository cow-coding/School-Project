#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> map;
vector<string> nodes;
vector<int> ans;

void dfs(int n, int ret) {
    ret += nodes[n-1].size();
    
    ans[n] = ret;
    
    for (int i = 0; i < map[n].size(); i++) {
        int node = map[n][i];
        
        dfs(node, ret+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, N;
    
    cin >> T;
    
    while (T--) {
        
        cin >> N;
        
        map.clear();
        nodes.clear();
        ans.clear();
        ans.resize(N+1);
        map.resize(N+1);
        
        for (int i = 0; i < N-1; i++) {
            int a, b;
            
            cin >> a >> b;
            
            map[a].push_back(b);
        }
        
        for (int i = 0; i < N; i++) {
            string s;
            
            cin >> s;
            
            nodes.push_back(s);
        }
        
        dfs(1, 0);
        
        for (int i = 1; i <= N; i++) {
            cout << ans[i] << "\n";
        }
    }
}
