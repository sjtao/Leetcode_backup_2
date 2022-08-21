class ZigzagIterator {
public:
    int p1, p2, k, n, m;
    queue<int> q;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        int n = max(n1, n2);
        for(int i = 0; i < n; i++){
            if(i < n1) q.push(v1[i]);
            if(i < n2) q.push(v2[i]);
        }
    }

    int next() {
        int a = q.front();
        q.pop();
        return a;
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