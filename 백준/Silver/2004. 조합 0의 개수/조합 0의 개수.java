import java.util.*;
import java.io.*;

public class Main
{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());

        long two, five;
        five = cal(a, 5) -cal(b, 5) - cal(a-b, 5);
        two = cal(a,2) - cal(b,2)- cal(a-b,2);
        
        long ans = Math.min(five, two);
        bw.write( Long.toString( ans) );
        bw.write('\n');


        br.close();
        bw.flush();
        bw.close();

    }
    private static long cal(long num, long mod)
    {
        long ret = 0;
        while( num >= mod) {
            num = num/mod;
            ret += num;
        }

        return ret;
    }
}