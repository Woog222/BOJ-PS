import java.util.*;
import java.io.*;

public class Main
{
    static int[] p = new int[1001];
    static int[] dp = new int[12];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        dp[0] = 1;
        dp[1] = 1; dp[2]= 2; dp[3] = 4;
        for (int i=4; i<=11; ++i)
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

        if (k > dp[n]) {
            bw.write("-1\n");
        }
        else {
            bw.write(fun(n, k));
        }
        bw.newLine();
        bw.flush();
        bw.close();
        br.close();

    }

    static String fun(int num, int k)
    {
        // last cases
        if (num==1 & k==1)
            return "1";
        else if (num==2 && k==2)
            return "2";
        else if (num==3 && k==4)
            return "3";

        if ( k <= dp[num-1] ) {
            return "1+" + fun(num-1, k);
        }
        else if ( k <= dp[num-1]+dp[num-2] ) {
            return "2+" + fun(num-2, k-dp[num-1]);
        }
        else
            return "3+" + fun(num-3, k-dp[num-1]-dp[num-2]);
    }


}