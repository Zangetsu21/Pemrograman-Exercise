import java.util.*;

class Vec {
    private ArrayList<Integer> num = new ArrayList<Integer>();
    private int size;
    private int shift;

    public Vec() {
        num.clear();
        size = 0;
        shift = 1;
    }

    public void addElem(int x) {
        num.add(x);
        size++;
    }

    public void delElem(int x) {
        num.remove(x - shift);
        size--;
        shift++;
    }

    public int getSize() {
        return size;
    }

    public double getRataan() {
        if (size == 0)
            return -9.99;
        int sum = 0;
        for (int i = 0; i < num.size(); i++) {
            sum += num.get(i);
        }
        double rataan = 1.0 * sum / (double) size;
        return rataan;
    }
};

public class Vector {
    public static void main(String args[]) {
        int n;
        Scanner inp = new Scanner(System.in);
        Vec obj = new Vec();
        n = inp.nextInt();
        while (n != -9) {
            obj.addElem(n);
            n = inp.nextInt();
        }
        double rataanAwal = obj.getRataan();
        int sizeAwal = obj.getSize();
        n = inp.nextInt();
        while (n != -9) {
            obj.delElem(n);
            n = inp.nextInt();
        }
        System.out.printf("%d %d\n", sizeAwal, obj.getSize());
        System.out.printf("%.2f %.2f\n", rataanAwal, obj.getRataan());
    }
}
