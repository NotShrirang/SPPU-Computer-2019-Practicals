%macro dispmsg 2
    mov rax,1
    mov rdi, 1
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro


%macro exitprog 0
    mov rax, 60
    mov edi,0
    syscall
%endmacro

%macro gtch 1
    mov rax, 0
    mov rdi, 0
    mov rsi, %1
    mov rdx, 1
    syscall
%endmacro

section .data
    nwline db 10
    m0 db 10,10,"Program to calculate factorial of a given number.",10
    l0 equ $-m0

    m2 db 10,"Enter Number (2 digit HEX no) : "
    l2 equ $-m2

    m4 db 10,"The factorial is : "
    l4 equ $-m4
    factorial  dq 1

section .bss
    no1 resq 1
    input resb 1
    output resb 1


section .text
    global _start

_start :
    dispmsg m0,l0
    dispmsg m2,l2    ; Display message
    call getnum

    mov [no1],rax     ; Accept number
    gtch input ; To read and discard ENTER key pressed.

    mov rcx,[no1]

    call facto
    mov rax,00

    dispmsg m4,l4
    mov rax,qword[factorial]
    call disphx16   	  ; displays a 8 digit hex number  in rax
    exitprog



facto:
    push rcx
    cmp rcx,01
    jne ahead
    jmp exit2

ahead:
    dec rcx
    call facto

exit2:
    pop rcx
    mov rax,rcx
    mul qword[factorial]
    mov qword[factorial],rax
    ret

;; Procedure to get a 2 digit hex no from user; number returned in rax
getnum:
    mov cx,0204h
    mov rbx,0
ll2:
    push rcx	; syscall destroys rcx. Rest all regs are preserved
    gtch input
    pop rcx
    mov rax,0
    mov al,byte[input]
    sub rax,30h
    cmp rax,09h
    jbe skip1
    sub rax,7
skip1:
    shl rbx,cl
    add rbx,rax
    dec ch
    jnz ll2
    mov rax,rbx
    ret


disphx16:   ; displays a 16 digit hex number passed in rax
    mov rbx,rax
    mov cx,1004h		;16 digits to display and 04 count to rotate
ll6:
    rol rbx,cl
    mov rdx,rbx
    and rdx,0fh
    add rdx,30h
    cmp rdx,039h
    jbe skip4
    add rdx,7
skip4:
    mov byte[output],dl
    push rcx
    dispmsg output,1
    pop rcx
    dec ch
    jnz ll6
    ret



