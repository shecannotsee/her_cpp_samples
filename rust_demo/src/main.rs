use crate::add::add_two;

mod add;

fn main() {
    let s = "hello world";
    println!("{}", s);
    println!("{}", add_two(10));
}