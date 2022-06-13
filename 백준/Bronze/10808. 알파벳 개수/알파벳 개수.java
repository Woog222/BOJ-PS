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
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] arr = new int[26];
        String p = br.readLine();
        for (int i=0; i<p.length(); ++i) {
            arr[ p.charAt(i)-'a' ]++;
        }

        for (int i : arr) {
            bw.write(Integer.toString(i));
            bw.write(" ");
        }
        bw.write('\n');
        bw.flush();
        bw.close();
        br.close();
    }
}