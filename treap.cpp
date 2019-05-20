struct xorshift {
    ll x=123456789, y=362436069, z=521288629, w=88675123, t;
    ll random() {
        t=(x^(x<<11)); x=y; y=z; z=w;
        return (w=(w^(w>>19))^(t^(t>>8)));
    }
    ll random(ll x) {
        return random() % x;
    }
    ll random(ll x, ll y) {
        return x + random(y - x);
    }
};

template<class T>
class Treap {
    xorshift rnd;
    const int P_MAX = 1e9;
    struct Node {
        T key;
        int priority;
        Node *lch, *rch;
        Node(T key, int priority): key(key), priority(priority), lch(nullptr), rch(nullptr) {}
    } *root = nullptr;
    using Tree = Node *;

    void split(Tree t, T key, Tree& l, Tree& r) {
        if (!t) {
            l = r = nullptr;
        } else if (key < t->key) {
            split(t->lch, key, l, t->rch);
            r = t;
        } else {
            split(t->rch, key, t->rch, r);
            l = t;
        }
    }

    void merge(Tree& t, Tree l, Tree r) {
        if (!l || !r) {
            t = l ? l : r;
        } else if (l->priority > r->priority) {
            merge(l->rch, l->rch, r);
            t = l;
        } else {
            merge(r->lch, l, r->lch);
            t = r;
        }
    }

    void insert(Tree& t, Tree v) {
        if (!t) {
            t = v;
        } else if (v->priority > t->priority) {
            split(t, v->key, v->lch, v->rch);
            t = v;
        } else {
            insert(v->key < t->key ? t->lch : t->rch, v);
        }
    }

    void erase(Tree& t, T key) {
        if (t->key == key) {
            merge(t, t->lch, t->rch);
        } else {
            erase(key < t->key ? t->lch : t->rch, key);
        }
    }

    bool find(Tree& t, T key) {
        if (!t) {
            return false;
        } else if (t->key == key) {
            return true;
        } else {
            return find(key < t->key ? t->lch : t->rch, key);
        }
    }

    void print(Tree t) {
        if (t->lch) print(t->lch);
        cout << t->key << " ";
        if (t->rch) print(t->rch);
    }

public:
    void insert(T key) {
        insert(root, new Node(key, rnd.random(P_MAX)));
    }

    void erase(T key) {
        erase(root, key);
    }

    bool find(T key) {
        return find(root, key);
    }

    void print() {
        print(root);
        cout << endl;
    }
};
