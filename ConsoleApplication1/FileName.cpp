#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

// Define a constant variable for the size of the array
const int MAX_SIZE = 100;

int main()
{
    int i, n;
    int key; // Use a meaningful name for the value to be searched
    int array[MAX_SIZE] = { 0 }; // Use the constant variable for the size
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> array[i]; // Use cin instead of scanf
    }
    int left = 0, right = n - 1;
    int mid; // Use a meaningful name for the middle position
    cin >> key;
    bool found = false; // Use a boolean variable to store the result of the search
    vector<int> mids; // Use a vector to store all the mid values in the process
    while (left <= right)
    {
        mid = (left + right) / 2;
        mids.push_back(mid); // Append each mid value to the vector
        if (key == array[mid])
        {
            found = true; // Set the result to true if the key is found
            break; // Stop the loop
        }
        if (key > array[mid])
        {
            left = mid + 1;
        }
        if (key < array[mid])
        {
            right = mid - 1;
        }

    }

    if (found) { // If the key is found
        cout << array[mid]+1 << endl; // Print the value of temp
    }
    else { // If the key is not found
        cout << "no" << endl; // Print "no"
    }

    for (int i = 0; i < mids.size(); i++) { // Loop through all the mid values in the vector
        cout << array[mids[i]]; // Print each mid value
        if (i < mids.size() - 1) { // If it is not the last value
            cout << ","; // Print a comma to separate them
        }
    }

    return 0;
}
