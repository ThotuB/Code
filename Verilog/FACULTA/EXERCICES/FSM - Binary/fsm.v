module fsm(
    input A0, A4, I3,
    input clk, rst_b,
    output reg U4, U8, O3
);
    localparam S_I8 = 0;
    localparam S_Z4 = 1;
    localparam S_P6 = 2;
    localparam S_F3 = 3;
    localparam S_K5 = 4;
    localparam S_Z6 = 5;

    wire[2:0] st;
    reg[2:0] st_next;

    always @ (*) begin
        case ( st )
            S_I8:   if ( (I3&~A0)|(~A0&~A4) ) begin
                        st_next = S_Z6;
                    end else if ( (A0&I3)|(A0&~A4) ) begin
                        st_next = S_Z6;
                    end else if ( A4&~I3 ) begin
                        st_next = S_Z4;
                    end else if ( A4&I3&~A0 ) begin
                        st_next = S_Z4;
                    end else if ( ~A0&~A4&~I3 ) begin
                        st_next = S_P6;
                    end 
            
            S_Z4:   if ( A0&A4&I3 ) begin
                        st_next = S_Z4;
                    end else if ( A4&I3&~A0 ) begin
                        st_next = S_F3;
                    end else if ( A0&~A4&~I3 ) begin
                        st_next = S_F3;
                    end else if ( (A0&I3)|(I3&~A4) ) begin
                        st_next = S_F3;
                    end else if ( ~A4&~I3 ) begin
                        st_next = S_K5;
                    end else if ( A4&~I3 ) begin
                        st_next = S_K5;
                    end else if ( ~A0&~A4&~I3 ) begin
                        st_next = S_K5;
                    end

            S_P6:   st_next = S_K5;
            
            S_F3:   if ( A4&I3&~A0 ) begin
                        st_next = S_Z6;
                    end else if ( (A0&I3)|(~A0&~I3) ) begin
                        st_next = S_K5;
                    end else if ( A0&~I3 ) begin
                        st_next = S_Z4;
                    end else if ( I3&~A0&~A4 ) begin
                        st_next = S_Z4;
                    end
            
            S_K5:   if ( (A0&A4)|(~A0&~I3) ) begin
                        st_next = S_Z6;
                    end else if ( (A0&~A4)|(I3&~A0) ) begin
                        st_next = S_Z6;
                    end
            
            S_Z6:   st_next = S_I8;
        endcase
    end

    always @ (*) begin
        U4 = 0;
        U8 = 0;
        O3 = 0;
        case ( st )
            S_I8:   if ( (I3&~A0)|(~A0&~A4) ) begin
                        U4 = 1;
                    end else if ( (A0&I3)|(A0&~A4) ) begin
                        U8 = 1;
                    end else if ( A4&~I3 ) begin
                        U4 = 1;
                        U8 = 1;
                        O3 = 1;
                    end
            
            S_Z4:   if ( A0&A4&I3 ) begin
                        U4 = 1;
                        O3 = 1;
                    end else if ( A4&I3&~A0 ) begin
                        U4 = 1;
                        O3 = 1;
                    end else if ( (A0&I3)|(I3&~A4) ) begin
                        U4 = 1;
                    end else if ( ~A4&~I3 ) begin
                        U4 = 1;
                        U8 = 1;
                        O3 = 1;
                    end else if ( A4&~I3 ) begin
                        U8 = 1;
                        O3 = 1;
                    end else if ( ~A0&~A4&~I3 ) begin
                        U4 = 1;
                    end
            
            S_F3:   if ( A4&I3&~A0 ) begin
                        U4 = 1;
                        O3 = 1;
                    end else if ( (A0&I3)|(~A0&~I3) ) begin
                        U8 = 1;
                    end else if ( I3&~A0&~A4 ) begin
                        U8 = 1;
                    end
            
            S_K5:   if ( (A0&~A4)|(I3&~A0) ) begin
                        U8 = 1;
                        O3 = 1;
                    end
        endcase
    end

    // always @ (posedge clk, negedge rst_b) begin
    //     if ( !rst_b ) begin
    //         st <= S_I8;
    //     end else begin
    //         st <= st_next;
    //     end
    // end
    
    d_ff flipflop0(.clk(clk), .rst_b(rst_b), .d(st_next[0]), .q(st[0]));
    d_ff flipflop1(.clk(clk), .rst_b(rst_b), .d(st_next[1]), .q(st[1]));
    d_ff flipflop2(.clk(clk), .rst_b(rst_b), .d(st_next[2]), .q(st[2]));


endmodule

module fsm_tb;
    reg clk, rst_b;
    reg A0, A4, I3;
    wire U4, U8, O3;
    
    fsm inst(.clk(clk), .rst_b(rst_b), .A0(A0), .A4(A4), .I3(I3), .U4(U4), .U8(U8), .O3(O3) ); 
    
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