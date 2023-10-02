class MyMath {
    private MyMath() {
        // nem peldanyostihato
    }

    public static int max(int a, int b) {
        return a > b ? a : b;
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println(MyMath.max(5, 16));
    }
}
