#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector< vector<int> > map;
vector<int> answer;

void DFS(int curr, int len, const vector<int> &vec) {
    int ret = len + vec[curr];
    answer[curr] = ret;
    
    for (int i = 0; i < map[curr].size(); i++) {
        int next = map[curr][i];
        
        DFS(next, ret+1, vec);
    }
}

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        int N;
        vector<int> directories;
        
        cin >> N;
        
        map.clear();
        answer.clear();
        map.resize(N);
        answer.resize(N);
        
        for (int i = 0; i < N-1; i++) {
            int s, e;
            
            cin >> s >> e;
            s--; e--;
            
            map[s].push_back(e);
        }
        
        for (int i = 0; i < N; i++) {
            string dir;
            
            cin >> dir;
            
            directories.push_back(dir.size());
        }
        
        DFS(0, 0, directories);
        
        for (int i = 0; i < N; i++) {
            cout << answer[i] << "\n";
        }
    }
}
