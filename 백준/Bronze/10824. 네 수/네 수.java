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

        Scanner sc = new Scanner(System.in);
        long a, b,c, d;
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        d = sc.nextInt();

        long len_b = ps.len(b);
        long len_d = ps.len(d);

        long new_num = b+d+ (a*len_b) + (c*len_d);
        System.out.println(new_num);
    }
}
