import java.util.Scanner;

class Lingkaran {
    int d;

    Lingkaran(int diameter) {
        this.d = diameter;
    }

    double luas() {
        double r = d / 2.0;
        return Math.PI * r * r;
    }
}

class SegiEmpat {
    int w, h;

    SegiEmpat(int lebar, int tinggi) {
        this.w = lebar;
        this.h = tinggi;
    }

    double luas() {
        return w * h;
    }
}

class Silinder {
    Lingkaran lingkaran;
    SegiEmpat segiEmpat;

    Silinder(int diameter, int lebar, int tinggi) {
        lingkaran = new Lingkaran(diameter);
        segiEmpat = new SegiEmpat(lebar, tinggi);
    }

    double volume() {
        return lingkaran.luas() * segiEmpat.h;
    }
}

public class cylnder {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        double totalVolume = 0;
        Silinder[] silinders = new Silinder[n];

        for (int i = 0; i < n; i++) {
            int d = scanner.nextInt();
            int w = scanner.nextInt();
            int h = scanner.nextInt();

            silinders[i] = new Silinder(d, w, h);
            totalVolume += silinders[i].volume();
        }

        double rataRata = totalVolume / n;
        int banyakDiAtasRataRata = 0;

        for (int i = 0; i < n; i++) {
            if (silinders[i].volume() > rataRata) {
                banyakDiAtasRataRata++;
            }
        }

        System.out.printf("%.2f %d", rataRata, banyakDiAtasRataRata);
    }
}
