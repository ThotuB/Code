library verilog;
use verilog.vl_types.all;
entity pat is
    port(
        clk             : in     vl_logic;
        rst_b           : in     vl_logic;
        i9              : in     vl_logic;
        a9              : in     vl_logic;
        o0              : out    vl_logic;
        o5              : out    vl_logic;
        o9              : out    vl_logic
    );
end pat;
