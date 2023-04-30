#include <stdio.h>
#define MAX_VERtEX_NUM 20                   //顶点的最大个数
#define VRType int                          //表示顶点之间关系的类型, 0 表示不相邻，1 表示相邻
#define VertexType int                      //图中顶点的数据类型
#define States int         //定义bool型常量
bool visited[MAX_VERtEX_NUM];               //设置全局数组，标记图中的各个顶点是否被访问过

typedef struct {
    VRType adj;                             //用 1 或 0 表示是否相邻；
}ArcCell, AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERtEX_NUM];        //存储图中的顶点
    AdjMatrix arcs;                         //二维数组，记录顶点之间的关系
    int vexnum, arcnum;                      //记录图的顶点数和弧（边）数
}MGraph;

//根据顶点数据，返回顶点在二维数组中的位置下标
int LocateVex(MGraph* G, VertexType v) {
    int i = 0;
    //遍历一维数组，找到变量v
    for (; i < G->vexnum; i++) {
        if (G->vexs[i] == v) {
            break;
        }
    }
    //如果找不到，输出提示语句，返回-1
    if (i > G->vexnum) {
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}

//构造无向图
States CreateDN(MGraph* G) {
    int i, j, n, m;
    int v1, v2;
    scanf_s("%d,%d", &(G->vexnum), &(G->arcnum));
    for (i = 0; i < G->vexnum; i++) {
        scanf_s("%d", &(G->vexs[i]));
    }
    for (i = 0; i < G->vexnum; i++) {
        for (j = 0; j < G->vexnum; j++) {
            G->arcs[i][j].adj = 0;
        }
    }
    for (i = 0; i < G->arcnum; i++) {
        scanf_s("%d,%d", &v1, &v2);
        n = LocateVex(G, v1);
        m = LocateVex(G, v2);
        if (m == -1 || n == -1) {
            printf("no this vertex\n");
            return -1;
        }
        G->arcs[n][m].adj = 1;
        G->arcs[m][n].adj = 1;//无向图的二阶矩阵沿主对角线对称
    }
    return 1;
}

int FirstAdjVex(MGraph G, int v)
{
    int i;
    //对于数组下标 v 处的顶点，找到第一个和它相邻的顶点，并返回该顶点的数组下标
    for (i = 0; i < G.vexnum; i++) {
        if (G.arcs[v][i].adj) {
            return i;
        }
    }
    return -1;
}

int NextAdjVex(MGraph G, int v, int w)
{
    int i;
    //对于数组下标 v 处的顶点，从 w 位置开始继续查找和它相邻的顶点，并返回该顶点的数组下标
    for (i = w + 1; i < G.vexnum; i++) {
        if (G.arcs[v][i].adj) {
            return i;
        }
    }
    return -1;
}

void DFS(MGraph G, int v) {
    int w;
    printf("%d ", G.vexs[v]);  //访问第 v 个顶点
    visited[v] = true;         //将第 v 个顶点的标记设置为true
    //对于与第 v 个顶点相邻的其它顶点，逐个调用深度优先搜索算法
    for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)) {
        //如果该顶点的标记为false，证明尚未被访问，就调用深度优先搜索算法
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}

//深度优先搜索
void DFSTraverse(MGraph G) {
    int v;
    //visit数组记录各个顶点是否已经访问过，全部初始化为 false
    for (v = 0; v < G.vexnum; ++v) {
        visited[v] = false;
    }
    //对于每个标记为false的顶点，都调用一次深度优先搜索算法
    for (v = 0; v < G.vexnum; v++) {
        //如果该顶点的标记位为false，就调用深度优先搜索算法
        if (!visited[v]) {
            DFS(G, v);
        }
    }
}

int main() {
    MGraph G;      //建立一个图
    CreateDN(&G);  //初始化图
    DFSTraverse(G);//深度优先搜索图
    return 0;
}