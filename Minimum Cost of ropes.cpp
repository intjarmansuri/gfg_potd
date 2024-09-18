class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        for(auto it: arr) {
            minHeap.push(it);
        }
        
        long long totalCost = 0;
        
        while(minHeap.size() > 1) {
            long long first = minHeap.top();
            minHeap.pop();
            
            long long second = minHeap.top();
            minHeap.pop();
            
            long long cost = first + second;
            
            minHeap.push(cost);
            
            totalCost += cost;
        }
        return totalCost;
    }
};