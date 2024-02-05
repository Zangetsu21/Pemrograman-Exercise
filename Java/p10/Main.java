import java.util.*;

class Pegawai {
    protected String id;
    protected int usia, tipe;
    protected int income;

    public void set(String pid, int u, int t) {
        id = pid;
        usia = u;
        tipe = t;
    }

    public String getID() {
        return id;
    }

    public void print() {
        System.out.println(id + " " + tipe + " " + income);
    }
}

class Tetap extends Pegawai {
    public Tetap(String pid, int u, int t, int uang) {
        set(pid, u, t);
        income = uang;
    }

    public void addIncome(int uang) {
        income += uang;
    }
}

class Harian extends Pegawai {
    public Harian(String pid, int u, int t) {
        set(pid, u, t);
        income = 0;
    }

    public void addIncome(int uang) {
        income += uang;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n, age, type, gaji;
        String id;
        ArrayList<Tetap> Obj_T = new ArrayList<Tetap>();
        ArrayList<Harian> Obj_H = new ArrayList<Harian>();
        ArrayList<Tetap> tempT = new ArrayList<Tetap>();
        ArrayList<Harian> tempH = new ArrayList<Harian>();
        boolean foundT, foundH;

        n = input.nextInt();
        for (int i = 0; i < n; i++) {
            id = input.next();
            age = input.nextInt();
            type = input.nextInt();
            if (type == 1) {
                gaji = input.nextInt();
                Tetap temp = new Tetap(id, age, type, gaji);
                Obj_T.add(temp);
            } else {
                Harian temp = new Harian(id, age, type);
                Obj_H.add(temp);
            }
        }
        id = input.next();
        while (!id.equals("END")) {
            gaji = input.nextInt();
            foundT = false;
            foundH = false;
            for (int i = 0; i < Obj_T.size(); i++) {
                if (Obj_T.get(i).getID().equals(id)) {
                    Obj_T.get(i).addIncome(gaji);
                    foundT = true;
                    break;
                }
            }
            if (!foundT) {
                for (int i = 0; i < Obj_H.size(); i++) {
                    if (Obj_H.get(i).getID().equals(id)) {
                        Obj_H.get(i).addIncome(gaji);
                        foundH = true;
                        break;
                    }
                }
            }
            id = input.next();
        }
        for (int i = 0; i < Obj_T.size(); i++) {
            Obj_T.get(i).print();
        }
        for (int i = 0; i < Obj_H.size(); i++) {
            Obj_H.get(i).print();
        }
    }
}
