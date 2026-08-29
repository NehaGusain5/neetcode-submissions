class CountSquares {
public:
    unordered_map<int, unordered_map<int,int>> cnt;
    CountSquares() {}
    
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        cnt[x][y]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int res = 0;

        for (auto &p : cnt) {
            int x2 = p.first;
            if (x2 == x) continue; 
            int d = abs(x2 - x);

            res += cnt[x][y+d] * cnt[x2][y] * cnt[x2][y+d];

            res += cnt[x][y-d] * cnt[x2][y] * cnt[x2][y-d];
        }
        return res;
    }
};
