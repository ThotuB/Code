module d_ff(
    input clk, rst_b, set_b, d,
    output reg q
);
    always @ (posedge clk, posedge rst_b, posedge set_b) begin // posedge rst, posedge set not necessary but resets/sets on negedge of clock so output is not xxxxx 
        if ( !rst_b ) begin
            q <= 0;
        end else if ( !set_b ) begin
            q <= 1;
        end else begin
            q <= d; 
        end
    end
endmodule