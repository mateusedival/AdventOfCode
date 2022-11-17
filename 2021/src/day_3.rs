
use std::{io::Error, fs, i64};

fn frequencies(input: &String) -> Vec<i64> {
    input
        .lines()
        .map(|line| {
            line
                .chars()
                .map(|bit| {
                    bit
                        .to_string()
                        .parse::<i64>()
                        .unwrap()
                }).collect()
        })
        .collect::<Vec<Vec<i64>>>()
        .into_iter()
        .reduce(|acc,x| {
            acc
                .iter()
                .zip(x)
                .map(|(a,b)| a+b)
                .collect()
        }).unwrap()
}

pub fn run() -> Result<i64,Error> {
    let input = match fs::read_to_string("src\\input\\day_3.txt") {
        Err(error) =>  return Err(error),
        Ok(file) => file 
    };

    let half = (input.lines().collect::<Vec<_>>().len() / 2) as i64;

    let sums = frequencies(&input);

    let gamma_rate = sums
                                .into_iter()
                                .map(|bits| {
                                    if bits > half {"1".to_string()} else {"0".to_string()}
                                }).collect::<Vec<String>>()
                                .join("");

    let epsilon_rate = gamma_rate
                                .chars()
                                .map(|bit| {
                                    if bit == '0' {String::from("1")} else {String::from("0")}
                                }).collect::<Vec<String>>()
                                .join("");

    let power_consumption = i64::from_str_radix(&gamma_rate, 2).unwrap() * i64::from_str_radix(&epsilon_rate, 2).unwrap();
    Ok(power_consumption) 
}

pub fn run_2() -> Result<i64,Error> {
    
    let input = match fs::read_to_string("src\\input\\day_3.txt") {
        Err(error) =>  return Err(error),
        Ok(file) => file 
    };

    let mut half = (input.lines().collect::<Vec<_>>().len() / 2) as i64;

    let mut sums = frequencies(&input);

    let mut lines: Vec<String> = input.lines().map(|line| line.to_string()).collect();
    let mut lines_2: Vec<String> = input.lines().map(|line| line.to_string()).collect();

    for i in 0..sums.len() {
        let mut a = if sums[i] > half {"1"} else {"0"};

        if lines.len() % 2 == 0 && sums[i] == half{
            a = "1";
        }
        
        lines = lines
                    .clone()
                    .into_iter()
                    .filter(|line| {
                        if let Some(b) = line.get(i..i+1)  {
                            if a == b  {return true} 
                        }
                        false
                    }).collect();
        
        let aux = lines.join("\n");
        sums = frequencies(&aux);
        half = (aux.lines().collect::<Vec<_>>().len() / 2) as i64;
        
        
        if lines.len() == 1  {
            break;
        }
    };

    half = (input.lines().collect::<Vec<_>>().len() / 2) as i64;

    sums = frequencies(&input);

    for i in 0..sums.len() {
        let mut a = if sums[i] > half {"0"} else {"1"};

        if lines_2.len() % 2 == 0 && sums[i] == half{
            a = "0";
        }

        lines_2 = lines_2
                        .clone()
                        .into_iter()
                        .filter(|line| {
                            if let Some(b) = line.get(i..i+1)  {
                            if a != b  {return false} 
                        }
                            true
                        }).collect();

        let aux = lines_2.join("\n");
        sums = frequencies(&aux);
        half = (aux.lines().collect::<Vec<_>>().len() / 2) as i64;
        
        if lines_2.len() == 1  {
            break;
        }
    };

    let oxygen_generator_rating: i64 =  i64::from_str_radix(&lines[0],2).unwrap();
    let co2_scrubber_rating: i64 =  i64::from_str_radix(&lines_2[0],2).unwrap();
    Ok(oxygen_generator_rating * co2_scrubber_rating)
}