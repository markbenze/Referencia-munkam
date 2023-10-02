import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] tomb = { 1, 2, 6, 8, 95, 25 };
        int[] tomb2 = { 1, 2, 6, 5, 95, 25 };

        boolean equals = MyArrayUtils.equals(tomb, tomb2);
        System.out.println("A ket tomb egyenlo: " + equals);

        boolean sorted = MyArrayUtils.isSorted(tomb);
        System.out.println("A tomb sorba rendezett: " + sorted);

        System.out.println("Min: " + MyArrayUtils.getMinElem(tomb));
        System.out.println("Max: " + MyArrayUtils.getMaxElem(tomb));

        MyArrayUtils.fill(tomb, 16);
        System.out.println(Arrays.toString(tomb));
    }
}
