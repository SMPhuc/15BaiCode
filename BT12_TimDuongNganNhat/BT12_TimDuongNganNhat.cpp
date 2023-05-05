#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct Edge {
    int source, target, weight;
};

vector<int> bellmanFord(int vertices, int start, vector<Edge> edges) {
    vector<int> distances(vertices, INT_MAX);
    distances[start] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        for (Edge e : edges) {
            int u = e.source;
            int v = e.target;
            int w = e.weight;
            if (distances[u] != INT_MAX && distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
            }
        }
    }

    for (Edge e : edges) {
        int u = e.source;
        int v = e.target;
        int w = e.weight;
        if (distances[u] != INT_MAX && distances[u] + w < distances[v]) {
            distances[v] = INT_MIN;
        }
    }

    return distances;
}

int main() {
    int vertices, edges_count, start;
    cin >> vertices >> edges_count >> start;

    vector<Edge> edges;
    for (int i = 0; i < edges_count; i++) {
        int source, target, weight;
        cin >> source >> target >> weight;
        edges.push_back({ source, target, weight });
    }

    vector<int> distances = bellmanFord(vertices, start, edges);

    for (int i = 0; i < vertices; i++) {
        if (distances[i] == INT_MAX) {
            cout << "Khong the den dinh " << i << endl;
        }
        else if (distances[i] == INT_MIN) {
            cout << "Dinh " << i << " co khoang cach la -vo cuc" << endl;
        }
        else {
            cout << "Khoang cach ngan nhat tu " << start << " den dinh " << i << " la " << distances[i] << endl;
        }
    }

    return 0;
}
