use std::{fs};

fn get_value(c: &char) -> i64 {
    match c {
        ')' => 3,
        ']' => 57,
        '}' => 1197,
        '>' => 25137,
         _  => 0,
    }
}

fn get_autocomplete_value(c: &char) -> i64 {
    match c {
        ')' => 1,
        ']' => 2,
        '}' => 3,
        '>' => 4,
         _  => 0,
    }
}

fn get_close_match(c: &char) -> char {
    match c {
        '(' => ')',
        '[' => ']',
        '{' => '}',
        '<' => '>',
         _  => 'x',
    }
}

pub fn run() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_10.txt").unwrap();

    let syntax_error: i64 = input
        .lines()
        .fold(0, |acc, line| {
            let mut stack = Vec::new(); 
            let mut line_value = 0;
            
            for c in line.chars() {
                    let top = stack.iter().last().unwrap_or(&'x').to_owned();

                    if c == '(' || c == '[' || c == '{' || c == '<' {
                        stack.push(c);
                    } else if top == '(' && c != ')' {
                        line_value = get_value(&c);
                        break;
                    } else if top == '[' && c != ']' {
                        line_value = get_value(&c);
                        break;
                    } else if top == '{' && c != '}' {
                        line_value = get_value(&c);
                        break;
                    } else if top == '<' && c != '>' {
                        line_value = get_value(&c);
                        break;
                    } else if top == '(' && c == ')' {
                        stack.pop();
                    } else if top == '[' && c == ']' {
                        stack.pop();
                    } else if top == '{' && c == '}' {
                        stack.pop();
                    } else if top == '<' && c == '>' {
                        stack.pop();
                    }                               
            }
            acc + line_value
        
        });

    Ok(syntax_error)
}

pub fn run_2() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_10.txt").unwrap();

    let mut lines_score: Vec<i64> = input
        .lines()
        .map(|line| {
            let mut stack = Vec::new(); 
            let mut line_value = 0;
            
            for c in line.chars() {
                    let top = stack.iter().last().unwrap_or(&'x').to_owned();

                    if c == '(' || c == '[' || c == '{' || c == '<' {
                        stack.push(c);
                    } else if top == '(' && c != ')' {
                        line_value = get_value(&c);
                        break;
                    } else if top == '[' && c != ']' {
                        line_value = get_value(&c);
                        break;
                    } else if top == '{' && c != '}' {
                        line_value = get_value(&c);
                        break;
                    } else if top == '<' && c != '>' {
                        line_value = get_value(&c);
                        break;
                    } else if top == '(' && c == ')' {
                        stack.pop();
                    } else if top == '[' && c == ']' {
                        stack.pop();
                    } else if top == '{' && c == '}' {
                        stack.pop();
                    } else if top == '<' && c == '>' {
                        stack.pop();
                    }                               
            }

            if line_value == 0 {
                let line_score = stack
                    .iter()
                    .rev()
                    .map(|c| get_autocomplete_value(&get_close_match(&c)))
                    .fold(0, |acc, i| (acc * 5) + i);
                
                return line_score
            } 
            0
        })
        .filter(|i| i != &0)
        .collect();
    
    lines_score.sort();

    Ok(lines_score[lines_score.len()/2 as usize])

}
