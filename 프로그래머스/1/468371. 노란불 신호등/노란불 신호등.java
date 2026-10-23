class Solution {
    public int solution(int[][] signals) {
        int answer = -1;
        int n = signals.length;
        int LCM = signals[0][0] + signals[0][1] + signals[0][2];
        for (int i = 1; i < n; i++) {
            int period = signals[i][0] + signals[i][1] + signals[i][2];
            LCM = lcm(LCM, period);
        }

        for (int t = 1; t <= LCM; t++) {
            boolean is_all_yellow = true;
            for (int i = 0; i < n; i++) {
                int period = signals[i][0] + signals[i][1] + signals[i][2];
                int time = t % period;

                if (signals[i][0] + 1 <= time && time <= signals[i][0] + signals[i][1]) continue;
                else {
                    is_all_yellow = false;
                    break;
                }
            }

            if (is_all_yellow) {
                answer = t;
                break;
            }
        }
        return answer;
    }
    
    public int gcd(int a, int b) {
        if (a < b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    public int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }
}