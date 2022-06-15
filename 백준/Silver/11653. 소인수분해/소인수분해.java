import java.util.*;
import java.io.*;

public class Main
{
    static ArrayList<Integer> primes = new ArrayList<>(500000);
    static boolean[] not_prime = new boolean[10000001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        pre(10000000);

        int num = Integer.parseInt(br.readLine());
        for (int i=0; i<primes.size(); ++i)
        {
            if (num == 1) break;
            int p = primes.get(i);
            while (num % p == 0 ) {
                num/=p;
                bw.write(String.valueOf(p));
                bw.newLine();
            }
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