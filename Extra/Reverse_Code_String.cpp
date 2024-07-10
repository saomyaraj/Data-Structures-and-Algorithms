
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
         stack<string>st;
         string temp="";
         string revtemp="";
         for(int i=0;i<S.size();i++)
         {
             if(S[i]=='.')
             {
                 st.push(temp);
                 st.push(".");
                 temp="";
             }
             else
             temp+=S[i];
         }
         st.push(temp);
         while(!st.empty())
         {
             revtemp+=st.top();
             st.pop();
         }
         return revtemp;
    } 
};