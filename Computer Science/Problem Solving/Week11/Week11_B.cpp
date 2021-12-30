#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> answer;

bool all_same(vector<vector<int>> &map, int r, int c, int size, int val) {
    for (int i = r; i < r + size; i++) {
        for (int j = c; j < c + size; j++) {
            if (map[i][j] != val) return false;
        }
    }
    
    return true;
}

void DC(vector<vector<int>> &map, int r, int c, int size) {
    if (size == 1 || all_same(map, r, c, size, map[r][c])) {
        int curr = map[r][c];
        answer[curr][0]++;
        answer[curr][1] += size * size;
        return;
    }
    
    DC(map, r, c, size/2);
    DC(map, r, c + size/2, size/2);
    DC(map, r + size/2, c, size/2);
    DC(map, r + size/2, c + size/2, size/2);
}

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        int N;
        vector<vector<int>> map;
        answer.clear();
        answer.resize(2, vector<int>(2, 0));
        
        cin >> N;
        
        map.resize(N, vector<int> (N, 0));
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char c;
                cin >> c;
                
                if (c == 'R') map[i][j] = 0;
                else map[i][j] = 1;
            }
        }
        
        DC(map, 0, 0, N);
        
        cout << answer[0][0] << " " << answer[0][1] << " " << answer[1][0] << " " << answer[1][1] << "\n";
    }
}
