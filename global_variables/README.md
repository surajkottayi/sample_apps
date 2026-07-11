# sample_apps
Sample apps to learn global variables

+-------------------------+
| .text   | Functions     |
+-------------------------+
| .rodata | const data    |
+-------------------------+
| .data   | Initialized globals/static
|         | int x = 5;
+-------------------------+
| .bss    | Zero/uninitialized globals/static
|         | int y;
|         | int z = 0;
+-------------------------+
| Heap                    |
+-------------------------+
| Stack                   |
+-------------------------+

nm -C app(Name list and symbol table)

00000000000051c0 b guard variable for sample_apps::CFile1::getInstance()::instance
00000000000051f0 b guard variable for sample_apps::CFile2::getInstance()::instance
00000000000051a0 b global_static_variable
00000000000051d0 b global_static_variable
00000000000051f8 b global_static_variable
0000000000005010 u global_inline_variable

b => .bss (Block Started by Symbol)
u => unique
d => data
D => global

| Code | Meaning                                                  |
| ---- | -------------------------------------------------------- |
| `T`  | Function in `.text`                                      |
| `t`  | Local function                                           |
| `D`  | Global initialized data                                  |
| `d`  | Local initialized data                                   |
| `B`  | Global uninitialized data (`.bss`)                       |
| `b`  | Local uninitialized data                                 |
| `R`  | Read-only data                                           |
| `r`  | Local read-only data                                     |
| `V`  | Weak object                                              |
| `W`  | Weak function                                            |
| `U`  | Undefined symbol (expected to be resolved by the linker) |
