class Solution {
    
    int backtrack( string t1 , string t2 , int i1 , int i2 , int ans , vector<vector<int>> &dp){
        if( i1 == t1.size() || i2 == t2.size()){
            return 0;
        }
        
        if( dp[i1][i2] != -1){
            return dp[i1][i2];
        }
        
        if( t1[i1] == t2[i2]){
            return dp[i1][i2] = 1 + backtrack( t1 , t2 , i1+1 , i2+1 , ans+1 ,dp);
        }
        
        return dp[i1][i2] = max( backtrack( t1 , t2 , i1+1 , i2 , ans ,dp) , backtrack( t1 , t2 , i1 , i2+1 , ans ,dp));
        
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        // we can generate a power set of all sub sequences int t1 t2 and then find longest common subseq form 2 sets
        
        
        /*we can make a reoccurance relation where the base condition will be if the chars match in the string
        then we add 1 to the ans else we move to next char in both string in diffrent recursive calls */
        
        // vector<vector<int>> dp( text1.size() , vector<int> (text2.size() , -1));
        
        // return backtrack( text1 , text2 , 0 , 0 , 0 , dp);
        
        
        /*
        for the tabulation we can make a 2d dp and move row by row filling max of upper col or left col and +1 if 
        current letter matches
        */
        
        vector<vector<int>> dp( text1.size()+1 , vector<int> (text2.size()+1 , 0 ));
        
        for( int i = 1 ; i <= text1.size() ; i++ ){
            for( int j = 1 ; j <= text2.size() ; j++){
                
                if( text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] =  max( dp[i-1][j] , dp[i][j-1]);
                }
                
            }
        }
        
        return dp[text1.size()][text2.size()];
    }
};