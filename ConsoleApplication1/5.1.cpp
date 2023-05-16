#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& nums, int n) {
    for (int i = 1; i < n; ++i) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
        for (int k = 0; k < n; ++k) {
            cout << nums[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    insertionSort(nums, n);
    return 0;
}