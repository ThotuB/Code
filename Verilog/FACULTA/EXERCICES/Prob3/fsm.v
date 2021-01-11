module fsm(
    input A0, A4, I3,
    input clk, rst_b,
    output U4, U8, O3, 
    output[5:0] state
);
    localparam S_I8 = 0;
    localparam S_Z4 = 1;
    localparam S_P6 = 2;
    localparam S_F3 = 3;
    localparam S_K5 = 4;
    localparam S_Z6 = 5;

    reg[5:0] st;
    wire[5:0] st_next;

    assign st_next[S_I8] =  ( st[S_Z6] );

    assign st_next[S_Z4] =  ( st[S_I8] & ( A4 & ~I3 ) ) |
                            ( st[S_Z4] & ( A0 & A4 & I3 ) ) |
                            ( st[S_F3] & ( I3 & ~A0 & ~A4 ) ) |
                            ( st[S_F3] & ( A0 & ~I3 ) );

    assign st_next[S_P6] =  ( st[S_I8] & ( A4 & I3 & ~A0) ) |
                            ( st[S_I8] & ( ~A0 & ~A4 & ~I3 ) );

    assign st_next[S_F3] =  ( st[S_Z4] & ( A4 & I3 & ~A0 ) ) |
                            ( st[S_Z4] & ( A0 & ~A4 & ~I3 ) ) |
                            ( st[S_Z4] & ( ( A0 & I3 ) | ( I3 & ~A4 ) ) );

    assign st_next[S_K5] =  ( st[S_Z4] & ( ~A4 & ~I3 ) ) |
                            ( st[S_Z4] & ( A4 & ~I3 ) ) |
                            ( st[S_Z4] & ( ~A0 & ~A4 & ~I3 ) ) |
                            ( st[S_P6] ) |
                            ( st[S_F3] & ( ( A0 & I3 ) | ( ~A0 & ~I3) ) );
                    
    assign st_next[S_Z6] =  ( st[S_I8] & ( ( I3 & ~A0 ) | ( ~A0 & ~A4) ) ) |
                            ( st[S_I8] & ( ( A0 & I3 ) | ( A0 & ~A4) ) ) |
                            ( st[S_F3] & ( A4 & I3 & ~A0 ) ) |
                            ( st[S_K5] & ( ( A0 & A4 ) | ( ~A0 & ~I3 ) ) ) |
                            ( st[S_K5] & ( ( A0 & ~A4 ) | ( I3 & ~A0 ) ) );

    assign U4 = ( st[S_I8] & ( A4 & ~I3 ) ) |
                ( st[S_Z4] & ( A0 & A4 & I3 ) ) |
                ( st[S_Z4] & ( A4 & I3 & ~A0 ) ) |
                ( st[S_Z4] & ( ( A0 & I3 ) | ( I3 & ~A4 ) ) ) |
                ( st[S_Z4] & ( ~A4 & ~I3 ) ) |
                ( st[S_Z4] & ( ~A0 & ~A4 & ~I3 ) ) |
                ( st[S_I8] & ( ( I3 & ~A0 ) | ( ~A0 & ~A4) ) ) |
                ( st[S_F3] & ( A4 & I3 & ~A0 ) );

    assign U8 = ( st[S_I8] & ( A4 & ~I3 ) ) |
                ( st[S_F3] & ( I3 & ~A0 & ~A4 ) ) |
                ( st[S_Z4] & ( ~A4 & ~I3 ) ) |
                ( st[S_Z4] & ( A4 & ~I3 ) ) |
                ( st[S_F3] & ( ( A0 & I3 ) | ( ~A0 & ~I3) ) ) |
                ( st[S_I8] & ( ( A0 & I3 ) | ( A0 & ~A4) ) ) |
                ( st[S_K5] & ( ( A0 & ~A4 ) | ( I3 & ~A0 ) ) );

    assign O3 = ( st[S_I8] & ( A4 & ~I3 ) ) |
                ( st[S_Z4] & ( A0 & A4 & I3 ) ) |
                ( st[S_Z4] & ( A4 & I3 & ~A0 ) ) |
                ( st[S_Z4] & ( ~A4 & ~I3 ) ) |
                ( st[S_Z4] & ( A4 & ~I3 ) ) |
                ( st[S_F3] & ( A4 & I3 & ~A0 ) ) |
                ( st[S_K5] & ( ( A0 & ~A4 ) | ( I3 & ~A0 ) ) );

    always @ (posedge clk, negedge rst_b) begin
        if ( !rst_b ) begin
            st <= 0;
            st[S_I8] <= 1 ;
        end else begin
            st <= st_next;
        end
    end

    assign state = st;

endmodule

module fsm_tb;
    reg clk, rst_b;
    reg A0, A4, I3;
    wire U4, U8, O3;
    wire[5:0] state;
    
    fsm inst(.clk(clk), .rst_b(rst_b), .A0(A0), .A4(A4), .I3(I3), .U4(U4), .U8(U8), .O3(O3), .state(state)); 
    
    localparam CLK_PERIOD = 100;
    localparam RUNNING_CYCLES = 22;
    initial begin
        clk = 0;
        repeat (2*RUNNING_CYCLES) #(CLK_PERIOD/2) clk = ~clk;
    end
    
    localparam RST_DURATION = 100;
    initial begin
        rst_b = 0;
        #RST_DURATION rst_b = 1;
    end
    
    initial begin
        I3 = 0;
        #(4 * CLK_PERIOD/2) I3 = 1;
        #(4 * CLK_PERIOD/2) I3 = 0;
        #(2 * CLK_PERIOD/2) I3 = 1;
        #(2 * CLK_PERIOD/2) I3 = 0;
        #(6 * CLK_PERIOD/2) I3 = 1;
        #(2 * CLK_PERIOD/2) I3 = 0;
        #(6 * CLK_PERIOD/2) I3 = 1;
        #(2 * CLK_PERIOD/2) I3 = 0;
        #(2 * CLK_PERIOD/2) I3 = 1;
        #(2 * CLK_PERIOD/2) I3 = 0;
        #(4 * CLK_PERIOD/2) I3 = 1;
    end

    initial begin
        A0 = 1;
        #(2 * CLK_PERIOD/2) A0 = 0;
        #(8 * CLK_PERIOD/2) A0 = 1;
        #(2 * CLK_PERIOD/2) A0 = 0;
        #(2 * CLK_PERIOD/2) A0 = 1;
        #(2 * CLK_PERIOD/2) A0 = 0;
        #(6 * CLK_PERIOD/2) A0 = 1;
        #(6 * CLK_PERIOD/2) A0 = 0;
        #(2 * CLK_PERIOD/2) A0 = 1;
        #(6 * CLK_PERIOD/2) A0 = 0;
        #(2 * CLK_PERIOD/2) A0 = 1;
    end

    initial begin
        A4 = 0;
        #(2 * CLK_PERIOD/2) A4 = 1;
        #(2 * CLK_PERIOD/2) A4 = 0;
        #(2 * CLK_PERIOD/2) A4 = 1;
        #(2 * CLK_PERIOD/2) A4 = 0;
        #(8 * CLK_PERIOD/2) A4 = 1;
        #(2 * CLK_PERIOD/2) A4 = 0;
        #(2 * CLK_PERIOD/2) A4 = 1;
        #(2 * CLK_PERIOD/2) A4 = 0;
        #(4 * CLK_PERIOD/2) A4 = 1;
        #(4 * CLK_PERIOD/2) A4 = 0;
        #(2 * CLK_PERIOD/2) A4 = 1;
        #(8 * CLK_PERIOD/2) A4 = 0;
    end
endmodule