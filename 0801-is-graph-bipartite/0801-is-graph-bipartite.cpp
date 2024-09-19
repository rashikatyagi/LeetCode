class Solution {
public:
    bool bfs(int source, vector<vector<int>>& graph, vector<int> &color){
        queue<int> q;
        q.push(source);
        color[source] = 1;
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            for(auto it : graph[currNode]){
                if(color[it] == -1){
                    color[it] = !color[currNode];
                    q.push(it);
                }
                else if(color[it] == color[currNode]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        //for disconnected components
        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
                if(bfs(i, graph, color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};