public class Main {
    public static void main(String[] args) {
        // int hamming = new Hammingv2();

        int distance = Hammingv2.distance("alma", "almb");

        System.out.println(distance == -1 ? "A hamming tavolsag nem ertelmezett a ket szora"
                : "A ket szo Hamming tavolsaga = %d".formatted(distance));
    }
}