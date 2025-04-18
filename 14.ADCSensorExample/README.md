# How to implement time.h lib

## How to get CPU frequency in HZ

### 1. Manually
Using some #define and put manually

### 2. Compute 
We know that 3Ghz processor means 3,000,000,000 cycles per second.  
If needs to compyte cycles count for 0.1 sec then   
0.1 x 3,000,000,000 cycles = 300,000,000 cycles

Normally for loop as below each iteration will consume almost ~ 2 to 3 cycles depending on compiler optimizations and architecture.
```c
    for(volatile unsigned long alter = 0; alter < N; alter++)
```
so if needs to waist 0.1 sec approx we need to do this:

```c
    N = 100,000,000   //Because we know that one iteration will took approx 3 cycles
    for(volatile unsigned long alter = 0; alter < N; alter++)
        __asm__ volatile("nop");        //no operation 
```

This way will get delay for 0.1 sec approax, for compute freq we need to follow this    
- start No of CPU cycles
- delay of 0.1 sec
- end No of CPU cycles
- elsepsed cycles = start cycle count / end cycle count
- freq Hz = elsepsed cycles / 0.1 sec

