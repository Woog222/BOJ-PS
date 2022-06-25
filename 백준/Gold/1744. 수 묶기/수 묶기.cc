#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

int zero, n;
vector<int> p;
vector<int> m;


int main()
{
    cin >> n;
    
    while(n--) {
        int temp;
        cin >> temp;
        if(temp>0) {
            p.push_back(temp);
        }
        else if(temp<0) {
            m.push_back(temp*(-1));
        }
        else 
            zero +=1;
    }
    sort(p.begin(), p.end(), greater<int>());
    sort(m.begin(), m.end(), greater<int>());
    
   long long ans=0;
   
   int psize =p.size();
   for(int i=0; i<(psize-1); i+=2) {
       if(p[i+1] != 1){
           ans += p[i]*p[i+1];
            
          
       }
       else {
           ans += p[i]+p[i+1];
            
       }
   }
   if( (psize%2) ==1 ){
       ans += p.back();
       
   }
       
   int msize = m.size();
   for(int i=0; i<(msize-1); i+=2) {
           ans += m[i]*m[i+1];       
   }
   if( (msize%2) ==1 && zero==0 )
       ans -= m.back();   
   
    cout << ans<<endl;    
}