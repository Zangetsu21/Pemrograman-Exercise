import java.util.Scanner;

interface Shape2D {
    void set(int n, double[] x, double[] y);
    void print();
    double keliling();
}

class Poligon implements Shape2D {
    private int n;
    private double[] x;
    private double[] y;

    public void set(int n, double[] x, double[] y) {
        this.n = n;
        this.x = x;
        this.y = y;
    }

    public void print() {
        System.out.printf("[%.2f,%.2f]-[%.2f,%.2f]\n", x[0], y[0], x[n-1], y[n-1]);
    }

    public double keliling() {
        double keliling = 0.0;
        for (int i = 0; i < n - 1; i++) {
            double dx = x[i+1] - x[i];
            double dy = y[i+1] - y[i];
            keliling += Math.sqrt(dx*dx + dy*dy);
        }
        double dx = x[0] - x[n-1];
        double dy = y[0] - y[n-1];
        keliling += Math.sqrt(dx*dx + dy*dy);
        return keliling;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        double[] x = new double[n];
        double[] y = new double[n];

        for (int i = 0; i < n; i++) {
            x[i] = sc.nextDouble();
            y[i] = sc.nextDouble();
        }

        Poligon poligon = new Poligon();
        poligon.set(n, x, y);

        poligon.print();
        System.out.printf("%.2f\n", poligon.keliling());

        sc.close();
    }
}
