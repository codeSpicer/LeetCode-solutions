class Solution {
public:
    int dfs(int i, int n, int cur_profit, vector<int>& group, vector<int>& profit, int minProfit, vector<vector<vector<int>>>& memo) {
        if (i == group.size()) {
            return cur_profit >= minProfit ? 1 : 0;
        }
        if (memo[i][n][cur_profit] != -1) {
            return memo[i][n][cur_profit];
        }
        int left = dfs(i + 1, n, cur_profit, group, profit, minProfit, memo);
        int right = 0;
        if (n - group[i] >= 0) {
            right = dfs(i + 1, n - group[i], min(cur_profit + profit[i], minProfit), group, profit, minProfit, memo);
        }
        memo[i][n][cur_profit] = (left + right) % (int)(1e9 + 7);
        return memo[i][n][cur_profit];
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> memo(group.size(), vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));
        return dfs(0, n, 0, group, profit, minProfit, memo);
    }
};
