#include <stdio.h>
#include <queue>
#include <algorithm>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

int nfiled[1001][1001];
int nvisit[1001][1001];
int x, y;
int nRet;

typedef struct pos{
	int x, y, dis;
	bool flag;
};

int dirx[] = { 0, 0, 1, -1 };
int diry[] = { 1, -1, 0, 0 };



int bfs()
{
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			nvisit[i][j] = 0;

	queue <pos> bfs_q;
	bfs_q.push({ 0, 0, 0, true });

	nvisit[0][0] = 1;

	pos cur_pos = { 0, }; 
	pos next_pos = { 0, };
	
	int dis = 0;

	while (!bfs_q.empty())
	{
		cur_pos = bfs_q.front();
		bfs_q.pop();

		for (int i = 0; i < 4; i++){
			next_pos.x = cur_pos.x + dirx[i];
			next_pos.y = cur_pos.y + diry[i];
			next_pos.dis = cur_pos.dis;
			next_pos.flag = cur_pos.flag;

			if (next_pos.x == x - 1 && next_pos.y == y - 1){
				return next_pos.dis + 2;
			}

			if (next_pos.x >= 0 && next_pos.x < x && next_pos.y >= 0 && next_pos.y < y
				&& !nvisit[next_pos.y][next_pos.x]){

				if (nfiled[next_pos.y][next_pos.x]){
					if (next_pos.flag){
						dis = next_pos.dis + 1;
						bfs_q.push({ next_pos.x, next_pos.y, dis, false });
						nvisit[next_pos.y][next_pos.x] = 1;
					}
				}
				else{
					dis = next_pos.dis + 1;
					bfs_q.push({ next_pos.x, next_pos.y, dis, next_pos.flag });
					nvisit[next_pos.y][next_pos.x] = 1;
				}
			}
		}
	}

	return -1;
}






int breaking_wall()
{
	int temp_dis = 0;

	temp_dis = bfs();
	nRet = min(temp_dis, nRet);

	
	return 0;


}


int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &y, &x);

	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			scanf("%d", &nfiled[i][j]);
		}
	}

	nRet = 987654321;
	breaking_wall();

	if (nRet == 987654321){
		nRet = -1;
	}

	printf("%d\n", nRet);



	
	return 0;
}