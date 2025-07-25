section .data
    msg db 'Hello, World!', 0xA
    len equ $ - msg

section .text
    global _start

_start:
    mov eax, 4       ; syscall number for sys_write
    mov ebx, 1       ; file descriptor: stdout
    mov ecx, msg     ; message to print
    mov edx, len     ; length of message
    int 0x80         ; make syscall

    mov eax, 1       ; syscall: exit
    xor ebx, ebx     ; return 0
    int 0x80
