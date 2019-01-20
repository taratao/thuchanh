/*
Bài 4
Cho một đồ thị vô hướng, không khuyên, không đa cung có n đỉnh và m cung.

Viết chương trình tính và in ra màn hình đỉnh có bậc lớn nhất và bậc tương ứng của nó. Nếu có nhiều đỉnh có bật bằng nhau thì in ra đỉnh có số thứ tự nhỏ nhất.

Đầu vào (Input):

Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

- Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.

- m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v mô tả cung (u, v)

Đầu ra (Output):

In ra màn hình đỉnh có bậc lớn nhất và bậc của nó.

Xem thêm ví dụ bên dưới.

Trong ví dụ đầu tiên ta có:

+ Bậc của đỉnh 1 là 1,
+ Bậc của đỉnh 2 là 3
+ Bậc của đỉnh 3 là 2
+ Bậc của đỉnh 4 là 2
Vậy đỉnh có bậc lớn nhất là đỉnh 2 và bậc của nó là 3. Vì thế ta in ra:

2 3

Chú ý:

Để chạy thử chương trình, bạn nên tạo một tập tin dt.txt chứa đồ thị cần kiểm tra.
Thêm dòng freopen("dt.txt", "r", stdin); vào ngay sau hàm main(). Khi nộp bài, nhớ gỡ bỏ dòng này ra.
Có thể sử dụng đoạn chương trình đọc dữ liệu mẫu sau đây:
*/
#include <stdio.h>
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
    int A[100][500];
    int n, m;
} Graph;

typedef struct {
    ElementType data[MAX_ELEMENTS];
    int size;
} List;
/* Tao danh sach rong */
void make_null(List* L) {
    L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List* L, ElementType x) {
    L->data[L->size] = x;
    L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
ElementType element_at(List* L, int i) {
    return L->data[i-1];
}
/* Tra ve so phan tu cua danh sach */
int count_list(List* L) {
    return L->size;
}


void init_graph(Graph *pG, int n, int m){
	pG->n = n;
	pG->m = m;
	int i, j;
	for(i = 1; j <= n; i++){
		for(j = 1; j <= m; j++){
			pG->A[i][j] = 0;
		}
	}
}

void add_edge(Graph *pG, int e, int x, int y){
	pG->A[x][e] = 1;
	pG->A[y][e] = 1;
}

int deg(Graph *G, int x){
	int dg = 0;
	int i;
	for(i = 1; i <= G->m; i++){
		dg += G->A[x][i];
	}
	return dg;
}

int main(){
	int n, m, i, u, v;
	Graph G;
	scanf("%d%d", &n, &m);
	init_graph(&G, n, m);
	for(i = 1; i <= m; i++){
		scanf("%d%d", &v, &u);
		add_edge(&G,i,v,u);
	}
	
	int max = deg(&G,1);
	int j = 1;
	
	for(i = 1; i <= n; i++){
		if(deg(&G,i) > max){
			max = deg(&G,i);
			j = i;
		}
	}
	
	printf("%d %d", j, max);
	return 0;
}
