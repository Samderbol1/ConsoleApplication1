#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target, vector<int>& process) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        process.push_back(nums[mid]);
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> nums[i] >> c;
    }
    int target;
    cin >> target;
    vector<int> process;
    int index = binarySearch(nums, target, process);
    if (index == -1) {
        cout << "no" << endl;
    }
    else {
        cout << index << endl;
        for (int i = 0; i < process.size(); ++i) {
            cout << process[i];
            if (i != process.size() - 1) {
                cout << ",";
            }
        }
        cout << endl;
    }
    return 0;
}