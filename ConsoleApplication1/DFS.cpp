#include <stdio.h>
#define MAX_VERtEX_NUM 20                   //�����������
#define VRType int                          //��ʾ����֮���ϵ������, 0 ��ʾ�����ڣ�1 ��ʾ����
#define VertexType int                      //ͼ�ж������������
#define States int         //����bool�ͳ���
bool visited[MAX_VERtEX_NUM];               //����ȫ�����飬���ͼ�еĸ��������Ƿ񱻷��ʹ�

typedef struct {
    VRType adj;                             //�� 1 �� 0 ��ʾ�Ƿ����ڣ�
}ArcCell, AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERtEX_NUM];        //�洢ͼ�еĶ���
    AdjMatrix arcs;                         //��ά���飬��¼����֮��Ĺ�ϵ
    int vexnum, arcnum;                      //��¼ͼ�Ķ������ͻ����ߣ���
}MGraph;

//���ݶ������ݣ����ض����ڶ�ά�����е�λ���±�
int LocateVex(MGraph* G, VertexType v) {
    int i = 0;
    //����һά���飬�ҵ�����v
    for (; i < G->vexnum; i++) {
        if (G->vexs[i] == v) {
            break;
        }
    }
    //����Ҳ����������ʾ��䣬����-1
    if (i > G->vexnum) {
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}

//��������ͼ
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
        G->arcs[m][n].adj = 1;//����ͼ�Ķ��׾��������Խ��߶Գ�
    }
    return 1;
}

int FirstAdjVex(MGraph G, int v)
{
    int i;
    //���������±� v ���Ķ��㣬�ҵ���һ���������ڵĶ��㣬�����ظö���������±�
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
    //���������±� v ���Ķ��㣬�� w λ�ÿ�ʼ�������Һ������ڵĶ��㣬�����ظö���������±�
    for (i = w + 1; i < G.vexnum; i++) {
        if (G.arcs[v][i].adj) {
            return i;
        }
    }
    return -1;
}

void DFS(MGraph G, int v) {
    int w;
    printf("%d ", G.vexs[v]);  //���ʵ� v ������
    visited[v] = true;         //���� v ������ı������Ϊtrue
    //������� v ���������ڵ��������㣬�������������������㷨
    for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)) {
        //����ö���ı��Ϊfalse��֤����δ�����ʣ��͵���������������㷨
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}

//�����������
void DFSTraverse(MGraph G) {
    int v;
    //visit�����¼���������Ƿ��Ѿ����ʹ���ȫ����ʼ��Ϊ false
    for (v = 0; v < G.vexnum; ++v) {
        visited[v] = false;
    }
    //����ÿ�����Ϊfalse�Ķ��㣬������һ��������������㷨
    for (v = 0; v < G.vexnum; v++) {
        //����ö���ı��λΪfalse���͵���������������㷨
        if (!visited[v]) {
            DFS(G, v);
        }
    }
}

int main() {
    MGraph G;      //����һ��ͼ
    CreateDN(&G);  //��ʼ��ͼ
    DFSTraverse(G);//�����������ͼ
    return 0;
}