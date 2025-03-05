import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int n,l;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());

        int arr[] = new int[n];
        st = new StringTokenizer(br.readLine());

        for(int i=0; i < n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);
        int range =  (int) (arr[0] - 0.5 + l);
        int cnt = 1;

        for(int i=1; i < n; i++){
            if(range < (int) (arr[i] + 0.5)){
                range =  (int) (arr[i] - 0.5 + l);
                cnt++;
            }
        }
        bw.write(cnt + "\n");
        bw.flush();
    }
}
