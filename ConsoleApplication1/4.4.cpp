#include <iostream>
#include <queue>
using namespace std;

// 使用广度优先遍历算法，从一个结点开始，遍历其所有邻接的结点，并标记为已访问
void bfs(int A[][100], int n, int start, bool visited[]) {
    // 创建一个队列，存储待访问的结点
    queue<int> q;
    // 将起始结点入队，并标记为已访问
    q.push(start);
    visited[start] = true;
    // 当队列不为空时，循环执行以下操作
    while (!q.empty()) {
        // 取出队首结点
        int u = q.front();
        q.pop();
        // 遍历其所有邻接的结点
        for (int v = 0; v < n; v++) {
            // 如果邻接且未访问过，则入队，并标记为已访问
            if (A[u][v] == 1 && !visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

// 判断图的连通分量的个数
int count_components(int A[][100], int n) {
    // 创建一个布尔数组，记录每个结点是否被访问过
    bool visited[n];
    // 初始化为false，表示都未访问过
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    // 创建一个计数器，记录连通分量的个数
    int count = 0;
    // 遍历每个结点，如果未访问过，则从该结点开始广度优先遍历，并将计数器加一
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(A, n, i, visited);
            count++;
        }
    }
    // 返回计数器的值
    return count;
}

int main() {
    // 输入图的结点个数和邻接矩阵
    int n;
    cin >> n;
    int A[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    // 调用函数判断连通分量的个数，并输出结果
    int ans = count_components(A, n);
    cout << ans << endl;
    return 0;
}