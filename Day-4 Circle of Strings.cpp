class Solution {
  public:
    // DFS to explore all reachable nodes from a given node
    void DFS(int node, vector<int> adj[], vector<int>& visited) {
        visited[node] = 1;
        
        // Explore all neighbors of the current node
        for(int j = 0; j < adj[node].size(); j++) {
            if(!visited[adj[node][j]]) {
                DFS(adj[node][j], adj, visited);
            }
        }
    }
    
    int isCircle(vector<string> &arr) {
        int n = arr.size();
        
        // Graph with nodes from 'a' to 'z' (i.e., 26 nodes)
        vector<int> adj[26];
        vector<int> inDeg(26, 0);
        vector<int> outDeg(26, 0);
        
        // Build the adjacency list and calculate in-degrees and out-degrees
        for(int i = 0; i < n; i++) {
            string str = arr[i];
            int u = str[0] - 'a';
            int v = str[str.size() - 1] - 'a';
            adj[u].push_back(v);  // Directed edge from u to v
            outDeg[u]++;        
            inDeg[v]++;          
        }
        
        // Check if in-degree equals out-degree for all nodes
        for(int i = 0; i < 26; i++) {
            if(inDeg[i] != outDeg[i]) {
                return 0;
            }
        }
        
        // Initialize visited array to track visited nodes during DFS
        vector<int> visited(26, 0);
        
        // Start DFS from the first character of the first string
        int startNode = arr[0][0] - 'a';
        DFS(startNode, adj, visited);
        
        // Check if all nodes with non-zero in-degree are visited
        for(int i = 0; i < 26; i++) {
            if(inDeg[i] > 0 && !visited[i]) {
                return 0; 
            }
        }
        
        return 1;
    }
};