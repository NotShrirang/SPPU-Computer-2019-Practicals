section .data
	menumsg db 10,'****** Menu ******',
	db 10,'1: Addition'
	db 10,'2: Subtraction'
	db 10,'3: Multiplication'
	db 10,'4: Division'
	db 10,10,'Enter your choice:: '

	menumsg_len: equ $-menumsg

	addmsg db 10,'Welcome to additon',10
	addmsg_len equ $-addmsg

	submsg db 10,'Welcome to subtraction',10
	submsg_len equ $-submsg

	mulmsg db 10,'Welcome to Multiplication',10
	mulmsg_len equ $-mulmsg

	divmsg db 10,'Welcome to Division',10
	divmsg_len equ $-divmsg

	wrchmsg db 10,10,'You Entered a Wrong Choice....!',10
	wrchmsg_len equ $-wrchmsg

	no1 dq 08h
	no2 dq 02h

	nummsg db 10
	result dq 0

	resmsg db 10,'Result is:'
	resmsg_len equ $-resmsg

	qmsg db 10,'Quotient::'
	qmsg_len equ $-qmsg

	rmsg db 10,'Remainder::'
	rmsg_len equ $-rmsg
	
	nwmsg db 10
	resh dq 0
	resl dq 0
section .bss
	choice resb 2
	dispbuff resb 16

%macro scall 4
        mov rax,%1
        mov rdi,%2
        mov rsi,%3
        mov rdx,%4
        syscall
%endmacro

section .text
global _start
	_start:
up:
	scall 1,1,menumsg,menumsg_len
	scall 0,0,choice,2

	cmp byte [choice],'1'
	jne case2
	call add_proc
	jmp up


case2:
	cmp byte [choice],'2'
	jne case3
	call sub_proc
	jmp up

case3:
	cmp byte [choice],'3'
	jne case4
	call mul_proc
	jmp up
case4:
	cmp byte [choice],'4'
	jne caseinv
	call div_proc
	jmp up
caseinv:
	scall 1,1, wrchmsg,wrchmsg_len
exit: 
	mov eax,01
	mov ebx,0
	int 80h

add_proc:
        mov rax,[no1]
	adc rax,[no2]
	mov [result],rax
	scall 1,1,resmsg,resmsg_len
	mov rbx,[result]
	call disp64num
	scall 1,1,nummsg,1
	ret
	
sub_proc:
	
        mov rax,[no1]
	sub rax,[no2]
	mov [result],rax
	scall 1,1,resmsg,resmsg_len
	mov rbx,[result]
	call disp64num
	scall 1,1,nummsg,1
	ret
		
	mul_proc:
	scall 1,1,mulmsg,mulmsg_len
	mov rax,[no1]
	mov rbx,[no2]
	mul rbx
	mov [resh],rdx
	mov [resl],rax
	scall 1,1, resmsg,resmsg_len
	mov rbx,[resh]
	call disp64num
	mov rbx,[resl]
	call disp64num
	scall 1,1,nwmsg,1
	ret
div_proc:
	scall 1,1,divmsg,divmsg_len
	mov rax,[no1]
	mov rdx,0
	mov rbx,[no2]
	div rbx
	mov [resh],rdx ;Remainder
	mov [resl],rax ;Quotient
	scall 1,1, rmsg,rmsg_len
	mov rbx,[resh]
	call disp64num
	scall 1,1, qmsg,qmsg_len
	mov rbx,[resl]
	call disp64num
	scall 1,1, nwmsg,1
	ret
disp64num:
	mov ecx,16
	mov edi,dispbuff
	dup1:
		rol rbx,4
		mov al,bl
		and al,0fh
		cmp al,09
		jbe dskip
		add al,07h
		dskip: add al,30h
		mov [edi],al
		inc edi
		loop dup1
	scall 1,1,dispbuff,16
	ret


