#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int i, n;
    int chazhao;
    int array[100] = { 0 };
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf_s("%d,", &array[i]);
    }
    int left = 0, right = n - 1;
    int temp;
    cin >> chazhao;
    while (left <= right)
    {
        temp = (left + right) / 2;
        if (chazhao == array[temp])
        {
            cout << endl << temp;
            return 0;
        }
        if (chazhao > array[temp])
        {
            left = temp + 1;
            cout << array[temp] << ",";
        }
        if (chazhao < array[temp])
        {
            right = temp - 1;
            cout << array[temp] << ",";
        }

    }
    cout << "no";
    return 0;
}

