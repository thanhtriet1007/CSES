import java.io.*;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class Main {

    static final int N = (int) 2e5 + 7;
    static final int MOD = (int) 1e9 + 7;
    static final long oo = (long) 1e18 + 7;

    PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] ILoveBaoNghi) {
        Main main = new Main();
        main.solve();
        main.out.flush();
    }

    int n, q;
    
    class Query {
        int l, r, id;

        Query(int l, int r, int id) {
            this.l = l;
            this.r = r;
            this.id = id;
        }

    };

    int a[] = new int[N];  
    int st[] = new int[N * 4];
    int ans[] = new int[N];

    void update(int id, int l, int r, int pos, int val) {
        if (l > pos || r < pos) return;
        if (l == r) {
            st[id] += val;
            return;
        }
        int mid = (l + r) / 2;
        update(id * 2, l, mid, pos, val);
        update(id * 2 + 1, mid + 1, r, pos, val);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }   

    int get(int id, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (l >= ql && r <= qr) return st[id];
        int mid = (l + r) / 2;
        return get(id * 2, l, mid, ql, qr) + get(id * 2 + 1, mid + 1, r, ql, qr);
    }
    

    void solve() {
        FastScanner sc = new FastScanner();
        n = sc.nextInt();
        q = sc.nextInt(); 

        ArrayList<Query> queries = new ArrayList<>();
        Map<Integer, Integer> mp = new HashMap<>();


        for (int i = 1; i <= n; ++i) {
            a[i] = sc.nextInt();
        }

        queries.add(new Query(0, 0, 0));

        for (int i = 1; i <= q; ++i) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            int id = i;
            queries.add(new Query(l, r, id));
        }   
        
        

        queries.sort((o1, o2) -> (o1.r - o2.r));

        int j = 0;
        for (int i = 1; i <= n; ++i) {
            if (!mp.containsKey(a[i])) {
                mp.put(a[i], i);
                update(1, 1, n, i, 1);
            } else {
                update(1, 1, n, mp.get(a[i]), -1);
                update(1, 1, n, i, 1);
                mp.put(a[i], i);
            }
            while (j + 1 <= q && queries.get(j + 1).r == i) {
                j++;
                ans[queries.get(j).id] = get(1, 1, n, queries.get(j).l, queries.get(j).r);
            }
        }

        for (int i = 1; i <= q; ++i) {
            out.println(ans[i]);
        }
        out.close();
        //i luv BN
    }

    class FastScanner {
        private InputStream in;
        private byte[] buffer = new byte[1 << 16]; // Bo dem 64KB
        private int head = 0, tail = 0;

        public FastScanner() {
            in = System.in;
        }

        private int read() {
            if (head >= tail) {
                head = 0;
                try {
                    tail = in.read(buffer, 0, buffer.length);
                } catch (Exception e) { 
                    return -1; 
                }
                if (tail <= 0) return -1;
            }
            return buffer[head++];
        }

        public int nextInt() {
            int c = read();
            while (c <= 32) {
                if (c == -1) return -1;
                c = read();
            }
            int res = 0;
            while (c > 32) {
                res = res * 10 + (c - '0');
                c = read();
            }
            return res;
        }
    }
}