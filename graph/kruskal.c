#include <stdio.h>

#define MAX 20

struct Edge
{
    int u, v, w;
};

struct Edge edge[MAX];
int parent[MAX];
int n, e;

/* Find parent */
int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

/* Union of two sets */
void unionSet(int i, int j)
{
    parent[j] = i;
}

/* Sort edges by weight */
void sort()
{
    struct Edge temp;
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edge[j].w > edge[j + 1].w)
            {
                temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int count = 0, sum = 0;
    int u, v, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++)
    {
        printf("Enter edge (u v w): ");
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    }

    sort();

    for (i = 0; i < e && count < n - 1; i++)
    {
        u = find(edge[i].u);
        v = find(edge[i].v);

        if (u != v)
        {
            unionSet(u, v);
            printf("Edge (%d, %d) = %d\n", edge[i].u, edge[i].v, edge[i].w);
            sum += edge[i].w;
            count++;
        }
    }

    printf("Minimum cost = %d\n", sum);
    return 0;
}
