import java.util.*;
import java.io.*;

public class Main
{
    static long[] dp = new long[1_000_001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        int t = Integer.parseInt(br.readLine());

        dp[0] = 1;
        dp[1] = 1; dp[2]= 2; dp[3] = 4;
        for (int i=4; i<=1_000_000; ++i) {
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1_000_000_009;
        }

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            bw.write(String.valueOf(dp[n]));
            bw.newLine();
        }

        bw.flush();
        bw.close();
        br.close();

    }
}