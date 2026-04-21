class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>minHeap;
    int k_size;
    KthLargest(int k, vector<int>& nums) {
        k_size = k;
        for(int x:nums){
            add(x);
        }
    }
    
    int add(int val){
        minHeap.push(val);

        if(minHeap.size()>k_size){
            minHeap.pop();
        }

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */