class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> result(3);
        for(auto triplet: triplets)
        {
            if(triplet[0]<=target[0] && triplet[1]<=target[1] && triplet[2]<=target[2])
            {
                result[0] = max(result[0],triplet[0]);
                result[1] = max(result[1],triplet[1]);
                result[2] = max(result[2],triplet[2]);
            }
        }
        return result[0] == target[0] && result[1] == target[1] && result[2] == target[2];
    }
};