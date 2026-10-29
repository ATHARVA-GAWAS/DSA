class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, subtreeSize;
    vector<int> segTree;
    string s;
    int curPos;
    
   
    int dfs(int node, int par) {
        parent[node] = par;
        subtreeSize[node] = 1;
        int maxSize = 0;
        
        for (int child : adj[node]) {
            if (child == par) continue;
            depth[child] = depth[node] + 1;
            int childSize = dfs(child, node);
            subtreeSize[node] += childSize;
            
            if (childSize > maxSize) {
                maxSize = childSize;
                heavy[node] = child;
            }
        }
        return subtreeSize[node];
    }
    
    void decompose(int node, int h) {
        head[node] = h;
        pos[node] = curPos++;
        
        if (heavy[node] != -1)
            decompose(heavy[node], h);
        
        for (int child : adj[node]) {
            if (child == parent[node] || child == heavy[node]) continue;
            decompose(child, child);
        }
    }
    
    //using  Segment tree functions
    void build(int idx, int left, int right) {
        if (left == right) {
            segTree[idx] = 1 << (s[left] - 'a');
            return;
        }
        int mid = (left + right) / 2;
        build(2*idx, left, mid);
        build(2*idx+1, mid+1, right);
        segTree[idx] = segTree[2*idx] ^ segTree[2*idx+1];
    }
    
    void updateSeg(int idx, int left, int right, int i, int val) {
        if (left == right) {
            segTree[idx] = val;
            return;
        }
        int mid = (left + right) / 2;
        if (i <= mid)
            updateSeg(2*idx, left, mid, i, val);
        else
            updateSeg(2*idx+1, mid+1, right, i, val);
        segTree[idx] = segTree[2*idx] ^ segTree[2*idx+1];
    }
    
    int querySeg(int idx, int left, int right, int l, int r) {
        if (r < left || right < l) return 0;
        if (l <= left && right <= r) return segTree[idx];
        int mid = (left + right) / 2;
        return querySeg(2*idx, left, mid, l, r) ^
               querySeg(2*idx+1, mid+1, right, l, r);
    }
    
    int queryPath(int u, int v, int n) {
        int result = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);
            result ^= querySeg(1, 0, n-1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        result ^= querySeg(1, 0, n-1, pos[u], pos[v]);
        return result;
    }
    
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string str, vector<string>& queries) {
        s = str;
        adj.resize(n);
        parent.resize(n);
        depth.resize(n);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        subtreeSize.resize(n);
        
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        depth[0] = 0;
        dfs(0, -1);
        curPos = 0;
        decompose(0, 0);
        
        string reordered(n, ' ');
        for (int i = 0; i < n; i++)
            reordered[pos[i]] = s[i];
        s = reordered;
        
        segTree.resize(4*n);
        build(1, 0, n-1);
        
        vector<bool> answer;
        
        for (auto &q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                updateSeg(1, 0, n-1, pos[u], 1 << (c - 'a'));
            } else {
                int u, v;
                ss >> u >> v;
                int mask = queryPath(u, v, n);
                bool can = (mask == 0) || ((mask & (mask - 1)) == 0);
                answer.push_back(can);
            }
        }
        
        return answer;
    }
};