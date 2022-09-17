class Solution {
public:
    int countSubstrings(string s) {
        string str;
        int len=0;
        int start=0;
        int count=0;
   for(int i=0;i<s.length();i++)
   {
       int len1=expandFromCenter(s,i,i);
       int len2=expandFromCenter(s,i,i+1);
       
       count += len1 + len2;
   }
     return count;   
   }
    int expandFromCenter(string &s,int left,int right)
    {
        if(s.length()<1||left>right)
         return 0;
        int count = 0;
        while(left>=0&&right<s.length()&&s[left]==s[right])
        {
            left--;
            right++;
            count++;
        } 
        return count;
    }
};