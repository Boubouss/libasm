extern malloc
extern ft_strlen
extern ft_strcpy

section .text
  global ft_strdup
  ft_strdup:
    mov rbx, rdi
    call ft_strlen
    inc rax
    mov rdi, rax
    call malloc
    test rax, rax
    je .end
    mov rdi, rax
    mov rsi, rbx
    call ft_strcpy
  .end:
    ret
