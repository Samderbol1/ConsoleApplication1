#include <iostream>
#include <queue>
using namespace std;

// ʹ�ù�����ȱ����㷨����һ����㿪ʼ�������������ڽӵĽ�㣬�����Ϊ�ѷ���
void bfs(int A[][100], int n, int start, bool visited[]) {
    // ����һ�����У��洢�����ʵĽ��
    queue<int> q;
    // ����ʼ�����ӣ������Ϊ�ѷ���
    q.push(start);
    visited[start] = true;
    // �����в�Ϊ��ʱ��ѭ��ִ�����²���
    while (!q.empty()) {
        // ȡ�����׽��
        int u = q.front();
        q.pop();
        // �����������ڽӵĽ��
        for (int v = 0; v < n; v++) {
            // ����ڽ���δ���ʹ�������ӣ������Ϊ�ѷ���
            if (A[u][v] == 1 && !visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

// �ж�ͼ����ͨ�����ĸ���
int count_components(int A[][100], int n) {
    // ����һ���������飬��¼ÿ������Ƿ񱻷��ʹ�
    bool visited[n];
    // ��ʼ��Ϊfalse����ʾ��δ���ʹ�
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    // ����һ������������¼��ͨ�����ĸ���
    int count = 0;
    // ����ÿ����㣬���δ���ʹ�����Ӹý�㿪ʼ������ȱ�����������������һ
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(A, n, i, visited);
            count++;
        }
    }
    // ���ؼ�������ֵ
    return count;
}

int main() {
    // ����ͼ�Ľ��������ڽӾ���
    int n;
    cin >> n;
    int A[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    // ���ú����ж���ͨ�����ĸ�������������
    int ans = count_components(A, n);
    cout << ans << endl;
    return 0;
}