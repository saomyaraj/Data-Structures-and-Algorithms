public class Binary_Search1  {
    public static void main(String[] args) {
        int[] arr = {2,4,6,7,10,12,14,16,18,20};
        int target = 5;
        int ans = (Binary_Search(arr, target));
        System.out.println(ans);

    }
    static int Binary_Search(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;
        
        while (start<=end) {
            int mid = start+(end-start)/2;
            if (target<arr[mid]) {
                end = mid-1;
            }
            else if (target > arr[mid]) {
                start = mid+1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
}