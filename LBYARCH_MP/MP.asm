section .text
bits 64
Default rel

global asmComputeSAXPY

asmComputeSAXPY:
	;ECX HAS A
	;xmm1 has x
	;xmm2 has y
	;xmm0 is our return

    ;Get Scalar Value
    CVTSI2SS XMM5, ECX   
	
    ;Multiply Scalar with VectorX Value
    VMULSS XMM4, XMM1, XMM5 
    
    ;Add Product with VectorY Value
    VADDSS XMM0, XMM4, XMM2

	xor rax, rax
	ret