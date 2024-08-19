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
        int i = 0;
        while(i < s.length()){
            if(pq.size() == 1 && pq.top().count > 1) return "";
            Info temp1 = pq.top();
            pq.pop();
            s[i++] = temp1.val;
            temp1.count--;
            Info temp2 = pq.top();
            pq.pop();
            s[i++] = temp2.val;
            temp2.count--;
            if(temp1.count > 0) pq.push(temp1);
            if(temp2.count > 0) pq.push(temp2);
        }
        return s;
    }
};