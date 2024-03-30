section .data
scalar dd 2
vectorX dd 1.0, 2.0, 3.0
vectorY dd 11.0, 12.0, 13.0
vectorZ dd 0

section .text
bits 64
Default rel

global asmMain

asmMain:
    mov rbp, rsp; for correct debugging
    ;write your code here
    MOVSS XMM3, [vectorZ]
    
    ;Get Scalar Value
    MOV R8D, [scalar]
    CVTSI2SS XMM5, R8D
    
    ;Iterator
    XOR RCX, RCX
    MOV RCX, 0
    
    ;Compute SAXPY
    JMP computeSAXPY

computeSAXPY:

    ;Check if the current value of vectorX is the same with vectorY first value.
    ;Stop when equal.
    
    ;Get VectorY Value
    MOVSS XMM2, [vectorY + rcx * 4]
    UCOMISS XMM2, XMM3
    JZ DONE
    
    ;Get VectorX Value
    MOVSS XMM1, [vectorX + rcx * 4]
    
    ;Multiply Scalar with VectorX Value
    VMULSS XMM4, XMM1, XMM5
    
    ;Add Product with VectorY Value
    VADDSS XMM6, XMM4, XMM2
    
    ;Store XMM6 to vectorZ. For this example, dapat may tatlong value si VectorZ after ung loop nito.
        
    INC rcx
    JMP computeSAXPY

DONE:


    xor rax, rax
    ret
	