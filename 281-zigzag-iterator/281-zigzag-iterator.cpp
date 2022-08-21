class ZigzagIterator {
public:
    queue<pair<vector<int>::iterator,vector<int>::iterator>> q;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(v1.size()) q.push({v1.begin(), v1.end()});
        if(v2.size()) q.push({v2.begin(), v2.end()});
    }

    int next() {
        auto it = q.front().first;
        auto ie = q.front().second;
        q.pop();
        if(it + 1 != ie)
            q.push({it+1, ie});
        return *it;
    }

    bool hasNext() {
        return !(q.empty());
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */