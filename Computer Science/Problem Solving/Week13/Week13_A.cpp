#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> P;
int dir[3][2] = {{1, 0}, {0, 1}, {1, 1}};

int main() {
    int N, M;
    vector<vector<char>> map;
    vector<vector<P>> start_positions(26);
    
    cin >> N >> M;
    
    map.resize(N, vector<char> (N));
    
    for (int i = 0; i < N; i++) {
        string word;
        
        cin >> word;
        
        for (int j = 0; j < word.size(); j++) {
            char curr = word[j];
            map[i][j] = curr;
            
            start_positions[curr-'A'].push_back(P(i, j));
        }
    }
    
    for (int i = 0; i < M; i++) {
        string word;
        
        cin >> word;
        
        int start = word[0]-'A';
        int wordSize = word.size();
        bool find = false;
        
        for (int j = 0; j < start_positions[start].size(); j++) {
            find = false;
            int cr = start_positions[start][j].first;
            int cc = start_positions[start][j].second;
            
            for (int d = 0; d < 3; d++) {
                find = false;
                int er = cr + dir[d][0] * (wordSize-1);
                int ec = cc + dir[d][1] * (wordSize-1);
                
                if (er < 0 || er > N-1 || ec < 0 || ec > N-1) continue;
                
                if (map[cr][cc] == word[0] && map[er][ec] == word[wordSize-1]) {
                    find = true;
                    int l = 1;
                    int r = wordSize-2;
                    
                    while (l <= r) {
                        int lr = cr + dir[d][0] * l;
                        int lc = cr + dir[d][1] * l;
                        int rr = cr + dir[d][0] * r;
                        int rc = cr + dir[d][1] * r;
                        
                        if (map[lr][lc] != word[l] || map[rr][rc] != word[r]) {
                            find = false;
                            break;
                        }
                        l++;
                        r--;
                    }
                }
                
                if (find) break;
            }
            if (find) break;
        }
        
        if (find) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}
