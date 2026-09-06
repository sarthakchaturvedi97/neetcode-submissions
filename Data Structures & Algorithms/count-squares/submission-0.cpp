struct PairHash{
    size_t operator()(const pair<int,int> &p) const{
    return hash<int>()(p.first) ^ (hash<int>()(p.second)<<16);
    }
};
class CountSquares {
public:
    unordered_map<pair<int,int>,int,PairHash> mp;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int count = 0;
        int x = point[0], y = point[1];
        for(auto const& [pt,f1]: mp)
        {
            int px = pt.first, py = pt.second;
            if(px!=x && py!=y && abs(px-x) == abs(py-y))
            {
                auto it = mp.find({px,y});
                auto it2 = mp.find({x,py});
                if(it!=mp.end() && it2!=mp.end())
                {
                    int f2 = it->second;
                    int f3 = it2->second;
                    count+=f1*f2*f3;
                }
            }
        }
        return count;
    }
};