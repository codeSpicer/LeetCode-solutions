class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        dfs(combinations, combination, candidates, 0, target);
        return combinations;
    }

    void dfs(vector<vector<int>>& combinations, vector<int>& combination, vector<int>& candidates, int index, int target) {
        if(target < 0 ) return;

        if(target == 0) {
            combinations.push_back(combination);
            return;
        }
        
        for(int i = index; i < candidates.size(); ++i) {
            combination.push_back(candidates[i]);
            dfs(combinations, combination, candidates, i, target - candidates[i]);
            combination.pop_back();
        }
    }
};