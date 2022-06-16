import java.util.*;
import java.io.*;

public class Main
{
    static long[][] dp = new long[100004][2];
    static int MOD = 1_000_000_009;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        int t = Integer.parseInt(br.readLine());

        dp[1][1] = 1;
        dp[2][1] = dp[2][0] = 1;
        dp[3][0] = dp[3][1] = 2;


        for (int i=4; i<=100000; ++i) {
            dp[i][0] = (dp[i-1][1] + dp[i-2][1] + dp[i-3][1])%MOD;
            dp[i][1] = (dp[i-1][0] + dp[i-2][0] + dp[i-3][0])%MOD;
        }

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String val = String.valueOf(dp[n][1]) +" "+String.valueOf(dp[n][0]);
            bw.write(val);
            bw.newLine();
        }


        bw.flush();
        bw.close();
        br.close();

    }




}
