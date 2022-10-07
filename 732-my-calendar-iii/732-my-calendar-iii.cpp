class MyCalendarThree {
public:
    map<int,int> mp;
    MyCalendarThree() {
        
        // idea is to use an ordered map to store start and end points of intervals
        // we add 1 to start points and substract 1 from end points
        // then interate the map from start to end and sum the values of all the point to find max 
        
    }
    
    int book(int start, int end) {
        int cur = 0, res = 0;
        mp[start]++;
        mp[end]--;
        
        for (auto& [ first , second] : mp) {
            cur += second;
            res = max(res, cur);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */