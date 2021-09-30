#include <iostream>
#include <cmath>
using namespace std;

struct P {
    int x, y;
    
    P (int _x, int _y) {
        x = _x, y = _y;
    }
    
    P () {}
    
    bool operator < (P p1) {
        if (x == p1.x) return y < p1.y;
        
        return x < p1.x;
    }
    
    bool operator > (P p1) {
        if (x == p1.x) return y > p1.y;
        
        return x > p1.x;
    }
    
    bool operator == (P p1) {
        return x == p1.x && y == p1.y;
    }
    
    bool operator != (P p1) {
        if (x == p1.x) return y != p1.y;
        
        return x != p1.x;
    }
    
    bool operator <= (P p1) {
        if (x == p1.x) return y <= p1.y;
        
        return x <= p1.x;
    }
};

int ccw(P p1, P p2, P p3) {
    int det = (p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y);
    
    if (det > 0) return 1; // ccw
    else if (det < 0) return -1; // cw
    else return 0; // parellel
}

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        P p1, p2, p3, p4;
        
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        cin >> p3.x >> p3.y >> p4.x >> p4.y;
        
        if (p1.x > p2.x || p1.y > p2.y) swap(p1, p2);
        if (p3.x > p4.x || p3.y > p4.y) swap(p3, p4);
        
        if (p1.x > p3.x || p1.y > p3.y) {
            swap(p1, p3);
            swap(p2, p4);
        }
        
        int abc = ccw(p1, p2, p3);
        int abd = ccw(p1, p2, p4);
        int cda = ccw(p3, p4, p1);
        int cdb = ccw(p3, p4, p2);
        
        int ccw1 = abc * abd;
        int ccw2 = cda * cdb;
        
        if (ccw1 <= 0 && ccw2 <= 0) {
            if (ccw1 == 0 && ccw2 == 0) {
                // parellel || triangle
                if (abc == 0 && abd == 0 && cda == 0 && cdb == 0) {
                    // parellel
                    if (p1 <= p3 && p4 <= p2) cout << 4 << "\n";
                    else if (p2 <= p4) {
                        if (p1 == p3) cout << 4 << "\n";
                        else if (p3 < p2) cout << 3 << "\n";
                        else if (p2 == p3) cout << 2 << "\n";
                        else cout << 1 << "\n";
                    }
                }else {
                    // triangle
                    cout << 2 << "\n";
                }
            }else cout << 2 << "\n";
        }else {
            cout << 1 << "\n";
        }
    }
}
