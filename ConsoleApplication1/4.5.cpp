#include <iostream>
using namespace std;

// 使用折半查找法查找关键值k的位置，并输出查找过程
int binary_search(int A[], int N, int k) {
    // 定义左右边界
    int left = 0;
    int right = N - 1;
    // 定义一个标志，记录是否输出过逗号
    bool flag = false;
    // 当左右边界不相交时，循环执行以下操作
    while (left <= right) {
        // 计算中间位置
        int mid = (left + right) / 2;
        // 输出中间位置的值，如果之前已经输出过，则先输出逗号
        if (flag) {
            cout << ",";
        }
        cout << A[mid];
        flag = true;
        // 如果中间位置的值等于k，则返回该位置
        if (A[mid] == k) {
            return mid;
        }
        // 如果中间位置的值大于k，则将右边界移动到中间位置的左边
        else if (A[mid] > k) {
            right = mid - 1;
        }
        // 如果中间位置的值小于k，则将左边界移动到中间位置的右边
        else {
            left = mid + 1;
        }
    }
    // 如果循环结束还没有找到k，则返回-1表示不存在
    return -1;
}

int main() {
    // 输入数组大小和数组元素
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    // 输入关键值k
    int k;
    cin >> k;
    // 调用函数查找k的位置，并输出结果
    int ans = binary_search(A, N, k);
    if (ans == -1) {
        cout << "no" << endl;
    }
    else {
        cout << ans << endl;
    }
    return 0;
}