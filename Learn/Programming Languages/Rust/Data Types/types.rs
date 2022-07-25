use std;

fn print_type<T: std:fmt:Display>(value: T) {
    println!("{}: {}", std::any::type_name::<T>(), value);
}

fn main() {
    /// Scalar Types
    // integer types
    let i_8: i8 = -8;
    let i_16: i16 = -16;
    let i_32: i32 = 5;
    let i_64: i64 = 5;
    let i_128: i128 = 5;

    let u_8: u8 = 5;
    let u_16: u16 = 5;
    let u_32: u32 = 5;
    let u_64: u64 = 5;
    let u_128: u128 = 5;

    // floating point types
    let f_32: f32 = 5.0;
    let f_64: f64 = 5.0;

    // boolean types
    let b_true: bool = true;
    let b_false: bool = false;

    // character types
    let character: char = 'a';
    let string: &str = "Hello";

    // Compound Types
    // tuple types
    let tuple: (i32, f64, u8) = (500, 6.4, 1);

    // array types
    let array: [i32; 5] = [1, 2, 3, 4, 5];

    // slice types
    let slice: &[i32] = &[1, 2, 3, 4, 5];


    // reference types
    let reference: &i32 = &i_32;

    // pointer types
    let pointer: *const i32 = &i_32;

    // function types
    let function: fn(nr: i32) -> i32 = |nr| nr + 1;
}
