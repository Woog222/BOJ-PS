import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter( new OutputStreamWriter(System.out));
        int num = Integer.parseInt(bf.readLine());
        Stack<Character> stack = new Stack<Character>();

        while (num-- > 0) {
            String input = bf.readLine() + " ";

            for (char c : input.toCharArray() ) {
                if (c == ' ' ) {
                    while ( !stack.isEmpty()) {
                        bw.write(stack.pop());
                    }
                    bw.write(" ");
                }
                else {
                    stack.push(c);
                }
            }
            bw.write('\n');
        }


        bw.flush();
        bw.close();
        return ;
    }
}