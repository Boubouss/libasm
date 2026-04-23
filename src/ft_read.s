extern __errno_location

section .text
  global ft_read
  ft_read:
    xor rax, rax 
    syscall
    cmp rax, 0
    jl .err
    ret
  .err:
    mov rbx, rax
    neg rbx
    call __errno_location
    mov [rax], rbx
    mov rax, -1
    ret
