class MedianFinder {
public:
    priority_queue<int>leftSide; //max-heap
    priority_queue<int,vector<int>,greater<int>>rightSide; //min-heap
    MedianFinder() {}
    
    void addNum(int num) {
        leftSide.push(num);
        rightSide.push(leftSide.top());
        leftSide.pop();
        if(leftSide.size()<rightSide.size()){
            leftSide.push(rightSide.top());
            rightSide.pop();
        }
    }
    
    double findMedian() {
        if(leftSide.size()>rightSide.size()){
            return leftSide.top();
        }else{
            return (leftSide.top()+rightSide.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */