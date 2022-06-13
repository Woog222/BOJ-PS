import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(bf.readLine());
        ArrayList<Integer> arr = new ArrayList<>();
        StringTokenizer stk = new StringTokenizer(bf.readLine());
        while (stk.hasMoreTokens()) {
            arr.add(Integer.parseInt(stk.nextToken()) );
        }

        int[] ans = new int[n];
        Stack<Integer> st = new Stack<>();
        for (int i=n-1; i>=0; --i)
        {
            while (!st.isEmpty() && st.peek() <= arr.get(i))
                st.pop();

            if (st.isEmpty())
                ans[i] = -1;
            else
                ans[i] = st.peek();

            st.push( arr.get(i) );
        }

        StringBuilder sb = new StringBuilder();

        for(int i : ans) {
            sb.append(i).append(" ");
        }
        sb.append("\n");

        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}