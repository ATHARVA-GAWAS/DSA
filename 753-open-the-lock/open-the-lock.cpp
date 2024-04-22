class Solution {
    void fillneighbours(queue<string> &que,string &curr,unordered_set<string> &dead){
        for(int i=0;i<4;i++){
            char ch=curr[i];
            char dec= ch=='0'?'9':ch-1;
            char inc=ch=='9'?'0':ch+1;

            curr[i]=dec;

            if(!dead.count(curr)){
                dead.insert(curr);
                que.push(curr);
            }

            curr[i]=inc;
            if(!dead.count(curr)){
                dead.insert(curr);
                que.push(curr);
            }
            curr[i]=ch;
        }
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(),deadends.end());

        string start="0000";

        if(dead.count(start)){
            return -1;
        }

        queue<string> que;
        que.push(start);
        int level=0;

        while(!que.empty()){
            int n=que.size();
            while(n--){
                string curr=que.front();
                que.pop();

                if(curr==target){
                    return level;
                }

                fillneighbours(que,curr,dead);
            }
            level++;
        }
        return -1;
    }
};