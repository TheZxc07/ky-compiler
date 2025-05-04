**KY-Compiler**

Currently translates .kysap files into assembly

- Takes an input file like `test_src/simple_prog.kysap`
  ```asm
  3 + 4 - ((5 + 2) * (7 + 2)) / 7
- Outputs valid assembly instructions in AT&T syntax to a file like `out.as`:
```asm
.globl _start
.text

_start:
    MOVQ $3, %rbx
    MOVQ $4, %r10
    ADDQ %r10, %rbx
    ...
    MOVQ $60, %rax
    MOVQ %rbx, %rdi
    SYSCALL
