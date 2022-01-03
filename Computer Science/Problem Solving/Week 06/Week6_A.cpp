#include <iostream>
#include <queue>
using namespace std;

struct counter {
    int number;
    int time;
    
    counter(int n, int t) {
        number = n;
        time = t;
    }
};

struct cmp {
    bool operator() (const counter &c1, const counter &c2) {
        if (c1.time == c2.time) return c1.number > c2.number;
        
        return c1.time > c2.time;
    }
};

int main() {
    int N, M;
    vector<int> costs;
    priority_queue<counter, vector<counter>, cmp> pq;
    priority_queue<int> times;
    
    cin >> N >> M;
    
    costs.resize(N+1, 0);
    
    for (int i = 0; i < M; i++) {
        int time, cost;
        
        cin >> time >> cost;
        
        if (pq.size() < N) {
            pq.push(counter(i, time));
            costs[i] += cost;
            times.push(time);
        }else {
            counter top = pq.top();
            pq.pop();
            
            costs[top.number] += cost;
            pq.push(counter(top.number, top.time+time));
            times.push(top.time+time);
        }
    }
    
    cout << times.top() << "\n";
    
    for (int i = 0; i < N; i++) {
        cout << costs[i] << "\n";
    }
}
