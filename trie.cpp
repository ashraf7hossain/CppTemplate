// https://leetcode.com/problems/longest-common-prefix/submissions/442285683/?envType=problem-list-v2&envId=trie


int trie[201][26];
int ended[26*201],ans = 0;

int dfs(int u,int depth, int n){
    int now = ended[u];
    for(int i=0;i<26;++i){
        if(trie[u][i]!=-1){
            now += dfs(trie[u][i],depth+1,n);

            }
        }
    if(now==n){
        ans = max(ans,depth);
        }
    return now;
    }
            
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<1)return "";
        if(strs.size()==1)return strs[0];
        memset(trie,-1,sizeof(trie));
        int sz = 1;
        ans = 0;
        int n = strs.size();
        memset(ended,0,sizeof(ended));
        for(string s: strs){
            int cur = 0;
            for(char c : s){
                if(trie[cur][c-'a']==-1){
                    trie[cur][c-'a']=sz++;
                    }
                cur = trie[cur][c-'a'];
                }
            ended[cur]++;
            }
        dfs(0,0,n);
       // cout << ans << " \n";
        return strs[0].substr(0,ans);
        
    }
};
