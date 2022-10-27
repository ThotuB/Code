fn main() {
    let result: Result<i32, &str> = Ok(1);
    match result {
        Ok(value) => println!("value: {}", value),
        Err(error) => println!("error: {}", error),
    }
}

