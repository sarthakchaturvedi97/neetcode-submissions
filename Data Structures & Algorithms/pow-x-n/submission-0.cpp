class Solution {
public:
    double getPow(double x, int n)
    {
        if(n == 0)
        return 1;

        double ans = getPow(x,n/2);
        if(n%2 == 0)
        return ans*ans;
        else
        return x*ans*ans;
    }
    double myPow(double x, int n) {
        if(n == 0)
        return 1;

        if(n>=1)
        return getPow(x,n);
        else
        return 1/getPow(x,n);
    }
};