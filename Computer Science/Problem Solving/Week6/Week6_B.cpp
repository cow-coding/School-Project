#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P;
vector <vector<bool> > map;
vector <vector<bool> > visit;

int main() {
    const int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    int T;
    
    cin >> T;
    
    while (T--) {
        
        int N;
        int answer = 0;
        int inhaX, inhaY;
        int safeX, safeY;
        int knightX, knightY;
        int gunX, gunY;
        
        cin >> N;
        
        map.clear();
        visit.clear();
        map.resize(N+10, vector<bool>(N+1, true));
        visit.resize(N+10, vector<bool>(N+1, false));
        
        cin >> inhaX >> inhaY >> safeX >> safeY;
        cin >> knightX >> knightY >> gunX >> gunY;
        
        for (int i = 0; i < 8; i++) {
            for (int k = 1; k <= N; k++) {
                int nx = gunX + (dir[i][0] * k);
                int ny = gunY + (dir[i][1] * k);
                
                if (nx == knightX && ny == knightY) break;
                if (nx > 0 && nx <= N && ny > 0 && ny <= N) map[nx][ny] = false;
            }
        }
        
        for (int i = 0; i < 8; i++) {
            int nx = knightX + dir[i][0];
            int ny = knightY + dir[i][1];
            
            if (nx > 0 && nx <= N && ny > 0 && ny <= N) map[nx][ny] = false;
        }
        
        queue< pair<P, int> > q;
        
        q.push(make_pair(P(inhaX, inhaY), 0));
        visit[inhaX][inhaY] = true;
        
        while (!q.empty()) {
            int cx = q.front().first.first;
            int cy = q.front().first.second;
            int dist = q.front().second;
            
            q.pop();
            
            if (cx == safeX && cy == safeY) {
                answer = dist;
                break;
            }
            
            for (int i = 0; i < 8; i++) {
                int nx = cx + dir[i][0];
                int ny = cy + dir[i][1];
                
                if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
                    if (map[nx][ny] && !visit[nx][ny]) {
                        visit[nx][ny] = true;
                        q.push(make_pair(P(nx, ny), dist+1));
                    }
                }
            }
        }
        
        cout << answer << "\n";
    }
    
}
