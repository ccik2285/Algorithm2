import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = {};
        
        Map<String,Integer> mp = new HashMap<>();
        
        for(int i=0; i < players.length; i++){
            mp.put(players[i],i);
        }
        
        for(int i=0; i < callings.length; i++){
            int curr_rank = mp.get(callings[i]);
            
            String pre = players[curr_rank - 1];
            
            players[curr_rank] = pre;
            players[mp.get(pre)] = callings[i];
            
            mp.put(callings[i],mp.get(pre));
            mp.put(pre,curr_rank);
                    
        }
        
        answer = players;
        
        return answer;
    }
}