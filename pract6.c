#include <stdio.h>
#define V 6
#define INF 99999

int main() {
    double lat[V] = {21.1458, 21.1490, 21.1415, 21.1465, 21.1501, 21.1432};
    double lon[V] = {79.0882, 79.0950, 79.1002, 79.0825, 79.1103, 79.0899};

    int u[100], v[100];
    double w[100];
    int E = V * (V - 1);
    int k = 0;

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(i != j) {
                u[k] = i;
                v[k] = j;
                double d1 = lat[i] - lat[j];
                if(d1 < 0) d1 = -d1;
                double d2 = lon[i] - lon[j];
                if(d2 < 0) d2 = -d2;
                w[k] = d1 + d2;
                k++;
            }
        }
    }

    double dist[V];
    int source = 0;

    for(int i = 0; i < V; i++)
        dist[i] = INF;

    dist[source] = 0;

    for(int i = 0; i < V - 1; i++) {
        for(int j = 0; j < E; j++) {
            if(dist[u[j]] + w[j] < dist[v[j]]) {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }

    printf("Shortest Distance from Pickup Point 0:\n");
    for(int i = 0; i < V; i++) {
        printf("0 to %d = %lf\n", i, dist[i]);
    }

    return 0;
}

