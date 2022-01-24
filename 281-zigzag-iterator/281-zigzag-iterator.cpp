class ZigzagIterator {
public:
    vector<int> a;
    int k;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        int n = max(n1, n2);
        for(int i = 0; i < n; i++){
            if(i < n1) a.push_back(v1[i]);
            if(i < n2) a.push_back(v2[i]);
        }
        k = 0;
    }

    int next() {
        return a[k++];
    }

    bool hasNext() {
        return k < a.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */