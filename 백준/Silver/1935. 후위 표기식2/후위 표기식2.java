import java.util.*;
import java.io.*;

class ps {
    public static boolean is_digit(char c) {
        return (c >='A' && c<='Z');
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
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(bf.readLine());
        String p = bf.readLine();
        double[] val = new double[26];
        for (int i=0; i<n; ++i) {
            val[i] = Double.parseDouble(bf.readLine());
        }

        Stack<Double> stack = new Stack<Double>();
        for (int i=0; i<p.length() ;++i)
        {
            char c = p.charAt(i);

            if (ps.is_digit(c)) {
                stack.push( (double)val[c-'A'] );
            }
            else {
                double a = stack.pop();
                double b = stack.pop();
                double res = ps.cal(a, b, c);
                stack.push(res);
            }
        }

        System.out.printf("%.2f\n", stack.pop());

    }
}