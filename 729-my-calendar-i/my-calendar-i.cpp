class MyCalendar {
public:
    vector<vector<int>> cal;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it:cal){
            
            if(end>it[0] && start<it[1]){
                return false;
            }
        }
        
        cal.push_back({start,end});
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */