import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
		Arrays.fill(answer, -1);
		
		Stack<Integer> st = new Stack<>();

		for (int i = 0; i < numbers.length; i++) {
			while (!st.isEmpty() && numbers[i] > numbers[st.peek()]) {
				answer[st.peek()] = numbers[i];
                st.pop();
			}
			
			st.push(i);
		}

		return answer;
    }
}