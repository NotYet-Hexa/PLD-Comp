.text
.global main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $48, %rsp
	movq $1, -16(%rbp)
	movq $1, -24(%rbp)
	movq -16(%rbp), %rax
	addq -24(%rbp), %rax
	movq %rax, -32(%rbp)
	movq $1, -40(%rbp)
	movq -32(%rbp), %rax
	addq -40(%rbp), %rax
	movq %rax, -48(%rbp)
	movq -48(%rbp), %rax
	movq %rax,-8(%rbp)
	movq -8(%rbp), %rax

	leave
	ret
