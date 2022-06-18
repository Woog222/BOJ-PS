import java.util.*;
import java.io.*;

public class Main
{
    // 0 1up 2down
    private static int[][][] dp =new int[1001][3][3];
    private static int[][] cost= new int [1001][3];
    private static int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        for (int i=1; i<=n; ++i) {
            StringTokenizer st= new StringTokenizer(br.readLine());
            for (int j=0; j<3; ++j) {
                cost[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dp[1][0][0] = cost[1][0];
        dp[1][1][0] = dp[1][2][0] = INF;
        dp[1][1][1] = cost[1][1];
        dp[1][0][1] = dp[1][2][1] = INF;
        dp[1][2][2] = cost[1][2];
        dp[1][1][2] = dp[1][0][2] = INF;


        for (int first=0; first<3; ++first) {
            for (int i=2; i<=n; ++i) {
                for (int j=0; j<3; ++j) {
                    dp[i][j][first] = INF;
                    for (int k=0; k<3; ++k) {
                        if (k!=j)
                            dp[i][j][first] = Math.min(dp[i][j][first],
                                    dp[i-1][k][first]+cost[i][j]);
                    }

                }
            }
        }
        int ans = INF;
        for (int first=0; first<3; ++first) {
            for (int last=0; last<3; ++last) {
                if ( last ==first ) continue;
                ans = Math.min(ans, dp[n][last][first]);
            }

        }

        bw.write(String.valueOf(ans));
        bw.newLine();

        bw.flush();
        bw.close();
        br.close();
    }



}