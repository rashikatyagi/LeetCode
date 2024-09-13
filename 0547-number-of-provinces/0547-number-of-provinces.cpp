class Solution {
public:
    void dfs(int source, vector<int> adjList[], vector<int> &visited){
        visited[source] = 1;
        for(int it : adjList[source]){
            if(visited[it] == 0){
                dfs(it, adjList, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjList[n + 1];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i != j && isConnected[i][j] == 1){
                    adjList[i + 1].push_back(j + 1);
                }
            }
        } 
        vector<int> visited(n + 1, 0);
        int answer = 0;
        for(int i = 1 ; i <= n ; i++){
            if(visited[i] == 0){
                answer++;
                dfs(i, adjList, visited);
            }
        }
        return answer;
    }
};