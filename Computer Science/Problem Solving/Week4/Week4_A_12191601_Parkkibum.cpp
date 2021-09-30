#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    
    cin >> T;
    
    while (T--) {
        int A, B, x, y;
        
        cin >> A >> B >> x >> y;
        
        int a = A, b = B;
        int ab = abs(A-B);
        int up_cost = 0, down_cost = 0;
        
        while (1) {
            if (a % ab == 0 && b % ab == 0) break;
            
            a++, b++;
            up_cost += x;
        }
        
        bool no_down = false;
        
        while (1) {
            if (A == 0) {
                no_down = true;
                break;
            }
            
            if (B == 0) {
                no_down = true;
                break;
            }
            
            if (A % ab == 0 && B % ab == 0) break;
            
            A--, B--;
            down_cost += y;
        }
        
        if (!no_down) {
            if (down_cost > up_cost) {
                cout << ab << " " << up_cost << "\n";
            }else {
                cout << ab << " " << down_cost << "\n";
            }
        }else {
            cout << ab << " " << up_cost << "\n";
        }
        
        
    }
}
