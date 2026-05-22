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

    void solve() {
        FastScanner sc = new FastScanner();
        int n, q;
        n = sc.nextInt();
        q = sc.nextInt();

        long a[] = new long[N];
        long prefixSum[] = new long[N];

        for (int i = 1; i <= n; ++i) 
            a[i] = sc.nextInt();

        for (int i = 1; i <= n; ++i) 
            prefixSum[i] = prefixSum[i - 1] + a[i];

        while (q-- > 0) {
            int l, r; 
            l = sc.nextInt();
            r = sc.nextInt();

            out.println(prefixSum[r] - prefixSum[l - 1]);
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