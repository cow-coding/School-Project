#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> alphabets(26, 0);
vector<vector<string>> words(101);
vector<int> score_list;
bool arr[101] = {false,};
int answer = -1;

// 특정 단어를 넣고 DFS, 빼고 DFS 모두 체크

void DFS(vector<int> &alphabet_status, int curr_score_idx, int curr_idx, int cnt) {
    if (curr_score_idx >= score_list.size()) {
        // score test
        answer = max(answer, cnt);
        return;
    }
    
    vector<int> curr_alphabet = alphabet_status;
    vector<int> prev_alphabet = curr_alphabet;
    
    int curr_score = score_list[curr_score_idx];
    
    if (curr_idx < words[curr_score].size()) {
        string curr = words[curr_score][curr_idx];
        bool can = true;
        
        for (int i = 0; i < curr.size(); i++) {
            if (curr_alphabet[curr[i]-'a']-1 < 0) {
                can = false;
                break;
            }
            
            curr_alphabet[curr[i]-'a']--;
        }
        
        if (can) {
            DFS(curr_alphabet, curr_score_idx, curr_idx+1, cnt + curr_score);
            curr_alphabet = prev_alphabet;
            DFS(curr_alphabet, curr_score_idx, curr_idx+1, cnt);
        }else {
            curr_alphabet = prev_alphabet;
            DFS(curr_alphabet, curr_score_idx, curr_idx+1, cnt);
        }
    }else {
        DFS(alphabet_status, curr_score_idx+1, 0, cnt);
    }
}

bool cmp(const string &str1, const string &str2) {
    return str1.size() < str2.size();
}

int main() {
    int n;
    
    for (int i = 0; i < 26; i++) {
        cin >> alphabets[i];
    }
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string str;
        int score;
        
        cin >> str >> score;
        
        words[score].push_back(str);
        
        if (!arr[score]) {
            score_list.push_back(score);
            arr[score] = true;
        }
    }
    
    for (int i = 0; i < score_list.size(); i++) {
        sort(words[score_list[i]].begin(), words[score_list[i]].end(), cmp);
    }
    
    sort(score_list.begin(), score_list.end(), greater<>());
    
    DFS(alphabets, 0, 0, 0);
    
    cout << answer << "\n";
}
