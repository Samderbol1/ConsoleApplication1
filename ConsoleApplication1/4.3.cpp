#include <iostream>
using namespace std;

// 插入排序函数
void insertion_sort(int arr[], int n) {
    // 从第二个元素开始，依次插入到前面已排序的序列中
    for (int i = 1; i < n; i++) {
        // 保存当前元素
        int temp = arr[i];
        // 找到插入位置
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            // 后移较大的元素
            arr[j + 1] = arr[j];
            j--;
        }
        // 插入当前元素
        arr[j + 1] = temp;
        // 输出每趟排序的结果
        cout << "第" << i << "趟排序结果：";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    // 输入整数个数和待排序整数
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // 调用插入排序函数
    insertion_sort(arr, n);
    return 0;
}