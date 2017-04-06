.text
.global main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $80, %rsp
	movq $99, -16(%rbp)
	movq -16(%rbp), %rax
	movq %rax,-8(%rbp)
	movq $2, -24(%rbp)
	movq -8(%rbp), %rax
	addq -24(%rbp), %rax
	movq %rax, -32(%rbp)
	movq $2, -40(%rbp)
	movq -32(%rbp), %rax
	addq -40(%rbp), %rax
	movq %rax, -48(%rbp)
	movq $2, -56(%rbp)
	movq -48(%rbp), %rax
	addq -56(%rbp), %rax
	movq %rax, -64(%rbp)
	movq $2, -72(%rbp)
	movq -64(%rbp), %rax
	addq -72(%rbp), %rax
	movq %rax, -80(%rbp)
	movq -80(%rbp), %rdi
	call putchar

	leave
	ret
