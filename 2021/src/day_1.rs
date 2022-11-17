use std::fs;

pub fn run() -> Result<i64, ()> {

    let result_input = fs::read_to_string("src\\input\\day_1.txt");

    let input = match result_input {
        Err(_error) => return Err(()),
        Ok(s) => s
    };

    let result: Vec<i64> = input.lines().map(|line| { 
        line.parse::<i64>().unwrap()
    }).collect();

    let count: i64 = result.iter().enumerate().map(|(idx, x,)| {
        let next: Option<&i64> = result.get(idx + 1);

        if let Some(value) = next {
            return if x > value {0} else {1} as i64;
        } 
        0 as i64
    }).sum();

    Ok(count)    
}

pub fn run_2() -> Result<i64,()> {
    let result_input = fs::read_to_string("src\\input\\day_1.txt");
    
    let input = match result_input {
        Err(_error) => return Err(()),
        Ok(s) => s
    };

    let result: Vec<i64> = input.lines().map(|line| { 
        line.parse::<i64>().unwrap()
    }).collect();

    let count = result
                    .windows(3)
                    .map(|w| w.iter().sum())
                    .collect::<Vec<i64>>()
                    .windows(2)
                    .filter(|x| x[0] < x[1])
                    .count() as i64;
    Ok(count)
    
}