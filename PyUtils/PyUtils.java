import java.util.List;
import java.util.ArrayList;

class PyUtils {
    private PyUtils() {
        //
    }

    public static List<Integer> range(int start, int end, int step) {
        List<Integer> list = new ArrayList<>();

        if (start > end || end <= 0) {
            return list;
        }

        for (int i = start; i < end; i = i + step) {
            list.add(i);
        }
        return list;
    }

    public static List<Integer> range(int start, int end) {
        return range(start, end, 1);
    }

    public static List<Integer> range(int end) {
        return range(0, end, 1);
    }
}