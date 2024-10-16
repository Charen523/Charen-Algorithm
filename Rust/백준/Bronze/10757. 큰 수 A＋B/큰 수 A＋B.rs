use std::io::{self, Write};

fn add_large_numbers(a: &str, b: &str) -> String {
    let mut carry = 0;
    let mut result = String::new();

    let a_digits = a.chars().rev();
    let b_digits = b.chars().rev();

    let mut a_iter = a_digits.peekable();
    let mut b_iter = b_digits.peekable();

    while a_iter.peek().is_some() || b_iter.peek().is_some() || carry != 0 {
        let a_digit = a_iter.next().and_then(|ch| ch.to_digit(10)).unwrap_or(0);
        let b_digit = b_iter.next().and_then(|ch| ch.to_digit(10)).unwrap_or(0);

        let sum = a_digit + b_digit + carry;
        carry = sum / 10;
        result.push(std::char::from_digit(sum % 10, 10).unwrap());
    }

    result.chars().rev().collect()
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let numbers: Vec<&str> = input.trim().split_whitespace().collect();
    let a = numbers[0];
    let b = numbers[1];

    let result = add_large_numbers(a, b);
    println!("{}", result);
}