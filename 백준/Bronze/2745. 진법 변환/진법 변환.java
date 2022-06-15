import java.util.*;
import java.io.*;

public class Main
{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        String p = st.nextToken();
        int m = Integer.parseInt(st.nextToken());
        int res = 0;

        for (int i=0; i<p.length(); ++i)
        {
            res *= m;
            res += convert(p.charAt(i));
        }

        bw.write(String.valueOf(res));
        bw.newLine();

        br.close();
        bw.flush();
        bw.close();

    }

    private static int convert(char c)
    {
        if (c >= '0' && c <= '9') {
            return (int)(c-'0');
        }
        else
            return (int)(c-'A'+10);
    }

}