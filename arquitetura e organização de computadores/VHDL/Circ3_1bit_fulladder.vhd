library ieee;
use ieee.std_logic_1164.all;

entity Circ3_1bit_fulladder is
  port
  (
    i_A     : in std_logic;
    i_B     : in std_logic;
    i_C_IN  : in std_logic;
    o_S     : out std_logic;
    o_C_OUT : out std_logic
  );
end entity;

architecture arch_1 of Circ3_1bit_fulladder is
begin
  o_S     <= i_A xor i_B xor i_C_IN;
  o_C_OUT <= (i_A and i_B) or (i_C_IN and i_A) or (i_C_IN and i_B);

end architecture;