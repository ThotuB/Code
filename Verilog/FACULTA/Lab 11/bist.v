module bist(
    input clk,
    input rst_b,
    output sig
);
    wire[4:0] lsfr5b_check;
    wire check_sisr4b;

    lfsr5b inst_lfsr5b(.clk(clk), .rst_b(rst_b), .q(lsfr5b_check));
    check inst_check(.i(lsfr5b_check), .o(check_sisr4b));
    sisr4b inst_sisr4b(.clk(clk), .rst_b(rst_b), .i(check_sisr4b), .q(sig));
endmodule

module bist_tb;
    reg clk;
    reg rst_b;
    wire[3:0] sig;

    bist inst(.clk(clk), .rst_b(rst_b), .sig(sig));

    initial begin
        $display("time\tclk\trst_b\tq");
        $monitor("%4t\t%b\t%b\t%d", $time, clk, rst_b, sig);
    end

    localparam CLK_PERIOD = 100;
    localparam RUNNING_CYCLES = 35;
    initial begin
        clk = 0;
        repeat (2*RUNNING_CYCLES) #(CLK_PERIOD/2) clk = ~clk;
    end

    localparam RST_DURATION = 25;
    initial begin
        rst_b = 0;
        #RST_DURATION rst_b = 1;
    end
endmodule