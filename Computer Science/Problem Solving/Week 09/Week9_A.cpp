#include <iostream>
using namespace std;

typedef long long ll;
ll X;
ll N;
ll M;

ll my_pow(ll x, ll n) {
    if (n == 0) return 1;
    
    if (n % 2) return (x * my_pow(x, n-1)) % M;
    
    return my_pow((x * x) % M, n / 2) % M;
}

ll solution(ll n) {
    if (n == 1) return X;
    
    ll mid = solution(n /2);
    
    if (n % 2) return ((mid % M) * (my_pow(X, n/2) + 1) % M + (my_pow(X, n) % M)) % M;
    
    return ((mid % M) * (my_pow(X, n/2) + 1) % M) % M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    
    cin >> T;
    
    while (T--) {
        cin >> X >> N >> M;
        
        cout << solution(N) << "\n";
    }
}
