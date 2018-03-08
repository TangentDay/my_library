#define INF 1e15

struct edge{ll to,cost;};
 
VL dijkstra(vector<vector<edge> > graph){
    int n = graph.size();
    VL d(n, INF);
    d[0] = 0;
    priority_queue<PL, vector<PL>, greater<PL> > q;
    q.push(make_pair(0, 0));
    while (!q.empty()){
        PL a = q.top();
        q.pop();
        int now = a.second;
        if(d[now] < a.first) continue;
        REP(i,graph[now].size()){
            edge e = graph[now][i];
            int next = e.to;
            if (d[next] > d[now] + e.cost){
                d[next] = d[now] + e.cost;
                q.push(make_pair(d[next], next));
            }
        }
    }
    return d;
}