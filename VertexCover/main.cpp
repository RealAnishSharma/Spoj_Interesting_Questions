#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

// Constants used by our algorithm
namespace constants {
const int NIL       = 0;
const int MAX_SIZE  = 100000;
const int INF       = 1000000;
}

class HopcroftKarp {
 private:
    // Nodes for both sides in the bipartite graph stored in arrays of vectors
    // We don't care about the values/weights of the nodes, just that they exist
    // Thus, the data structure is as follows:
    //      Array[] Index -> Vector of connecting edge indices { a, b, c }
    //      Example: graph[1] = { 5, 6, 7 } <-- with num_nodes_left = 4
    //      means that node 1 on the left has edges to nodes (5-4), (6-4), (7-4)
    //      on the right, or node 1 on the left has edges to nodes 1, 2, 3
    //      on the right side of the graph.
    // This logic with index node numbering also extends to matching and distance
    std::vector<int> graph[constants::MAX_SIZE];

    // Cached number of nodes on each side
    int num_nodes_left, num_nodes_right;

    // A mapping of matched nodes used during the algorithm
    int matching[constants::MAX_SIZE];

    // Distance stored during search
    int distance[constants::MAX_SIZE];

    // Private functions
    void input_data_test();
    void input_data();
    bool bfs();
    bool dfs(int);
    void output_matching(int);

 public:
    // The only public interface for running the algorithm
    void run();
};


void HopcroftKarp::input_data_test() {
    num_nodes_left = 5;
    num_nodes_right = 4;

    graph[5].push_back(2);
    graph[7].push_back(5);

    graph[1].push_back(2);
    graph[7].push_back(1);

    graph[4].push_back(3);
    graph[8].push_back(4);

    graph[3].push_back(1);
    graph[6].push_back(3);

    graph[2].push_back(2);
    graph[7].push_back(2);

    graph[4].push_back(4);
    graph[9].push_back(4);
}

void HopcroftKarp::input_data() {
    std::cout<<"Enter the number of nodes on LEFT side of bipartite graph: ";
    scanf("%d", &num_nodes_left);

    std::cout<<"Enter the number of nodes on RIGHT side of bipartite graph: ";
    scanf("%d", &num_nodes_right);

    int total_edges, left_edge, right_edge;
    std::cout<<"Enter the total number of edges: ";
    scanf("%d", &total_edges);

    for(int i=0; i<total_edges; i++) {
        std::cout<<"Enter edge indices "<<i+1<<" of "<<total_edges<<" separated by a space: ";
        scanf("%d%d", &left_edge, &right_edge);
        right_edge += num_nodes_left;
        graph[left_edge].push_back(right_edge);
        graph[right_edge].push_back(left_edge);
    }
}

bool HopcroftKarp::bfs() {
    // Standard use of queues to perform BFS
    std::queue<int> queue;
    // Nodes are numbered 1 through n, and don't start from 0
    for(int i = 1; i <= num_nodes_left; i++) {
        // Check to see if there is a matching for this node already
        if(matching[i] == constants::NIL) {
            // Not found, set distance to 0 and add to queue
            distance[i] = 0;
            queue.push(i);
        } else {
            distance[i] = constants::INF;
        }
    }

    distance[constants::NIL] = constants::INF;

    // As long as the queue isn't empty...
    while(!queue.empty()) {
        int left = queue.front();
        queue.pop();
        // Sanity check
        if(left != constants::NIL) {
            // For each node on the right connected to left by an edge...
            for(int right : graph[left]) {
                // If the distance is set to INF/-1, set distance to be
                // that of left node + 1 (for this edge)
                if(distance[ matching[right] ] == constants::INF) {
                    distance[ matching[right] ] = distance[left] + 1;
                    queue.push(matching[right]);
                }
            }
        }
    }
    return (distance[constants::NIL] != constants::INF);
}

bool HopcroftKarp::dfs(int left) {
    // Only proceed with DFS if the node isn't NIL
    if(left != constants::NIL) {
        // For each node on the right connected to left by an edge...
        for(int right : graph[left]) {
            if(distance[ matching[right] ] == distance[ left ] + 1) {
                // Standard DFS recursion
                if(dfs(matching[right])) {
                    matching[left] = right;
                    matching[right] = left;
                    std::cout<<"\n\tFound Matching; left: "<<left<<", right: "<<right;
                    return true;
                }
            }
        }
        distance[left] = constants::INF;
        return false;
    }
    // Node was nil, no further depth search possible; return true
    return true;
}

void HopcroftKarp::output_matching(int num_matching) {
    std::cout<<"\n\tMaximum Cardinality Matching: "<<num_matching<<"\n";
}

void HopcroftKarp::run() {
    // Input data to form bipartite graph
    //input_data();
    input_data_test();

    // Run the algorithm to count max matching
    int num_matching;
    while(bfs()) {
        for(int i = 0; i <= num_nodes_left; i++) {
            if(matching[i] == constants::NIL && dfs(i)) {
                num_matching++;
            }
        }
    }

    // Output function
    output_matching(num_matching);
}

int main() {
    HopcroftKarp algorithm;
    algorithm.run();
    return 0;
}

/*#include<bits/stdc++.h>
using namespace std;
#define NIL 0
#define INF INT_MAX
vector<int> G[100001];
map <int ,int>mapo;
int color[100001],mm,nn;
class BipGraph
{
    int m, n;
    list<int> *adj;
    int *pairU, *pairV, *dist;
public:
    BipGraph(int m, int n);
    void addEdge(int u, int v);
    bool bfs();
    bool dfs(int u);
    int hopcroftKarp();
};

int BipGraph::hopcroftKarp()
{
    pairU = new int[m+1];
    pairV = new int[n+1];
    dist = new int[m+1];

    for (int u=0; u<m; u++) pairU[u] = NIL;
    for (int v=0; v<n; v++) pairV[v] = NIL;

    int result = 0;

    while (bfs())
    {
        for (int u=1; u<=m; u++)
        if (pairU[u]==NIL && dfs(u))
        result++;
    }
    return result;
}

bool BipGraph::bfs()
{
    queue<int> Q;
    for (int u=1; u<=m; u++)
    {
        if (pairU[u]==NIL)
        {
            dist[u] = 0;
            Q.push(u);
        }
        else dist[u] = INF;
    }
    dist[NIL] = INF;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        if (dist[u] < dist[NIL])
        {
            list<int>::iterator i;
            for (i=adj[u].begin(); i!=adj[u].end(); ++i)
            {
                int v = *i;
                if (dist[pairV[v]] == INF)
                {
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    return (dist[NIL] != INF);
}


bool BipGraph::dfs(int u)
{
    if (u != NIL)
    {
        list<int>::iterator i;
        for (i=adj[u].begin(); i!=adj[u].end(); ++i)
        {
            int v = *i;
            if (dist[pairV[v]] == dist[u]+1)
            {
                if (dfs(pairV[v]) == true)
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

BipGraph::BipGraph(int m, int n)
{
    this->m = m;
    this->n = n;
    adj = new list<int>[m+1];
}

void BipGraph::addEdge(int u, int v)
{
    adj[u].push_back(v); adj[v].push_back(u);
}
/*
int main()
{
    BipGraph g(4, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 2);
    g.addEdge(4, 2);
    g.addEdge(4, 4);

    cout << "Size of maximum matching is " << g.hopcroftKarp();

    return 0;
}
*/
void bfso(int s,int N)
{
    queue<int> Q;
    Q.push(s);
    bool visit[N+1];
    memset(visit,false,sizeof(visit));
    memset(color,0,sizeof(color));
    int h;mm=0,nn=0;
    color[s]=1;nn++;
    while(!Q.empty())
    {
        h=Q.front();Q.pop();
        visit[h]=true;

        for(int i=0;i<G[h].size();i++)
        {
            if(!visit[G[h][i]])
            {
                if(color[h]==1) {color[G[h][i]]=2;mm++;}
                else if(color[h]==2) {color[G[h][i]]=1;nn++;}
                Q.push(G[h][i]);
            }
        }
    }
}






int main()
{
    int N,u,v;scanf("%d",&N);

    for(int i=1;i<N;i++)
    {
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }


    bfso(1,N);
    printf("%d %d-\n",nn,mm);
    BipGraph g(nn,mm);
    int k=1,kk=1;
    for(int i=1;i<=N;i++)
    {
        if(color[i]==2) {G[i].clear();
        mapo[i]=k;k++;}
        else{mapo[i]=kk;kk++;}
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {g.addEdge(mapo[i],mapo[G[i][j]]);
        printf("%d %d\n",mapo[i],mapo[G[i][j]]);
    }}

    cout<<g.hopcroftKarp()<<endl;
}

*/
