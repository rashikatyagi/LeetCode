class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});
        string ans = "";
        while(!pq.empty()){
            int currFrequency = pq.top().first;
            char currChar = pq.top().second;
            int currLength = ans.length();
            pq.pop();
            if(currLength >= 2 && ans[currLength - 1] == currChar && ans[currLength - 2] == currChar){
                if(pq.empty()) break;
                int nextFrequency = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();
                ans.push_back(nextChar);
                nextFrequency--;
                if(nextFrequency > 0) pq.push({nextFrequency, nextChar});
            }
            else{
                ans.push_back(currChar);
                currFrequency--;
            }
            if(currFrequency > 0) pq.push({currFrequency, currChar});
        }

        return ans;
    }
};