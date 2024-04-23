import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        
        char cmp = s.charAt(0);
        int first_num = 0;
        int diff_num = 0;
        for(int i=0; i < s.length(); i++){
            if(first_num == diff_num){
                cmp = s.charAt(i);
                answer++;
            }
            if(s.charAt(i) == cmp){
                first_num++;
            }
            else diff_num++;
        }
        
        return answer;
    }
}