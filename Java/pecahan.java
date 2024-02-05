import java.io.*;
import java.util.*;

public class pecahan {
    private int a,b,c;
    public pecahan()
    {
        a=0;b=0;c=1;
    }
    public void set(int x, int y, int z)
    {
        a=x;b=y;c=z;simple();
    }
    public int fpb(int m, int n)
    {
        while(n!=0)
        {
        int t =m%n;
        m=n;
        n=t;
        }
        return m;
    }
    public void simple()
    {
        a= a+b/c;
        b=b%c;
        int t=fpb(b,c);
        b=b/t;
        c=c/t;
    }
    public void cetak()
    {
        if(b==0)
        {
            System.out.println(a);
        }
        else
        {
            System.out.printf("%d %d/%d\n", a,b,c);
        }
    }
    public void add (int pa, int pb, int pc)
    {
        this.a= this.a+pa;
        this.b= this.b*pc+this.c*pb;
        this.c=this.c*pc;
        simple();
    }
    public void mul (int pa, int pb, int pc)
    {
        this.b= (this.a*this.c+this.b)*(pa*pc+pb);
        this.c=this.c*pc;
        this.a=0;
        simple();
    }
    public void inc ()
    {
        this.a++;
    }
    public void dec ()
    {
        this.a--;
    }
    public static void main(String[] args)
    {
        pecahan p = new pecahan();
        Scanner inp = new Scanner(System.in);
        String x;
        x = inp.next();
        while(!x.equals("end"))
        {
            if(x.equals("set"))
            {
                int a= inp.nextInt();
                int b= inp.nextInt();
                int c= inp.nextInt();
                p.set(a,b,c);
            }
            if(x.equals("add"))
            {
                int a= inp.nextInt();
                int b= inp.nextInt();
                int c= inp.nextInt();
                p.add(a,b,c);
            }
            if(x.equals("mul"))
            {
                int a= inp.nextInt();
                int b= inp.nextInt();
                int c= inp.nextInt();
                p.mul(a,b,c);
            }
            if(x.equals("inc"))
            {
                p.inc();
            }
            if(x.equals("dec"))
            {
                p.dec();
            }
            if(x.equals("p"))
            {
                p.cetak();
            }
            x = inp.next();
        }
    }
};

