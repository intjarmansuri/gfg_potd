/* ----------------------- Approach : Priority Queue (MinHeap) ------------------------ */
// Time Complexity : O(n log n)
// Space Complexity : O(K)

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i = 0; i <= k && arr.size(); i++) {
            minHeap.push(arr[i]);
        }
        
        int index = 0;
        
        for(int i = k+1; i < arr.size(); i++) {
            arr[index++] = minHeap.top();
            minHeap.pop();
            minHeap.push(arr[i]);
        }
        
        while(!minHeap.empty()) {
            arr[index++] = minHeap.top();
            minHeap.pop();
        }
    }
};