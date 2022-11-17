use std::iter::FromIterator;
use std::{io::Error, fs, i64};
use std::collections::{HashMap, HashSet};

#[derive(Debug)]
struct Board {
    numbers: HashMap<i64,(usize,usize)>,
    last: i64,
    col: [u8;5],
    row: [u8;5]
}

impl Board {
    fn new(board: &[String]) -> Self {
        let col: [u8;5] = [0;5];
        let row: [u8;5] = [0;5];
        let mut numbers = HashMap::new();
        board
            .iter()
            .enumerate()
            .for_each(|(x, line)| {
                line
                    .split_whitespace()
                    .enumerate()
                    .for_each(|(y, s)| {
                        let key = s.to_string().parse::<i64>().unwrap();
                        numbers.insert(key, (x,y));
                    });
            });
        Board { numbers, last: -1, col, row }
    }

    fn mark_board_and_check(&mut self, drew_number: &i64) -> bool {
        if self.numbers.contains_key(drew_number) {
            self.last = *drew_number;
            let (_, (x, y)) = self.numbers.remove_entry(drew_number).unwrap();
            self.col[x]+=1;
            self.row[y]+=1;

            if self.col[x] == 5 || self.row[y] == 5 {
                return true
            }
        }

        return false
    }

    fn score(&self) -> i64 {
        let sum: i64 = self.numbers.keys().sum();
        sum * self.last
    }
}

pub fn run() -> Result<i64,Error> {
    let input = match fs::read_to_string("src\\input\\day_4.txt") {
        Err(error) =>  return Err(error),
        Ok(file) => file 
    };
    let input: Vec<String> = input.lines().filter(|l| l != &"").map(|a| a.to_string()).collect();
    let numbers = input[0]
                                .split(",")
                                .map(|a| a
                                                .to_string()
                                                .parse::<i64>()
                                                .unwrap()
                                ).collect::<Vec<i64>>();

    let mut boards: Vec<Board> = input[1..]
                                        .chunks(5)
                                        .map(|s| {
                                          Board::new(s)      
                                        }).collect();
    
    for number in numbers {
        for board in &mut boards {
            let win = board.mark_board_and_check(&number);

            if win {
                return Ok(board.score())
                
            }
        }
    };

    Ok(-1)
}

pub fn run_2() -> Result<i64,Error> {
    let input = match fs::read_to_string("src\\input\\day_4.txt") {
        Err(error) =>  return Err(error),
        Ok(file) => file 
    };
    let input: Vec<String> = input.lines().filter(|l| l != &"").map(|a| a.to_string()).collect();
    let numbers = input[0]
                                .split(",")
                                .map(|a| a
                                                .to_string()
                                                .parse::<i64>()
                                                .unwrap()
                                ).collect::<Vec<i64>>();

    let mut boards: Vec<Board> = input[1..]
                                        .chunks(5)
                                        .map(|s| {
                                          Board::new(s)      
                                        }).collect();

    let mut winners: HashSet<usize> = HashSet::from_iter(0..boards.len());
    
    for number in numbers {
        for (idx, board) in (&mut boards).iter_mut().enumerate() {
            let win = board.mark_board_and_check(&number);

            if win && winners.len() == 1 && winners.contains(&idx) {
                return Ok(board.score())
            }

            if win && winners.contains(&idx) {
                winners.remove(&idx);
            }
            
        }
    };

    Ok(-1)
}