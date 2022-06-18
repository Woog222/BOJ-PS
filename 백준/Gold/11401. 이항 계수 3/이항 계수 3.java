import java.util.*;
import java.io.*;

public class Main
{
    private static int[][] dp =new int[1001][10];
    private static long MOD = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long k = sc.nextLong();

        long ans = 1;
        for (long i=0; i<k; ++i)
            ans = (ans * (n-i))%MOD;

        long temp = 1;
        for (long i=1; i<=k; ++i)
            temp = (temp*i)%MOD;



        ans = (ans * pow(temp, MOD-2)) % MOD;

        bw.write(String.valueOf(ans));
        bw.newLine();
        bw.flush();
        bw.close();
        br.close();
    }

    private static long pow(long base, long k)
    {
        long ret = 1;

        while (k>0) {
            if (k%2 > 0)
                ret = (ret * base) % MOD;
            base = (base * base)%MOD;
            k /=2;
        }

        return ret;
    }


}