module fsm(
    input clk, rst_b,
    input i9, a9,
    output o0, o5, o9
);

    localparam S_H2 = 0;
    localparam S_M1 = 1;
    localparam S_D5 = 2;
    localparam S_V8 = 3;
    localparam S_O8 = 4;
    localparam S_F6 = 5;
    
    reg[2:0] st;
    reg[2:0] st_next;
  
    always @ (*) begin
        case (st)
            S_H2:   if ( a9 & i9 ) begin 
                        st_next = S_M1;
                    end else if ( a9 & ~i9 ) begin
                        st_next = S_D5;
                    end else if ( ~a9 ) begin
                        st_next = S_V8;
                    end

            S_M1:   if ( a9 | ~i9 ) begin 
                        st_next = S_H2;
                    end else if ( ~a9 & i9 ) begin
                        st_next = S_D5;
                    end

            S_D5:   if ( ~i9 ) begin 
                        st_next = S_D5;
                    end else if ( i9 ) begin
                        st_next = S_F6;
                    end

            S_V8:   if ( ~i9 ) begin 
                        st_next = S_O8;
                    end else if ( i9 ) begin
                        st_next = S_F6;
                    end

            S_O8: st_next = S_F6;

            S_F6: st_next = S_F6;

        endcase
    end
  
    assign o0 = ( st == S_H2 && st_next == S_M1 ) |
                ( st == S_H2 && st_next == S_D5 ) |
                ( st == S_H2 && st_next == S_V8 ) |
                ( st == S_M1 && st_next == S_D5 ) |
                ( st == S_D5 && st_next == S_D5 ) |
                ( st == S_D5 && st_next == S_F6 ) |
                ( st == S_O8 && st_next == S_F6 && ((a9 & i9) | (~a9 & ~i9)) );

    assign o5 = ( st == S_H2 && st_next == S_D5 ) |
                ( st == S_M1 && st_next == S_D5 ) |
                ( st == S_D5 && st_next == S_F6 ) |
                ( st == S_O8 && st_next == S_F6 && ((a9 & i9) | (~a9 & ~i9)) );

    assign o9 = ( st == S_H2 && st_next == S_D5 ) |
                ( st == S_H2 && st_next == S_V8 ) |
                ( st == S_M1 && st_next == S_D5 ) |
                ( st == S_D5 && st_next == S_D5 ) |
                ( st == S_D5 && st_next == S_F6 ) |
                ( st == S_V8 && st_next == S_F6 ) |
                ( st == S_O8 && st_next == S_F6 && ((a9 & i9) | (~a9 & ~i9)) );
    
    always @ (posedge  clk, negedge rst_b) begin
        if ( !rst_b ) begin
            st <= S_H2;
        end
        else begin
            st <= st_next;  
        end
    end

  endmodule
  
  module fsm_tb;
    reg clk, rst_b;
    reg i2, a2;
    wire o0, o5, o9;
    
    fsm inst1(.clk(clk), .rst_b(rst_b), .i9(i2), .a9(a2), .o0(o0), .o5(o5), .o9(o9));
    
    initial begin
        $display("time\tclk\trst_b\ta9\ti9\to0\to5\to9");
        $monitor("%4t\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t", $time, clk, rst_b, a2, i2, o0, o5, o9);
    end

    localparam CLK_PERIOD = 100;
    localparam RUNNING_CYCLES = 25;
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
  endmodule;
      