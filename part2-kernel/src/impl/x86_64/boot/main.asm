global star 

section .text
bits 32
star: 
    ; print ok
    mov dword [0xb8000], 0x2f4b2f4f
    hlt