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
    static boolean not_prime[] = new boolean[1000001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        pre();
        for (int i=a; i<=b; ++i) {
            if (!not_prime[i]) {
                bw.write(Integer.toString(i));
                bw.write('\n');
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
            for (int k=2*i; k<=1000000 ; k += i)
                not_prime[k] = true;
        }
    }
}