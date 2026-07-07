class Solution {
    public:
        int expand(string s,int left, int right, int n)
            {
                    while(left>=0 && right<n && s[left] == s[right])
                            {
                                        left--;
                                                    right++;
                                                            }
                                                                    return right-left-1;
                                                                        }
                                                                            string longestPalindrome(string s) {
                                                                                    int st = 0, mxLen = 0, n = s.length();
                                                                                            for(int i=0;i<n;i++)
                                                                                                    {
                                                                                                                int l1 = expand(s,i,i,n);
                                                                                                                            int l2 = expand(s,i,i+1,n);
                                                                                                                                        int len = max(l1,l2);
                                                                                                                                                    if(len>mxLen)
                                                                                                                                                                {
                                                                                                                                                                                mxLen = len;
                                                                                                                                                                                                st = i - (len-1)/2;
                                                                                                                                                                                                            }
                                                                                                                                                                                                                    }
                                                                                                                                                                                                                            return s.substr(st,mxLen);
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                };