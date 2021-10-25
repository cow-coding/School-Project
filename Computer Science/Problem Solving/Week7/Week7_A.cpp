#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vec;
bool visit[101];

int DFS(int node) {
    int ret = 0;
    visit[node] = true;
    
    for (auto n : vec[node]) {
        if (!visit[n]) {
            ret += DFS(n);
            ret++;
        }
    }
    
    return ret;
}

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        int N, M;
        
        cin >> N >> M;
        
        vec.clear();
        vec.resize(N);
        
        for (int i = 0; i < M; i++) {
            int a, b;
            
            cin >> a >> b;
            
            a--; b--;
            
            vec[a].push_back(b);
        }
        
        for (int i = 0; i < N; i++) {
            fill(visit, visit+N+1, false);
            
            cout << DFS(i) << " ";
        }
        
        cout << "\n";
    }
}
