class ZigzagIterator {
public:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(v1.size()) q.push({v1.begin(), v1.end()});
        if(v2.size()) q.push({v2.begin(), v2.end()});
    }

    int next() {
        auto p = q.front();
        q.pop();
        int a = *(p.first++);
        if(p.first != p.second) q.push(p);
        return a;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */