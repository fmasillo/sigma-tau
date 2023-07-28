#include <stdlib.h>
#include <stdio.h>
int *C;                // Permutation shared w/ application that owns its O(n) space.
int n, b, p, u, count;  // See variable descriptions in main.

int pi(int i){ // Return the permutation's ith value via the cyclic pi array.
    return C[1 + ((b + i - 2) % n)]; 
} 

void Visit(){ // Called for each new permutation; this method prints the perm.
    for(int i=1; i<=n; i++) printf("%d", pi(i)); 
    printf("\n"); 
}

void Sigma(){ // Apply sigma by cyclically incrementing b
    b = (b % n) + 1; 
} 

void Tau(){ // Apply tau by swapping the first two elements and updating p and u
    u -= (pi(n) < pi(1)) + (pi(1) < pi(2)) + (pi(2) < pi(3)); // Remove old up-steps
    u += (pi(n) < pi(2)) + (pi(2) < pi(1)) + (pi(1) < pi(3)); // Add new up-steps
    if(p == b) p = (b % n) + 1;      // Update p if it was in the first index
    else if(p == (b % n) + 1) p = b; // Update p if it was in the second index    

    int tmp = C[b];          // Swap pi[1] and pi[2]
    C[b] = C[(b % n) + 1]; 
    C[(b % n) + 1] = tmp; 
}  

void Next(){ // Calls Sigma() or Tau() to create the next permutation.
    if(count <= 2*n - 2) count++; // Increase counter until SpecialP is met.
    int r = (p != b) ? C[(p % n) + 1] : pi(3); // Value right of n skipping 2nd.
    if((pi(2) == (r % (n-1)) + 1) && count != (2*n - 2)) Tau();
    else Sigma();
}

int main(int argc, char *argv[]){
    n = (argc > 1) ? atoi(argv[1]) : 0;  // Read n from command-line; default 0.
    if (n < 4) { 
        printf("usage: %s n for n > 3\n",argv[0]); 
        exit(0); 
    }

    C = (int *)malloc((n+1)*sizeof(int));  // Current permutation.
    C[1] = n-1; C[2] = n;                  // Initialize permutation to 
    for(int i=3; i<=n; i++) C[i] = n-i+1;  // n-1,n,n-2,n-3,...,3,2,1.   

    b = 1;      // First cyclic index into C (with C[0] ignored).
    p = 2;      // Index of n in C.
    u = 2;      // Number of up-steps in pi.
    count = 0;  // Counter for the number of op. to be done before SpecialP is met.
    while(u != 2 || pi(1) != n-2 || pi(2) != n-1 || pi(n-1) != 1 || pi(n) != n){ 
        Visit(); 
        Next(); 
    }
    Visit(); 
}