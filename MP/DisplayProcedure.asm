; Display Procedure

display64:
    mov rbx, rax
    mov rdi, result
    mov cx, 16

    up1:
        rol bx, 04
        mov al, bl

    and al, 0fh
    cmp al, 09h
    jg add_37h
    add al, 30h
    jmp skip

    add_37h:
        add al, 37h
    skip:
        mov [rdi], al
        inc rdi
        dec cx
    jnz up1
    dispmsg result, 16
    ret
