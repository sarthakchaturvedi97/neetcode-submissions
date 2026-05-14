class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int n = digits.size(), sum = (digits[n-1]+1)%10, carry = (digits[n-1]+1)/10;
        result.push_back(sum);
        for(int i=digits.size()-2;i>=0;i--)
        {
            sum = digits[i]+carry;
            result.push_back(sum%10);
            carry = sum/10;
        }

        if(carry)
        result.push_back(carry);

        reverse(result.begin(),result.end());
        return result;
    }
};