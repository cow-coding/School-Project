#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

vector<P> map[2010];
bool visit[2010];

int diameter = -1;
int farNode = -1;

void DFS(int curr, int cost) {
    if (visit[curr]) return;
    
    visit[curr] = true;
    
    if (diameter < cost) {
        farNode = curr;
        diameter = cost;
    }
    
    for (int i = 0; i < map[curr].size(); i++) {
        int next = map[curr][i].first;
        int c = map[curr][i].second;
        
        DFS(next, cost+c);
    }
}

void init(int n) {
    for (int i = 0; i < n+1; i++) {
        map[i].clear();
    }
}

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        int n;
        diameter = -1;
        farNode = -1;
        
        cin >> n;
        
        init(n);
        
        for (int i = 0; i < n-1; i++) {
            int s, e, c;
            
            cin >> s >> e >> c;
            
            map[s].push_back(P(e, c));
            map[e].push_back(P(s, c));
        }
        
        fill(visit, visit+n+1, false);
        DFS(1, 0);
        
        fill(visit, visit+n+1, false);
        diameter = 0;
        
        DFS(farNode, 0);
        
        cout << diameter << "\n";
    }
}
