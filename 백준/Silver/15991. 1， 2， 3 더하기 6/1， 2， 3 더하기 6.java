import java.util.*;
import java.io.*;

public class Main
{
    static long[] dp = new long[100004];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        int t = Integer.parseInt(br.readLine());

        dp[1]=1;
        dp[2] = 2;
        dp[3]= 2;
        dp[4] =  dp[2] + 1;
        dp[5] = dp[1] + dp[3];
        dp[6] = dp[2] + dp[4] + 1;

        for (int i=7; i<=100000; ++i) {
            dp[i] = (dp[i-2] + dp[i-4] + dp[i-6])% 1_000_000_009;
        }

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            long ans = dp[n];
            bw.write(String.valueOf(ans));
            bw.newLine();
        }


        bw.flush();
        bw.close();
        br.close();

    }




}