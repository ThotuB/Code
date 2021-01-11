module fsm (
    input clk, rst,
    input a2, i2,
    output o3, u8, U6, U9
);
    localparam S_C1 = 0;
    localparam S_N7 = 1;
    localparam S_C2 = 2;
    localparam S_G1 = 3;
    localparam S_E0 = 4;

    reg[4:0] st;
    wire[4:0] st_next;

    assign st_next[S_C1] =  ( st[S_C1] & ( i2 & ~a2 ) );
    
    assign st_next[S_N7] =  ( st[S_C1] & ( ~i2 ) ) |
                            ( st[S_G1] );
    
    assign st_next[S_C2] =  ( st[S_C1] & ( i2 & a2 ) ) |
                            ( st[S_N7] & ( i2 | ~a2 ) );
    
    assign st_next[S_G1] =  ( st[S_N7] & ( ~i2 & a2 ) ) |
                            ( st[S_C2] & ( i2 & ~a2) );
    
    assign st_next[S_E0] =  ( st[S_C2] & ( ~i2 | a2 ) ) |
                            ( st[S_E0] );

    assign o3 = st[S_C1] | st[S_C2];
    assign u8 = st[S_C2] | st[S_G1];
    assign U6 = st[S_C2] | st[S_G1] | st[S_E0];
    assign U9 = st[S_C2] | st[S_E0];

    always @ (posedge clk, posedge rst) begin
        if ( rst )  begin
            st <= 0;
            st[S_C1] <= 1;
        end
        else begin
            st <= st_next;
        end
    end

endmodule

module fsm_tb;
    reg clk, rst;
    reg a2, i2;
    wire o3, u8, U6, U9;

    fsm inst( .clk(clk), .rst(rst), .a2(a2), .i2(i2), .o3(o3), .u8(u8), .U6(U6), .U9(U9) );

    initial begin
        $display("time\tclk\trst\ta2\ti2\to3\tu8\tU6\tU9");
        $monitor("%4t\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t", $time, clk, rst, a2, i2, o3, u8, U6, U9);
    end

    localparam CLK_PERIOD = 100;
    localparam RUNNING_CYCLES = 25;
    initial begin
        clk = 0;
        repeat (2*RUNNING_CYCLES) #(CLK_PERIOD/2) clk = ~clk;
    end

    localparam RST_DURATION = 100;
    initial begin
        rst = 1;
        #RST_DURATION rst = 0;
    end

    initial begin
        i2 = 0;
        #(3 * CLK_PERIOD/2) i2 = 1;
        #(1 * CLK_PERIOD/2) i2 = 0;
        #(7 * CLK_PERIOD/2) i2 = 1;
        #(1 * CLK_PERIOD/2) i2 = 0;
        #(1 * CLK_PERIOD/2) i2 = 1;
        #(7 * CLK_PERIOD/2) i2 = 0;
        #(1 * CLK_PERIOD/2) i2 = 1;
        #(1 * CLK_PERIOD/2) i2 = 0;
        #(2 * CLK_PERIOD/2) i2 = 1;
        #(1 * CLK_PERIOD/2) i2 = 0;
        #(1 * CLK_PERIOD/2) i2 = 1;
        #(4 * CLK_PERIOD/2) i2 = 0;
        #(4 * CLK_PERIOD/2) i2 = 1;
        #(1 * CLK_PERIOD/2) i2 = 0;
        #(2 * CLK_PERIOD/2) i2 = 1;
        #(3 * CLK_PERIOD/2) i2 = 0;
        #(3 * CLK_PERIOD/2) i2 = 1;
        #(3 * CLK_PERIOD/2) i2 = 0;
        #(2 * CLK_PERIOD/2) i2 = 1;
    end

    initial begin
        a2 = 0;
        #(1 * CLK_PERIOD/2) a2 = 1;
        #(1 * CLK_PERIOD/2) a2 = 0;
        #(3 * CLK_PERIOD/2) a2 = 1;
        #(2 * CLK_PERIOD/2) a2 = 0;
        #(1 * CLK_PERIOD/2) a2 = 1;
        #(7 * CLK_PERIOD/2) a2 = 0;
        #(2 * CLK_PERIOD/2) a2 = 1;
        #(1 * CLK_PERIOD/2) a2 = 0;
        #(1 * CLK_PERIOD/2) a2 = 1;
        #(4 * CLK_PERIOD/2) a2 = 0;
        #(2 * CLK_PERIOD/2) a2 = 1;
        #(1 * CLK_PERIOD/2) a2 = 0;
        #(2 * CLK_PERIOD/2) a2 = 1;
        #(2 * CLK_PERIOD/2) a2 = 0;
        #(5 * CLK_PERIOD/2) a2 = 1;
        #(1 * CLK_PERIOD/2) a2 = 0;
        #(2 * CLK_PERIOD/2) a2 = 1;
        #(1 * CLK_PERIOD/2) a2 = 0;
        #(1 * CLK_PERIOD/2) a2 = 1;
        #(1 * CLK_PERIOD/2) a2 = 0;
        #(1 * CLK_PERIOD/2) a2 = 1;
        #(3 * CLK_PERIOD/2) a2 = 0;
        #(1 * CLK_PERIOD/2) a2 = 1;
    end
endmodule