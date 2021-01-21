module d_ff(
    input clk, rst_b, d,
    output reg q
);

    always @ (posedge clk, negedge rst_b) begin
        if ( !rst_b ) begin
            q <= 0;
        end else begin
            q <= d;
        end
    end

endmodule