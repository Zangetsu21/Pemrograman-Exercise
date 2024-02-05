import java.util.Scanner;

interface AritmatikaDasar {
    double tambah(double a, double b);
    double kurang(double a, double b);
    double kali(double a, double b);
    double bagi(double a, double b);
}

interface AritmatikaLanjut {
    double akarKuadrat(double a);
    double pangkat(double a, double b);
}

interface KalkulatorSaintifik extends AritmatikaDasar, AritmatikaLanjut {
    void clear();
}

class Kalkulator implements KalkulatorSaintifik {
    private double currentValue;

    public Kalkulator() {
        this.currentValue = 0;
    }

    public double tambah(double a, double b) {
        return a + b;
    }

    public double kurang(double a, double b) {
        return a - b;
    }

    public double kali(double a, double b) {
        return a * b;
    }

    public double bagi(double a, double b) {
        return a / b;
    }

    public double akarKuadrat(double a) {
        return Math.sqrt(a);
    }

    public double pangkat(double a, double b) {
        return Math.pow(a, b);
    }

    public void clear() {
        this.currentValue = 0;
    }

    public double getCurrentValue() {
        return currentValue;
    }

    public void setCurrentValue(double value) {
        this.currentValue = value;
    }
}

public class Kalku {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Kalkulator kalkulator = new Kalkulator();

        String input;
        while (true) {
            input = scanner.nextLine();
            String[] tokens = input.split(" ");

            if (tokens[0].equals("+")) {
                double value = Double.parseDouble(tokens[1]);
                kalkulator.setCurrentValue(kalkulator.tambah(kalkulator.getCurrentValue(), value));
            } else if (tokens[0].equals("-")) {
                double value = Double.parseDouble(tokens[1]);
                kalkulator.setCurrentValue(kalkulator.kurang(kalkulator.getCurrentValue(), value));
            } else if (tokens[0].equals("*")) {
                double value = Double.parseDouble(tokens[1]);
                kalkulator.setCurrentValue(kalkulator.kali(kalkulator.getCurrentValue(), value));
            } else if (tokens[0].equals("/")) {
                double value = Double.parseDouble(tokens[1]);
                kalkulator.setCurrentValue(kalkulator.bagi(kalkulator.getCurrentValue(), value));
            } else if (tokens[0].equals("^")) {
                double value = Double.parseDouble(tokens[1]);
                kalkulator.setCurrentValue(kalkulator.pangkat(kalkulator.getCurrentValue(), value));
            } else if (tokens[0].equals("#")) {
                kalkulator.setCurrentValue(kalkulator.akarKuadrat(kalkulator.getCurrentValue()));
            } else if (tokens[0].equals("C")) {
                kalkulator.clear();
            } else if (tokens[0].equals("~")) {
                break;
            }

            System.out.printf("%.2f\n", kalkulator.getCurrentValue());
        }

        scanner.close();
    }
}
