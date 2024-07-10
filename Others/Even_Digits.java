import java.lang.Math;

    public class Even_Digits {
        public static void main(String[] args) {
            int[] arr = {12, 345, 2, 6, 7896};
            int length = 0;
            for (int i=0; i<arr.length; i++) {
                if (Even(arr[i]) % 2 == 0) {
                 length ++;
                }
            }
            System.out.println(length);
        }

        public static int Even(int n) {
            int ans = (int) Math.log10(n) + 1;
            return (ans);
        }
    }