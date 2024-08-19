class Info{
public:
    char val;
    int count;
    Info(char val, int cnt){
        this->val = val;
        this->count = cnt;
    }
};

class compare{
public:
    bool operator()(Info a, Info b){
        return a.count < b.count;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        int frequency[26] = {0};
        for(char ch : s){
            frequency[ch - 'a']++;
        }
        //creating the max heap
        priority_queue<Info, vector<Info>, compare> pq;
        //filling the max heap
        for(int i = 0 ; i < 26 ; i++){
            if(frequency[i] > 0){
                Info temp(i + 'a', frequency[i]);
                pq.push(temp);
            }
        }
        string ans;
        while(pq.size() > 1){
            Info first = pq.top();
            pq.pop();
            Info second = pq.top();
            pq.pop();
            ans.push_back(first.val);
            ans.push_back(second.val);
            first.count--;
            second.count--;
            if(first.count > 0) pq.push(first);
            if(second.count > 0) pq.push(second);
        }
        //handling single element in pq case
        if(pq.size() == 1){
            Info first = pq.top();
            ans.push_back(first.val);
            first.count--;
            if(first.count > 0) return "";
        }
        return ans;
    }
};