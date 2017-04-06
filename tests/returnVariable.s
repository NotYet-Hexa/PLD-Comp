.text
.global main
main:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq $6, -16(%rbp)
	movq -16(%rbp), %rax
	movq %rax,-8(%rbp)
	movq -8(%rbp), %rax

	leave
	ret
