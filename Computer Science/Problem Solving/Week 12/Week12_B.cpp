#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct house {
    int score;
    int dist;
    
    house(int s, int d) {
        score = s;
        dist = d;
    }
};

bool operator > (const house &h1, const house &h2) {
    return h1.dist > h2.dist;
}

typedef pair<int, int> P;

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        int N;
        vector<P> vec;
        int max_rating = -1;
        
        cin >> N;
        
        for (int i = 0; i < N; i++) {
            int d, s;
            
            cin >> s >> d;
            
            vec.push_back(P(d, s));
        }
        
        sort(vec.begin(), vec.end());
        
        int answer = 0;
        
        for (int i = 0; i < vec.size(); i++) {
            if (max_rating < vec[i].second) {
                max_rating = vec[i].second;
                answer++;
            }
        }
        
        cout << answer << "\n";
    }
}
