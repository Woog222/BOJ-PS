import java.util.*;
import java.io.*;

public class Main
{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int a= Integer.parseInt(st.nextToken());
        int b= Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());

        int val_10 = 0;
        for (int i=0; i<m; ++i) {
            int temp = Integer.parseInt(st.nextToken());
            val_10 *= a;
            val_10 += temp;
        }

        int[] nums = new int[50];
        int len = 0;
        while(val_10 != 0) {
            nums[len++] = val_10%b;
            val_10 /=b;
        }

        for (int i=len-1; i>=0; --i) {
            bw.write(String.valueOf(nums[i]));
            bw.write(" ");
        }
            
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