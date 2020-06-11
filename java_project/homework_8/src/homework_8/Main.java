package homework_8;

import java.util.Arrays;
import java.util.concurrent.CountDownLatch;

public class Main extends Thread {

    private static void merge(int[] l, int[] r, int[] res){
        int i = 0, j = 0, k = 0;
        while( i<l.length && j<r.length){
            if(l[i]<=r[j]){
                res[k]=l[i];
                i++;
            }
            else{
                res[k]=r[j];
                j++;
            }
            k++;
        }
        if(i==l.length){
            for(;j<r.length;j++){
                res[k]=r[j];
                k++;
            }
        }
        else{
            for(;i<l.length;i++){
                res[k]=l[i];
                k++;
            }
        }
    }

    private static void normal_merge_sort(int a[]){
        if(a.length>1){
            int[] l = Arrays.copyOfRange(a,0,a.length/2);
            int[] r = Arrays.copyOfRange(a,a.length/2,a.length);
            normal_merge_sort(l);
            normal_merge_sort(r);
            merge(l,r,a);
        }
    }


    static void multi_merge_sort(int a[]) throws InterruptedException{
        if(a.length>1){
            int[] l = Arrays.copyOfRange(a,0,a.length/2);
            int[] r = Arrays.copyOfRange(a,a.length/2,a.length);
            CountDownLatch latch = new CountDownLatch(2);

            new Thread(new Runnable(){
                @Override
                public void run(){
                    normal_merge_sort(l);
                    latch.countDown();
                }
            }).start();

            new Thread(new Runnable(){
                @Override
                public void run(){
                    normal_merge_sort(r);
                    latch.countDown();
                }
            }).start();

            try{
                latch.await();
            }catch(Exception ignored){};
            merge(l,r,a);
        }
    }

    public static void main(String[] args) throws InterruptedException {
        int length = 100000;
        int[] a = new int[length + 1];
        for (int i = 1; i<= length; i++) {
            a[i] = (int) ( Math.random() * 10000) ;
        }
        int b[] = a;
        long time1 = System.currentTimeMillis();
        normal_merge_sort(b);
        long time2 = System.currentTimeMillis();
        System.out.println("the cost of the normal sort is " + (time2 - time1));
        int c[] = a;
        long time3 = System.currentTimeMillis();
        multi_merge_sort(c);
        long time4 = System.currentTimeMillis();
        System.out.println("the cost of the multi-thread sort is " + (time4 - time3));

    }
}

