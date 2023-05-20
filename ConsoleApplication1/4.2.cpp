#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ����һ���ṹ�壬�洢ͼ����Ϣ
struct Book {
    string id; // ���
    string name; // ����
    double price; // �۸�
};

// ����һ��˳����洢ͼ����Ϣ��
struct List {
    Book* data; // ��̬���飬�洢ͼ����Ϣ
    int size; // ��Ĵ�С
    int capacity; // �������
};

// ��ʼ��һ���յ�˳���������ʼ����
void init_list(List& L, int cap) {
    L.data = new Book[cap]; // ���䶯̬����ռ�
    L.size = 0; // ��ʼ����Ĵ�СΪ0
    L.capacity = cap; // ��¼�������
}

// ����˳����ͷŶ�̬����ռ�
void destroy_list(List& L) {
    delete[] L.data; // �ͷŶ�̬����ռ�
    L.size = 0; // ����Ĵ�С��Ϊ0
    L.capacity = 0; // �����������Ϊ0
}

// ��˳����ĩβ����һ��ͼ����Ϣ
void insert_list(List& L, Book b) {
    // �����Ĵ�С���ڱ��������˵��û�пռ���룬��Ҫ����
    if (L.size == L.capacity) {
        // ����һ���µĶ�̬���飬����Ϊԭ��������
        Book* new_data = new Book[L.capacity * 2];
        // ��ԭ�������ݸ��Ƶ��µ�������
        for (int i = 0; i < L.size; i++) {
            new_data[i] = L.data[i];
        }
        // ɾ��ԭ��������ռ�
        delete[] L.data;
        // ���µ����鸳ֵ��L.data��������L.capacity
        L.data = new_data;
        L.capacity *= 2;
    }
    // �ڱ��ĩβ����ͼ����Ϣ��������L.size
    L.data[L.size] = b;
    L.size++;
}
// ���Ҽ۸���ߵ�ͼ�飬�������Ӧ��Ϣ
void find_max_price(List& L) {
    // �����Ϊ�գ�ֱ�ӷ���
    if (L.size == 0) {
        return;
    }
    // ����һ����������¼��߼۸�
    double max_price = L.data[0].price;
    // �������е�ÿ��ͼ�飬������߼۸�
    for (int i = 1; i < L.size; i++) {
        if (L.data[i].price > max_price) {
            max_price = L.data[i].price;
        }
    }
    // ����һ������������¼��߼۸��ͼ�����
    int count = 0;
    // �������е�ÿ��ͼ�飬����۸������߼۸����������һ�������ͼ����Ϣ
    for (int i = 0; i < L.size; i++) {
        if (L.data[i].price == max_price) {
            count++;
            if (count == 1) { // ����ǵ�һ����߼۸��ͼ�飬�����������
                cout << count << endl;
            }
            cout << L.data[i].id << " " << L.data[i].name << " " << fixed << setprecision(2) << L.data[i].price << endl;
        }
    }
}
int main() {
    // ����ͼ����Ŀ�ͳ�ʼ�����������������ã�
    int n, cap;
    cin >> n >> cap;
    // ��ʼ��һ���յ�˳���
    List L;
    init_list(L, cap);
    // ����ÿ��ͼ�����Ϣ�������뵽˳�����
    for (int i = 0; i < n; i++) {
        Book b;
        cin >> b.id >> b.name >> b.price;
        insert_list(L, b);
    }
    // ���Ҽ۸���ߵ�ͼ�飬�������Ӧ��Ϣ
    find_max_price(L);
    // ����˳����ͷŶ�̬����ռ�
    destroy_list(L);
    return 0;
}