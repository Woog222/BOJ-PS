import java.util.*;
import java.io.*;

public class Main
{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        char[] reversed_ans = new char[50];
        int size = 0;

        while (n!=0)
        {
            int r = n%m;
            reversed_ans[size++] = convert(r);
            n/=m;
        }

        for (int i=size-1; i>=0; --i)
            bw.write(reversed_ans[i]);
        bw.newLine();

        br.close();
        bw.flush();
        bw.close();

    }

    private static char convert(int r)
    {
        if (r >=0 && r<=9)
            return (char)(r + '0');
        else
            return (char)(r-10 + 'A');
    }

}