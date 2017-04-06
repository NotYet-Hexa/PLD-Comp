.text
.global main
main:
	pushq %rbp
	movq %rsp, %rbp
	subq $0, %rsp
	call a

	leave
	ret
