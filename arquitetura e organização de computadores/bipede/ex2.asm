.data
  I:    0
.text
  ldi   0
  sto   1
L1:
  LD    I
  addi  1
  sto   I
  subi  10
  blt   L1
L2:
  hlt