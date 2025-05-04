	.globl _start
	.text

_start:
	MOVQ $3, %rbx
	MOVQ $4, %r10
	ADDQ %r10, %rbx
	MOVQ $5, %r10
	MOVQ $2, %r11
	ADDQ %r11, %r10
	MOVQ $7, %r11
	MOVQ $2, %r12
	ADDQ %r12, %r11
	MOVQ %r10, %rax
	IMUL %r11
	MOVQ %rax, %r11
	MOVQ $7, %r10
	MOVQ %r11, %rax
	CQO
	IDIVQ %r10
	MOVQ %rax, %r10
	SUBQ %r10, %rbx
	MOVQ $60, %rax
	MOVQ %rbx, %rdi
	SYSCALL
