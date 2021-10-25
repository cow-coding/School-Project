#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

struct point {
    int x, y, dist;
    
    point(int _x, int _y, int _d) {
        x = _x;
        y = _y;
        dist = _d;
    }
    
    point() {
        x = 0, y = 0;
        dist = 0;
    }
};

int dist(int x, int y) {
    return x*x + y*y;
}

bool operator > (point a, point b) {
    if (a.dist == b.dist) {
        if (a.x == b.x) return a.y > b.y;
        return a.x > b.x;
    }
    
    return a.dist > b.dist;
}

bool operator < (point a, point b) {
    if (a.dist == b.dist) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    }
    
    return a.dist < b.dist;
}

int main() {
    int T, M, N, K;
    
    cin >> T;
    
    while (T--) {
        priority_queue<point> pq;
    
        cin >> M >> N >> K;
        
        point kth;
        
        for (int i = 0; i < M; i++) {
            int x, y;
            
            cin >> x >> y;
            
            point p1 = point(x, y, dist(x, y));
            
            if (pq.size() < K) {
                pq.push(p1);
            }else {
                if (pq.top() > p1) {
                    pq.pop();
                    pq.push(p1);
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            int x, y;
            
            cin >> x >> y;
            
            point p = point(x, y, dist(x, y));
            
            if (pq.top() > p) {
                pq.pop();
                pq.push(p);
            }
            
            cout << pq.top().x << " " << pq.top().y << "\n";
        }
    }
}
