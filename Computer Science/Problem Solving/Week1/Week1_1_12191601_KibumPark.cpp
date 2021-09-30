#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        string str;
        char arr[1010][1010] = {{'\0'}};
        int k;
        int row = 0;
        int col = 0;
        bool dir = true;
        
        cin >> str >> k;
        
        for (int i = 0; i < str.size(); i++) {
            char curr = str[i];
            
            arr[row][col] = curr;
            
            if (dir) {
                if (row == k-1) {
                    dir = false;
                    col++;
                }else row++;
            }else {
                if (row == 0) {
                    dir = true;
                    col++;
                }else row--;
            }
        }
        
        for (int i = 0; i < k; i++) {
            cout << arr[i];
        }
        
        cout << "\n";
    }
}
