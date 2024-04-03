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
| `2^15` | `0.000067` | `0.000000` |
| `2^20` | `0.003167` | `0.003100` |
| `2^24` | `0.044667` | `0.045500` |
| `2^26` | `0.178733` | `0.183100` |
| Total | `0.226634` | `0.231700` |

![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/25ed9b4d-0caa-4f4e-a596-d02943af22f7)

During debug mode, the table and figure above show that **C kernel is faster than the x86-64 kernel** by a (C - x86-64) difference of **-0.005066** seconds in average execution time, where negative difference means C is indeed faster than x86-64.

#### Release Mode
| Vector Size (n) | Average Time (C) | Average Time (x86-64) | 
| :-------- | :------- | :------- | 
| `2^15` | `0.000033` | `0.000067` |
| `2^20` | `0.000633` | `0.001700` |
| `2^24` | `0.009600` | `0.029433` |
| `2^26` | `0.035667` | `0.114900` |
| Total | `0.045933` | `0.146100` |

![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/97ac4101-13f8-4e8f-afd9-afee2e39ab29)

While on release mode, the **C kernel is still faster than the x86-64 kernel** by a (C - x86-64) difference of **-0.100167** seconds in average execution time. 

### PC 2: C vs x86-64 Average Execution Time Analysis
#### Debug Mode
| Vector Size (n) | Average Time (C) | Average Time (x86-64) | 
| :-------- | :------- | :------- | 
| `2^15` | `0.000067` | `0.000000` |
| `2^20` | `0.002400` | `0.002133` |
| `2^24` | `0.037033` | `0.033967` |
| `2^26` | `0.147867` | `0.133500` |
| Total | `0.187367` | `0.169600` |

![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/c4a930da-f228-49d1-a71b-8ea33b85e9ff)

During debug mode, the table and figure show that the **x86-64 kernel is faster than the C kernel in all of the vector sizes** by a (C - x86-64) difference of **0.017767** seconds in average execution time, where positive difference means that x86-64 is indeed faster than C.

#### Release Mode
| Vector Size (n) | Average Time (C) | Average Time (x86-64) | 
| :-------- | :------- | :------- | 
| `2^15` | `0.000000` | `0.000100` |
| `2^20` | `0.000600` | `0.001533` |
| `2^24` | `0.009833` | `0.025267` |
| `2^26` | `0.037367` | `0.100967` |
| Total | `0.047800` | `0.127867` |

![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/11928a49-51bc-4549-9f69-56d528608763)

While on release mode, the **C kernel is faster than the x86-64 kernel** by a difference of **-0.080067** seconds in average execution time. 

### Analysis of the Results
#### Which PC is the fastest in executing the kernels?
This question is asked because we want to determine if different computer specifications can affect the execution time of the kernels.
| PC # | Debug Mode (Total Average Time in C) | Debug Mode (Total Average Time in x86-64) | Release Mode (Total Average Time in C) | Release Mode (Total Average Time in x86-64) | TOTAL |
| :-------- | :------- | :------- | :------- | :------- | :------- | 
| `PC1` | `0.226634` | `0.231700` | `0.045933` | `0.146100` | `0.650367` |
| `PC2` | `0.187367` | `0.169600` | `0.047800` | `0.127867` | `0.532634` |

![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/f4b8ee08-8232-44d0-8d7d-3a3b24b2192d)

The table and figure show that in all modes and kernels, **PC 2 contains a more powerful CPU than PC 1 and can execute the kernels faster than PC 1**. Hence, CPU specification matters in having a faster execution time which PC 2 overpowers PC 1 in this case.

#### Which Kernel is the fastest?
This question is also asked because we want to determine if the x86-64 kernel is truly faster than the C kernel. After all, according to the lessons that have been discussed, there are 3 levels of program code: high-level language, assembly language, and hardware representation.
It is said that assembly language skips the first level which should make it more faster than high-level languages. An image is attached for a better visualization.

![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/24885e11-a8d5-45ff-8fb5-e3a051b0b9db)

Furthermore, using only the fastest total average execution time among the two PCs. This will properly show which kernel would be faster than the other.

| Kernel | Debug Mode | Release Mode | Total |
| :-------- | :------- | :------- | :------- | 
| `C` | `0.187367` | `0.047766` | `0.233300` | 
| `x86-64` | `0.1696` | `0.127867` | `0.297467` |

![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/eb7c82c1-845a-4b07-902b-3c6fd4f7cfc4)

The table and figure show that **in debug mode the x86-64 kernel is faster than the C kernel. While in release mode, the C kernel is faster than the x86-64 kernel**.

Overall, **the average execution time of x86-64 is slower than C**. The group outlines 2 possible reasons made from inferences with working with Visual Studios, first, the code implemented in C is more optimized than the code in x86-64. Thus, giving C less execution time. Second, every time Visual Studio needs to run the Assembly code, it needs to invoke the assembler (NASM) through the command line. Add to that having to output the .asm file into a .obj object just for it to link with the Main C program.

### Abstract *(Program output of C and x86-64 w/ Correctness Check)*
#### 2^15
![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/b8043746-4d28-49a9-be9a-58b17f1507fb)
#### 2^20
![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/b579344d-c391-4b19-8506-04a26e3ff419)
#### 2^24
![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/1c583416-b4ec-4be0-b64e-420ddcb6fc0b)
#### 2^26
![image](https://github.com/mauries-lopez/LBYARCH-SAXPY/assets/102708347/2353b4b0-20cb-4d25-bd87-485f144b8083)


