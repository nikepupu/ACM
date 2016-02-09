#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 105
#define inf (1LL << 56)
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

long long dis[MAX][MAX];
int t, n, m, U[1 << 16], V[1 << 16], C[1 << 16];

int main(){
    read();
    write();
    int T = 0, i, j, k, u, v, c;

    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &n, &m);
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (i == j) dis[i][j] = 0;
                else dis[i][j] = inf;
            }
        }

        for (i = 0; i < m; i++){
            scanf("%d %d %d", &U[i], &V[i], &C[i]);
            u = U[i], v = V[i], c = C[i];
            if (c < dis[u][v]) dis[u][v] = c;
            if (c < dis[v][u]) dis[v][u] = c;
        }

        for (k = 0; k < n; k++){
            for (i = 0; i < n; i++){
                for (j = 0; j < n; j++){
                    if (dis[i][j] > (dis[i][k] + dis[k][j])){
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }

        printf("Case #%d:\n", ++T);
        for (i = 0; i < m; i++){
            int flag = 0;
            u = U[i], v = V[i], c = C[i];

            for (j = 0; j < n; j++){
                for (k = 0; k < n; k++){
                    if (j == k) continue;

                    long long x = dis[j][k];
                    long long y = dis[u][j] + dis[k][v] + c;
                    if (x == y){
                        flag = 1;
                        goto Skip;
                    }
                }
            }

            Skip:
                if (!flag) printf("%d\n", i);
        }
    }
    return 0;
}
