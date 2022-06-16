import java.util.*;
import java.io.*;

public class Main
{
    static int[] p = new int[1001];
    static int[] dp = new int[1001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i=1; i<=n; ++i)
            p[i] = Integer.parseInt(st.nextToken());

        bw.write(String.valueOf(fun(n)));
        bw.newLine();



        bw.flush();
        bw.close();
        br.close();

    }

    static int fun(int left)
    {
        if (left == 0)
            return 0;

        if (dp[left] != 0)
            return dp[left];

        int temp_ret = 987654321;
        for (int i=1; i<=left; ++i) {
            temp_ret = Math.min(temp_ret, p[i] + fun(left-i));
        }

        return (dp[left] = temp_ret);
    }

}