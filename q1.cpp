#include<iostream>
 using namespace std;
  int main()
  {
     cout <<"enter size of array";
     int n;
     cin>>n;
      int arr[n];
      cout<<"enter elements of array";
        for(int i=0;i<n;i++)
        {
             cin>>arr[i];
        }
        cout<<"enter element to be searched";
        int x;
        cin>>x;
        int l=0;
        int h=n-1;
        int mid;
        
        bool found=false;
         while(l<=h)
         {
            mid=(l+h)/2;
            if(arr[mid]==x)
            {
                cout<<"element found at index "<<mid;
                found =true;

                break;

            } 
            else if(arr[mid]<x)
            {
                 l=mid+1;


            }   
            else{
                h=mid-1;
            } 
        }       
          if(!found)
          {
                  cout<<"element not found";

          }

            
         }
       



