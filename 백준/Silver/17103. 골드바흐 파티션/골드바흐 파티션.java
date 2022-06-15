import java.util.*;
import java.io.*;

public class Main
{
    static ArrayList<Integer> primes = new ArrayList<>(100000);
    static boolean[] not_prime = new boolean[1000001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        pre(1000000);
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int num = Integer.parseInt(br.readLine());
            int upper = num/2;
            int ans = 0;
            for (int p : primes) {
                if (p > num/2) break;
                if (!not_prime[num-p]) ans++;
            }
            bw.write(String.valueOf(ans));
            bw.newLine();
        }


        br.close();
        bw.flush();
        bw.close();

    }
    private static void pre(int last)
    {
        not_prime[1] = true;
        for (int i=2; i<=last; ++i) {
            if (not_prime[i])
                continue;

            // 소수
            primes.add(i);
            for (int np= i*2; np<=last; np += i)
                not_prime[np] = true;
        }
    }
}
