// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int res=0;
        
        for(int i=0;i<=31;i++){
            bool x=false,y=false,z=false;
            
            if(a & (1<<i))
                x = true;
            if(b & (1<<i))
                y = true;
            if(c & (1<<i))
                z = true;
            
            if(z==false){
                if(x==true)
                    res++;
                if(y==true)
                    res++;
               
            }
            else{
                 if (x==false && y==false)
                    res++;
            }
        }
    return res;
    }
};