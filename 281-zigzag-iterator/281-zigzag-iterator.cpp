class ZigzagIterator {
public:
    queue<int> q;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        int i = 0, j = 0;
        while(i < n1 || j < n2){
            if(i < n1) q.push(v1[i++]);
            if(j < n2) q.push(v2[j++]);
        }
    }

    int next() {
        int a = q.front();
        q.pop();
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