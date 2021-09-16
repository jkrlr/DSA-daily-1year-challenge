/*  As we iterate through the characters in the input string:

    If the character is not in unpairedCharacters, we add it.
    If the character is already in unpairedCharacters, we remove it.
    Finally, we just need to check if less than two characters don’t have a pair.*/

// Time = O(n), Space = O(1) - because ASCII has only 128 chars(including standard english alphabets and punctuations)
// and Unicode has 110,000 = 10^5 characters(supporting several languages and some icons/symbols)
bool hasPalindromePermutation(const string& str)
{
    // track characters we've seen an odd number of times
    unordered_set<char> unpairedCharacters;
    
    for(char ch: str){
        if(unpairedCharacters.find(ch)!=unpairedCharacters.end()){
            unpairedCharacters.erase(ch);
        }
        else{
            unpairedCharacters.insert(ch);
        }
    }

    // the string has a palindrome permutation if it
    // has one or zero characters without a pair
    return unpairedCharacters.size() <= 1;
}


