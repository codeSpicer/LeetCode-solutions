class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        // find the max no of bananas in one pile in piles 
        
        // then we use a binary search ranging form 1 to max_banana to find the required number of
        // banana per hour speed 
        // if mid value of banana give less than or more then give hours we change left right pointers acc
        
        int left =1 , right = *max_element(piles.begin(), piles.end());
        // left is min piles per hour and right is max piles per hour         
        
        while( left < right ){
            
            int hourSpent = 0;
            int mid = ( left + right )/2;
            
            for( int pile :piles){
                hourSpent += pile /mid + ( pile % mid !=0);
                // hour = piles/no of piles per hour and if there are banana left less than hourspent
                // we add one for one more hour
            }
            if( hourSpent <= h){
                    right = mid;    // if at any pile hourspent goes over h then no use for iterating furter and break;
            }else{
                left = mid +1;
            }
        }
        
        return right;
        
        
    }
};