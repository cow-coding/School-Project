#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > map;
const int dir[8][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void map_checker(int n, int r, int c, int block) {
    // row left check
    int block_count = 0;
    int find = false;
    
    for (int i = c-1; i >= 0; i--) {
        if (map[r][i] == -1 * block) {
            block_count++;
        }else if (map[r][i] == block) {
            find = true;
            break;
        }else {
            // 0
            block_count = 0;
            find = false;
            break;
        }
    }
    
    if (find) {
        for (int i = c-1; i >= 0; i--) {
            if (block_count == 0) break;
            
            map[r][i] = block;
            block_count--;
        }
    }
    
    
    // row right check
    for (int i = c+1; i < n; i++) {
        if (map[r][i] == -1 * block) {
            block_count++;
        }else if (map[r][i] == block) {
            find = true;
            break;
        }else {
            // 0
            block_count = 0;
            find = false;
            break;
        }
    }
    
    if (find) {
        for (int i = c+1; i < n; i++) {
            if (block_count == 0) break;
            
            map[r][i] = block;
            block_count--;
        }
    }
    
    // up check
    for (int i = r-1; i >= 0 ; i--) {
        if (map[i][c] == -1 * block) {
            block_count++;
        }else if (map[i][c] == block) {
            find = true;
            break;
        }else {
            block_count = 0;
            find = false;
            break;
        }
    }
    
    if (find) {
        for (int i = r-1; i >= 0; i--) {
            if (block_count == 0) break;
            
            map[i][c] = block;
            block_count--;
        }
    }
    
    // down check
    for (int i = r+1; i < n ; i++) {
        if (map[i][c] == -1 * block) {
            block_count++;
        }else if (map[i][c] == block) {
            find = true;
            break;
        }else {
            block_count = 0;
            find = false;
            break;
        }
    }
    
    if (find) {
        for (int i = r+1; i < n; i++) {
            if (block_count == 0) break;
            
            map[i][c] = block;
            block_count--;
        }
    }
    
    // diagonal check
    for (int i = 4; i < 8; i++) {
        for (int j = 1; j < n+1; j++) {
            int nr = r + dir[i][0] * j;
            int nc = c + dir[i][1] * j;
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                if (map[nr][nc] == -1 * block) {
                    block_count++;
                }else if (map[nr][nc] == block) {
                    find = true;
                    break;
                }else {
                    block_count = 0;
                    find = false;
                    break;
                }
            }
        }
        
        if (find) {
            for (int j = 1; j < n+1; j++) {
                int nr = r + dir[i][0] * j;
                int nc = c + dir[i][1] * j;
                
                if (block_count == 0) break;
                
                map[nr][nc] = block;
                block_count--;
            }
        }
    }
}

bool can_position(int r, int c, int n, int block) {
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < 8; i++) {
            int nr = r + dir[i][0] * k;
            int nc = c + dir[i][1] * k;
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                if (map[nr][nc] == -1 * block) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        
        int n, Q;
        int turn = 1; // 1 : black (inha) , -1: white
        int cnt = 0;
        
        cin >> n >> Q;
        
        map.clear();
        map.resize(n+10, vector<int>(n+10, 0));
        
        while (cnt < Q) {
            int r, c;
            
            cin >> r >> c;
            r--;c--;
            
            if (cnt == 0) {
                map[r][c] = turn;
                cnt++;
                continue;
            }
            
            if (can_position(r, c, n, turn)) {
                if (map[r][c] == 0) {
                    map[r][c] = turn;
                    
                    map_checker(n, r, c, turn);
                    
                    turn *= -1;
                }
            }else {
                turn *= -1;
            }
            
            cnt++;
        }
        
        int black_count = 0;
        int white_count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 1) {
                    black_count++;
                }else if (map[i][j] == -1) {
                    white_count++;
                }
            }
        }
        
        if (black_count > white_count) cout << 2 << "\n";
        else if (black_count == white_count) cout << 0 << "\n";
        else cout << 1 <<"\n";
    }
}
