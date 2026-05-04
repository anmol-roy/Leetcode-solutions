// Last updated: 04/05/2026, 15:43:53
class MinStack {
public:
    stack<long long> s;
    long long minval;

    MinStack() {}

    void push(int val) {
        if(s.empty()) {
            s.push(val);
            minval = val;
        } else {
            if(val < minval) {
                s.push(2LL * val - minval);
                minval = val;
            } else {
                s.push(val);
            }
        }
    }

    void pop() {
        if(s.empty()) return;
        long long topVal = s.top();
        s.pop();
        if(topVal < minval) {
            minval = 2LL * minval - topVal;
        }
    }

    int top() {
        if(s.empty()) return -1;
        long long topVal = s.top();
        if(topVal < minval) return minval;
        return topVal;
    }

    int getMin() {
        if(s.empty()) return -1;
        return minval;
    }
};
