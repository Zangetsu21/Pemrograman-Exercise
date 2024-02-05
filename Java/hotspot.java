import java.util.*;

class Pairs implements Comparable<Pairs> {
    public int first;
    public int second; 
    public Pairs(int first, int second) {
        this.first = first;
        this.second = second;
    } 
    @Override
    public int compareTo(Pairs other) {
        if (this.first < other.first) {
            return 1;
        } else if (this.first > other.first) {
            return -1;
        } else {
            if (this.second < other.second) {
                return 1;
            } else if (this.second > other.second) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

public class hotspot {
    Set<Pairs> coordinate = new TreeSet<>();
    public hotspot(){
        this.coordinate.clear();
    }
    public void add(Pairs p){
        coordinate.add(p);
    }
    public int getsize(){
        return coordinate.size();
    }
    public void print(){
        for(Pairs p : coordinate){
            if(p.second > 0)
            {
                System.out.printf("(%d,%d)", p.first, p.second);
            }
        }
    }
    public void read(){
        Scanner sc = new Scanner(System.in);
        int n, x, y;
        n = sc.nextInt();
        for(int i = 0; i < n; i++)
        {
            x = sc.nextInt();
            y = sc.nextInt();
            Pairs p = new Pairs(x, y);
            coordinate.add(p);
        }
    }
    public static void main(String[] args) {
        hotspot h = new hotspot();
        h.read();
        System.out.println(h.getsize());
        h.print();
    }
}