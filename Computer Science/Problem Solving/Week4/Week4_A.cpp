#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        int A, B, x, y;
        int upCost = 0;
        int downCost = 0;
        
        cin >> A >> B >> x >> y;
        
        int aCopy = A;
        int bCopy = B;
        
        int diff = abs(A-B);
        
        while (1) {
            if (A % diff == 0 && B % diff == 0) break;
            
            A++;
            B++;
            
            upCost += x;
        }
        
        bool noDown = false;
        
        while (1) {
            if (aCopy == 0 || bCopy == 0) {
                noDown = true;
                break;
            }
            
            if (aCopy % diff == 0 && bCopy % diff == 0) break;
            
            aCopy--;
            bCopy--;
            
            downCost += y;
        }
        
        cout << diff << " ";
        
        if (noDown) {
            cout << upCost << "\n";
        }else {
            cout << min(upCost, downCost) << "\n";
        }
    }
}
