fn binary_search<T: Ord>(target: &T, val_fn: &dyn Fn(usize) -> T, len: usize) -> Option<usize> {
    let mut left = 0;
    let mut right = len;
    while left < right {
        let mid = left + (right - left) / 2;
        if val_fn(mid) < *target {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if left < len && val_fn(left) == *target {
        Some(left)
    } else {
        None
    }
}

fn fib(n: u64) -> u64 {
    let mut a = 0;
    let mut b = 1;
    for _ in 0..n {
        let c = a + b;
        a = b;
        b = c;
    }
    a
}

fn main() {
    let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9];
    let target = 5;
    let result = binary_search(&target, &|i| arr[i], arr.len());
    match result {
        Some(index) => println!("Found at index: {}", index),
        None => println!("Not found"),
    }

    let mat = vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]];
    let target = 5;
    let result = binary_search(&target, &|i| mat[i / 3][i % 3], 9);
    match result {
        Some(index) => println!("Found at index: {}", index),
        None => println!("Not found"),
    }

    let target = 13;
    let result = binary_search(&target, &|i| fib(i as u64), 10);
    match result {
        Some(index) => println!("Found at index: {}", index),
        None => println!("Not found"),
    }
}
