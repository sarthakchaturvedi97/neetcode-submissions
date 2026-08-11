class MedianFinder {
public:
    priority_queue<int> low;
    priority_queue<int,vector<int>, greater<int>> high;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        low.push(num);
        high.push(low.top());
        low.pop();

        if(low.size()<high.size())
        {
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() {
        return low.size()>high.size()?low.top():(double)(low.top()+high.top())/2;
    }
};
