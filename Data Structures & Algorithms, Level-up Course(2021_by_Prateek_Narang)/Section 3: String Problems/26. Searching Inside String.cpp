#include <iostream>
#include <string>

using namespace std;

int main()
{
    string paragraph = "We are learning about STL strings. STL string class is quite powerful.";

    string word;
    getline(cin, word);

    // find function
    size_t idx = paragraph.find(word); // If we convert unsigned long of max size into int
    int index = paragraph.find(word);  // Then it's value will be -1

    if (index != -1)
    {
        cout << "first occ" << index << endl;
    }

    index = paragraph.find(word, index + 1);

    if (index != -1)
        cout << "second occ" << index << endl;
}