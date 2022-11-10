class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        // storing a pair of char and its freq
        // when the conseq freq reaches k elements then we pop of k elements
        
        stack< pair<char , int> > st;
        string res="";
        
        for( const auto &ch : s){
            
            if( !st.empty()){
                if( st.top().first != ch){      // gonna push with freq 1 if top != cur
                    st.push({ch , 1});
                }else if( st.top().first == ch ){       // if top == cur then push 
                    // st.push({ch , st.top().second +1 });    // with freq == top.second+1
                    st.top().second++;  // instead of pusing same elements we can update frequency of elements 
                }
            }else{
                st.push({ch , 1});      // gonna push which freq 1 if st empty 
            }
            
            if( st.top().second == k  ){
                // for( int i = 0 ; i < k ;i++){       // if top elements freq == k then we pop k
                cout<< st.top().first << " "<< st.top().second<<" ";
                st.pop();
                // }
            }
            
        }
        cout<<endl;
        
        while( !st.empty()){
            // res = st.top().first* st.top().second + res;
            for( int i = 0 ; i < st.top().second ; i ++){       // add elements their frequency times
                res += st.top().first;
            }
            st.pop();
        }
        reverse( res.begin() , res.end());
        
        return res;
    }
};