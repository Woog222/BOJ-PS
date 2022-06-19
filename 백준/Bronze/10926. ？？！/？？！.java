import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String s = br.readLine();
        bw.write(s + "??!");
        bw.newLine();
        

        bw.flush();
        bw.close();
        br.close();
    }


}
