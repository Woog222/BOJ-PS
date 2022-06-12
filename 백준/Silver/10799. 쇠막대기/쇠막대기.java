import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = bf.readLine();
        Stack<Character> st = new Stack<>();
        int ans = 0;
        for (int i=0; i< input.length(); ++i)
        {
            char c = input.charAt(i);
            // lazer
            if (c=='(' && i+1< input.length() && input.charAt(i+1) ==')') {
                ans += st.size();
                i++;
                continue;
            }

            if (c == '('){
                st.push(c);
            }
            else {
                st.pop();
                ans += 1;
            }
        }

        bw.write(String.valueOf(ans));
        bw.flush();
        bw.close();
    }
}