module lfsr(
    input clk, rst_b,
    output[9:0] q
);
    generate // 25c 10 0101 1100
        genvar k;
        for (k=0; k<10; k=k+1) begin:v
            if ( k == 0 ) begin
                d_ff gu(.clk(clk), .rst_b(1'b1), .set_b(rst_b), .d(q[9]), .q(q[k]));
            end else if ( k == 5 || k == 7 ) begin
                d_ff gu(.clk(clk), .rst_b(1'b1), .set_b(rst_b), .d(q[k-1]), .q(q[k]));
            end else if ( k == 1 || k == 2 ) begin
                d_ff gu(.clk(clk), .rst_b(rst_b), .set_b(1'b1), .d(q[k-1]), .q(q[k]));
            end else if ( k == 3 || k == 6 ) begin
                d_ff gu(.clk(clk), .rst_b(1'b1), .set_b(rst_b), .d(q[9] ^ q[k-1]), .q(q[k]));
            end else begin
                d_ff gu(.clk(clk), .rst_b(rst_b), .set_b(1'b1), .d(q[9] ^ q[k-1]), .q(q[k]));
            end
                
        end
  endgenerate
endmodule

module lfsr_tb;
    reg clk, rst_b;
    wire[9:0] q;

    lfsr inst_lfsr(.clk(clk), .rst_b(rst_b), .q(q));

    initial begin
       $display("clk\trst_b\tq");
       $monitor("%b\t%b\t%b", clk, rst_b, {q[0], q[1], q[2], q[3], q[4], q[5], q[6], q[7], q[8], q[9]} );
    end

    localparam CLK_PERIOD = 100;
    localparam RUNNING_CYCLES = 31;
    initial begin
        clk = 0;
        repeat (2*RUNNING_CYCLES) #(CLK_PERIOD/2) clk = ~clk;
    end
    
    initial begin
        rst_b = 0;
        #CLK_PERIOD rst_b = 1;
    end
endmodule