#include <iostream>
using namespace std;

// ����������
void insertion_sort(int arr[], int n) {
    // �ӵڶ���Ԫ�ؿ�ʼ�����β��뵽ǰ���������������
    for (int i = 1; i < n; i++) {
        // ���浱ǰԪ��
        int temp = arr[i];
        // �ҵ�����λ��
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            // ���ƽϴ��Ԫ��
            arr[j + 1] = arr[j];
            j--;
        }
        // ���뵱ǰԪ��
        arr[j + 1] = temp;
        // ���ÿ������Ľ��
        cout << "��" << i << "����������";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    // �������������ʹ���������
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // ���ò���������
    insertion_sort(arr, n);
    return 0;
}