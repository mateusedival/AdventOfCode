use std::{fs};

pub fn run() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_7.txt").unwrap();

    let mut xs: Vec<i64> = input.split(",").map(|x| x.parse::<i64>().unwrap()).collect();
 
    xs.sort();

	let median = xs[xs.len()/2];

    let fuel = xs.iter().fold(0,|acc, x| acc + (x-median).abs());
    
    Ok(fuel)
}

pub fn run_2() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_7.txt").unwrap();

    let xs: Vec<i64> = input.split(",").map(|x| x.parse::<i64>().unwrap()).collect();
    
	let mean = xs.iter().sum::<i64>() / xs.len() as i64;

    let fuel = xs
                    .iter()
                    .fold(0,|acc, x| {
                        let n = (x-mean).abs(); 
                        acc + (n * (n + 1))/ 2
                    });
    
    Ok(fuel)
}
