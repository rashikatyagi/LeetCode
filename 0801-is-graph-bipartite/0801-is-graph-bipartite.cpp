class Solution {
public:
    bool bfs(int source, vector<vector<int>>& graph, vector<int> &color){
        color[source] = 0;
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int currnode = q.front();
            q.pop();
            for(auto it : graph[currnode]){
                if(color[it] == -1){
                    color[it] = !color[currnode];
                    q.push(it);    
                }
                else if(color[it] == color[currnode]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
                if(!bfs(i, graph, color)) return false;
            }
        }
        return true;
    }
};