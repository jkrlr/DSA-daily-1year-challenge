/* Unlike arrays, vectors are passed by value to a function, you may still pass them by reference if the need arises.

function(vector<int> v){

}

function (vector<int> &v){

} */

/*When a vector is full. Then it'll automatically double its size dynamically.
Vectors use contiguous memory location, which means elements can be accessed directly in O(1) time.*/

/*You can define the array of your own custom class type.
e.g.

struct Book{
    string name;
    float price;
    string author;
};

Book b[100]; // Array of type Book of size equal to 100.*/