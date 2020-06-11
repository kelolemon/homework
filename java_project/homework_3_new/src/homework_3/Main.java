package homework_3;

import java.util.Arrays;

public class Main {
    private static double[] selectsort(double[] arr) {
        for(int x=0;x<arr.length-1;x++) {
            for(int y=x+1;y<arr.length;y++) {
                if(arr[x]>arr[y]) {
                    double temp=arr[x];
                    arr[x]=arr[y];
                    arr[y]=temp;
                }
            }
        }
        return arr;
    }

    private static double[] std_sort(double[] arr) {
        Arrays.sort(arr);
        return arr;
    }

    public static void main(String[] args) {
	    // write your code here
        double[] arr = new double[10001];
        for (int i = 1; i <=10000; i++) {
            arr[i] = Math.random();
        }

        long time1 = System.currentTimeMillis();
        double[] arr1 = selectsort(arr);
        long time2 = System.currentTimeMillis();
        System.out.printf("Select sort 's time is %d\n", time2 - time1);
        long time3 = System.currentTimeMillis();
        double[] arr2 = std_sort(arr);
        long time4 = System.currentTimeMillis();
        System.out.printf("Std array sort 's time is %d\n", time4 - time3);
    }
}
