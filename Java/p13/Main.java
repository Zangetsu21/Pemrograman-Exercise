import java.util.Scanner;

interface Answerable {
    boolean cekJawaban(String jawaban);
}

class Soal implements Answerable {
    private String pertanyaan;
    private String kunciJawaban;

    public Soal(String pertanyaan, String kunciJawaban) {
        this.pertanyaan = pertanyaan;
        this.kunciJawaban = kunciJawaban;
    }

    public boolean cekJawaban(String jawaban) {
        return kunciJawaban.equalsIgnoreCase(jawaban);
    }
}

class Ujian {
    private Soal[] soal;
    private int jumlahSoal;

    public Ujian(int jumlahSoal) {
        this.jumlahSoal = jumlahSoal;
        soal = new Soal[jumlahSoal];
    }

    public void setSoal(int index, Soal s) {
        soal[index] = s;
    }

    public double nilaiUjian(String[] jawaban, int jumlahJawaban) {
        int jumlahBenar = 0;

        for (int i = 0; i < jumlahJawaban; i++) {
            int nomorPertanyaan = Integer.parseInt(jawaban[i * 2]);
            String jawabanPengguna = jawaban[i * 2 + 1];

            if (nomorPertanyaan >= 1 && nomorPertanyaan <= jumlahSoal) {
                Soal s = soal[nomorPertanyaan - 1];
                if (s.cekJawaban(jawabanPengguna)) {
                    jumlahBenar++;
                }
            }
        }

        return (double) jumlahBenar / jumlahSoal * 100;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Membaca jumlah pertanyaan
        int jumlahPertanyaan = input.nextInt();
        input.nextLine();

        // Membaca pasangan pertanyaan dan kunci jawaban
        Ujian ujian = new Ujian(jumlahPertanyaan);
        for (int i = 0; i < jumlahPertanyaan; i++) {
            String pertanyaan = input.nextLine();
            String kunciJawaban = input.nextLine();

            Soal soal = new Soal(pertanyaan, kunciJawaban);
            ujian.setSoal(i, soal);
        }

        // Membaca jawaban yang dijawab
        int jumlahJawaban = input.nextInt();
        input.nextLine();

        String[] jawaban = new String[jumlahJawaban * 2];
        for (int i = 0; i < jumlahJawaban; i++) {
            jawaban[i * 2] = input.nextLine();
            jawaban[i * 2 + 1] = input.nextLine();
        }

        // Menghitung dan mencetak nilai ujian
        double nilai = ujian.nilaiUjian(jawaban, jumlahJawaban);
        System.out.printf("%.2f%n", nilai);

        input.close();
    }
}
