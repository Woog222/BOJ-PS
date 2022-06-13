import java.util.*;
import java.io.*;

class ps {
    public static boolean is_digit(char c) {
        return (c >='A' && c<='Z') || (c>='a' && c<=
                'z');
    }

    public static long len(long num)
    {
        long res = 1;
        while (num > 0) {
            num /= 10;
            res *= 10;
        }

        return res;
    }

    public static double cal(double a, double b, char c) {
        if (c=='+') {
            return a+b;
        }
        else if (c=='-') {
            return b-a;
        }
        else if (c == '*') {
            return a*b;
        }
        else  {
            return b/a;
        }
    }
}

public class Main
{


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String p = br.readLine();
        String[] arr= new String[p.length()];
        for (int i=0; i<p.length(); ++i) {
            arr[i] = p.substring(i, p.length());
        }

        Arrays.sort(arr);
        for (int i=0; i<p.length(); ++i) {
            bw.write(arr[i]);
            bw.write('\n');
        }

        bw.flush();
        bw.close();
        br.close();

    }
}