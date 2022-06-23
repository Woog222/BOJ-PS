#include <iostream>
using namespace std;

int mask =0;
int n,k, cnt =0;
int letters[50];

void fun(int idx, int num) 
{
    if (num== k) 
    {
        
        int temp =0;
        for (int i=0; i<n; i++)
        {
            int word = letters[i];
            if(word == (mask & word) )
                temp++;
        }
        if ( cnt < temp) {
            
            cnt = temp;
        }
        return;
    }
    
    
    if (idx==26) return;
    
    mask =  mask | ( 1<<idx );
    fun(idx+1, num+1);
    mask = mask & ~(1<<idx);
    fun(idx+1, num);
    
    
    
}



int main()
{
    cin >> n >> k;
    string temp;
    
    for (int i=0; i<n; i++)
    {
        cin >> temp;
        for (auto letter : temp) {
            letters[i] = letters[i] | (   1<<(letter -'a') );
            
        }
        
    }
    
    fun(0,0);
    cout << cnt << endl;
    
}