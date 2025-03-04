import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static StringBuilder sb;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        sb = new StringBuilder();

        n = Integer.parseInt(br.readLine());
        HashMap<Long,Integer> mp = new HashMap<>();

        for(int i=0; i < n; i++){
            st = new StringTokenizer(br.readLine());

            int max = 0;
            Long idx = 0L;

            int a = Integer.parseInt(st.nextToken());
            for(int j=0; j < a; j++){
                long num = Long.parseLong(st.nextToken());

                if(mp.containsKey(num)){
                    mp.replace(num,mp.get(num) + 1);
                }
                else {
                    mp.put(num,1);
                }

                if(mp.get(num) > max) {
                    idx = num;
                    max = mp.get(num);
                }
            }
            if (max > a / 2) {
                bw.write(idx + "\n");
            } else {
                bw.write("SYJKGW\n");
            }
            mp.clear();
        }
        bw.flush();
    }
}
