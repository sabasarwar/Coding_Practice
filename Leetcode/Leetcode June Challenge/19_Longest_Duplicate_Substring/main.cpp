/* ---------------------------------------- Problem Statement ------------------------------------

Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

Example 1:

Input: "banana"
Output: "ana"

Example 2:

Input: "abcd"
Output: ""
 
-------------------------------------------------------------------------------------------------*/

class Solution 
{
public:
    string ans = "" ; 
    int base = 26 ;
    int mod = 10000001 ;
    int power[(int)1e5+5];
    string longestDupSubstring(string S) 
    {
        power[0] = 1 ; 
        for(int i = 1 ; i < S.size() ; i ++ ) power[i] = ( power[i-1] * base ) % mod ; 
        int L = 0 , R = ( S.size() - 1 )  , mid = 0 ;
        while( L  <= R )
        {
            mid = ( L + R ) >> 1 ; 
            if( solve(  mid  ,  S )  ) L = mid + 1 ; 
            else R = mid - 1 ; 
        }
        return ans ;
    } 
    
    
    bool solve( int cur , string S )
    {
       unordered_map<int,vector<int>>v ; 
       int cur_pow = cur ;
       int Rabin = 0     ;
       for( int i = 0 ; i <= cur ; i ++ )
       {
           Rabin = ( Rabin % mod +  (  S[i]-'a') * power[cur_pow] )  % mod ;
           --cur_pow ;
       }
       v[Rabin] = { 0 } ;
       int L = 0 , R = cur ; 
       while( 1 )
       {
           Rabin =   ( ( Rabin - ( ( S[L] - 'a' ) * power[cur] % mod )  ) + mod ) % mod  ;
           Rabin = ( Rabin % mod  * base ) % mod ; 
           ++R ;
           ++L ;
           if( R == S.size() ) return 0 ;
           Rabin = ( Rabin % mod + ( S[R]-'a' ) ) % mod ;
           if( v.find(Rabin) == v.end() ) v[Rabin] = {L} ;
           else
           {
               string str = S.substr(L , cur + 1 ) ;
               for( int index : v[Rabin] )
               {
                   if( str == S.substr( index , cur + 1 ) )
                   {
                       ans = str ; 
                       return 1  ;
                   }
               }
               v[Rabin].push_back( L ) ;
           }
           
           }
        return 0 ; 
       }
    
};