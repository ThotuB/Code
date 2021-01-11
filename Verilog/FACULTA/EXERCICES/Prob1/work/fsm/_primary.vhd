library verilog;
use verilog.vl_types.all;
entity fsm is
    port(
        clk             : in     vl_logic;
        rst             : in     vl_logic;
        a2              : in     vl_logic;
        i2              : in     vl_logic;
        o3              : out    vl_logic;
        u8              : out    vl_logic;
        U6              : out    vl_logic;
        U9              : out    vl_logic
    );
end fsm;
