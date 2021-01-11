module lfsr5b(
    input clk, rst_b,
    output [4:0] q
);
	d_ff dflipflop0(.clk(clk), .rst_b(1'd1), .set_b(rst_b), .d(q[4]),      .q(q[0]));
	d_ff dflipflop1(.clk(clk), .rst_b(1'd1), .set_b(rst_b), .d(q[0]),      .q(q[1]));
	d_ff dflipflop2(.clk(clk), .rst_b(1'd1), .set_b(rst_b), .d(q[1]^q[4]), .q(q[2]));
	d_ff dflipflop3(.clk(clk), .rst_b(1'd1), .set_b(rst_b), .d(q[2]),      .q(q[3]));
	d_ff dflipflop4(.clk(clk), .rst_b(1'd1), .set_b(rst_b), .d(q[3]),      .q(q[4]));

endmodule

module lfsr5b_tb;
    reg clk,rst_b;
    wire [4:0] q;
    
    lfsr5b inst(.clk(clk), .rst_b(rst_b), .q(q));
    
    localparam CLK_PERIOD = 100;
    localparam RUNNING_CYCLES = 35;
    initial begin
        clk = 0;
        repeat (2*RUNNING_CYCLES) #(CLK_PERIOD/2) clk = ~clk;
    end
    
    localparam RST_DURATION = 25;
    initial begin
        rst_b = 0;
        #RST_DURATION rst_b = 1 ; 
    end
endmodule