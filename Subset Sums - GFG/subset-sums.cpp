//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> s;
        int sum = 0;
        backtrack( arr , sum , s , 0);
        return s;
        
    }
    
    void backtrack( vector<int> arr , int sum , vector<int> &s , int index){
        
        if( index == arr.size() ){
            s.push_back( sum);
            return;
        }
        
        backtrack( arr , sum , s , index+1);
        backtrack( arr , sum+arr[index] , s , index+1);
           
    }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends