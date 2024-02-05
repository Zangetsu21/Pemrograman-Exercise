import java.io.*;
import java.util.*;
class orang
{
    private String nama;
    private int usia, tinggi;
    private double berat;
    public orang()
    {
        nama = " ";
        usia = 0;
        tinggi = 0;
        berat = 0;
    }
    public orang(String nama, int usia,int tinggi, double berat)
    {
        this.nama = nama;
        this.usia = usia;
        this.tinggi = tinggi;
        this.berat = berat;
    }
    public String getnama()
    {
        return nama;
    }
    public int getusia()
    {
        return usia;
    }
    public int gettinggi()
    {
        return tinggi;
    }
};
public class person 
{
    public static void main(String[] args) 
    {
        int n, counter = 0, sum = 0;
        double rata=0;
        orang org[] = new orang[100];
        Scanner inp = new Scanner(System.in);
        n = inp.nextInt();
        for(int i=0; i<n; i++)
        {
            String nama;
            int usia, tinggi;
            double berat;
            nama = inp.next();
            usia = inp.nextInt();
            tinggi = inp.nextInt();
            berat = inp.nextDouble();
            org[i] = new orang(nama,usia,tinggi,berat);
            sum = sum + org[i].gettinggi();
        }
        rata = (double) sum/n;
        for(int i=0; i<n; i++)
        {
            if(org[i].gettinggi()>rata)
            {
                counter++;
            }
        }
        for (int i=0; i<n; i++)
        {
            System.out.println(org[i].getnama()+" "+org[i].getusia());
        }
        System.out.printf("%.2f\n", rata);
        System.out.println(counter);
    }
}
