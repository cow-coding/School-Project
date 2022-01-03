#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

typedef pair<int, int> P;
int dir[2][2] = {{1, 0}, {1, 1}};

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        int N;
        queue<P> q;
        vector<vector<int>> vec;
        vector<vector<int>> dp;
        
        cin >> N;
        
        vec.resize(N, vector<int>(N, 0));
        dp.resize(N, vector<int>(N, 987654321));
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i+1; j++) {
                cin >> vec[i][j];
            }
        }
        
        dp[0][0] = vec[0][0];
        q.push(P(0, 0));
        
        while (!q.empty()) {
            int cr = q.front().first;
            int cc = q.front().second;
            
            q.pop();
            
            for (int i = cc; i <= cc+1; i++) {
                int nr = cr+1;
                int nc = i;
                
                if (nr < N && nc <= cc+1) {
                    if (dp[nr][nc] > dp[cr][cc] + vec[nr][nc]) {
                        dp[nr][nc] = dp[cr][cc] + vec[nr][nc];
                        q.push(P(nr, nc));
                    }
                }
            }
        }
        
        int answer = 987654321;
        
        for (int i = 0; i < N; i++) {
            answer = min(answer, dp[N-1][i]);
        }
        
        cout << answer << "\n";
    }
}
