import java.io.*;

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

    long st[] = new long[N * 4];
    long a[] = new long[N];

    void build(int id, int l, int r) {
        if (l > r) return;
        if (l == r) {
            st[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        st[id] = Math.min(st[id * 2], st[id * 2 + 1]);
    }

    long get(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return oo;
        if (l >= u && r <= v) {
            return st[id];
        }

        int mid = (l + r) >> 1;
        return Math.min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }


    void solve() {
        FastScanner sc = new FastScanner();
        int n, q; 

        n = sc.nextInt();
        q = sc.nextInt();

        for (int i = 1; i <= n; ++i) {
            a[i] = sc.nextInt();
        }

        build(1, 1, n);

        while(q-- > 0) {
            int l, r; 
            l = sc.nextInt();
            r = sc.nextInt();

            out.println(get(1, 1, n, l, r));
        }   
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