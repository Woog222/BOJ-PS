import java.util.*;
import java.io.*;

public class Main
{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());

        while (t-- >0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt( st.nextToken() );

            int[] arr = new int[n];
            for (int i=0; i<n; ++i) {
                arr[i] = Integer.parseInt( st.nextToken() );
            }

            long ans = 0;
            for (int i=0; i<n; ++i)
                for (int j=i+1; j<n; ++j) {
                    ans += gcd(arr[i], arr[j]);
                }

            bw.write(Long.toString(ans));
            bw.write("\n");
        }





        br.close();
        bw.flush();
        bw.close();

    }
    private static long gcd(int a, int b)
    {
        if (a<b) {
            int temp = b;
            b =a;
            a = temp;
        }
        // a>b
        while (b>0) {
            int r = a%b;
            a = b;
            b = r;
        }

        return a;
    }
}