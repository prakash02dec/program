// #include <iostream>
// #include <climits>
// #include <iomanip>
// struct Edge
// {
//     int src, dest, weight;
// };
// struct Graph
// {
//     int V, E;
//     struct Edge *edge;
// };
// struct Graph *create_graph(int V, int E)
// {
//     struct Graph *graph = new Graph;
//     graph->V = V;
//     graph->E = E;
//     graph->edge = new Edge[E];
//     return graph;
// }
// void print_array(int dist[], int n)
// {
//     std::cout<< "Vertex Distance from Source" << std::endl;
//     for (int i = 0; i < n; ++i)
//         std::cout<< std::endl << i << std::setw(10)<<std::right<<dist[i];
// }
// void bellman_ford(struct Graph *graph, int src)
// {
//     int V = graph->V;
//     int E = graph->E;
//     int dist[V];
//     for (int i = 0; i < V; i++)
//         dist[i] = INT_MAX;
//     dist[src] = 0;
//     for (int i = 1; i <= V - 1; i++)
//     {
//         for (int j = 0; j < E; j++)
//         {
//             int u = graph->edge[j].src;
//             int v = graph->edge[j].dest;
//             int weight = graph->edge[j].weight;
//             if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
//                 dist[v] = dist[u] + weight;
//         }
//     }
//     for (int i = 0; i < E; i++)
//     {
//         int u = graph->edge[i].src;
//         int v = graph->edge[i].dest;
//         int weight = graph->edge[i].weight;
//         if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
//         {
//             std::cout<<("Graph contains negative weight cycle");
//             return;
//         }
//     }
//     print_array(dist, V);
//     return;
// }
// int main()
// {
//     int V, E;
//     std::cout << "\n\nBellman Ford\n";
//     std::cout << "Enter the No of Vertices : ";
//     std::cin>> V;
//     std::cout << "Enter the No of Edges : ";
//     std::cin>> E;
//     struct Graph *graph = create_graph(V, E);
//     std::cout << "Enter edges Note. Vertex Numbered from (0)\n";
//     for (int i = 0; i < E; i++)
//     {
//         std::cout << "\n\nEnter the edge " << (i + 1) << " : \n";
//         std::cout << "Source : ";
//         std::cin>> graph->edge[i].src;
//         std::cout << "Destination : ";
//         std::cin>> graph->edge[i].dest;
//         std::cout << "Weight : ";
//         std::cin>> graph->edge[i].weight;
//     }
//     std::cout << "\n\n";
//     bellman_ford(graph, 0);
//     std::cout << "\n\n";
//     return 0;
// }

