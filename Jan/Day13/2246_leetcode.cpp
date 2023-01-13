class Solution {
public:
    
    int ans = 1;
    
    int dfs(vector<vector<int>> &vec, string &s, int start, int par)
    {
        int count = 1;
        
        for(int i = 0; i < vec[start].size(); i++)
        {
            if(vec[start][i] != par)
            {
                int temp = dfs(vec, s, vec[start][i], start);
                
                if(s[start] != s[vec[start][i]])
                { 
                    ans = max(ans, count + temp);
                    count = max(count, 1 + temp);
                }
            }
        }
        return count;
    }
    
    int longestPath(vector<int>& parent, string s) 
    {
        vector<vector<int>> vec(parent.size());
        
        for(int i = 1; i < parent.size(); i++)
        {
            vec[parent[i]].push_back(i);
            vec[i].push_back(parent[i]);
        }
        
        dfs(vec, s, 0, -1);
        return ans;
    }
};
