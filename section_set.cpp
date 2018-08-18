struct section_set{
    // [l, r]
    const int INF = 1e9;
    set<P> st = {P(-INF, -INF), P(INF, INF)};

    void insert_point(int x){
        int l = x, r = x;
        auto sec = st.lower_bound(P(x + 1, 0));
        if (sec->first == x + 1){
            r = sec->second;
            st.erase(sec);
        }
        sec = st.lower_bound(P(x + 1, 0));
        sec--;
        if (sec->second == x - 1){
            l = sec->first;
            st.erase(sec);
        }
        st.insert(P(l, r));
    }

    int right(int x){
        auto sec = st.lower_bound(P(x + 1, 0));
        if (sec->first == x + 1){
            return sec->second + 1;
        }else{
            return x + 1;
        }
    }

    int left(int x){
        auto sec = st.lower_bound(P(x + 1, 0));
        sec--;
        if (sec->second == x - 1){
            return sec->first - 1;
        }else{
            return x - 1;
        }
    }

    void show(){
        cout << "show" << endl;
        for (P p : st){
            cout << "[" << p.first << ", " << p.second << "]" << endl;
        }
    }
};