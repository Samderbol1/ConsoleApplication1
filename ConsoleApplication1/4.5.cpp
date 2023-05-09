#include <iostream>
using namespace std;

// ʹ���۰���ҷ����ҹؼ�ֵk��λ�ã���������ҹ���
int binary_search(int A[], int N, int k) {
    // �������ұ߽�
    int left = 0;
    int right = N - 1;
    // ����һ����־����¼�Ƿ����������
    bool flag = false;
    // �����ұ߽粻�ཻʱ��ѭ��ִ�����²���
    while (left <= right) {
        // �����м�λ��
        int mid = (left + right) / 2;
        // ����м�λ�õ�ֵ�����֮ǰ�Ѿ�������������������
        if (flag) {
            cout << ",";
        }
        cout << A[mid];
        flag = true;
        // ����м�λ�õ�ֵ����k���򷵻ظ�λ��
        if (A[mid] == k) {
            return mid;
        }
        // ����м�λ�õ�ֵ����k�����ұ߽��ƶ����м�λ�õ����
        else if (A[mid] > k) {
            right = mid - 1;
        }
        // ����м�λ�õ�ֵС��k������߽��ƶ����м�λ�õ��ұ�
        else {
            left = mid + 1;
        }
    }
    // ���ѭ��������û���ҵ�k���򷵻�-1��ʾ������
    return -1;
}

int main() {
    // ���������С������Ԫ��
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    // ����ؼ�ֵk
    int k;
    cin >> k;
    // ���ú�������k��λ�ã���������
    int ans = binary_search(A, N, k);
    if (ans == -1) {
        cout << "no" << endl;
    }
    else {
        cout << ans << endl;
    }
    return 0;
}