class Solution {
public:
    int sq(int n)
    {
        int sum = 0;
        while(n)
        {
            int r = n%10;
            sum+=r*r;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = sq(n), fast = sq(sq(n));
        while(fast!=slow)
        {
            slow = sq(slow);
            fast = sq(sq(fast));
        }
        return fast == 1;
    }
};