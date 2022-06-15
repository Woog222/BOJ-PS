import java.util.*;
import java.io.*;

public class Main
{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        long n = Long.parseLong(br.readLine());
        StringBuilder ans = new StringBuilder();
        
        // 0
        if (n ==0) {
            bw.write("0\n");
            bw.newLine();
            bw.flush();
            return;
        }

        while (n != 0)
        {
            if ( n%2 == 0) {
                ans.append("0");
            }
            else {
                n -= 1;
                ans.append("1");
            }

            n = n/-2;
        }



        char[] a = ans.toString().toCharArray();

        for (int i=ans.length()-1; i>=0; --i)
            bw.write((int)a[i]);
        bw.newLine();


        br.close();
        bw.flush();
        bw.close();

    }
    private static int gcd(int a, int b)
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