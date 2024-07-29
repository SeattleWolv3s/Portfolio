#include <iostream> 
using namespace std;

int main() {
    int seconds;
    cout << "Enter how many seconds:" << endl;
    cin >> seconds;
    int minutes = (seconds / 60);
    int seconds_1 = seconds - (minutes * 60);
    int hours = (minutes / 60);
    int minutes_1 = minutes - (hours * 60);
    int days = (hours / 24);
    int hours_1 = hours - (days * 24);
    cout << "The time is " << days << " day(s), " << hours_1 << " hour(s), " << minutes_1 << " minute(s), and " << seconds_1 << " second(s)." << endl;
    return 0;
}
