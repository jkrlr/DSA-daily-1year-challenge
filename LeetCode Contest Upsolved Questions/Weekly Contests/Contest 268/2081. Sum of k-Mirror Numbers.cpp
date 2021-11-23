// https://leetcode.com/problems/sum-of-k-mirror-numbers/

// Hard

// Tags - Enumeration, Palindrome

// What this problem wants to teach me?
/* In contest/Online Assessment their is nothing legal or illegal 
    i.e. If the input data is small and in Online Jdge Brute-Force will give TLE
    Then, From theis Brute-Force You can also precompute the answer on local machine for all the cases and 
    Then use that precomputed answer to give answer of query in O(1) time */
/* For hard problems first always think Brute-Force, It will be very easy for hard problem */
/* If you are using a variable in another function by using reference i.e. by using &
    Then for int& type if you use long long int& , Then in case of reference Implicit conversion doesn't happen */
/* How to check palindrome using lo and hi pointers */
/* How to convert a base-10 number into another base-k number */
/* How to observe the pattern of Plaindrome i.e. we can generete the next higher palindrome 
    of length 2*M and 2*M-1 from the given palindrome length M 
    e.g. aba => ababa and abaaba */
/* Same computation on strings takes more time than intergers 
    i.e to_string(num) is slower than char(num + '0') */


#include<bits/stdc++.h>
using namespace std;

// Brute-Force ->TLE | Time = O(Not Known), Space = O(1)
class Solution {
private:
    string to_base(long long num, long long k){
        string res = "";
        while(num!=0){
            res += char(num%k + '0');   // to_string(num%k) runs slowly than char(num%k + '0')
            num = num/k;
        }
        return res;
    }
private:
    bool isPalind(long long num){
        long long rev = 0;
        long long dupnum = num;
        
        while(num!=0){
            rev = rev*10 + num%10;
            num = num/10;
        }
        
        return rev==dupnum;
    }
private:
    bool isPalindStr(string str){
        int lo = 0;
        int hi = str.length()-1;
        
        while(lo < hi){
            if(str[lo++]!=str[hi--]){
                return false;
            }
        }
        
        return true;
    }
public:
    long long kMirror(int k, int n) {
        
        long long sum = 0;    
        for(long long i=1; n; i++){
            if(isPalind(i)){
                if(isPalindStr(to_base(i,k))){
                    sum += i;
                    n--;
                }
            }
        }
        
        return sum;
    }
};

// Brute-Force + Enumeration | Time = O(F(n)), Space = O(1)
// F(n) represents the size of all palindrome numbers of base 10 smaller than nth k-mirror number

class Solution {
private:
    string to_base(long long num, long long k){
        string res = "";
        while(num!=0){
            res += char(num%k + '0');
            num = num/k;
        }
        return res;
    }
private:
    bool isPalindStr(string str){
        int lo = 0;
        int hi = str.length()-1;
        
        while(lo < hi){
            if(str[lo++]!=str[hi--]){
                return false;
            }
        }
        
        return true;
    }
private:
    long long generatePalindNumber(long long num, bool odd){
        long long dupnum = num;
        if(odd){
            dupnum = dupnum/10;
        }
        
        while(dupnum!=0){
            num = num*10 + dupnum%10;
            dupnum = dupnum/10;
        }
        
        return num;
    }
    
public:
    long long kMirror(int k, int n) {
        
        long long sum = 0;    
        for(long long i=1; n; i = 10*i){
                
            // Base-10 odd digit Palindrome generation
            for(int j=i; j<10*i && n; j++){
                long long num = generatePalindNumber(j,true);
                
                string  str = to_base(num,k);
                if(isPalindStr(str)){
                    sum += num;
                    n--;
                }
            }

            // Base-10 even digit Palindrome generation
            for(int j=i; j<10*i && n; j++){
                long long num = generatePalindNumber(j,false);
                
                string  str = to_base(num,k);
                if(isPalindStr(str)){
                    sum += num;
                    n--;
                }
            }            
        }
        
        return sum;
    }
};