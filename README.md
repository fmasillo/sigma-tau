# Constant Time and Space Updates for the Sigma-Tau Problem

This repository contains three C code files for constructing the Hamiltonian path(s) and the Hamiltonian cycle in the Sigma-Tau graph.

File hp.c contains the code for generating the Hamiltonian path with the rule present in [1]. \
File hp_prime.c contains the code for generating the Hamiltonian path with the rule present in [2]. \
File hc.c contains the code for generating the Hamiltonian cycle with the rule present in [2].

If you use this code in academic settings, please cite our paper:
```
  @inproceedings{LiptakMNW2023,
    author    = {Zsuzsanna Lipták and Francesco Masillo and Gonzalo Navarro and Aaron Williams},
    title     = {Constant Time and Space Updates for the Sigma-Tau Problem},
    booktitle = {30th International Symposium On String Processing and Information Retrieval, 
                {SPIRE} 2023, September 26-28, 2023, Pisa, Italy},
    year      = {2023},
  }
```

Bibliography:

[1] Joe Sawada, Aaron Williams: A Hamilton Path for the Sigma-Tau Problem. SODA 2018: 568-575

[2] Joe Sawada, Aaron Williams: Solving the Sigma-Tau Problem. ACM Trans. Algorithms 16(1): 11:1-11:17 (2020)
