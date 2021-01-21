library verilog;
use verilog.vl_types.all;
entity fsm is
    port(
        A0              : in     vl_logic;
        A4              : in     vl_logic;
        I3              : in     vl_logic;
        clk             : in     vl_logic;
        rst_b           : in     vl_logic;
        U4              : out    vl_logic;
        U8              : out    vl_logic;
        O3              : out    vl_logic
    );
end fsm;
