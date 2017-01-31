#include<iostream>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;

int main ()
{
    cout << "Input three different integers: ";
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int sum = n1 + n2 + n3, 
        avg = sum / 3, 
        pro = n1 * n2 * n3,
        min_ = min(n1, min(n2, n3)),
        max_ = max(n1, max(n2, n3));

    cout << "Sum is " << sum << endl
        << "Average is " << avg << endl
        << "Product is " << pro << endl
        << "Smallest is " << min_ << endl
        << "Largest is " << max_ << endl;

    return 0;
}
