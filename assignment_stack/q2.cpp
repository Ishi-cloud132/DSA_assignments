#include <iostream>
#include <stack>
using namespace std;
bool check(string str)

{
    stack<char>st;
    int n=str.length();
    
    for(int i=0;i<n;i++ )
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
        {
            st.push(str[i]);
        }
        else if(str[i]==')'||str[i]=='}'||str[i]==']')
    {
         if(st.empty())
         return false;
         
         else if((str[i]==')'&& st.top()!='(')||(str[i]=='}' && st.top()!='{')||(str[i]==']'&&st.top()!='[') )
         return false;


    }


    }
    return st.empty();
  
     


}
int main()
{
    cout<<"enter your expression";
    string s;
    cin>>s;
    bool checker= check(s);
    cout<<checker;





}