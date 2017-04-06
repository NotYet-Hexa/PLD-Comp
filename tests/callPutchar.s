.text
.global main
main:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq $97, -8(%rbp)
	movq -8(%rbp), %rdi
	call putchar

	leave
	ret
