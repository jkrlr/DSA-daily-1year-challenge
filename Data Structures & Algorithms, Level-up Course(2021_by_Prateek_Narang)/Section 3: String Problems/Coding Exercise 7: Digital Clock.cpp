#include <string>
using namespace std;

string convert_to_digital_time(int minutes)
{
    string hour = to_string(minutes / 60);
    int temp = minutes % 60;
    string min;

    if (temp < 10)
        min = "0" + to_string(temp);
    else
        min = to_string(temp);

    string time = hour + ":" + min;

    return time;
}
