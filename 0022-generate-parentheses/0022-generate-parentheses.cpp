class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> result ;
        string combination = "";
      
        recurse( result , combination , n , 0 , 0 );
        
        return result;
        
    }
    
    void recurse( vector<string> &result , string combi , int max , int open , int close ){
        
        if( combi.length() == 2 * max){
            result.push_back(combi);        // if combination gets to correct size we push it in result
        }
        
        if( open < max ){                   // so that opne brackets do no exceed the max limit 
            combi.append("(");
            recurse( result , combi , max , open+1 , close);
            combi.pop_back();
        }
        
        if( close < open ){                 // so that close bracket do not come before opening open bracket
            combi.append(")");
            recurse( result , combi , max , open , close+1);
            combi.pop_back();
        }
        
    }
    
};