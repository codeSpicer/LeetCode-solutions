class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        
        while( n!= 1 && s.find(n)==s.end()){
            s.insert( n);
            n = getSq(n);
            
        } 
        return n==1;
        
    }
    
    int getSq( int n ){
        
        int square =0;
        while( n > 0){
            int d = n%10;
            n /= 10;
            square += d*d;
        }
        return square;
    }
};