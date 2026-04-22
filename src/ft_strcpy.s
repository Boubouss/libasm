section .text
  global ft_strcpy
  ft_strcpy:
    xor rax, rax
  .loop:
    mov r10b, [rsi + rax]
    mov [rdi + rax], r10b
    test r10b, r10b
    je .end
    inc rax 
    jmp .loop
  .end:
    mov rax, rdi
    ret
