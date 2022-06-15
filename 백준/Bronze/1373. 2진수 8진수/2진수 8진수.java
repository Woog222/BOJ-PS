import java.util.*;
import java.io.*;

public class Main
{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String p = br.readLine();
        int len = p.length();


        StringBuilder ans = new StringBuilder();
        for (int i=len-3; i>=0; i-= 3) {
            int val = (int)(p.charAt(i) - '0') *4;
            val += (int)(p.charAt(i+1) - '0') *2;
            val += (int)(p.charAt(i+2) - '0') *1;
            ans.insert(0, Integer.toString(val) );
        }

        if (len % 3 == 1) {
            int val = (int)(p.charAt(0) - '0') * 1;
            ans.insert(0, Integer.toString(val));
        }
        else if (len % 3 == 2) {
            int val = (int)(p.charAt(0) - '0') * 2;
            val += (int)(p.charAt(1) - '0') * 1;
            ans.insert(0, Integer.toString(val));
        }

        bw.write(ans.toString());
        bw.write('\n');
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