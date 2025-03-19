fn main() {
    
    let name = "Nicolas"; // I give ownership to variable name, so that it is allocated a memopry slot

    print_value(&name); //Here I am borrowing the reference of the variable so I can use it

    // Once the function completed execution, the memory is deallocated
} 

fn print_value(value) {
    println!("Value: {}", value);
}