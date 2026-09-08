class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int element = 1, m = matrix.size(), n = matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!matrix[i][j])
                {
                    matrix[i][0] = 0;
                    if(j)
                    matrix[0][j] = 0;
                    else
                    element = 0;
                }
            }
        }

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(!matrix[i][0]||!matrix[0][j])
                matrix[i][j] = 0;
            }
        }

        if(!matrix[0][0])
        {
            for(int j=0;j<n;j++)
            matrix[0][j] = 0;
        }

        if(!element)
        {
            for(int i=0;i<m;i++)
            matrix[i][0] = 0;
        }
    }
};
