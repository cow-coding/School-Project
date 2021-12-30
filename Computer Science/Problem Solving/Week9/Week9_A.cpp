#include <iostream>
using namespace std;

typedef long long ll;
ll X;
ll N;
ll M;

ll my_pow(ll x, ll y) {
    if (!y) return 1;
    if (y%2) return (x * my_pow(x, y-1)) % M;
    return my_pow((x * x) % M, y / 2) % M;
}

ll solution(ll a, ll r, ll size) {
    if (size == 1) return (X * my_pow(a, r)) % M;
    if (size % 2 == 0) return (solution(a, a*(size/2)-1, size/2) * (my_pow(X, (size/2))+1)) % M;
    else return (solution(r, r, 1) + solution(a, a + (size/2)-1, size/2) * (my_pow(X, (size/2))+1)) % M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    
    cin >> T;
    
    while (T--) {
        
        
        cin >> X >> N >> M;
        
        cout << solution(0, N-1, N) << "\n";
    }
}
