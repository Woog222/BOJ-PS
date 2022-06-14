import java.util.*;
import java.io.*;

class ps {
    public static int gcd(int a, int b)
    {
        int temp;
        if (a < b) {
            temp = b;
            b =a;
            a = temp;
        }

        // a>b
        while (b!=0) {
            int r = a % b;

            a = b;
            b = r;
        }
        return a;
    }



}

public class Main
{
    static boolean[] not_prime = new boolean[1000001];
    static ArrayList<Integer> primes = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int two =0, five = 0;
        for (int i=1; i<=n; ++i)
        {
            int temp = i;
            while ( temp > 0 && temp%2 ==0  ) {
                temp /=2;
                two++;
            }
            while (temp>0 && temp%5 == 0) {
                temp /= 5;
                five++;
            }
        }
        bw.write(Integer.toString( Math.min(two, five) ) );
        bw.write('\n');


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