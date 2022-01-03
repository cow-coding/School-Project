#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int make_rev(int num) {
    string rnum = to_string(num);
    
    while (rnum.size() < 4) {
        rnum = "0" + rnum;
    }
    
    reverse(rnum.begin(), rnum.end());
    
    return stoi(rnum);
}

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        queue<P> q;
        vector<bool> visit;
        string room;
        int a, b;
        
        cin >> a >> b;
        
        visit.resize(10000);
        
        visit[a] = true;
        q.push(P(a, 0));
        
        while (!q.empty()) {
            vector<int> cand_room;
            int rnum = q.front().first;
            int cnt = q.front().second;
            int rev = make_rev(rnum);
            
            q.pop();
            
            if (rnum == b) {
                cout << cnt << "\n";
                break;
            }
            
            cand_room.push_back(rnum+1);
            cand_room.push_back(rnum-1);
            cand_room.push_back(rev);
            
            for (int i = 0; i < cand_room.size(); i++) {
                int curr = cand_room[i];
                
                if (curr >= 0 && curr < 10000 && !visit[curr]) {
                    visit[curr] = true;
                    q.push(P(curr, cnt+1));
                }
            }
        }
        
    }
}
