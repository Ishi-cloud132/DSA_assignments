#include <iostream>
# include <stack>
 using namespace std;
string rev(string str)
 {  string reverse="";
    stack<char>st;
  int len=str.length();
  for(int i=0;i<len;i++)
  { 
    char c=str[i];
    st.push(c);
   
  }
while(!st.empty())
{ 
   
 reverse=reverse+st.top();
 st.pop();



}
return reverse;
   


 }
 int main()
 {
    
   cout<<"enter a string";
   string str;
    getline(cin,str);
  string reverse=rev(str);
  cout<<reverse;

  

 }
  