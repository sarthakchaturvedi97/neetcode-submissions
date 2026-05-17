class MinStack {
public:
    stack<pair<int,int>> st;   
    MinStack() {
        
    }
    
    void push(int val) {
        int minimum = st.empty() ? val : min(val,st.top().second);
        st.push({val,minimum});
        return;
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
      return st.empty() ? -1 : st.top().first; 
    }
    
    int getMin() {
        return st.empty() ? -1 : st.top().second;
    }
};