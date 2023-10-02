import java.util.Arrays;

public class MyArrayUtils {
    private MyArrayUtils() {
        // nem peldanyosithato
    }

    public static void reverse(int[] tomb) {
        for (int i = 0; i < (tomb.length) / 2; ++i) {
            int buff = tomb[i];
            tomb[i] = tomb[tomb.length - i - 1];
            tomb[tomb.length - i - 1] = buff;
        }
    }

    public static void sortDescending(int[] tomb) {
        Arrays.sort(tomb);
        MyArrayUtils.reverse(tomb);
    }

    public static boolean equals(int[] tomb1, int[] tomb2) {
        if (tomb1.length != tomb2.length) {
            return false;
        }
        for (int i = 0; i < tomb1.length; ++i) {
            if (tomb1[i] != tomb2[i]) {
                return false;
            }
        }
        return true;
    }

    public static void fill(int[] tomb, int value) {
        for (int i = 0; i < tomb.length; ++i) {
            tomb[i] = value;
        }
    }

    public static void sort(int[] tomb) {
        for (int i = 0; i < tomb.length - 1; ++i) {
            for (int j = i + 1; j < tomb.length; ++j) {
                if (tomb[i] > tomb[j]) {
                    int buff = tomb[i];
                    tomb[i] = tomb[j];
                    tomb[j] = buff;
                }
            }
        }
    }

    public static boolean isSorted(int[] tomb) {
        int[] buff = tomb.clone();
        MyArrayUtils.sort(buff);

        if (MyArrayUtils.equals(tomb, buff))
            return true;

        return false;
    }

    public static int getMinElem(int[] tomb) {
        MyArrayUtils.sort(tomb);
        return tomb[0];
    }

    public static int getMaxElem(int[] tomb) {
        MyArrayUtils.sort(tomb);
        return tomb[tomb.length - 1];
    }
}
