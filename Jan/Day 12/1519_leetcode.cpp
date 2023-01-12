// using vector<int> as return value faster than 80% solutions
class Solution {
public:
    
    vector<int> dfs(vector<vector<int>> &vec, int start, int par, string &str, vector<int> &ans)
    {
        vector<int> cv(26, 0);
        for(int i = 0; i < vec[start].size(); i++)
        {
            if(vec[start][i] != par)
            {
                vector<int> temp = dfs(vec, vec[start][i], start, str, ans);
                
                for(int i = 0; i < 26; i++)
                {
                    cv[i] += temp[i];
                }
            }
        }
        cv[str[start] - 'a'] += 1;
        ans[start] = cv[str[start] - 'a'];
        return cv;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string str) 
    {
        vector<vector<int>> vec(n);
        for(int i = 0; i < edges.size(); i++)
        {
            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> v(n);
        dfs(vec, 0, 0, str, v);
        return v;
    }
};








// using unordered_map<char, int> as return value faster than 5% of the solutions
class Solution {
public:
    
    unordered_map<char, int> dfs(vector<vector<int>> &vec, int start, int par, string &str, vector<int> &ans)
    {
        unordered_map<char, int> mp;
        
        for(int i = 0; i < vec[start].size(); i++)
        {
            if(vec[start][i] != par)
            {
                unordered_map<char, int> temp = dfs(vec, vec[start][i], start, str, ans);
                
                for(auto it = temp.begin(); it != temp.end(); it++)
                {
                    mp[it -> first] += it -> second;
                }
                
            }
        }
        
        
        mp[str[start]]++;
        ans[start] = mp[str[start]];
        return mp;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string str) 
    {
        vector<vector<int>> vec(n);
        for(int i = 0; i < edges.size(); i++)
        {
            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> v(n);
        unordered_map<char, int> mp = dfs(vec, 0, 0, str, v);
        return v;
    }
};
