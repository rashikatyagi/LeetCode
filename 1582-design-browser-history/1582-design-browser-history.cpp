class BrowserHistory {
public:
    string home;
    string currenturl;
    stack<string> fw;
    stack<string> bk;
    BrowserHistory(string homepage) {
        home = homepage;
        currenturl = homepage;
    }
    
    void visit(string url) {
        bk.push(currenturl);
        currenturl = url;
        fw = stack<string>();
    }
    
    string back(int steps) {
        while (steps > 0 && !bk.empty()) {
        fw.push(currenturl);          // Push current URL to the forward stack
        currenturl = bk.top();        // Update current URL
        bk.pop();                     // Pop from the back stack
        steps--;
        }
        return currenturl;
    }
    
    string forward(int steps) {
        while (steps > 0 && !fw.empty()) {
        bk.push(currenturl);          // Push current URL to the back stack
        currenturl = fw.top();        // Update current URL
        fw.pop();                     // Pop from the forward stack
        steps--;
        }
        return currenturl;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */