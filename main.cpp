#include <iostream>
#include<vector>
#include<stdio.h>
using namespace std;
#define INF 100000;
void djikstra(vector<int>graph[], int dist[], int vertices, bool visit[], int tujuan);
int dist[1000000];


void addedge(vector<int>graph[],int u, int v){
graph[u].push_back(v);
graph[v].push_back(u);
}
int main()
{
vector<int>graph[100000];
	int test = 0;
	scanf("%d", &test);
	while (test) {
		bool visit[100000] = { false };
		int tujuan = 0;
		int vertices = 0;
		int awal, akhir;
		int edges = 0;
		scanf("%d %d", &tujuan, &edges);
		vertices = edges + 1;

		std::fill(dist, dist + vertices+1, 10000000);
		for (int i = 1; i <edges+1; i++) {
			awal=0;
			akhir=0;
			scanf("%d %d", &awal, &akhir);
            addedge(graph,awal,akhir);
		}



		dist[1] = 0;


		for (int i = 1; i < vertices; i++) {
			if (visit[i] == true)
				continue;
			else
				visit[i] = true;

			int y = graph[i].size();
			for (int k = 0; k < graph[i].size(); k++) {
				if (dist[graph[i][k]] > dist[i] + 1)
					dist[graph[i][k]] = dist[i] + 1;
			}
		}
		cout << dist[tujuan]<<"\n";



		test--;
	}

	return 0;
}
