#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    vector<int> house;
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        int num;
        
        cin >> num;
        
        house.push_back(num);
    }
    
    int l = 1, r = house[N-1];
    int mid = (l+r)/2;
    int ret = 0;
    
    while (l <= r) {
        mid = (l+r)/2;
        int prev = house[0];
        int set = 1;
        
        for (int i = 1; i < N; i++) {
            if (house[i] - prev >= mid) {
                prev = house[i];
                set++;
            }
        }
        
        if (set >= M) {
            ret = mid;
            l = mid+1;
        }else r = mid-1;
    }
    
    cout << ret << "\n";
}
