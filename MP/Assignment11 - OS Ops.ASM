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

buffer: db 20 
length equ $buffer

nwline db 10
m0 db 10,10,"Program to perform DOS operation"
l0 equ $-m0

m1 db 10,"1.TYPE",10,"2. COPY",10,"3.DELETE",10,"4. Exit",10,10, "Enter your choice (1/2/3/4 <ENTER>): "
l1 equ $-m1

m4 db 10,"1 file(s) copied."
l4 equ $-m4

m5 db 10,"syntax of command is incorrect"
l5 equ $-m5


section .bss

input resb 1
output resb 1
choice resb 1

fname resb 15
fname1 resb 15
fd_in resb 1
fd_in1 resb 1


section .text
global _start

_start :

dispmsg m0,l0

back:
dispmsg m1,l1  			; display Menu

gtch input

mov al, byte[input]    		; Get choice
mov byte[choice],al

gtch input 			; To read and discard ENTER key pressed.

mov al, byte[choice]

cmp al, '1'
jz type1

cmp al, '2'
jz copy1

cmp al, '3'
jz delete1

cmp al,'4'
jnz back
exitprog

;;;;;;;;;;;;;;;;;; type command
type1:

mov rcx,00
pop rcx
cmp rcx,1
jne next_arg
dispmsg m5,l5

jmp back
next_arg:
 	pop 	rcx				; get pointer for args
	pop rcx	
mov 	rdx,00

up: 	mov al,byte[rcx+rdx]
        mov byte[fname+rdx],al
cmp 	byte [rcx+rdx],0	;check for end of argument
	je 	Print_arg
	inc 	rdx
	
	jmp 	up

Print_arg: mov byte[fname+rdx],0
	
	mov rax,2
        mov rdi,fname
        mov rsi,0
        mov rdx,0777
        syscall

        mov [fd_in],rax

        mov rax,0
        mov rdi,[fd_in]     
        mov rsi,buffer
        mov rdx,20
        syscall

        
	mov rax,1
        mov rdi,1
        mov rsi,buffer
        mov rdx,20
        syscall

        mov rax,3
        mov rdi,[fd_in]
        mov rsi,0
        syscall

jmp back


;;;;;;;;;;;;;;;;;;;;;;;copy command
copy1:


mov rcx,00
pop rcx
cmp rcx,2
jne next_arg1
dispmsg m5,l5
jmp back

next_arg1:
pop rcx 	
pop rcx	
mov 	rdx,00

up1: 	mov al,byte[rcx+rdx]
        mov byte[fname+rdx],al
cmp 	byte [rcx+rdx],0	;check for end of argument
	je 	next_arg2
	inc 	rdx
	inc rsi
	jmp 	up1

next_arg2:
	mov byte[fname+rdx],0
	
	pop rcx	
	mov 	rdx,00

up2: 	mov al,byte[rcx+rdx]
        mov byte[fname1+rdx],al
cmp 	byte [rcx+rdx],0	;check for end of argument
	je 	disp_arg1
	inc 	rdx
	jmp 	up2

disp_arg1:mov byte[fname1+rdx],0	
		
	mov rax,2
        mov rdi,fname
        mov rsi,0
        mov rdx,0777
        syscall

        mov [fd_in],rax
	
	mov rax,0
        mov rdi,[fd_in]     
        mov rsi,buffer
        mov rdx,20
        syscall
	
	;mov    rax, 1          ; 'write' syscall
        ;mov    rdi, 1  ; file descriptor
        ;mov    rsi, buffer     ; message address
        ;mov    rdx, 20     ; message string length
        ;syscall
		
	mov rax, 2            ; 'open' syscall
        mov rdi, fname1        ; file name
        mov rsi, 0102o      ; read and write mode, create if not
        mov rdx, 0666o       ; permissions set
        syscall

        mov [fd_in1], rax


        mov    rax, 1          ; 'write' syscall
        mov    rdi, [fd_in1]   ; file descriptor
        mov    rsi, buffer     ; message address
        mov    rdx, 20     ; message string length
        syscall

	
	mov rax,3
        mov rdi,[fd_in]
        syscall
       
	mov rax,3
        mov rdi,[fd_in1]
        syscall

	dispmsg m4,l4
	
jmp back


delete1:

mov rcx,00
pop rcx
cmp rcx,1
jne next_arg5
dispmsg m5,l5

jmp back
next_arg5:
 	pop 	rcx				; get pointer for args
	pop rcx	
mov 	rdx,00

up3: 	mov al,byte[rcx+rdx]
        mov byte[fname+rdx],al
	cmp 	byte [rcx+rdx],0	;check for end of argument
	je 	print_arg5
	inc 	rdx
	jmp 	up3
print_arg5:
	mov byte[fname+rdx],0
	mov rax, 87        ; defines which systemcall we are using (87th)
	mov rdi,fname     ;moves the address of file we want to delete into %rdi
                      	   ; (this is where the argument of sys_unlink(x86-64) is stored)
	syscall             ; starts the appropriate function

jmp back












