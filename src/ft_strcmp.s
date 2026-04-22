section .text
  global ft_strcmp
  ft_strcmp:
    xor rax, rax
    xor r10, r10
    xor r11, r11
  .loop:
    movzx rax, byte [rdi + r11]
    movzx r10, byte [rsi + r11]
    test rax, rax
    je .end
    test r10, r10
    je .end
    sub rax, r10
    test rax, rax
    inc r11
    je .loop
    ret
  .end:
    sub rax, r10
    ret

