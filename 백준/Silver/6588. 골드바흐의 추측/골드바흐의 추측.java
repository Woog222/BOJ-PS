import java.util.*;
import java.io.*;

public class Main
{
    static boolean not_prime[] = new boolean[1000001];
    static ArrayList<Integer> primes = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        pre();
        while( true )
        {
            int num = Integer.parseInt(br.readLine());
            if (num == 0) break;

            StringBuilder sb = new StringBuilder();
            sb.append(num).append(" = ");
            for (int p : primes) {
                if (p>= num) {
                    bw.write("Goldbach's conjecture is wrong\n");
                    break;
                }
                if (!not_prime[num-p]) {
                    sb.append(p).append(" + ").append(num-p).append("\n");
                    bw.write(sb.toString());
                    break;
                }
            }
        }

        br.close();
        bw.flush();
        bw.close();

    }

    private static void pre()
    {
        not_prime[1] = true;

        for (int i=2; i<=1000000; ++i) {
            if (not_prime[i]) continue;

            // 소수임
            if (i != 2)
                primes.add(i);
            for (int k=2*i; k<=1000000 ; k += i)
                not_prime[k] = true;
        }
    }
}