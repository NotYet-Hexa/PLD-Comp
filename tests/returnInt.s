.text
.global main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq $3, -8(%rbp)
	movq -8(%rbp), %rax

	leave
	ret
