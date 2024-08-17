class Info {
public:
    int data;
    int row;
    int col;
    Info(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class compare {
public:
    bool operator()(Info* a, Info* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare> pq;
        int k = nums.size();
        int maxi = INT_MIN;
        for(int i = 0 ; i < k ; i++){
            int element = nums[i][0];
            maxi = max(maxi, element);
            Info* temp = new Info(element, i, 0);
            pq.push(temp);
        }
        int mini = INT_MAX;
        int range = INT_MAX;
        vector<int> ans(2);
        while(!pq.empty()){
            Info* front = pq.top();
            mini = front->data;
            int topRow = front->row;
            int topCol = front->col;
            pq.pop();
            if(maxi - mini < range){
                range = maxi - mini;
                ans[0] = mini;
                ans[1] = maxi;
            }
            if(topCol + 1 < nums[topRow].size()){
                int element = nums[topRow][topCol + 1];
                Info* temp = new Info(element, topRow, topCol + 1);
                pq.push(temp);
                maxi = max(maxi, element);
            }
            else break;
        }
        return ans;
    }
};