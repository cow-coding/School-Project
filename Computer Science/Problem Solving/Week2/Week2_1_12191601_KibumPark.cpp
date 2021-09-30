#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    
    cin >> T;
    
    while (T--) {
        int N, M;
        vector<string> prof_list;
        
        cin >> N >> M;
        
        for (int i = 0; i < M; i++) {
            string word;
            
            cin >> word;
            
            prof_list.push_back(word);
        }
        
        vector<queue<string>> word_list;
        
        word_list.resize(N);
        
        for (int i = 0; i < N; i++) {
            int word_num;
            
            cin >> word_num;
            
            for (int j = 0; j < word_num; j++) {
                string word;
                
                cin >> word;
                
                word_list[i].push(word);
            }
        }
        
        bool is_not_exist = false;
        
        for (int i = 0; i < prof_list.size(); i++) {
            string curr = prof_list[i];
            
            
            for (int j = 0; j < N; j++) {
                if (word_list[j].front() == curr) {
                    word_list[j].pop();
                    is_not_exist = false;
                    break;
                }
                
                is_not_exist = true;
            }

            if (is_not_exist) {
                cout << 0 << "\n";
                break;
            }
        }
        
        if (!is_not_exist) {
            cout << 1 << "\n";
        }
    }
    
    return 0;
}

/*
3
3 7
use binary search to solve the problem
4 use search solve study
3 binary the problem
4 to ordered array hard
3 6
ordered array to use binary search
4 use search solve study
3 binary the problem
4 to ordered array hard
3 6
ordered array to use binary search
5 to use search solve study
3 binary the problem
3 ordered array ha
 */
