import java.util.*;
import java.io.*;

public class Main
{
    private static int INF = 1987654321;
    private static int[] arr = new int[10];
    private static int[] a = new int[10];
    private static boolean[] use = new boolean[10];
    static int n, m;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i=0; i<n; ++i)
            a[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(a,0, n);

        fun(0,-1);

        bw.write(sb.toString());

        bw.flush();
        bw.close();
        br.close();
    }

    static private void fun(int idx, int before) {
        if (idx==m) {
            // print
            for (int i=0; i<m ;++i) {
                sb.append(arr[i]);
                sb.append(" ");
            }
            sb.append('\n');
            return;
        }

        for (int ith=0; ith<n; ++ith) {
            int i = a[ith];

            //if (use[i]) continue;

            //use[i] = true;
            arr[idx] = i;
            fun(idx+1, ith);
            //use[i] = false;
        }
    }

}