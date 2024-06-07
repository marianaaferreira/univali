library ieee;
use ieee.std_logic_1164.all;

entity Circ3_8bit_adder is
  port
  (
    i_A     : in std_logic_vector(7 downto 0);
    i_B     : in std_logic_vector(7 downto 0);
    i_C_IN  : in std_logic;
    o_S     : out std_logic_vector(7 downto 0);
    o_C_OUT : out std_logic
  );
end entity;

architecture arch_1 of Circ3_8bit_adder is
  signal carry : std_logic_vector(8 downto 0);
  signal sum   : std_logic_vector(8 downto 0);

  component Circ3_1bit_fulladder is
    port
    (
      i_A     : in std_logic;
      i_B     : in std_logic;
      i_C_IN  : in std_logic;
      o_S     : out std_logic;
      o_C_OUT : out std_logic
    );
  end component;

begin
  carry(0) <= i_C_IN;

  -- Implementa a cascata dos somadores de 1 bit
  adders : for n in 0 to 7 generate
    adder : Circ3_1bit_fulladder
    port map
    (
      i_A     => i_A(n),
      i_B     => i_B(n),
      i_C_IN  => carry(n),
      o_S     => sum(n),
      o_C_OUT => carry(n + 1)
    );
  end generate;

  o_S     <= sum(7 downto 0);
  o_C_OUT <= carry(8);

end architecture;