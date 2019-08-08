#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char nfiled[1001][1001];
int nvisit[1001][1001][2];
int x, y;
int nRet;

typedef struct pos{
	int x, y, flag;
};

int dirx[] = { -1, 1, 0, 0 };
int diry[] = { 0, 0, -1, 1 };



void bfs()
{

	queue <pos> bfs_q;
	bfs_q.push({ 0, 0, 0 });

	nvisit[0][0][0] = 1;

	pos cur_pos = { 0, };
	pos next_pos = { 0, };

	while (!bfs_q.empty())
	{
		cur_pos = bfs_q.front();
		bfs_q.pop();

		for (int i = 0; i < 4; i++){
			next_pos.x = cur_pos.x + dirx[i];
			next_pos.y = cur_pos.y + diry[i];

			if (next_pos.x >= 0 && next_pos.x < x && next_pos.y >= 0 && next_pos.y < y)
			{

				if (nfiled[next_pos.y][next_pos.x] == '0' && !nvisit[next_pos.y][next_pos.x][cur_pos.flag]){
					nvisit[next_pos.y][next_pos.x][cur_pos.flag] = nvisit[cur_pos.y][cur_pos.x][cur_pos.flag] + 1;
					bfs_q.push({ next_pos.x, next_pos.y, cur_pos.flag });
				}

				if (!cur_pos.flag && nfiled[next_pos.y][next_pos.x] == '1' && !nvisit[next_pos.y][next_pos.x][cur_pos.flag + 1])
				{
					nvisit[next_pos.y][next_pos.x][cur_pos.flag + 1] = nvisit[cur_pos.y][cur_pos.x][cur_pos.flag] + 1;
					bfs_q.push({ next_pos.x, next_pos.y, cur_pos.flag + 1 });
				}

			}
		}
	}
}






int breaking_wall()
{
	int Result = 0;

	bfs();

	if (nvisit[y - 1][x - 1][0] != 0 && nvisit[y - 1][x - 1][1] != 0)
		Result = min(nvisit[y - 1][x - 1][0], nvisit[y - 1][x - 1][1]);

	else if (nvisit[y - 1][x - 1][0] != 0)
		Result = nvisit[y - 1][x - 1][0];

	else if (nvisit[y - 1][x - 1][1] != 0)
		Result = nvisit[y - 1][x - 1][1];

	else
		Result = -1;


	return Result;


}


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> y >> x;

	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			cin >> nfiled[i][j];
		}
	}

	nRet = 0;
	nRet = breaking_wall();

	cout << nRet << endl;

	return 0;
}