#include <iostream>
using namespace std;

int main() {
    int initial_indoor = 12;
    int initial_outdoor = 18; 
    float indoor_fill = 0.4;
    float outdoor_fill = 0.7;
    float indoor_leak = 0.3;
    float outdoor_leak = 0.4;
    int time;
    cout << "How many hours have passed?" << endl;
    cin >> time;
    cout << "The indoor pool has " << initial_indoor + ((indoor_fill - indoor_leak) * time) << "inches of water, and the outdoor pool has " << initial_outdoor + ((outdoor_fill - outdoor_leak) * time) << "inches of water." << endl;
    return 0;
}
