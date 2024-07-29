#include <iostream>
#include <cmath>
using namespace std;

int recursiveHelperSum(int num);
int digitsSuperSumRecursive(int num);

int main()
{
    int sum = 0;
    cin >> sum;
    int summed = digitsSuperSumRecursive(sum);
    cout << "Sum of digits " << sum << " is " << summed << endl;
    return 0;
}

int recursiveHelperSum(int num)
{
    if (num >= 0)
    {
        if (num / 10 < 1)
        {
            return num;
        }
        else 
        {
            return (num % 10) + recursiveHelperSum(num / 10);
        }
    }
    else 
    {
        return -1;
    }
}

int digitsSuperSumRecursive(int num)
{
    int sum = recursiveHelperSum(num);
    if (sum / 10 < 1)
    {
        return sum;
    }
    else 
    {
        return (sum % 10) + recursiveHelperSum(sum / 10);
    }
}

 