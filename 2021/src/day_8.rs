use std::{fs};

pub fn run() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_8.txt").unwrap();

    let result = input.lines().fold(0,|count, line|{

        let line: Vec<&str> = line.split(" | ").collect();

        let output:Vec<&str> = line[1].split_whitespace().collect();

        let sum = output.iter().fold(0,|acc, digit|{
            let len = digit.len();
            
            if  len == 2 || len == 3 || len == 7 || len == 4 {
                return acc + 1;
            }
            acc
        });
        count + sum
    });
    Ok(result)
}

struct SevenDisplay {
    digits: Vec<String>,
}

fn diff_char(a: &str, b: &str) -> usize {
    let diff = a.chars().fold(0,|acc, char| {
        if b.contains(char) {
            return acc
        }
        acc + 1
    });

    diff
}

impl SevenDisplay {
    fn new() -> Self {
        Self {
            digits: vec!["".to_string();10],
        }
    }

    fn build(&mut self, digits: Vec<String>) {
        let mut n = vec!["";10];

        n[1] = digits.iter().filter(|digit| (*digit).len() == 2).collect::<Vec<&String>>()[0];
        n[4] = digits.iter().filter(|digit| (*digit).len() == 4).collect::<Vec<&String>>()[0];
        n[7] = digits.iter().filter(|digit| (*digit).len() == 3).collect::<Vec<&String>>()[0];
        n[8] = digits.iter().filter(|digit| (*digit).len() == 7).collect::<Vec<&String>>()[0];
        n[9] = digits.iter().filter(|digit|  diff_char(*digit, n[4]) == 2 && (*digit).len() == 6).collect::<Vec<&String>>()[0];
        n[0] = digits.iter().filter(|digit|  (*digit).len() == 6 && diff_char(n[1], *digit) == 0 && diff_char(n[8], *digit) == 1 && *digit != n[9]).collect::<Vec<&String>>()[0];
        n[6] = digits.iter().filter(|digit|  (*digit).len() == 6 && diff_char(n[1], *digit) == 1 && diff_char(n[8], *digit) == 1).collect::<Vec<&String>>()[0];
        n[2] = digits.iter().filter(|digit|  (*digit).len() == 5 && diff_char(n[1], *digit) == 1 && diff_char(n[4], *digit) == 2).collect::<Vec<&String>>()[0];
        n[3] = digits.iter().filter(|digit|  (*digit).len() == 5 && diff_char(n[1], *digit) == 0 && diff_char(n[4], *digit) == 1).collect::<Vec<&String>>()[0];
        n[5] = digits.iter().filter(|digit|  (*digit).len() == 5 && diff_char(n[1], *digit) == 1 && diff_char(n[4], *digit) == 1).collect::<Vec<&String>>()[0];

        (0..10).for_each(|i| {
            self.digits[i] = n[i].to_string();
        });
    }

    fn display(&self, output: Vec<String>) -> i64 {
        let display = output.iter().map(|out_digit| {

            let mut i = 0;
            for (idx, digit) in self.digits.iter().enumerate() {

                let mut digit: Vec<char> = digit.chars().collect();
                digit.sort();
                
                let mut sorted_digit: Vec<char> = out_digit.chars().collect();
                sorted_digit.sort();

                if digit.iter().collect::<String>() == sorted_digit.iter().collect::<String>() {
                    i = idx;
                    break;
                }
            }
            i.to_string()
        }).collect::<Vec<String>>();

        display.join("").parse::<i64>().unwrap()
    }
}

pub fn run_2() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_8.txt").unwrap();

    let sums: Vec<i64> = input.lines().map(|line| {
        let line: Vec<&str> = line.split(" | ").collect();

        let digits: Vec<String> = line[0].split_whitespace().map(|digit| digit.to_string()).collect();

        let output:Vec<String> = line[1].split_whitespace().map(|digit| digit.to_string()).collect();

        let mut seven_display = SevenDisplay::new();
        seven_display.build(digits);

        let display = seven_display.display(output);

        display
    }).collect::<Vec<i64>>();

    Ok(sums.iter().sum())
}
