import java.util.ArrayList;
import java.util.Scanner;

abstract class Bilangan {
    abstract public void print();
}

class BilanganDesimal extends Bilangan {
    public double nilai;

    BilanganDesimal(double nilai) {
        this.nilai = nilai;
    }

    public void add(BilanganDesimal b) {
        this.nilai += b.nilai;
    }

    public void print() {
        System.out.printf("%.2f\n", nilai);
    }
}

class BilanganPecahan extends Bilangan {
    public int pembilang;
    public int penyebut;

    BilanganPecahan(int pembilang, int penyebut) {
        this.pembilang = pembilang;
        this.penyebut = penyebut;
    }

    void add(BilanganPecahan b) {
        int p = this.pembilang;
        int q = this.penyebut;
        int r = b.pembilang;
        int s = b.penyebut;

        this.pembilang = p * s + q * r;
        this.penyebut = q * s;

        // Disederhanakan dengan FPB
        int fpb = fpb(this.pembilang, this.penyebut);
        this.pembilang /= fpb;
        this.penyebut /= fpb;
    }

    private int fpb(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return fpb(b, a % b);
        }
    }

    public void print() {
        System.out.println(pembilang + " " + penyebut);
    }
}

abstract class Operasi {
    abstract void add();
}

class OperasiDesimal extends Operasi {
    public BilanganDesimal a;
    public BilanganDesimal b;

    OperasiDesimal(BilanganDesimal a, BilanganDesimal b) {
        this.a = a;
        this.b = b;
    }

    void add() {
        a.add(b);
        a.print();
    }
}

class OperasiPecahan extends Operasi {
    public BilanganPecahan a;
    public BilanganPecahan b;

    OperasiPecahan(BilanganPecahan a, BilanganPecahan b) {
        this.a = a;
        this.b = b;
    }

    void add() {
        a.add(b);
        a.print();
    }
}

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<Operasi> operasi = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int type = sc.nextInt();
            if (type == 1) {
                BilanganDesimal a = new BilanganDesimal(sc.nextDouble());
                BilanganDesimal b = new BilanganDesimal(sc.nextDouble());
                OperasiDesimal o = new OperasiDesimal(a, b);
                operasi.add(o);
            } else {
                BilanganPecahan a = new BilanganPecahan(sc.nextInt(), sc.nextInt());
                BilanganPecahan b = new BilanganPecahan(sc.nextInt(), sc.nextInt());
                OperasiPecahan o = new OperasiPecahan(a, b);
                operasi.add(o);
            }
        }

        int startIdx = sc.nextInt();
        int endIdx = sc.nextInt();

        for (int i = startIdx - 1; i < endIdx; i++) {
            operasi.get(i).add();
        }
    }
}
