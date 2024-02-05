import java.util.Scanner;

abstract class TanahAgri {
    protected double keliling;

    public TanahAgri() {}

    public abstract void hitungKeliling();

    public double getKeliling() {
        return keliling;
    }
}

class PersegiPanjang extends TanahAgri {
    private double panjang;
    private double lebar;

    public PersegiPanjang(double panjang, double lebar) {
        this.panjang = panjang;
        this.lebar = lebar;
    }

    public void hitungKeliling() {
        keliling = 2 * (panjang + lebar);
    }
}

class Lingkaran extends TanahAgri {
    private double radius;

    public Lingkaran(double radius) {
        this.radius = radius;
    }

    public void hitungKeliling() {
        keliling = 2 * Math.PI * radius;
    }
}

public class Tanah {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        TanahAgri[] tanah = new TanahAgri[n];

        for (int i = 0; i < n; i++) {
            int bentukTanahAgri = input.nextInt();

            if (bentukTanahAgri == 0) {
                double panjang = input.nextDouble();
                double lebar = input.nextDouble();
                tanah[i] = new PersegiPanjang(panjang, lebar);
            } else {
                double radius = input.nextDouble();
                tanah[i] = new Lingkaran(radius);
            }

            tanah[i].hitungKeliling();
        }

        double rataRataKeliling = 0;
        for (int i = 0; i < n; i++) {
            rataRataKeliling += tanah[i].getKeliling();
        }
        rataRataKeliling /= n;

        double panjangPagar = 0;
        for (int i = 0; i < n; i++) {
            if (tanah[i].getKeliling() > rataRataKeliling) {
                panjangPagar += tanah[i].getKeliling();
            }
        }

        System.out.printf("%.2f\n", panjangPagar);
    }
}
