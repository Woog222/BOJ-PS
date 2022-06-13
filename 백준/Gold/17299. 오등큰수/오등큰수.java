import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(bf.readLine());
        int[] arr = new int[n];
        int[] ans = new int[n];
        int[] freq = new int[1000001];

        StringTokenizer st = new StringTokenizer(bf.readLine());
        int idx = 0;
        while(st.hasMoreTokens()) {
            arr[idx] = Integer.parseInt(st.nextToken());
            freq[arr[idx]]++;
            idx++;
        }

        Stack<Integer> stack = new Stack<Integer>();

        for (int i=n-1; i>=0; --i)
        {
            while (!stack.isEmpty() && freq[stack.peek()] <= freq[arr[i]] ) {
                stack.pop();
            }

            if (stack.isEmpty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = stack.peek();
            }
            stack.push(arr[i]);
        }

        for (int i : ans) {
            bw.write(Integer.toString(i));
            bw.write(" ");
        }

        bw.flush();
        bf.close();
        bw.close();

    }
}
