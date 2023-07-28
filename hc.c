#include <stdlib.h>
#include <stdio.h>
int *C;  // Permutation shared w/ application that owns its O(n) space.
int n, b, p, uPrime;  // O(1) additional space; see descriptions in main.

int pi(int i){  // Return the permutation's ith value via the cyclic pi array.
    return C[((b + i - 2) % n) + 1]; 
}

void Visit(){  // Called for each new permutation; this method prints the perm.
    for(int i=1; i<=n; i++) printf("%d", pi(i)); 
    printf("\n"); 
}

void Sigma(){   // Apply sigma by cyclically incrementing b and updating uPrime.
    uPrime -= (pi(1) < pi(3)) + (pi(3) < pi(4));  // Remove old up-steps.
    uPrime += (pi(1) < pi(2)) + (pi(2) < pi(4));  // Add new up-steps.
    b = (b % n) + 1; 
}

void Tau(){   // Apply tau by swapping array entries and updating p and uPrime.
    uPrime -= (pi(n) < pi(1)) + (pi(1) < pi(3));  // Remove old up-steps.
    uPrime += (pi(2) < pi(3)) + (pi(n) < pi(2));  // Add new up-steps.
    if(p == b) p = (b % n) + 1;       // Update p if it was in the first index.
    else if(p == (b % n) + 1) p = b;  // Update p if it was in the second index.

    int tmp = C[b];          // Swap the first two values in pi,
    C[b] = C[(b % n) + 1];   // which are pi[1] and pi[2],
    C[(b % n) + 1] = tmp;    // taken cyclically ignoring C[0].
}  

void Next(){   // Calls Sigma() or Tau() to create the next permutation.
    int r = (p != b) ? C[(p%n)+1] : pi(3);  // Value right of n skipping 2nd.
    int specialSet = (uPrime == n-2 && p == (b % n) + 1); // See paper.
    if(((r < n-1 && pi(2)==r+1) || (r==n-1 && pi(2)==2)) || specialSet) Tau();
    else Sigma(); 
}

int main(int argc, char *argv[]){  // Give odd n > 3 as command-line argument.
    n = (argc > 1) ? atoi(argv[1]) : 0;  // Read n from command-line; default 0.
    if (n < 5 || n % 2 == 0) {
       printf("usage: %s n for odd n > 3\n",argv[0]); 
       exit(0); 
    }

    C = (int *)malloc((n+1)*sizeof(int));  // Permutation stored in C array.
    for(int i=1; i<=n; i++) C[i] = i;      // Initialize permutation to 12...n.

    b = 1;          // First cyclic index into pi (with C[0] ignored).
    p = n;          // Index of n in C.
    uPrime = n-2;   // Number of up-steps in pi[1] pi[3] pi[4] ... pi[n].
    while(uPrime != n-2 || pi(1) != n || pi(2) != 1){ 
        Visit(); 
        Next(); 
    }
    Visit(); 
}
