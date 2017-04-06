.text
.global main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $32, %rsp
	movq $6, -24(%rbp)
	movq -24(%rbp), %rax
	movq %rax,-8(%rbp)
	movq -8(%rbp), %rax
	movq %rax,-16(%rbp)
	movq -16(%rbp), %rax

	leave
	ret
