#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P; // (value, idx);

bool cmp(P& a, P& b) {
    if (a.first == b.first)
        return a.second < b.second;

    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    
    cin >> T;
    
    while (T--) {
        vector<P> inha;
        vector<P> dragon;
        vector<P> sum;
        int answer = 0;
        bool element[10001] = {false,};
        
        int N;
        
        cin >> N;
        
        for (int i = 0; i < N; i++) {
            ll in, d;
            
            cin >> in >> d;
            
            inha.push_back(P(in, i));
            dragon.push_back(P(d, i));
            sum.push_back(P(d+in, i));
        }
        
        sort(sum.begin(), sum.end(), cmp);
        
        ll inha_sum = 0;
        ll d_sum = 0;
        bool turn = true;
        
        for (int i = 0; i < sum.size(); i++) {
            ll idx = sum[i].second;
            
            if (turn) {
                answer += inha[idx].first;
                turn = false;
            }else {
                answer -= dragon[idx].first;
                turn = true;
            }
        }
        
        cout << answer << "\n";
    }
    
    return 0;
}
