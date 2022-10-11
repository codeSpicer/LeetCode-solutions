class Solution {
public:
    bool judgeCircle(string moves) {
        
        int x = 0, y = 0;
        
        for( int i = 0 ; i < moves.size() ; i++){
            
            switch (moves[i]) {
                case 'U':
                    x--;
                    break;
                case 'D':
                    x++;
                    break;
                case 'L':
                    y--;
                    break;
                case 'R':
                    y++;
                    break;
            }
        }
        
        return ( x == 0 && y == 0);
            
        
    }
};