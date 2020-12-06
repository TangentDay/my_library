const ll INF = 1e18;

struct edge{ll to,cost;};
 
VL dijkstra(vector<vector<edge> > graph, int start){
    int n = graph.size();
    VL d(n, INF);
    d[start] = 0;
    priority_queue<PL, vector<PL>, greater<PL> > que;
    que.push(make_pair(0, start));
    while (!que.empty()){
        PL a = que.top();
        que.pop();
        int now = a.second;
        if(d[now] < a.first) continue;
        REP(i,graph[now].size()){
            edge e = graph[now][i];
            int next = e.to;
            if (d[next] > d[now] + e.cost){
                d[next] = d[now] + e.cost;
                que.push(make_pair(d[next], next));
            }
        }
    }
    return d;
}