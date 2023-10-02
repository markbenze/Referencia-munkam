public class Hammingv2 {
    private Hammingv2() {
        // ures
    }

    public static int distance(String s1, String s2) {
        int dist = 0;

        if (s1.length() != s2.length()) {
            return -1;
        }

        for (int i = 0; i < s1.length(); ++i) {
            if (s1.charAt(i) != s2.charAt(i)) {
                dist++;
            }
        }

        return dist;
    }
}