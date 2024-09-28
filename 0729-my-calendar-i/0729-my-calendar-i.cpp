class MyCalendar {
public:
    vector<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it : st){
            int start_prev = it.first;
            int end_prev = it.second;
            if(start < end_prev && end > start_prev){
                return false;
            }
        }
        st.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */