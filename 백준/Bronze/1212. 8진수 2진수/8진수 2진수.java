import java.util.*;
import java.io.*;

public class Main
{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String p = br.readLine();
        int len = p.length();

        if ( p.equals( "0" ) ) {
            bw.write("0\n");
            br.close();
            bw.flush();
            bw.close();
            return;
        }


        StringBuilder ans = new StringBuilder(333339);

        int num = Integer.parseInt( p.substring(0,1));
        if (num >= 4) {
            ans.append(1);
            num %= 4;
        }
        if (num>=2) {
            ans.append(1);
            num %= 2;
        }
        else if ( ans.length() > 0)
            ans.append(0);

        if (num>=1) {
            ans.append(1);
        }
        else if (ans.length() > 0)
            ans.append(0);

        for (int i=1; i<len; ++i) {
            num = Integer.parseInt( p.substring(i,i+1) );

            for (int div=2; div>=0; --div)
            {
                if (num >= (1<<div)) {
                    ans.append(1);
                    num%=(1<<div);
                }
                else
                    ans.append(0);
            }
        }

        bw.write(ans.toString());
        bw.write('\n');
        br.close();
        bw.flush();
        bw.close();

    }
}