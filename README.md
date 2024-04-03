## x86-to-C Interface Programming Project

### Comparative Result for C vs Assembly

Microsoft Visual Studio has *Performance Diagnostics Tools* that allow analysis of CPU usage. With this, we decided to execute the kernels in two machines with different CPUs, to determine if there is any significant difference between the average execution time when executed in different CPUs.

The following computer specifications will be used for the comparative analysis:

**Maui: PC 1**
| Part | Information |
| :-------- | :------- | 
| `CPU` | `AMD Ryzen 5 3600 6-Core Processor (12 CPUs), ~3.6GHz` |
| `RAM` | `32768 MB` |

**Nathan: PC 2**
| Part | Information |
| :-------- | :------- | 
| `CPU` | `AMD Ryzen 5 5600G with Radeon Graphics (12 CPUs), ~3.9GHz` |
| `RAM` | `16384MB` |

Furthermore, the analysis test results are conducted using a value of `2` for `scalar` and `30` for the `number of execution times`. Also, the analysis test will only be executed `once` because there is not 
much significant difference in the average execution time when running n number of times.

### PC 1: C vs x86-64 Average Execution Time Analysis
#### Debug Mode
| Vector Size (n) | Average Time (C) | Average Time (x86-64) | 
| :-------- | :------- | :------- | 
| `2^15` | `0.000067` | `0.000100` |
| `2^20` | `0.002700` | `0.002800` |
| `2^24` | `0.044167` | `0.045800` |
| `2^26` | `0.178833` | `0.184967` |
| Total | `0.225767` | `0.233667` |

![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/81527e20-3362-43b2-b7f9-559368494bee)

During debug mode, the table and figure above show that **C kernel is faster than the x86-64 kernel** by a (C - x86-64) difference of **-0.007900** seconds in average execution time, where negative difference means C is indeed faster than x86-64.

#### Release Mode
| Vector Size (n) | Average Time (C) | Average Time (x86-64) | 
| :-------- | :------- | :------- | 
| `2^15` | `0.000000` | `0.000033` |
| `2^20` | `0.000467` | `0.002400` |
| `2^24` | `0.009400` | `0.037867` |
| `2^26` | `0.035600` | `0.155867` |
| Total | `0.045467` | `0.1916167` |

![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/328bef30-fcb0-40cd-ac25-781de9e3f3f6)

While on release mode, the **C kernel is still faster than the x86-64 kernel** by a (C - x86-64) difference of **-0.1461497** seconds in average execution time. 

### PC 2: C vs x86-64 Average Execution Time Analysis
#### Debug Mode
| Vector Size (n) | Average Time (C) | Average Time (x86-64) | 
| :-------- | :------- | :------- | 
| `2^15` | `0.000067` | `0.000133` |
| `2^20` | `0.002200` | `0.002067` |
| `2^24` | `0.037033` | `0.032100` |
| `2^26` | `0.147167` | `0.134800` |
| Total | `0.186467` | `0.169100` |

![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/4c4fa8ba-613b-4b99-a72f-a25531a5d44f)

During debug mode, the table and figure show that except for vector size 2^15, the x86-64 kernel is faster than the C kernel on the other vector sizes. Overall, **x86-64 kernel is faster than the C kernel** by a (C - x86-64) difference of **0.017367** seconds in average execution time, 
where positive difference means the x86-64 kernel is indeed faster than the C kernel. 

#### Release Mode
| Vector Size (n) | Average Time (C) | Average Time (x86-64) | 
| :-------- | :------- | :------- | 
| `2^15` | `0.000000` | `0.000067` |
| `2^20` | `0.000600` | `0.001800` |
| `2^24` | `0.009733` | `0.025533` |
| `2^26` | `0.038033` | `0.098900` |
| Total | `0.048366` | `0.126300` |

![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/bf7b13f1-e798-4894-845c-d5e0b7b0a2ac)

While on release mode, the **C kernel is still faster than the x86-64 kernel** by a difference of **-0.077934** seconds in average execution time. 

### Analysis of the Results
#### Which PC is the fastest in executing the kernels?
This question is asked because we want to determine if different computer specifications can affect the execution time of the kernels.
| PC # | Debug Mode (Total Average Time in C) | Debug Mode (Total Average Time in x86-64) | Release Mode (Total Average Time in C) | Release Mode (Total Average Time in x86-64) | TOTAL |
| :-------- | :------- | :------- | :------- | :------- | :------- | 
| `PC1` | `0.225767` | `0.233667` | `0.045467` | `0.1916167` | `0.6965177` |
| `PC2` | `0.186467` | `0.169100` | `0.020066` | `0.052933` | `0.428566` |

![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/d394bab3-eea0-4827-85ba-7a68f95cbc80)

The table and figure show that in all modes and kernels, **PC 2 contains a more powerful CPU than PC 1 and can execute the kernels faster than PC 1**. Hence, CPU specification matters in having a faster execution time which PC 2 overpowers PC 1 in this case.

#### Which Kernel is the fastest?
This question is also asked because we want to determine if the x86-64 kernel is truly faster than the C kernel. After all, according to the lessons that have been discussed, there are 3 levels of program code: high-level language, assembly language, and hardware representation.
It is said that assembly language skips the first level which should make it more faster than high-level languages. An image is attached for a better visualization.

![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/24885e11-a8d5-45ff-8fb5-e3a051b0b9db)

Furthermore, using only the fastest total average execution time among the two PCs. This will properly show which kernel would be faster than the other.

| Kernel | Debug Mode | Release Mode | Total |
| :-------- | :------- | :------- | :------- | 
| `C` | `0.186467` | `0.020066` | `0.206533` | 
| `x86-64` | `0.169100` | `0.052933` | `0.222033` |

![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/9ed68eb8-6f6f-40ec-a55e-8297dd8e5b9d)

The table and figure show that in every mode, **x86-64 kernel is slower than C kernel**. According to 

### Abstract *(Program output of C and x86-64 w/ Correctness Check)*
#### 2^15
![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/e1c7876c-7c83-4321-b89c-5c722d0fc96b)
#### 2^20
![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/c287493c-f15b-4ca9-9967-97d878352e17)
#### 2^24
![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/cc847d9f-6cd5-4536-97dc-79b793215254)
#### 2^26
![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/b5ad986c-1397-4ce6-9b47-5f6e6293959b)



