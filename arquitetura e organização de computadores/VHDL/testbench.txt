library ieee;
use ieee.std_logic_1164.all;

entity tb_Circ3_8bit_adder is
end entity;

architecture behavior of tb_Circ3_8bit_adder is
  signal tb_i_A     : std_logic_vector(7 downto 0);
  signal tb_i_B     : std_logic_vector(7 downto 0);
  signal tb_i_C_IN  : std_logic;
  signal tb_o_S     : std_logic_vector(7 downto 0);
  signal tb_o_C_OUT : std_logic;

  component Circ3_8bit_adder
    port
    (
      i_A     : in std_logic_vector(7 downto 0);
      i_B     : in std_logic_vector(7 downto 0);
      i_C_IN  : in std_logic;
      o_S     : out std_logic_vector(7 downto 0);
      o_C_OUT : out std_logic
    );
  end component;

begin
  uut: Circ3_8bit_adder
    port map
    (
      i_A     => tb_i_A,
      i_B     => tb_i_B,
      i_C_IN  => tb_i_C_IN,
      o_S     => tb_o_S,
      o_C_OUT => tb_o_C_OUT
    );

  process
  begin
    -- Test case 1: 0x00 + 0x00 + 0
    tb_i_A <= "00000000";
    tb_i_B <= "00000000";
    tb_i_C_IN <= '0';
    wait for 10 ns;

    -- Test case 2: 0x01 + 0x01 + 0
    tb_i_A <= "00000001";
    tb_i_B <= "00000001";
    tb_i_C_IN <= '0';
    wait for 10 ns;

    -- Test case 3: 0x0F + 0x01 + 0
    tb_i_A <= "00001111";
    tb_i_B <= "00000001";
    tb_i_C_IN <= '0';
    wait for 10 ns;

    -- Test case 4: 0xFF + 0x01 + 0
    tb_i_A <= "11111111";
    tb_i_B <= "00000001";
    tb_i_C_IN <= '0';
    wait for 10 ns;

    -- Test case 5: 0xFF + 0x01 + 1
    tb_i_A <= "11111111";
    tb_i_B <= "00000001";
    tb_i_C_IN <= '1';
    wait for 10 ns;

    -- Test case 6: 0x55 + 0xAA + 0
    tb_i_A <= "01010101";
    tb_i_B <= "10101010";
    tb_i_C_IN <= '0';
    wait for 10 ns;

    -- Test case 7: 0x80 + 0x80 + 0
    tb_i_A <= "10000000";
    tb_i_B <= "10000000";
    tb_i_C_IN <= '0';
    wait for 10 ns;

    -- Test case 8: 0x80 + 0x80 + 1
    tb_i_A <= "10000000";
    tb_i_B <= "10000000";
    tb_i_C_IN <= '1';
    wait for 10 ns;

    -- End simulation
    wait;
  end process;

end architecture;