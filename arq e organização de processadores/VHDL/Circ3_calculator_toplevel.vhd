library ieee;
use ieee.std_logic_1164.all;

entity use Circ3_calculator_toplevel is
	port
	(
		i_Sel : in std_logic_vectot(1 downto 0);
		
		i_Segments_A_dez : out std_logic_vector(6 downto 0);
		i_Segments_A_uni : out std_logic_vector(6 downto 0);
		i_Segments_B_dez : out std_logic_vector(6 downto 0);
		i_Segments_B_uni : out std_logic_vector(6 downto 0);
		i_Segments_S_dez : out std_logic_vector(6 downto 0);
		i_Segments_S_uni : out std_logic_vector(6 downto 0);
		
		i_A : in std_logic_vector(3 downto 0);
		i_B : in std_logic_vector(3 downto 0);
		
		i_Clk : in std_logic
	);
end entity;

architecture arch_1 of Circ3_calculator_toplevel is 

	signal w_S : std_logic_vector(7 downto 0);
	signal w_A : std_logic_vector(7 downto 0);
	signal w_B : std_logic_vector(7 downto 0);
	signal w_Sel : std_logic_vector(2 downto 0);
	
	component Circ3_ULA_toplevel is 
		port
		(
			i_A : in std_logic_vector(7 downto 0);
			i_B : in std_logic_vector(7 downto 0);
			i_Sel : in std_logic_vector(7 downto 0);
			o_S : out std_logic_vector(7 downto 0);
		);
	end component;
	
	component BinTo7SegDisplays is 
		Port (
			clk : in std_logic;
			binary : in STD_LOGIC_VECTOR(7 downto 0);
			segments_dezena : out STD_LOGIC_VECTOR(6 downto 0);
			segments_unidade : out STD_LOGIC_VECTOR(6 downto 0);
		);
	end component;
	
	begin
	
		w_A <= ("0000" & i_A);
		
		w_B <= ("0000" & i_B);
		
		w_Sel <= ("0" & i_Sel);
		
		ula : Circ3+ULA_toplevel
		port map
		(
			i_A => w_A,
			i_B => w_B,
			i_Sel => w_Sel,
			o_S => w_S
		);
		
		disp_A : BinTo7SegDisplays
		port map (
			clk => i_Clk,
			binary => w_A,
			segments_dezena => i_Segments_A_dez,
			segments_unidade => i_Segments_A_uni
		);
		
		disp_B : BinTo7SegDisplays
		port map (
			clk => i_Clk,
			binary => w_B,
			segments_dezena => i_Segments_B_dez,
			segments_unidade => i_Segments_B_uni
		);
			
		disp_S : BinTo7SegDisplays
		port map (
			clk => i_clk,
			binary => w_S,
			segments_dezena => i_Segments_S_dez,
			segments_unidade => i_Segments_S_uni
		);
end architecture;
		
		
		
		