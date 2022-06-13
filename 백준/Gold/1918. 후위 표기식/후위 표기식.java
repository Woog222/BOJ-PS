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


        String p = bf.readLine();
        StringBuilder sb = new StringBuilder();
        Stack<Character> stack = new Stack<>();
        for (int i=0; i<p.length(); ++i)
        {
            char c = p.charAt(i);

            if (ps.is_digit(c)) {
                sb.append(c);
            }
            else if (c == '+' || c == '-') {
                while ( !stack.isEmpty() &&
                       stack.peek()!='(' )
                {
                    sb.append(stack.pop());
                }
                stack.push(c);
            }
            else if (c == '*' || c == '/') {
                while (!stack.isEmpty() &&
                        (stack.peek() == '*' || stack.peek()=='/' ) )
                {
                    sb.append(stack.pop());
                }
                stack.push(c);
            }
            else if (c == '(') {
                stack.push(c);
            }
            else { //closing parenthesis
                while (!stack.isEmpty() && stack.peek() != '(')
                {
                    sb.append(stack.pop());
                }
                stack.pop(); //deleting '('
            }
        }

        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        bf.close();

    }
}