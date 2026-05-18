import java.util.*;
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

        int nxt[][] = new int[40][N];
        int n, q;
        n = sc.nextInt();
        q = sc.nextInt();

        for (int i = 1; i <= n; ++i) {
            int node;
            node = sc.nextInt();
            nxt[0][i] = node;
        }

        for (int j = 1; (1L << j) <= 1e9; ++j) {
            for (int i = 1; i <= n; ++i) {
                nxt[j][i] = nxt[j - 1][nxt[j - 1][i]];
            }
        }

        for (int turn = 1; turn <= q; ++turn) {
            int node, k;
            node = sc.nextInt();
            k = sc.nextInt();

            for (int i = 31; i >= 0; --i) {
                if ((1L << i) <= k) {
                    k -= (1L << i);
                    node = nxt[i][node];
                }
            }
            out.println(node);
        }

    }

    class FastScanner {
        private InputStream in;
        private byte[] buffer = new byte[1 << 16]; // Bộ đệm 64KB để đọc theo mảng cho nhanh
        private int head = 0, tail = 0;

        public FastScanner() {
            in = System.in;
        }

        // Hàm đọc 1 byte từ luồng
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

        // Hàm đọc số nguyên siêu tốc
        public int nextInt() {
            int c = read();
            // 1. Bỏ qua các ký tự rác (dấu cách, tab, xuống dòng có mã ASCII <= 32)
            while (c <= 32) {
                if (c == -1)
                    return -1; // Kết thúc file
                c = read();
            }

            int res = 0;
            // 2. Đọc liên tục các chữ số và ghép thành số nguyên
            while (c > 32) {
                res = res * 10 + (c - '0'); // Công thức dịch sang trái 1 hàng rồi cộng đơn vị
                c = read();
            }
            return res;
        }
    }
}   