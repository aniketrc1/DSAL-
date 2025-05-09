#include<iostream>
using namespace std;

float a[20], b[20], wt[20][20], c[20][20];
int r[20][20], n;

void cons_obst(){
    int i, j, k, l;

    // Initialization
    for(i = 0; i <= n; i++){
        c[i][i] = 0;
        r[i][i] = 0;
        wt[i][i] = b[i];

        // For j - i = 1
        if (i < n) {
            wt[i][i+1] = b[i] + b[i+1] + a[i+1];
            c[i][i+1] = wt[i][i+1];
            r[i][i+1] = i+1;
        }
    }

    // OBST construction for length >= 2
    for(int m = 2; m <= n; m++) {
        for(i = 0; i <= n - m; i++) {
            j = i + m;
            wt[i][j] = wt[i][j-1] + a[j] + b[j];
            c[i][j] = 9999;

            for(l = i+1; l <= j; l++) {
                float cost = c[i][l-1] + c[l][j] + wt[i][j];
                if(cost < c[i][j]) {
                    c[i][j] = cost;
                    r[i][j] = l;
                }
            }
        }
    }

    // Final Result
    cout<<"\n\nOptimal BST Results:";
    cout<<"\nTotal weight (wt[0]["<<n<<"]) : "<<wt[0][n];
    cout<<"\nMinimum cost (c[0]["<<n<<"]) : "<<c[0][n];
    cout<<"\nRoot of tree (r[0]["<<n<<"]) : "<<r[0][n];
}

void print(int l1, int r1){
    if(l1 >= r1 || r[l1][r1] == 0) return;

    int root = r[l1][r1];
    if(r[l1][root-1] != 0)
        cout<<"\nLeft child of "<<root<<" : "<<r[l1][root-1];

    if(r[root][r1] != 0)
        cout<<"\nRight child of "<<root<<" : "<<r[root][r1];

    print(l1, root - 1);
    print(root, r1);
}

int main(){
    cout<<"Program for OBST (Optimal Binary Search Tree)"<<endl;
    cout<<"Enter number of nodes: ";
    cin >> n;

    cout<<"Enter probability of successful search (p[1] to p["<<n<<"]):\n";
    for(int i = 1; i <= n; i++){
        cout<<"p["<<i<<"]: ";
        cin >> a[i];
    }

    cout<<"Enter probability of unsuccessful search (q[0] to q["<<n<<"]):\n";
    for(int i = 0; i <= n; i++){
        cout<<"q["<<i<<"]: ";
        cin >> b[i];
    }

    cons_obst();
    print(0, n);

    return 0;
}
