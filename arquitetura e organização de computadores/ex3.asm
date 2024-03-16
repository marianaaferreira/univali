.data
  A:   15
  B:   11
  C:   0
.text
  LD   A
  SUB  B
  BGE  L1
  LD   B
  STO  C
  LD   A
  STO  B
  LD   C
  STO  A
L1:
  hlt
  
  
  