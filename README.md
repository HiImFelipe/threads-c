## Threads in C

Experimenting with the library pthreads, an API available for POSIX (in my case, Linux) ecosystems.

The program consists in having a race condition with a global value such as a bank account balance and making usage of a Mutex to solve it, locking the value and making it consistent throughout all threads.

### Running

Requirements:

- GCC compiler;
- POSIX API-compliant OS;

```bash
gcc -o program src/main.c src/bank_account/bank_account.c 

## program is essentially just the name of the executable and can be changed to whatever
```

### References:

- <a href="https://www.youtube.com/watch?v=raLCgPK-Igc">Mutex Introduction (pthreads)</a>
- <a href="https://www.youtube.com/watch?v=d9s_d28yJq0">Short introduction to threads (pthreads)</a>
- <a href="https://www.youtube.com/watch?v=4jXSU2jw3Ag">Cap. 18 – Concorrência – 2. Goroutines & WaitGroups</a> - GoLang explanation, helped me to understand what a Mutex is.
