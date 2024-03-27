.data
  A:   3
  B:   8
  C:   5
  D:   6
  Z:   0
.text
  LD 	A
  SUB 	B
  BNE 	L1
  JMP   L4
L1:
  LD   A
  SUB  C
  BNE  L2
  JMP  L4
L2:
  LD   A
  SUB  D
  BNE  L3
  JMP  L4
L3:
  LDI 0
  STO Z
  HLT 0
L4:
  LDI 1
  STO Z
  HLT 0