// Time = O(k + (N-k)*LogK) + O(k) = O(k+(N-k)*Logk), Space = O(k+k) =O(k)

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Car{
public:
    string id;
    int x, y;

    Car(string id, int x, int y){
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int dist() const{
        return x * x + y * y;   // square of distance
    }
};

class CarCompare{
public:
    bool operator()(const Car A, const Car B){
        return A.dist() < B.dist(); // max_heap
    }
};

/* bool DistCompare(Car A, Car B){
    return A.dist() < B.dist(); // asending order
} */

void printNearestCars(vector<Car> cars, int k){
    // create a max_heap of size k
    priority_queue<Car, vector<Car>, CarCompare> max_heap(cars.begin(), cars.begin() + k);

    // remaining cars
    for (int i = k; i < cars.size();i++){
        Car car = cars[i];

        if(car.dist() < max_heap.top().dist()){
            max_heap.pop();
            max_heap.push(car);
        }
    }

    // print all the cars inside the heap they will be the smallest
    vector<Car> output;
    while(!max_heap.empty()){
        // cout << max_heap.top().id << endl;
        output.push_back(max_heap.top());
        max_heap.pop();
    }

    // vector of k nearest car
    // sort(output.begin(), output.end(), DistCompare); // Time = O(kLogK)
    reverse(output.begin(), output.end());  // Time = O(k) - becoz cars are in descending order in max heap

    for(auto car:output){
        cout << car.id << endl;
    }
}

int main(){
    int N, K;
    cin >> N >> K;

    string id;
    int x, y;

    vector<Car> cars;

    for (int i = 0; i < N;i++){
        cin >> id >> x >> y;

        Car car(id, x, y);
        cars.push_back(car);
    }

    printNearestCars(cars, K);
}   