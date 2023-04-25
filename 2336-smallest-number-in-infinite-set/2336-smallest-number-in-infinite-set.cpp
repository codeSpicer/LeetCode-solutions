class SmallestInfiniteSet {
        set<int> st;
public:
    SmallestInfiniteSet() {
        for( int i = 1 ; i < 1001 ; i++){
            st.insert( i);
        }
    }
    
    int popSmallest() {
        int num;
        if( st.size() == 0){
            return 1;
        }else{
            set<int>::iterator it1 = st.begin();
            num = *it1;
            st.erase( it1);
        }
        return num;
    }
    
    void addBack(int num) {
        st.insert( num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */