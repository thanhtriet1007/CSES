import java.io.*;
import java.util.*;
@SuppressWarnings("unchecked")

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

    static long capacity[][] = new long [501][501];
    static ArrayList<Integer> adj[] = new ArrayList[501];
    static int parent[] = new int[501];

    void init(int n) {
        for (int i = 0; i <= n; ++i) {
            adj[i] = new ArrayList<>();
        }
    }

    boolean bfs(int s, int t) {
        Arrays.fill(parent, -1);
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        parent[s] = -2;

        while (!q.isEmpty()) {
            int u = q.poll();

            for (int v : adj[u]) {
                if (parent[v] == -1 && capacity[u][v] > 0) {
                    parent[v] = u;
                    if (v == t)
                        return true;
                    q.add(v);
                }
            }
        }
        return false;
    }

    long maxFlow(int s, int t) {
        long flow = 0;

        while (bfs(s, t)) {
            long pathFlow = oo;

            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                pathFlow = Math.min(pathFlow, capacity[u][v]);
            }

            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                capacity[u][v] -= pathFlow;
                capacity[v][u] += pathFlow;
            }

            flow += pathFlow;
        }

        return flow;
    }

    void addEdge(int u, int v, int cap) {
        adj[u].add(v);
        adj[v].add(u);

        capacity[u][v] += cap;
    }

    void solve() {
        FastScanner sc = new FastScanner();

        int n = sc.nextInt();
        int m = sc.nextInt();

        init(n);

        for (int i = 1; i <= m; ++i) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int cap = sc.nextInt();

            addEdge(u, v, cap); 
        }

        out.print(maxFlow(1, n));

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
                if (tail <= 0)
                    return -1;
            }
            return buffer[head++];
        }

        public int nextInt() {
            int c = read();
            while (c <= 32) {
                if (c == -1)
                    return -1;
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