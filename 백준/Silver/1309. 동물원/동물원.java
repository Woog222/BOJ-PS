import java.util.*;
import java.io.*;

public class Main
{
    private static int[][] dp =new int[100001][2];
    private static int MOD = 9901;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        int n = Integer.parseInt(br.readLine());
        dp[1][0] = 1;
        dp[1][1] = 2;
        for (int i=2; i<=n; ++i) {
            dp[i][0] = (dp[i-1][1] + dp[i-1][0]) % MOD;
            dp[i][1] = (dp[i-1][1] + 2*dp[i-1][0]) % MOD;
        }

        bw.write(String.valueOf((dp[n][0] + dp[n][1])%MOD) );
        bw.newLine();

        bw.flush();
        bw.close();
        br.close();
    }
}