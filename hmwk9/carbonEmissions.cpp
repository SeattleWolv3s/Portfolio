#include <iostream>
#include <vector>
using namespace std;

double emissionReduction(double current_reduction, int years);

int main()
{
    double emissions;
    int years;
    cin >> emissions;
    cin >> years;
    double prediction = emissionReduction(emissions, years);
    cout << prediction << endl;
    return 0;
}

double emissionReduction(double current_reduction, int years)
{
    if (current_reduction < 0 || years < 0)
    {
        return -1;
    }
    else if (years == 0)
    {
        return current_reduction;
    }
    else 
    {
        int tick = years;
        double new_reduction = current_reduction;
        if (tick == 0)
        {
            return new_reduction;
        }
        else
        {
            tick = tick - 1;
            new_reduction = emissionReduction((new_reduction + (0.1 * new_reduction) + 20), tick);
            return new_reduction;
        }
    }
}