class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1;
        
        for( int i = digits.size()-1 ; i > 0 ;i--){
            if( digits[i]>8){
                digits[i] = 0;
                carry = 1;
            }else{
                digits[i]+= carry;
                carry= 0;
                break;
            }
        }
        if( carry  ){
            if(digits[0] > 8){
                digits[0] = 0;
                digits.insert(digits.begin(), 1);
            }else{
                digits[0]++;
            }
        }
        
        return digits;
        
    }
};