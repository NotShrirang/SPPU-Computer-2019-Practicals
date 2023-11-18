section .data
	array db 11h, 55h, 33h, 22h,44h
	msg1 db 10,13,"Largest no in an array is:"
	len1 equ $-msg1

section .bss
	cnt resb 1
	result resb 16

section .text
	global _start
	_start:
		mov byte[cnt],5
		mov rsi,array
		mov al,0
	LP: cmp al,[rsi]
		jg skip
		xchg al ,[rsi]
		skip: inc rsi
		dec byte[cnt]
		jnz LP


	;display
		mov Rax,1
		mov Rdi,1
		mov Rsi,msg1
		mov Rdx,len1
		syscall


	;display al

	call display

	;exit system call
		mov Rax ,60
		mov Rdi,0
		syscall


	%macro dispmsg 2
		mov Rax,1
		mov Rdi,1
		mov rsi,%1
		mov rdx,%2
		syscall
	%endmacro
	display:
		mov rbx,rax                      ; store no in rbx
		mov rdi,result                   ;point rdi to result variable 
		mov cx,16                        ;load count of rotation in cl  

		up1: 
			rol rbx,04               ;rotate no of left by four bits
			mov al,bl	         ; move lower byte in dl		
			and al,0fh               ;get only LSB
			cmp al,09h               ;compare with 39h
			jg add_37                ;if greater than 39h skip add 37    
			add al,30h                
			jmp skip1                 ;else add 30     
		add_37: 
			add al,37h                 
		skip1: 
			mov [rdi],al             ;store ascii code in result variable
			inc rdi                  ; point to next byte
			dec cx                   ; decrement counter
			jnz up1                  ; if not zero jump to repeat
			dispmsg result,16        ;call to macro
	ret
