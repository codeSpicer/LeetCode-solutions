class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        // 1   1   1   1   2   2   2   2   2   3   3   3   4   4
        // limit is 4
        
        // we can only put 2 people in boat
        // we can sort the array and use 2 pointer approach
        // by pairing up lightesst and heavy person
        
        sort( people.begin() , people.end() );
        
        int count=0;
        
        int i = 0 ; int j = people.size()-1;
        
        while( i <= j ){
            if( people[i] + people[j] <= limit){
                i++;
            }
            j--;
            count++;
        }
        
        return count;
        
    }
};