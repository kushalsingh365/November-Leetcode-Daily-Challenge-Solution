public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int start = 1;
        while (start<=n){
            int mid = start + (n - start) /2 ;
            int test = guess(mid);
            if(test == 0){
                return mid;
            } else if (test == -1) {
                n = mid -1;
            }else{
                start = mid +1;
            }
        }
        return -1;
    }
}
