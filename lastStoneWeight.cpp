class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>>maxHeap;

        for(int stone: stones){
            maxHeap.push(stone);
        }
        while(maxHeap.size()>1){
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            if(x==y){
                maxHeap.pop();
            }else{
                maxHeap.pop();
                maxHeap.push(y-x);
            }
        }

        return maxHeap.empty()?0: maxHeap.top();
        

    }
};