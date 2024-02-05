#include<iostream>
using namespace std;

const int jumlah_node = 9;

int cariIndeksMinimal(int kunci_node[], bool sudah_kunjung[])  
{ 
    int tak_hingga = 999, indeks_minimal;
    for (int v = 0; v < jumlah_node; v++) { 
        if (sudah_kunjung[v] == false && kunci_node[v] < tak_hingga) { 
            tak_hingga = kunci_node[v];
            indeks_minimal = v;
        }
    }    
    return indeks_minimal;  
}  

int tampilkanMST(int node_parent[], int biaya[jumlah_node][jumlah_node])  
{  
    int total_biaya_minimum = 0;
    cout << "Edge \tWeight\n";  
    for (int i = 1; i < jumlah_node; i++) {
        cout << char('A' + node_parent[i]) << " - " << char('A' + i) << "      " << biaya[i][node_parent[i]] << " \n";  
        total_biaya_minimum += biaya[i][node_parent[i]];
    }
    cout << "Total Cost MST (Prims): " << total_biaya_minimum;
    return 0;
} 
 
void cariMST(int biaya[jumlah_node][jumlah_node])  
{  
    int node_parent[jumlah_node], kunci[jumlah_node];
    bool sudah_kunjung[jumlah_node];
    
    for (int i = 0; i < jumlah_node; i++) { 
        kunci[i] = 999;
        sudah_kunjung[i] = false;
        node_parent[i] = -1;
    }    

    kunci[0] = 0;  
    node_parent[0] = -1; 

    for (int x = 0; x < jumlah_node - 1; x++) 
    {  
        int u = cariIndeksMinimal(kunci, sudah_kunjung);  
        sudah_kunjung[u] = true;
        for (int v = 0; v < jumlah_node; v++)  
        {   
            if (biaya[u][v] != 0 && sudah_kunjung[v] == false && biaya[u][v] < kunci[v]){  
                node_parent[v] = u;
                kunci[v] = biaya[u][v];  
            }        
        }
    }

    tampilkanMST(node_parent, biaya);  
}  


int main()  
{   
    int graph_prims[jumlah_node][jumlah_node] = { { 0, 2, 4, 0, 0, 0, 7, 0, 0 },
                                            { 2, 0, 4, 0, 6, 4, 0, 0, 0 },
                                            { 4, 4, 0, 5, 0, 0, 0, 0, 0 },
                                            { 0, 0, 5, 0, 2, 0, 0, 0, 0 },
                                            { 0, 6, 0, 2, 0, 3, 0, 6, 3 },
                                            { 0, 4, 0, 0, 3, 0, 8, 5, 0 },
                                            { 7, 0, 0, 0, 0, 8, 0, 9, 0 },
                                            { 0, 0, 0, 0, 6, 5, 9, 0, 1 },
                                            { 0, 0, 0, 0, 3, 0, 0, 1, 0 } };
    
    cariMST(graph_prims);  

    return 0;  
}
