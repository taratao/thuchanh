/*
Bài 6:
Hãy viết chương trình đọc đồ thị từ tập tin và hiển thị ma trận kề của đồ thị này.

Giả sử đồ thị được cho là đồ thị vô hướng đơn.

Đầu vào (Input):

Dữ liệu đầu vào được nhập từ tập tin dt1.txt với định dạng:

- Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.

- m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v mô tả cung (u, v).

Đầu ra (Output):

In ra Ma trận kề (0/1) của đồ thị

Ví dụ:

Nếu đầu vào là:
4 4
1 2
1 3
2 3
3 4
Kết quả là:
0 1 1 0 
1 0 1 0 
1 1 0 1 
0 0 1 0
*/

#include <stdio.h>

typedef struct {
    int A[100][500];
    int n;
} Graph;

void init_graph(Graph *G, int n){
	G->n = n;
	int i, j;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			G->A[i][j] = 0;
		}
	}
}

void add_edge(Graph *pG, int x, int y){
	pG->A[x][y] = 1;
	pG->A[y][x] = 1;
}

int main(){
  freopen("dt1.txt", "r", stdin);
	int n, m, i, j, u, v;
	Graph G;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(i = 1; i <= m; i++){
		scanf("%d%d", &v, &u);
		add_edge(&G,v,u);
	}
    for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			printf("%d ", G.A[i][j]);
		}
		printf("\n");
	}
	return 0;
}
