class ZigzagIterator {
public:
    queue<pair<vector<int>::iterator, vector<int>::iterator>>q;         // use a queue to record iterators
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(v1.size()>0) q.push({v1.begin(), v1.end()});
        if(v2.size()>0) q.push({v2.begin(), v2.end()});
    }

    int next() {
        auto it = q.front(); q.pop();
        int ans = *(it.first);
        it.first++;
        if(it.first != it.second)
            q.push({it.first, it.second});
        return ans;
    }

    bool hasNext() {
        return q.size() > 0;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */