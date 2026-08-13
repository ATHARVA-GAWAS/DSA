class Solution {
public:
    vector<int> longestRepeating(string s, string q, vector<int>& idx) {

        int n = s.size();

 
        set<int> st;
        st.insert(0);

        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1])
                st.insert(i);
        }


        priority_queue<pair<int, int>> pq;

        auto add = [&](int l) {
            auto it = st.upper_bound(l);
            int r = (it == st.end() ? n : *it);

            pq.push({r - l, l});
        };


        for (int x : st)
            add(x);

        vector<int> ans;

        for (int k = 0; k < q.size(); k++) {

            int i = idx[k];
            s[i] = q[k];


            if (i > 0 && s[i] == s[i - 1]) st.erase(i);
            else st.insert(i);


            if (i + 1 < n && s[i] == s[i + 1]) st.erase(i + 1);
            else st.insert(i + 1);

 
            auto it = st.lower_bound(i);

            if (it != st.begin()) add(*prev(it));

            if (it != st.end()) {
                add(*it);

                if (next(it) != st.end())
                    add(*next(it));
            }

            while (true) {
                auto [length, start] = pq.top();

                auto next = st.upper_bound(start);
                int end = (next == st.end() ? n : *next);

                if (st.count(start) && end - start == length)
                    break;

                pq.pop();
            }

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};