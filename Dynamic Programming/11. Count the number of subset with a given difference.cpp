/*11. Count the number of subsets with a given difference

Flow :

-> Problem Statement :
Ex :    ar[] = 1 1 2 3 , Diff = 1
        Ans = 3 => {1,3} {1, 2} , {1,3} {1, 2} (because we've 2 one's) and {1, 1, 2} {3}

-> Will try to reduce the Problem Statement :
                    ar[]
                    /  \
                   S1  S2 
                   S1 -S2 = Diff 
                   S1 +S2 = Sum(ar)
                   ________________
                   2*S1   = Diff + Sum(ar)
                     S1   = Diff + Sum(ar)                
                           ________________
                                 2         

-> Solved it using already solved Problem :
Now, we've to find out the the sum of subset S1 to be = (Diff + sum(ar))/2 = Given sum
Now, this problem is reduced to => Count of subset Problem 

i.e. Count # of subsets with given d/f      ----------->     Count of subset sum
    Sum(S1)  = Diff + Sum(ar)                
              ________________
                    2         

Time Complexity = O(n*sum) -> for calculating the table
Space Complexity = O(n*sum) -> for storing the table      
*/

int CountOfSubsetsWithGivenDiff(int ar[], int n, int Diff){
      int SumOfArray = accumulate(ar, ar+n, 0);

      int Sum =  (Diff + SumOfArray) / 2 ;
      return CountOfSubsetSum(ar,n,Sum);
}

int CountOfSubsetSum(int ar[], int n, int sum){
      int t[n + 1][sum + 1];

    for(int i=0;i<=n;i++){
        for(int j=0; j<=sum;j++){
            if(i==0)
                t[i][j]=0;
            if(j==0)
                t[i][j]=1;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1; j<=sum;j++){
            if(ar[i-1]<=j)
                t[i][j] = (t[i-1][j-ar[i-1]] + t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[n][sum];
}