#include <vector>
#include <queue>
using namespace std;

class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 0; i < n; i++)
            q.emplace(i);
    }
    
    int reserve() {
        int t = q.top();
        q.pop();
        return t + 1;
    }
    
    void unreserve(int seatNumber) {
        q.push(seatNumber - 1);
    }
private:
    priority_queue<int, vector<int>, greater<int>> q;
};
// 通过 水题一个
/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */