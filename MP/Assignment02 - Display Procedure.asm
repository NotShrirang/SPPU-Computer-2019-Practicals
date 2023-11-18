section .data
    msg1 db 10, 13, "Enter a string : "
    len1 equ $-msg1

section .bss
    str1 resb 200
    result resb 16

    dispbuff resb 2
    %macro print 2
        mov eax, 4
        mov ebx, 1
        mov ecx, %1
        mov edx, %2
        int 80h
    %endmacro

section .text
    global _start

_start:
    mov rax, 1          ; display
    mov rdi, 1
    mov rsi, msg1
    mov rdx, len1
    syscall
    
    mov rax, 0      ; Store string
    mov rdi, 0
    mov rsi, 0
    mov rdx, 200
    syscall
        
    call display
    
    display:
        mov rbx, rax
        mov rdi, result
        mov cx, 16
        up1:
            rol rbx, 04
            mov al, bl

            and al, 0fh
            cmp al, 09h
            jg add_37
            add al, 30h
            jmp skip
    
    add_37:
        add al, 37h
        skip:
            mov [rdi], al
            inc rdi
            dec cx
        jnz up1
        print result, 16
        ret
            
    mov rax, 60      ; exit system call
    mov rdi, 0
    syscall