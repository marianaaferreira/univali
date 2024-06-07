library ieee;
use ieee.std_logic_1164.all;

entity tb_Circ3_1bit_fulladder is
end entity;

architecture behavior of tb_Circ3_1bit_fulladder is
  signal tb_i_A     : std_logic;
  signal tb_i_B     : std_logic;
  signal tb_i_C_IN  : std_logic;
  signal tb_o_S     : std_logic;
  signal tb_o_C_OUT : std_logic;

  component Circ3_1bit_fulladder
    port (
      i_A     : in std_logic;
      i_B     : in std_logic;
      i_C_IN  : in std_logic;
      o_S     : out std_logic;
      o_C_OUT : out std_logic
    );
  end component;

begin
  uut: Circ3_1bit_fulladder
    port map (
      i_A     => tb_i_A,
      i_B     => tb_i_B,
      i_C_IN  => tb_i_C_IN,
      o_S     => tb_o_S,
      o_C_OUT => tb_o_C_OUT
    );

  process
  begin
    -- Test case 1: 0 + 0 + 0
    tb_i_A <= '0';
    tb_i_B <= '0';
    tb_i_C_IN <= '0';
    wait for 10 ns;

    -- Test case 2: 0 + 0 + 1
    tb_i_A <= '0';
    tb_i_B <= '0';
    tb_i_C_IN <= '1';
    wait for 10 ns;

    -- Test case 3: 0 + 1 + 0
    tb_i_A <= '0';
    tb_i_B <= '1';
    tb_i_C_IN <= '0';
    wait for 10 ns;

    -- Test case 4: 0 + 1 + 1
    tb_i_A <= '0';
    tb_i_B <= '1';
    tb_i_C_IN <= '1';
    wait for 10 ns;

    -- Test case 5: 1 + 0 + 0
    tb_i_A <= '1';
    tb_i_B <= '0';
    tb_i_C_IN <= '0';
    wait for 10 ns;

    -- Test case 6: 1 + 0 + 1
    tb_i_A <= '1';
    tb_i_B <= '0';
    tb_i_C_IN <= '1';
    wait for 10 ns;

    -- Test case 7: 1 + 1 + 0
    tb_i_A <= '1';
    tb_i_B <= '1';
    tb_i_C_IN <= '0';
    wait for 10 ns;

    -- Test case 8: 1 + 1 + 1
    tb_i_A <= '1';
    tb_i_B <= '1';
    tb_i_C_IN <= '1';
    wait for 10 ns;

    -- End simulation
    wait;
  end process;

end architecture;