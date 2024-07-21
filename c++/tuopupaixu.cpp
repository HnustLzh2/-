/**拓扑排序用队列①定义一个队列Q，并把所有入度为0的结点加入队列。
②取队首结点，输出。然后删去所有从它出发的边，并令这些边到达的顶点的入度减1，如果某个顶点的入度减为0，则将其加入队列。
③反复进行②操作，直到队列为空。如果队列为空时入过队的结点数目恰好为N，说明拓扑排序成功，图G为有向无环图;否则，拓扑排序失败，图G中有环。**/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 1010;

vector<int> G[MAXV];//邻接表
int n, m, inDegree[MAXV];//顶点数、边数、入度

//拓扑排序
bool topologicalSort() {
	int num = 0;//记录加入拓扑序列的顶点数
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);//将所有入度为0的顶点入队
		}
	}
	while (!q.empty())
	{
		int u = q.front();//取队首顶点u
		//printf("%d", u);//此处可输出顶点u，作为拓扑序列中的顶点
		q.pop();
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];//u的后继结点v
			inDegree[v]--;//顶点v的入度减1
			if (inDegree[v] == 0) {//顶点v的入度减为0则入队
				q.push(v);
			}
		}
		G[u].clear();//清空顶点u的所有出边（如无必要可不写）
		num++;//加入拓扑序列的顶点加1
	}
	if (num == n) return true;//加入拓扑序列的顶点数为n，说明拓扑排序成功
	else return false;//加入拓扑序列的顶点数小于n，说明拓扑排序失败
}

int main() {
	fill(inDegree, inDegree + MAXV, 0);//初始化
	cin >> n >> m;//输入顶点数和边数
	int x, y;//分别代表出顶点和入顶点
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		G[x].push_back(y);
		inDegree[y]++;
	}
	cout << topologicalSort() << endl;

	return 0;
}
