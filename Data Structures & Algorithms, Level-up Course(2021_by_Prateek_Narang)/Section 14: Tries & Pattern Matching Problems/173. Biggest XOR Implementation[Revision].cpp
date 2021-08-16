// Time = O(N), Space = O(26*N)

// Modify classes according to question's need 
// If data variables is too small(e.g. 1, 2) - like If a trie node can have only 1 or 2 or 3 children at most
// Don't forget to take leverage of classes functions
// Not do the same task in Fn that can be done by classes function
// Don't afraid to write lenghty codes

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class node{
public:
    node *left;
    node *right;
};

class trie{
    node *root;

public:
    trie(){
        root = new node();
    }

    void insert(int num){

        node *temp = root;

        // Extract the bitsand insert it into trie
        for(int i = 31; i >= 0;i--){
            int bit = (num >> i) & 1;

            if(bit==0){
                if(temp->left==NULL){
                    temp->left = new node();
                }
                // go to that node
                temp = temp->left;
            }
            else{ // bit == 1
                if(temp->right==NULL){
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }

    int max_xor_helper(int num){
        node *temp = root;
        int curr_xor = 0;
        
        for (int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;

            if(bit==0){
                // look for one
                if(temp->right!=NULL){
                    curr_xor += (1 << i);
                    temp = temp->right;
                }
                else{
                    temp = temp->left;
                }
            }
            else{ // bit == 1
                // look for zero
                if(temp->left!=NULL){
                    curr_xor += (1 << i);
                    temp = temp->left;
                }
                else{
                    temp = temp->right;
                }
            }
        }

        return curr_xor;
    }

    int max_xor(vector<int> input){

        int max_xor = 0;
        for (int num : input){
            insert(num);
            int curr_xor = max_xor_helper(num);
            max_xor = max(max_xor, curr_xor);
        }

        return max_xor;
    }
};

int main(){
    vector<int> input = {3, 10, 5, 25, 9, 2};
    trie t;
    cout << t.max_xor(input) << endl;

    return 0;
}
