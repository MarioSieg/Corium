
0000000000000000 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z>:
   0:   55                      push   %rbp
   1:   41 57                   push   %r15
   3:   41 56                   push   %r14
   5:   41 55                   push   %r13
   7:   41 54                   push   %r12
   9:   56                      push   %rsi
   a:   57                      push   %rdi
   b:   53                      push   %rbx
   c:   48 83 ec 48             sub    $0x48,%rsp
  10:   48 8d 6c 24 40          lea    0x40(%rsp),%rbp
  15:   48 c7 45 00 fe ff ff    movq   $0xfffffffffffffffe,0x0(%rbp)
  1c:   ff
  1d:   48 89 d3                mov    %rdx,%rbx
  20:   48 89 ce                mov    %rcx,%rsi
  23:   e8 00 00 00 00          call   28 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x28>
  28:   48 89 c7                mov    %rax,%rdi
  2b:   e8 00 00 00 00          call   30 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x30>
  30:   48 89 c1                mov    %rax,%rcx
  33:   48 09 f9                or     %rdi,%rcx
  36:   48 c1 e9 20             shr    $0x20,%rcx
  3a:   74 0a                   je     46 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x46>
  3c:   48 99                   cqto
  3e:   48 f7 ff                idiv   %rdi
  41:   49 89 c6                mov    %rax,%r14
  44:   eb 07                   jmp    4d <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x4d>
  46:   31 d2                   xor    %edx,%edx
  48:   f7 f7                   div    %edi
  4a:   41 89 c6                mov    %eax,%r14d
  4d:   48 69 c2 00 ca 9a 3b    imul   $0x3b9aca00,%rdx,%rax
  54:   48 89 f9                mov    %rdi,%rcx
  57:   48 09 c1                or     %rax,%rcx
  5a:   48 c1 e9 20             shr    $0x20,%rcx
  5e:   48 89 5d f0             mov    %rbx,-0x10(%rbp)
  62:   74 07                   je     6b <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x6b>
  64:   48 99                   cqto
  66:   48 f7 ff                idiv   %rdi
  69:   eb 04                   jmp    6f <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x6f>
  6b:   31 d2                   xor    %edx,%edx
  6d:   f7 f7                   div    %edi
  6f:   48 89 45 f8             mov    %rax,-0x8(%rbp)
  73:   48 8b 0e                mov    (%rsi),%rcx
  76:   4c 8b 46 08             mov    0x8(%rsi),%r8
  7a:   48 89 75 e8             mov    %rsi,-0x18(%rbp)
  7e:   48 8b 46 10             mov    0x10(%rsi),%rax
  82:   48 8d 14 c1             lea    (%rcx,%rax,8),%rdx
  86:   4c 8d 0d 00 00 00 00    lea    0x0(%rip),%r9        # 8d <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x8d>
  8d:   e8 00 00 00 00          call   92 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x92>
  92:   84 c0                   test   %al,%al
  94:   74 2f                   je     c5 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0xc5>
  96:   49 69 c6 00 ca 9a 3b    imul   $0x3b9aca00,%r14,%rax
  9d:   48 01 45 f8             add    %rax,-0x8(%rbp)
  a1:   48 8b 45 e8             mov    -0x18(%rbp),%rax
  a5:   4c 8b 20                mov    (%rax),%r12
  a8:   48 8b 48 18             mov    0x18(%rax),%rcx
  ac:   48 89 4d e0             mov    %rcx,-0x20(%rbp)
  b0:   4c 8b 78 28             mov    0x28(%rax),%r15
  b4:   48 8b 58 30             mov    0x30(%rax),%rbx
  b8:   49 8d 44 24 08          lea    0x8(%r12),%rax
  bd:   4d 89 e5                mov    %r12,%r13
  c0:   48 89 c7                mov    %rax,%rdi
  c3:   ff 20                   jmp    *(%rax)
  c5:   48 8b 45 f0             mov    -0x10(%rbp),%rax
  c9:   c7 40 08 01 00 00 00    movl   $0x1,0x8(%rax)
  d0:   e9 0d 01 00 00          jmp    1e2 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x1e2>
  d5:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
  dc:   00 00 00
  df:   90                      nop
  e0:   8b 77 08                mov    0x8(%rdi),%esi
  e3:   89 f1                   mov    %esi,%ecx
  e5:   41 ff d7                call   *%r15
  e8:   4c 8d 77 08             lea    0x8(%rdi),%r14
  ec:   85 f6                   test   %esi,%esi
  ee:   7e 0c                   jle    fc <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0xfc>
  f0:   48 89 f8                mov    %rdi,%rax
  f3:   48 83 c0 10             add    $0x10,%rax
  f7:   48 89 c7                mov    %rax,%rdi
  fa:   ff 20                   jmp    *(%rax)
  fc:   0f 95 c0                setne  %al
  ff:   0f b6 c0                movzbl %al,%eax
 102:   4c 8b 7d f0             mov    -0x10(%rbp),%r15
 106:   41 89 47 08             mov    %eax,0x8(%r15)
 10a:   4c 8b 65 f8             mov    -0x8(%rbp),%r12
 10e:   4d 89 67 10             mov    %r12,0x10(%r15)
 112:   e8 00 00 00 00          call   117 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x117>
 117:   48 89 c7                mov    %rax,%rdi
 11a:   e8 00 00 00 00          call   11f <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x11f>
 11f:   48 89 c1                mov    %rax,%rcx
 122:   48 09 f9                or     %rdi,%rcx
 125:   48 c1 e9 20             shr    $0x20,%rcx
 129:   74 07                   je     132 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x132>
 12b:   48 99                   cqto
 12d:   48 f7 ff                idiv   %rdi
 130:   eb 04                   jmp    136 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x136>
 132:   31 d2                   xor    %edx,%edx
 134:   f7 f7                   div    %edi
 136:   48 69 c8 00 ca 9a 3b    imul   $0x3b9aca00,%rax,%rcx
 13d:   48 69 c2 00 ca 9a 3b    imul   $0x3b9aca00,%rdx,%rax
 144:   48 89 fa                mov    %rdi,%rdx
 147:   48 09 c2                or     %rax,%rdx
 14a:   48 c1 ea 20             shr    $0x20,%rdx
 14e:   74 07                   je     157 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x157>
 150:   48 99                   cqto
 152:   48 f7 ff                idiv   %rdi
 155:   eb 04                   jmp    15b <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x15b>
 157:   31 d2                   xor    %edx,%edx
 159:   f7 f7                   div    %edi
 15b:   48 01 c8                add    %rcx,%rax
 15e:   49 89 47 18             mov    %rax,0x18(%r15)
 162:   e8 00 00 00 00          call   167 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x167>
 167:   48 89 c7                mov    %rax,%rdi
 16a:   e8 00 00 00 00          call   16f <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x16f>
 16f:   48 89 c1                mov    %rax,%rcx
 172:   48 09 f9                or     %rdi,%rcx
 175:   48 c1 e9 20             shr    $0x20,%rcx
 179:   74 07                   je     182 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x182>
 17b:   48 99                   cqto
 17d:   48 f7 ff                idiv   %rdi
 180:   eb 04                   jmp    186 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x186>
 182:   31 d2                   xor    %edx,%edx
 184:   f7 f7                   div    %edi
 186:   48 69 c8 00 ca 9a 3b    imul   $0x3b9aca00,%rax,%rcx
 18d:   48 69 c2 00 ca 9a 3b    imul   $0x3b9aca00,%rdx,%rax
 194:   48 89 fa                mov    %rdi,%rdx
 197:   48 09 c2                or     %rax,%rdx
 19a:   48 c1 ea 20             shr    $0x20,%rdx
 19e:   74 07                   je     1a7 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x1a7>
 1a0:   48 99                   cqto
 1a2:   48 f7 ff                idiv   %rdi
 1a5:   eb 04                   jmp    1ab <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x1ab>
 1a7:   31 d2                   xor    %edx,%edx
 1a9:   f7 f7                   div    %edi
 1ab:   4c 29 e1                sub    %r12,%rcx
 1ae:   48 01 c1                add    %rax,%rcx
 1b1:   49 89 4f 20             mov    %rcx,0x20(%r15)
 1b5:   41 89 77 28             mov    %esi,0x28(%r15)
 1b9:   4c 89 f0                mov    %r14,%rax
 1bc:   48 8b 4d e8             mov    -0x18(%rbp),%rcx
 1c0:   48 2b 01                sub    (%rcx),%rax
 1c3:   48 c1 f8 03             sar    $0x3,%rax
 1c7:   49 89 47 30             mov    %rax,0x30(%r15)
 1cb:   48 2b 59 30             sub    0x30(%rcx),%rbx
 1cf:   48 c1 fb 03             sar    $0x3,%rbx
 1d3:   49 89 5f 38             mov    %rbx,0x38(%r15)
 1d7:   4d 29 ee                sub    %r13,%r14
 1da:   49 c1 fe 03             sar    $0x3,%r14
 1de:   4d 89 77 40             mov    %r14,0x40(%r15)
 1e2:   48 83 c4 48             add    $0x48,%rsp
 1e6:   5b                      pop    %rbx
 1e7:   5f                      pop    %rdi
 1e8:   5e                      pop    %rsi
 1e9:   41 5c                   pop    %r12
 1eb:   41 5d                   pop    %r13
 1ed:   41 5e                   pop    %r14
 1ef:   41 5f                   pop    %r15
 1f1:   5d                      pop    %rbp
 1f2:   c3                      ret
 1f3:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 1fa:   00 00 00
 1fd:   0f 1f 00                nopl   (%rax)
 200:   48 8b 57 08             mov    0x8(%rdi),%rdx
 204:   48 89 d9                mov    %rbx,%rcx
 207:   e8 00 00 00 00          call   20c <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x20c>
 20c:   48 83 c7 10             add    $0x10,%rdi
 210:   ff 27                   jmp    *(%rdi)
 212:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 219:   00 00 00
 21c:   0f 1f 40 00             nopl   0x0(%rax)
 220:   cc                      int3
 221:   48 8b 47 08             mov    0x8(%rdi),%rax
 225:   48 89 d9                mov    %rbx,%rcx
 228:   48 8b 55 e0             mov    -0x20(%rbp),%rdx
 22c:   ff 14 c2                call   *(%rdx,%rax,8)
 22f:   48 89 f8                mov    %rdi,%rax
 232:   48 83 c0 10             add    $0x10,%rax
 236:   48 89 c7                mov    %rax,%rdi
 239:   ff 20                   jmp    *(%rax)
 23b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)
 240:   48 8b 47 08             mov    0x8(%rdi),%rax
 244:   48 83 c7 10             add    $0x10,%rdi
 248:   49 8d 04 c4             lea    (%r12,%rax,8),%rax
 24c:   49 89 fd                mov    %rdi,%r13
 24f:   48 89 c7                mov    %rax,%rdi
 252:   ff 20                   jmp    *(%rax)
 254:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 25b:   00 00 00
 25e:   66 90                   xchg   %ax,%ax
 260:   48 8b 47 08             mov    0x8(%rdi),%rax
 264:   48 8b 4f 10             mov    0x10(%rdi),%rcx
 268:   48 8b 0c cb             mov    (%rbx,%rcx,8),%rcx
 26c:   48 89 0c c3             mov    %rcx,(%rbx,%rax,8)
 270:   48 83 c7 18             add    $0x18,%rdi
 274:   ff 27                   jmp    *(%rdi)
 276:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 27d:   00 00 00
 280:   48 8b 47 08             mov    0x8(%rdi),%rax
 284:   48 8b 4f 10             mov    0x10(%rdi),%rcx
 288:   48 89 0c c3             mov    %rcx,(%rbx,%rax,8)
 28c:   48 83 c7 18             add    $0x18,%rdi
 290:   ff 27                   jmp    *(%rdi)
 292:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 299:   00 00 00
 29c:   0f 1f 40 00             nopl   0x0(%rax)
 2a0:   48 8b 47 08             mov    0x8(%rdi),%rax
 2a4:   48 89 43 08             mov    %rax,0x8(%rbx)
 2a8:   48 83 c3 08             add    $0x8,%rbx
 2ac:   48 83 c7 10             add    $0x10,%rdi
 2b0:   ff 27                   jmp    *(%rdi)
 2b2:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 2b9:   00 00 00
 2bc:   0f 1f 40 00             nopl   0x0(%rax)
 2c0:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 2c4:   48 83 c7 08             add    $0x8,%rdi
 2c8:   ff 27                   jmp    *(%rdi)
 2ca:   66 0f 1f 44 00 00       nopw   0x0(%rax,%rax,1)
 2d0:   48 83 c3 f0             add    $0xfffffffffffffff0,%rbx
 2d4:   48 83 c7 08             add    $0x8,%rdi
 2d8:   ff 27                   jmp    *(%rdi)
 2da:   66 0f 1f 44 00 00       nopw   0x0(%rax,%rax,1)
 2e0:   48 8b 03                mov    (%rbx),%rax
 2e3:   48 89 43 08             mov    %rax,0x8(%rbx)
 2e7:   48 83 c3 08             add    $0x8,%rbx
 2eb:   48 83 c7 08             add    $0x8,%rdi
 2ef:   ff 27                   jmp    *(%rdi)
 2f1:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 2f8:   00 00 00
 2fb:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)
 300:   48 8b 03                mov    (%rbx),%rax
 303:   48 89 43 08             mov    %rax,0x8(%rbx)
 307:   48 89 43 10             mov    %rax,0x10(%rbx)
 30b:   48 83 c3 10             add    $0x10,%rbx
 30f:   48 83 c7 08             add    $0x8,%rdi
 313:   ff 27                   jmp    *(%rdi)
 315:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 31c:   00 00 00
 31f:   90                      nop
 320:   f3 0f 6f 43 f8          movdqu -0x8(%rbx),%xmm0
 325:   66 0f 70 c0 4e          pshufd $0x4e,%xmm0,%xmm0
 32a:   f3 0f 7f 43 f8          movdqu %xmm0,-0x8(%rbx)
 32f:   48 83 c7 08             add    $0x8,%rdi
 333:   ff 27                   jmp    *(%rdi)
 335:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 33c:   00 00 00
 33f:   90                      nop
 340:   90                      nop
 341:   48 83 c7 08             add    $0x8,%rdi
 345:   ff 27                   jmp    *(%rdi)
 347:   66 0f 1f 84 00 00 00    nopw   0x0(%rax,%rax,1)
 34e:   00 00
 350:   48 8b 7f 08             mov    0x8(%rdi),%rdi
 354:   ff 27                   jmp    *(%rdi)
 356:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 35d:   00 00 00
 360:   48 8b 7f 08             mov    0x8(%rdi),%rdi
 364:   ff 27                   jmp    *(%rdi)
 366:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 36d:   00 00 00
 370:   48 83 c7 08             add    $0x8,%rdi
 374:   48 83 3b 00             cmpq   $0x0,(%rbx)
 378:   75 03                   jne    37d <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x37d>
 37a:   48 8b 3f                mov    (%rdi),%rdi
 37d:   48 89 f8                mov    %rdi,%rax
 380:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 384:   48 83 c0 08             add    $0x8,%rax
 388:   48 89 c7                mov    %rax,%rdi
 38b:   ff 20                   jmp    *(%rax)
 38d:   0f 1f 00                nopl   (%rax)
 390:   48 83 c7 08             add    $0x8,%rdi
 394:   48 83 3b 00             cmpq   $0x0,(%rbx)
 398:   74 03                   je     39d <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x39d>
 39a:   48 8b 3f                mov    (%rdi),%rdi
 39d:   48 89 f8                mov    %rdi,%rax
 3a0:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 3a4:   48 83 c0 08             add    $0x8,%rax
 3a8:   48 89 c7                mov    %rax,%rdi
 3ab:   ff 20                   jmp    *(%rax)
 3ad:   0f 1f 00                nopl   (%rax)
 3b0:   48 89 f8                mov    %rdi,%rax
 3b3:   48 83 c0 08             add    $0x8,%rax
 3b7:   48 83 3b 01             cmpq   $0x1,(%rbx)
 3bb:   75 03                   jne    3c0 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x3c0>
 3bd:   48 8b 00                mov    (%rax),%rax
 3c0:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 3c4:   48 83 c0 08             add    $0x8,%rax
 3c8:   48 89 c7                mov    %rax,%rdi
 3cb:   ff 20                   jmp    *(%rax)
 3cd:   0f 1f 00                nopl   (%rax)
 3d0:   48 89 f8                mov    %rdi,%rax
 3d3:   48 83 c0 08             add    $0x8,%rax
 3d7:   f2 0f 10 05 00 00 00    movsd  0x0(%rip),%xmm0        # 3df <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x3df>
 3de:   00
 3df:   66 0f 2e 03             ucomisd (%rbx),%xmm0
 3e3:   75 03                   jne    3e8 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x3e8>
 3e5:   48 8b 00                mov    (%rax),%rax
 3e8:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 3ec:   48 83 c0 08             add    $0x8,%rax
 3f0:   48 89 c7                mov    %rax,%rdi
 3f3:   ff 20                   jmp    *(%rax)
 3f5:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 3fc:   00 00 00
 3ff:   90                      nop
 400:   48 89 f8                mov    %rdi,%rax
 403:   48 83 c0 08             add    $0x8,%rax
 407:   48 83 3b 01             cmpq   $0x1,(%rbx)
 40b:   74 03                   je     410 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x410>
 40d:   48 8b 00                mov    (%rax),%rax
 410:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 414:   48 83 c0 08             add    $0x8,%rax
 418:   48 89 c7                mov    %rax,%rdi
 41b:   ff 20                   jmp    *(%rax)
 41d:   0f 1f 00                nopl   (%rax)
 420:   48 8b 00                mov    (%rax),%rax
 423:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 427:   48 83 c0 08             add    $0x8,%rax
 42b:   48 89 c7                mov    %rax,%rdi
 42e:   ff 20                   jmp    *(%rax)
 430:   48 89 f8                mov    %rdi,%rax
 433:   48 83 c0 08             add    $0x8,%rax
 437:   f2 0f 10 05 00 00 00    movsd  0x0(%rip),%xmm0        # 43f <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x43f>
 43e:   00
 43f:   66 0f 2e 03             ucomisd (%rbx),%xmm0
 443:   0f 85 d7 ff ff ff       jne    420 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x420>
 449:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 44d:   48 83 c0 08             add    $0x8,%rax
 451:   48 89 c7                mov    %rax,%rdi
 454:   ff 20                   jmp    *(%rax)
 456:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 45d:   00 00 00
 460:   48 89 f8                mov    %rdi,%rax
 463:   48 83 c0 08             add    $0x8,%rax
 467:   48 8b 4b f8             mov    -0x8(%rbx),%rcx
 46b:   48 3b 0b                cmp    (%rbx),%rcx
 46e:   75 03                   jne    473 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x473>
 470:   48 8b 00                mov    (%rax),%rax
 473:   48 83 c3 f0             add    $0xfffffffffffffff0,%rbx
 477:   48 83 c0 08             add    $0x8,%rax
 47b:   48 89 c7                mov    %rax,%rdi
 47e:   ff 20                   jmp    *(%rax)
 480:   48 89 f8                mov    %rdi,%rax
 483:   48 83 c0 08             add    $0x8,%rax
 487:   f2 0f 10 43 f8          movsd  -0x8(%rbx),%xmm0
 48c:   66 0f 2e 03             ucomisd (%rbx),%xmm0
 490:   75 03                   jne    495 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x495>
 492:   48 8b 00                mov    (%rax),%rax
 495:   48 83 c3 f0             add    $0xfffffffffffffff0,%rbx
 499:   48 83 c0 08             add    $0x8,%rax
 49d:   48 89 c7                mov    %rax,%rdi
 4a0:   ff 20                   jmp    *(%rax)
 4a2:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 4a9:   00 00 00
 4ac:   0f 1f 40 00             nopl   0x0(%rax)
 4b0:   48 89 f8                mov    %rdi,%rax
 4b3:   48 83 c0 08             add    $0x8,%rax
 4b7:   48 8b 4b f8             mov    -0x8(%rbx),%rcx
 4bb:   48 3b 0b                cmp    (%rbx),%rcx
 4be:   74 03                   je     4c3 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x4c3>
 4c0:   48 8b 00                mov    (%rax),%rax
 4c3:   48 83 c3 f0             add    $0xfffffffffffffff0,%rbx
 4c7:   48 83 c0 08             add    $0x8,%rax
 4cb:   48 89 c7                mov    %rax,%rdi
 4ce:   ff 20                   jmp    *(%rax)
 4d0:   48 8b 00                mov    (%rax),%rax
 4d3:   48 83 c3 f0             add    $0xfffffffffffffff0,%rbx
 4d7:   48 83 c0 08             add    $0x8,%rax
 4db:   48 89 c7                mov    %rax,%rdi
 4de:   ff 20                   jmp    *(%rax)
 4e0:   48 89 f8                mov    %rdi,%rax
 4e3:   48 83 c0 08             add    $0x8,%rax
 4e7:   f2 0f 10 43 f8          movsd  -0x8(%rbx),%xmm0
 4ec:   66 0f 2e 03             ucomisd (%rbx),%xmm0
 4f0:   75 de                   jne    4d0 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x4d0>
 4f2:   48 83 c3 f0             add    $0xfffffffffffffff0,%rbx
 4f6:   48 83 c0 08             add    $0x8,%rax
 4fa:   48 89 c7                mov    %rax,%rdi
 4fd:   ff 20                   jmp    *(%rax)
 4ff:   90                      nop
 500:   48 89 f8                mov    %rdi,%rax
 503:   48 83 c0 08             add    $0x8,%rax
 507:   48 8b 4b f8             mov    -0x8(%rbx),%rcx
 50b:   48 3b 0b                cmp    (%rbx),%rcx
 50e:   7e 03                   jle    513 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x513>
 510:   48 8b 00                mov    (%rax),%rax
 513:   48 83 c3 f0             add    $0xfffffffffffffff0,%rbx
 517:   48 83 c0 08             add    $0x8,%rax
 51b:   48 89 c7                mov    %rax,%rdi
 51e:   ff 20                   jmp    *(%rax)
 520:   48 89 f8                mov    %rdi,%rax
 523:   48 83 c0 08             add    $0x8,%rax
 527:   f2 0f 10 43 f8          movsd  -0x8(%rbx),%xmm0
 52c:   66 0f 2e 03             ucomisd (%rbx),%xmm0
 530:   76 03                   jbe    535 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x535>
 532:   48 8b 00                mov    (%rax),%rax
 535:   48 83 c3 f0             add    $0xfffffffffffffff0,%rbx
 539:   48 83 c0 08             add    $0x8,%rax
 53d:   48 89 c7                mov    %rax,%rdi
 540:   ff 20                   jmp    *(%rax)
 542:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 549:   00 00 00
 54c:   0f 1f 40 00             nopl   0x0(%rax)
 550:   48 89 f8                mov    %rdi,%rax
 553:   48 83 c0 08             add    $0x8,%rax
 557:   48 8b 4b f8             mov    -0x8(%rbx),%rcx
 55b:   48 3b 0b                cmp    (%rbx),%rcx
 55e:   7d 03                   jge    563 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x563>
 560:   48 8b 00                mov    (%rax),%rax
 563:   48 83 c3 f0             add    $0xfffffffffffffff0,%rbx
 567:   48 83 c0 08             add    $0x8,%rax
 56b:   48 89 c7                mov    %rax,%rdi
 56e:   ff 20                   jmp    *(%rax)
 570:   48 89 f8                mov    %rdi,%rax
 573:   48 83 c0 08             add    $0x8,%rax
 577:   f2 0f 10 43 f8          movsd  -0x8(%rbx),%xmm0
 57c:   66 0f 2e 03             ucomisd (%rbx),%xmm0
 580:   73 03                   jae    585 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x585>
 582:   48 8b 00                mov    (%rax),%rax
 585:   48 83 c3 f0             add    $0xfffffffffffffff0,%rbx
 589:   48 83 c0 08             add    $0x8,%rax
 58d:   48 89 c7                mov    %rax,%rdi
 590:   ff 20                   jmp    *(%rax)
 592:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 599:   00 00 00
 59c:   0f 1f 40 00             nopl   0x0(%rax)
 5a0:   48 89 f8                mov    %rdi,%rax
 5a3:   48 83 c0 08             add    $0x8,%rax
 5a7:   48 8b 4b f8             mov    -0x8(%rbx),%rcx
 5ab:   48 3b 0b                cmp    (%rbx),%rcx
 5ae:   7c 03                   jl     5b3 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x5b3>
 5b0:   48 8b 00                mov    (%rax),%rax
 5b3:   48 83 c3 f0             add    $0xfffffffffffffff0,%rbx
 5b7:   48 83 c0 08             add    $0x8,%rax
 5bb:   48 89 c7                mov    %rax,%rdi
 5be:   ff 20                   jmp    *(%rax)
 5c0:   48 89 f8                mov    %rdi,%rax
 5c3:   48 83 c0 08             add    $0x8,%rax
 5c7:   f2 0f 10 43 f8          movsd  -0x8(%rbx),%xmm0
 5cc:   66 0f 2e 03             ucomisd (%rbx),%xmm0
 5d0:   72 03                   jb     5d5 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x5d5>
 5d2:   48 8b 00                mov    (%rax),%rax
 5d5:   48 83 c3 f0             add    $0xfffffffffffffff0,%rbx
 5d9:   48 83 c0 08             add    $0x8,%rax
 5dd:   48 89 c7                mov    %rax,%rdi
 5e0:   ff 20                   jmp    *(%rax)
 5e2:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 5e9:   00 00 00
 5ec:   0f 1f 40 00             nopl   0x0(%rax)
 5f0:   48 89 f8                mov    %rdi,%rax
 5f3:   48 83 c0 08             add    $0x8,%rax
 5f7:   48 8b 4b f8             mov    -0x8(%rbx),%rcx
 5fb:   48 3b 0b                cmp    (%rbx),%rcx
 5fe:   7f 03                   jg     603 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x603>
 600:   48 8b 00                mov    (%rax),%rax
 603:   48 83 c3 f0             add    $0xfffffffffffffff0,%rbx
 607:   48 83 c0 08             add    $0x8,%rax
 60b:   48 89 c7                mov    %rax,%rdi
 60e:   ff 20                   jmp    *(%rax)
 610:   48 89 f8                mov    %rdi,%rax
 613:   48 83 c0 08             add    $0x8,%rax
 617:   f2 0f 10 43 f8          movsd  -0x8(%rbx),%xmm0
 61c:   66 0f 2e 03             ucomisd (%rbx),%xmm0
 620:   77 03                   ja     625 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x625>
 622:   48 8b 00                mov    (%rax),%rax
 625:   48 83 c3 f0             add    $0xfffffffffffffff0,%rbx
 629:   48 83 c0 08             add    $0x8,%rax
 62d:   48 89 c7                mov    %rax,%rdi
 630:   ff 20                   jmp    *(%rax)
 632:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 639:   00 00 00
 63c:   0f 1f 40 00             nopl   0x0(%rax)
 640:   48 c7 43 08 00 00 00    movq   $0x0,0x8(%rbx)
 647:   00
 648:   48 83 c3 08             add    $0x8,%rbx
 64c:   48 83 c7 08             add    $0x8,%rdi
 650:   ff 27                   jmp    *(%rdi)
 652:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 659:   00 00 00
 65c:   0f 1f 40 00             nopl   0x0(%rax)
 660:   48 c7 43 08 01 00 00    movq   $0x1,0x8(%rbx)
 667:   00
 668:   48 83 c3 08             add    $0x8,%rbx
 66c:   48 83 c7 08             add    $0x8,%rdi
 670:   ff 27                   jmp    *(%rdi)
 672:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 679:   00 00 00
 67c:   0f 1f 40 00             nopl   0x0(%rax)
 680:   48 b8 00 00 00 00 00    movabs $0x3ff0000000000000,%rax
 687:   00 f0 3f
 68a:   48 89 43 08             mov    %rax,0x8(%rbx)
 68e:   48 83 c3 08             add    $0x8,%rbx
 692:   48 83 c7 08             add    $0x8,%rdi
 696:   ff 27                   jmp    *(%rdi)
 698:   0f 1f 84 00 00 00 00    nopl   0x0(%rax,%rax,1)
 69f:   00
 6a0:   48 83 03 01             addq   $0x1,(%rbx)
 6a4:   48 83 c7 08             add    $0x8,%rdi
 6a8:   ff 27                   jmp    *(%rdi)
 6aa:   66 0f 1f 44 00 00       nopw   0x0(%rax,%rax,1)
 6b0:   48 83 03 ff             addq   $0xffffffffffffffff,(%rbx)
 6b4:   48 83 c7 08             add    $0x8,%rdi
 6b8:   ff 27                   jmp    *(%rdi)
 6ba:   66 0f 1f 44 00 00       nopw   0x0(%rax,%rax,1)
 6c0:   48 8b 03                mov    (%rbx),%rax
 6c3:   48 01 43 f8             add    %rax,-0x8(%rbx)
 6c7:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 6cb:   48 83 c7 08             add    $0x8,%rdi
 6cf:   ff 27                   jmp    *(%rdi)
 6d1:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 6d8:   00 00 00
 6db:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)
 6e0:   48 8b 03                mov    (%rbx),%rax
 6e3:   48 29 43 f8             sub    %rax,-0x8(%rbx)
 6e7:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 6eb:   48 83 c7 08             add    $0x8,%rdi
 6ef:   ff 27                   jmp    *(%rdi)
 6f1:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 6f8:   00 00 00
 6fb:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)
 700:   48 8b 43 f8             mov    -0x8(%rbx),%rax
 704:   48 0f af 03             imul   (%rbx),%rax
 708:   48 89 43 f8             mov    %rax,-0x8(%rbx)
 70c:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 710:   48 83 c7 08             add    $0x8,%rdi
 714:   ff 27                   jmp    *(%rdi)
 716:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 71d:   00 00 00
 720:   48 89 d9                mov    %rbx,%rcx
 723:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 727:   48 8b 41 f8             mov    -0x8(%rcx),%rax
 72b:   48 8b 09                mov    (%rcx),%rcx
 72e:   48 89 c2                mov    %rax,%rdx
 731:   48 09 ca                or     %rcx,%rdx
 734:   48 c1 ea 20             shr    $0x20,%rdx
 738:   74 16                   je     750 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x750>
 73a:   48 99                   cqto
 73c:   48 f7 f9                idiv   %rcx
 73f:   48 89 03                mov    %rax,(%rbx)
 742:   48 89 f8                mov    %rdi,%rax
 745:   48 83 c0 08             add    $0x8,%rax
 749:   48 89 c7                mov    %rax,%rdi
 74c:   ff 20                   jmp    *(%rax)
 74e:   66 90                   xchg   %ax,%ax
 750:   31 d2                   xor    %edx,%edx
 752:   f7 f1                   div    %ecx
 754:   48 89 03                mov    %rax,(%rbx)
 757:   48 89 f8                mov    %rdi,%rax
 75a:   48 83 c0 08             add    $0x8,%rax
 75e:   48 89 c7                mov    %rax,%rdi
 761:   ff 20                   jmp    *(%rax)
 763:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 76a:   00 00 00
 76d:   0f 1f 00                nopl   (%rax)
 770:   48 89 d9                mov    %rbx,%rcx
 773:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 777:   48 8b 41 f8             mov    -0x8(%rcx),%rax
 77b:   48 8b 09                mov    (%rcx),%rcx
 77e:   48 89 c2                mov    %rax,%rdx
 781:   48 09 ca                or     %rcx,%rdx
 784:   48 c1 ea 20             shr    $0x20,%rdx
 788:   74 16                   je     7a0 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x7a0>
 78a:   48 99                   cqto
 78c:   48 f7 f9                idiv   %rcx
 78f:   48 89 13                mov    %rdx,(%rbx)
 792:   48 89 f8                mov    %rdi,%rax
 795:   48 83 c0 08             add    $0x8,%rax
 799:   48 89 c7                mov    %rax,%rdi
 79c:   ff 20                   jmp    *(%rax)
 79e:   66 90                   xchg   %ax,%ax
 7a0:   31 d2                   xor    %edx,%edx
 7a2:   f7 f1                   div    %ecx
 7a4:   48 89 13                mov    %rdx,(%rbx)
 7a7:   48 89 f8                mov    %rdi,%rax
 7aa:   48 83 c0 08             add    $0x8,%rax
 7ae:   48 89 c7                mov    %rax,%rdi
 7b1:   ff 20                   jmp    *(%rax)
 7b3:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 7ba:   00 00 00
 7bd:   0f 1f 00                nopl   (%rax)
 7c0:   48 8b 03                mov    (%rbx),%rax
 7c3:   48 21 43 f8             and    %rax,-0x8(%rbx)
 7c7:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 7cb:   48 83 c7 08             add    $0x8,%rdi
 7cf:   ff 27                   jmp    *(%rdi)
 7d1:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 7d8:   00 00 00
 7db:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)
 7e0:   48 8b 03                mov    (%rbx),%rax
 7e3:   48 09 43 f8             or     %rax,-0x8(%rbx)
 7e7:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 7eb:   48 83 c7 08             add    $0x8,%rdi
 7ef:   ff 27                   jmp    *(%rdi)
 7f1:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 7f8:   00 00 00
 7fb:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)
 800:   48 8b 03                mov    (%rbx),%rax
 803:   48 31 43 f8             xor    %rax,-0x8(%rbx)
 807:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 80b:   48 83 c7 08             add    $0x8,%rdi
 80f:   ff 27                   jmp    *(%rdi)
 811:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 818:   00 00 00
 81b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)
 820:   48 f7 13                notq   (%rbx)
 823:   48 83 c7 08             add    $0x8,%rdi
 827:   ff 27                   jmp    *(%rdi)
 829:   0f 1f 80 00 00 00 00    nopl   0x0(%rax)
 830:   0f b6 0b                movzbl (%rbx),%ecx
 833:   48 d3 63 f8             shlq   %cl,-0x8(%rbx)
 837:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 83b:   48 83 c7 08             add    $0x8,%rdi
 83f:   ff 27                   jmp    *(%rdi)
 841:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 848:   00 00 00
 84b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)
 850:   0f b6 0b                movzbl (%rbx),%ecx
 853:   48 d3 7b f8             sarq   %cl,-0x8(%rbx)
 857:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 85b:   48 83 c7 08             add    $0x8,%rdi
 85f:   ff 27                   jmp    *(%rdi)
 861:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 868:   00 00 00
 86b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)
 870:   0f b6 0b                movzbl (%rbx),%ecx
 873:   48 d3 43 f8             rolq   %cl,-0x8(%rbx)
 877:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 87b:   48 83 c7 08             add    $0x8,%rdi
 87f:   ff 27                   jmp    *(%rdi)
 881:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 888:   00 00 00
 88b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)
 890:   0f b6 0b                movzbl (%rbx),%ecx
 893:   48 d3 4b f8             rorq   %cl,-0x8(%rbx)
 897:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 89b:   48 83 c7 08             add    $0x8,%rdi
 89f:   ff 27                   jmp    *(%rdi)
 8a1:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 8a8:   00 00 00
 8ab:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)
 8b0:   48 f7 1b                negq   (%rbx)
 8b3:   48 83 c7 08             add    $0x8,%rdi
 8b7:   ff 27                   jmp    *(%rdi)
 8b9:   0f 1f 80 00 00 00 00    nopl   0x0(%rax)
 8c0:   f2 0f 10 03             movsd  (%rbx),%xmm0
 8c4:   f2 0f 58 43 f8          addsd  -0x8(%rbx),%xmm0
 8c9:   f2 0f 11 43 f8          movsd  %xmm0,-0x8(%rbx)
 8ce:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 8d2:   48 83 c7 08             add    $0x8,%rdi
 8d6:   ff 27                   jmp    *(%rdi)
 8d8:   0f 1f 84 00 00 00 00    nopl   0x0(%rax,%rax,1)
 8df:   00
 8e0:   f2 0f 10 43 f8          movsd  -0x8(%rbx),%xmm0
 8e5:   f2 0f 5c 03             subsd  (%rbx),%xmm0
 8e9:   f2 0f 11 43 f8          movsd  %xmm0,-0x8(%rbx)
 8ee:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 8f2:   48 83 c7 08             add    $0x8,%rdi
 8f6:   ff 27                   jmp    *(%rdi)
 8f8:   0f 1f 84 00 00 00 00    nopl   0x0(%rax,%rax,1)
 8ff:   00
 900:   f2 0f 10 03             movsd  (%rbx),%xmm0
 904:   f2 0f 59 43 f8          mulsd  -0x8(%rbx),%xmm0
 909:   f2 0f 11 43 f8          movsd  %xmm0,-0x8(%rbx)
 90e:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 912:   48 83 c7 08             add    $0x8,%rdi
 916:   ff 27                   jmp    *(%rdi)
 918:   0f 1f 84 00 00 00 00    nopl   0x0(%rax,%rax,1)
 91f:   00
 920:   f2 0f 10 43 f8          movsd  -0x8(%rbx),%xmm0
 925:   f2 0f 5e 03             divsd  (%rbx),%xmm0
 929:   f2 0f 11 43 f8          movsd  %xmm0,-0x8(%rbx)
 92e:   48 83 c3 f8             add    $0xfffffffffffffff8,%rbx
 932:   48 83 c7 08             add    $0x8,%rdi
 936:   ff 27                   jmp    *(%rdi)
 938:   0f 1f 84 00 00 00 00    nopl   0x0(%rax,%rax,1)
 93f:   00
 940:   48 8d 73 f8             lea    -0x8(%rbx),%rsi
 944:   f2 0f 10 43 f8          movsd  -0x8(%rbx),%xmm0
 949:   f2 0f 10 0b             movsd  (%rbx),%xmm1
 94d:   e8 00 00 00 00          call   952 <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x952>
 952:   f2 0f 11 43 f8          movsd  %xmm0,-0x8(%rbx)
 957:   48 83 c7 08             add    $0x8,%rdi
 95b:   48 89 f3                mov    %rsi,%rbx
 95e:   ff 27                   jmp    *(%rdi)
 960:   f2 0f 10 03             movsd  (%rbx),%xmm0
 964:   66 0f 57 05 00 00 00    xorpd  0x0(%rip),%xmm0        # 96c <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x96c>
 96b:   00
 96c:   66 0f 13 03             movlpd %xmm0,(%rbx)
 970:   48 83 c7 08             add    $0x8,%rdi
 974:   ff 27                   jmp    *(%rdi)
 976:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 97d:   00 00 00
 980:   f2 0f 10 03             movsd  (%rbx),%xmm0
 984:   f2 0f 58 05 00 00 00    addsd  0x0(%rip),%xmm0        # 98c <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x98c>
 98b:   00
 98c:   f2 0f 11 03             movsd  %xmm0,(%rbx)
 990:   48 83 c7 08             add    $0x8,%rdi
 994:   ff 27                   jmp    *(%rdi)
 996:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 99d:   00 00 00
 9a0:   f2 0f 10 03             movsd  (%rbx),%xmm0
 9a4:   f2 0f 58 05 00 00 00    addsd  0x0(%rip),%xmm0        # 9ac <?ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z+0x9ac>
 9ab:   00
 9ac:   f2 0f 11 03             movsd  %xmm0,(%rbx)
 9b0:   48 83 c7 08             add    $0x8,%rdi
 9b4:   ff 27                   jmp    *(%rdi)
 9b6:   66 2e 0f 1f 84 00 00    cs nopw 0x0(%rax,%rax,1)
 9bd:   00 00 00
 9c0:   66 0f 10 47 08          movupd 0x8(%rdi),%xmm0
 9c5:   66 0f 10 4f 18          movupd 0x18(%rdi),%xmm1
 9ca:   66 0f 11 4b 18          movupd %xmm1,0x18(%rbx)
 9cf:   66 0f 11 43 08          movupd %xmm0,0x8(%rbx)
 9d4:   48 83 c3 20             add    $0x20,%rbx
 9d8:   48 83 c7 28             add    $0x28,%rdi
 9dc:   ff 27                   jmp    *(%rdi)
 9de:   66 90                   xchg   %ax,%ax
 9e0:   48 83 c3 e0             add    $0xffffffffffffffe0,%rbx
 9e4:   48 83 c7 08             add    $0x8,%rdi
 9e8:   ff 27                   jmp    *(%rdi)
 9ea:   66 0f 1f 44 00 00       nopw   0x0(%rax,%rax,1)
 9f0:   66 0f 10 43 c8          movupd -0x38(%rbx),%xmm0
 9f5:   66 0f 10 4b d8          movupd -0x28(%rbx),%xmm1
 9fa:   66 0f 10 53 e8          movupd -0x18(%rbx),%xmm2
 9ff:   66 0f 58 d0             addpd  %xmm0,%xmm2
 a03:   66 0f 10 43 f8          movupd -0x8(%rbx),%xmm0
 a08:   66 0f 58 c1             addpd  %xmm1,%xmm0
 a0c:   66 0f 11 43 d8          movupd %xmm0,-0x28(%rbx)
 a11:   66 0f 11 53 c8          movupd %xmm2,-0x38(%rbx)
 a16:   48 83 c3 e0             add    $0xffffffffffffffe0,%rbx
 a1a:   48 83 c7 08             add    $0x8,%rdi
 a1e:   ff 27                   jmp    *(%rdi)
 a20:   66 0f 10 43 c8          movupd -0x38(%rbx),%xmm0
 a25:   66 0f 10 4b d8          movupd -0x28(%rbx),%xmm1
 a2a:   66 0f 10 53 e8          movupd -0x18(%rbx),%xmm2
 a2f:   66 0f 5c c2             subpd  %xmm2,%xmm0
 a33:   66 0f 10 53 f8          movupd -0x8(%rbx),%xmm2
 a38:   66 0f 5c ca             subpd  %xmm2,%xmm1
 a3c:   66 0f 11 4b d8          movupd %xmm1,-0x28(%rbx)
 a41:   66 0f 11 43 c8          movupd %xmm0,-0x38(%rbx)
 a46:   48 83 c3 e0             add    $0xffffffffffffffe0,%rbx
 a4a:   48 83 c7 08             add    $0x8,%rdi
 a4e:   ff 27                   jmp    *(%rdi)
 a50:   66 0f 10 43 c8          movupd -0x38(%rbx),%xmm0
 a55:   66 0f 10 4b d8          movupd -0x28(%rbx),%xmm1
 a5a:   66 0f 10 53 e8          movupd -0x18(%rbx),%xmm2
 a5f:   66 0f 59 d0             mulpd  %xmm0,%xmm2
 a63:   66 0f 10 43 f8          movupd -0x8(%rbx),%xmm0
 a68:   66 0f 59 c1             mulpd  %xmm1,%xmm0
 a6c:   66 0f 11 43 d8          movupd %xmm0,-0x28(%rbx)
 a71:   66 0f 11 53 c8          movupd %xmm2,-0x38(%rbx)
 a76:   48 83 c3 e0             add    $0xffffffffffffffe0,%rbx
 a7a:   48 83 c7 08             add    $0x8,%rdi
 a7e:   ff 27                   jmp    *(%rdi)
 a80:   66 0f 10 43 c8          movupd -0x38(%rbx),%xmm0
 a85:   66 0f 10 4b d8          movupd -0x28(%rbx),%xmm1
 a8a:   66 0f 10 53 e8          movupd -0x18(%rbx),%xmm2
 a8f:   66 0f 5e c2             divpd  %xmm2,%xmm0
 a93:   66 0f 10 53 f8          movupd -0x8(%rbx),%xmm2
 a98:   66 0f 5e ca             divpd  %xmm2,%xmm1
 a9c:   66 0f 11 4b d8          movupd %xmm1,-0x28(%rbx)
 aa1:   66 0f 11 43 c8          movupd %xmm0,-0x38(%rbx)
 aa6:   48 83 c3 e0             add    $0xffffffffffffffe0,%rbx
 aaa:   48 83 c7 08             add    $0x8,%rdi
 aae:   ff 27                   jmp    *(%rdi)
 ab0:   4c 89 ef                mov    %r13,%rdi
 ab3:   41 ff 65 00             jmp    *0x0(%r13)
 ab7:   66 0f 1f 84 00 00 00    nopw   0x0(%rax,%rax,1)
 abe:   00 00

0000000000000ac0 <?dtor$134@?0??ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z@4HA>:
 ac0:   48 89 54 24 10          mov    %rdx,0x10(%rsp)
 ac5:   55                      push   %rbp
 ac6:   41 57                   push   %r15
 ac8:   41 56                   push   %r14
 aca:   41 55                   push   %r13
 acc:   41 54                   push   %r12
 ace:   56                      push   %rsi
 acf:   57                      push   %rdi
 ad0:   53                      push   %rbx
 ad1:   48 83 ec 28             sub    $0x28,%rsp
 ad5:   48 8d 6a 40             lea    0x40(%rdx),%rbp
 ad9:   e8 00 00 00 00          call   ade <?dtor$134@?0??ReactorCore_Fallback@Core@Nominax@@YAXAEBUDetailedReactorDescriptor@12@AEAUReactorOutput@12@@Z@4HA+0x1e>
 ade:   cc                      int3

Disassembly of section .text:

0000000000000000 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z>:
   0:   56                      push   %rsi
   1:   48 83 ec 20             sub    $0x20,%rsp
   5:   48 89 ce                mov    %rcx,%rsi
   8:   48 8d 05 00 00 00 00    lea    0x0(%rip),%rax        # f <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0xf>
   f:   ff 24 d0                jmp    *(%rax,%rdx,8)
  12:   f2 0f 10 06             movsd  (%rsi),%xmm0
  16:   e8 00 00 00 00          call   1b <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x1b>
  1b:   e9 72 02 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
  20:   f2 0f 10 06             movsd  (%rsi),%xmm0
  24:   e8 00 00 00 00          call   29 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x29>
  29:   e9 64 02 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
  2e:   f2 0f 10 06             movsd  (%rsi),%xmm0
  32:   e8 00 00 00 00          call   37 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x37>
  37:   e9 56 02 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
  3c:   f2 0f 10 06             movsd  (%rsi),%xmm0
  40:   e8 00 00 00 00          call   45 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x45>
  45:   e9 48 02 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
  4a:   f2 0f 10 06             movsd  (%rsi),%xmm0
  4e:   e8 00 00 00 00          call   53 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x53>
  53:   e9 3a 02 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
  58:   f2 0f 10 06             movsd  (%rsi),%xmm0
  5c:   e8 00 00 00 00          call   61 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x61>
  61:   e9 2c 02 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
  66:   f2 0f 10 06             movsd  (%rsi),%xmm0
  6a:   e8 00 00 00 00          call   6f <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x6f>
  6f:   e9 1e 02 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
  74:   f2 0f 10 06             movsd  (%rsi),%xmm0
  78:   e8 00 00 00 00          call   7d <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x7d>
  7d:   e9 10 02 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
  82:   f2 0f 10 06             movsd  (%rsi),%xmm0
  86:   e8 00 00 00 00          call   8b <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x8b>
  8b:   e9 02 02 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
  90:   f2 0f 10 06             movsd  (%rsi),%xmm0
  94:   e8 00 00 00 00          call   99 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x99>
  99:   e9 f4 01 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
  9e:   f2 0f 10 06             movsd  (%rsi),%xmm0
  a2:   e8 00 00 00 00          call   a7 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0xa7>
  a7:   e9 e6 01 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
  ac:   f2 0f 10 06             movsd  (%rsi),%xmm0
  b0:   e8 00 00 00 00          call   b5 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0xb5>
  b5:   e9 d8 01 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
  ba:   f2 0f 10 06             movsd  (%rsi),%xmm0
  be:   e8 00 00 00 00          call   c3 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0xc3>
  c3:   48 98                   cltq
  c5:   48 89 06                mov    %rax,(%rsi)
  c8:   48 83 c4 20             add    $0x20,%rsp
  cc:   5e                      pop    %rsi
  cd:   c3                      ret
  ce:   f2 0f 10 06             movsd  (%rsi),%xmm0
  d2:   e8 00 00 00 00          call   d7 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0xd7>
  d7:   e9 b6 01 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
  dc:   f2 0f 10 06             movsd  (%rsi),%xmm0
  e0:   e8 00 00 00 00          call   e5 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0xe5>
  e5:   e9 a8 01 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
  ea:   48 8b 46 f8             mov    -0x8(%rsi),%rax
  ee:   48 8b 0e                mov    (%rsi),%rcx
  f1:   48 39 c8                cmp    %rcx,%rax
  f4:   48 0f 4c c1             cmovl  %rcx,%rax
  f8:   e9 70 01 00 00          jmp    26d <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x26d>
  fd:   f2 0f 10 46 f8          movsd  -0x8(%rsi),%xmm0
 102:   f2 0f 10 0e             movsd  (%rsi),%xmm1
 106:   e8 00 00 00 00          call   10b <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x10b>
 10b:   e9 09 01 00 00          jmp    219 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x219>
 110:   f2 0f 10 06             movsd  (%rsi),%xmm0
 114:   0f 54 05 00 00 00 00    andps  0x0(%rip),%xmm0        # 11b <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x11b>
 11b:   0f 13 06                movlps %xmm0,(%rsi)
 11e:   48 83 c4 20             add    $0x20,%rsp
 122:   5e                      pop    %rsi
 123:   c3                      ret
 124:   b9 01 00 00 00          mov    $0x1,%ecx
 129:   e8 00 00 00 00          call   12e <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x12e>
 12e:   ba 01 00 00 00          mov    $0x1,%edx
 133:   41 b8 08 00 00 00       mov    $0x8,%r8d
 139:   48 89 f1                mov    %rsi,%rcx
 13c:   49 89 c1                mov    %rax,%r9
 13f:   48 83 c4 20             add    $0x20,%rsp
 143:   5e                      pop    %rsi
 144:   e9 00 00 00 00          jmp    149 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x149>
 149:   31 c9                   xor    %ecx,%ecx
 14b:   e8 00 00 00 00          call   150 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x150>
 150:   48 89 f1                mov    %rsi,%rcx
 153:   ba 08 00 00 00          mov    $0x8,%edx
 158:   49 89 c0                mov    %rax,%r8
 15b:   48 83 c4 20             add    $0x20,%rsp
 15f:   5e                      pop    %rsi
 160:   e9 00 00 00 00          jmp    165 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x165>
 165:   b9 01 00 00 00          mov    $0x1,%ecx
 16a:   e8 00 00 00 00          call   16f <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x16f>
 16f:   48 89 c1                mov    %rax,%rcx
 172:   48 83 c4 20             add    $0x20,%rsp
 176:   5e                      pop    %rsi
 177:   e9 00 00 00 00          jmp    17c <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x17c>
 17c:   f2 0f 10 06             movsd  (%rsi),%xmm0
 180:   e8 00 00 00 00          call   185 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x185>
 185:   e9 08 01 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
 18a:   f2 0f 10 46 f8          movsd  -0x8(%rsi),%xmm0
 18f:   f2 0f 10 0e             movsd  (%rsi),%xmm1
 193:   e8 00 00 00 00          call   198 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x198>
 198:   eb 7f                   jmp    219 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x219>
 19a:   f2 0f 10 06             movsd  (%rsi),%xmm0
 19e:   e8 00 00 00 00          call   1a3 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x1a3>
 1a3:   e9 ea 00 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
 1a8:   f2 0f 10 06             movsd  (%rsi),%xmm0
 1ac:   e8 00 00 00 00          call   1b1 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x1b1>
 1b1:   e9 dc 00 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
 1b6:   f2 0f 10 06             movsd  (%rsi),%xmm0
 1ba:   e8 00 00 00 00          call   1bf <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x1bf>
 1bf:   e9 ce 00 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
 1c4:   f2 0f 10 06             movsd  (%rsi),%xmm0
 1c8:   e8 00 00 00 00          call   1cd <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x1cd>
 1cd:   e9 c0 00 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
 1d2:   f2 0f 10 46 f8          movsd  -0x8(%rsi),%xmm0
 1d7:   f2 0f 10 0e             movsd  (%rsi),%xmm1
 1db:   e8 00 00 00 00          call   1e0 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x1e0>
 1e0:   eb 37                   jmp    219 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x219>
 1e2:   f2 0f 10 06             movsd  (%rsi),%xmm0
 1e6:   66 0f 57 c9             xorpd  %xmm1,%xmm1
 1ea:   66 0f 2e c8             ucomisd %xmm0,%xmm1
 1ee:   0f 87 99 00 00 00       ja     28d <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x28d>
 1f4:   f2 0f 51 c0             sqrtsd %xmm0,%xmm0
 1f8:   e9 95 00 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
 1fd:   f2 0f 10 06             movsd  (%rsi),%xmm0
 201:   e8 00 00 00 00          call   206 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x206>
 206:   e9 87 00 00 00          jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
 20b:   f2 0f 10 46 f8          movsd  -0x8(%rsi),%xmm0
 210:   f2 0f 10 0e             movsd  (%rsi),%xmm1
 214:   e8 00 00 00 00          call   219 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x219>
 219:   f2 0f 11 46 f8          movsd  %xmm0,-0x8(%rsi)
 21e:   48 83 c4 20             add    $0x20,%rsp
 222:   5e                      pop    %rsi
 223:   c3                      ret
 224:   f2 0f 10 06             movsd  (%rsi),%xmm0
 228:   e8 00 00 00 00          call   22d <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x22d>
 22d:   eb 63                   jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
 22f:   f2 0f 10 06             movsd  (%rsi),%xmm0
 233:   e8 00 00 00 00          call   238 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x238>
 238:   eb 58                   jmp    292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
 23a:   48 8b 46 f8             mov    -0x8(%rsi),%rax
 23e:   48 8b 0e                mov    (%rsi),%rcx
 241:   48 39 c1                cmp    %rax,%rcx
 244:   48 0f 4e c1             cmovle %rcx,%rax
 248:   eb 23                   jmp    26d <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x26d>
 24a:   48 8d 46 f8             lea    -0x8(%rsi),%rax
 24e:   f2 0f 10 46 f8          movsd  -0x8(%rsi),%xmm0
 253:   66 0f 2e 06             ucomisd (%rsi),%xmm0
 257:   eb 0d                   jmp    266 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x266>
 259:   48 8d 46 f8             lea    -0x8(%rsi),%rax
 25d:   f2 0f 10 06             movsd  (%rsi),%xmm0
 261:   66 0f 2e 46 f8          ucomisd -0x8(%rsi),%xmm0
 266:   48 0f 42 c6             cmovb  %rsi,%rax
 26a:   48 8b 00                mov    (%rax),%rax
 26d:   48 89 46 f8             mov    %rax,-0x8(%rsi)
 271:   48 83 c4 20             add    $0x20,%rsp
 275:   5e                      pop    %rsi
 276:   c3                      ret
 277:   48 8b 06                mov    (%rsi),%rax
 27a:   48 89 c1                mov    %rax,%rcx
 27d:   48 f7 d9                neg    %rcx
 280:   48 0f 4c c8             cmovl  %rax,%rcx
 284:   48 89 0e                mov    %rcx,(%rsi)
 287:   48 83 c4 20             add    $0x20,%rsp
 28b:   5e                      pop    %rsi
 28c:   c3                      ret
 28d:   e8 00 00 00 00          call   292 <?SyscallIntrin@Core@Nominax@@YAXQEIATRecord@12@_K@Z+0x292>
 292:   f2 0f 11 06             movsd  %xmm0,(%rsi)
 296:   48 83 c4 20             add    $0x20,%rsp
 29a:   5e                      pop    %rsi
 29b:   c3                      ret

Disassembly of section .text:

0000000000000000 <??__E?id@?$num_put@DV?$ostreambuf_iterator@DU?$char_traits@D@std@@@std@@@std@@2V0locale@2@A@@YAXXZ>:
   0:   48 c7 05 fc ff ff ff    movq   $0x0,-0x4(%rip)        # 7 <??__E?id@?$num_put@DV?$ostreambuf_iterator@DU?$char_traits@D@std@@@std@@@std@@2V0locale@2@A@@YAXXZ+0x7>
   7:   00 00 00 00
   b:   c3                      ret

Disassembly of section .text:

0000000000000000 <??__E?id@?$numpunct@D@std@@2V0locale@2@A@@YAXXZ>:
   0:   48 c7 05 fc ff ff ff    movq   $0x0,-0x4(%rip)        # 7 <??__E?id@?$numpunct@D@std@@2V0locale@2@A@@YAXXZ+0x7>
   7:   00 00 00 00
   b:   c3                      ret
