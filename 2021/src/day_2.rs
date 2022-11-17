use std::fs; 
use std::io::Error;

#[derive(Debug)]
struct Submarine {
    x: i32,
    y: i32,
    aim: i32
}

impl Submarine {
    fn new() -> Self {
        Submarine {x: 0, y: 0, aim: 0}
    }

    fn result(&self) -> i32 {
        self.x*self.y
    } 

    fn foward(&mut self, distance: i32) ->() {
        self.x += distance
    }

    fn up(&mut self, distance: i32) ->() {
        self.y -= distance
    }

    fn down(&mut self, distance: i32) ->() {
        self.y += distance
    } 

    fn foward_2(&mut self, value: i32) ->() {
        self.x += value;
        self.y += self.aim * value;
    }

    fn up_2(&mut self, value: i32) ->() {
        self.aim -= value
    }

    fn down_2(&mut self, value: i32) ->() {
        self.aim += value
    }
}

pub fn run() -> Result<i32,Error> {
    
    let input = match fs::read_to_string("src\\input\\day_2.txt") {
        Err(error) =>  return Err(error),
        Ok(file) => file 
    };
    let commands: Vec<_> = input.lines().map(|line| {
        line.split_whitespace().collect::<Vec<_>>()
    }).collect();
    
    let mut submarine = Submarine::new();

    commands.iter()
            .for_each(|cmd| {
                let instruction = cmd[0];
                let value = cmd[1].parse().expect("Number");
                match instruction {
                    "forward" => submarine.foward(value),
                    "down" => submarine.down(value),
                    "up" => submarine.up(value),
                    _ => ()
            }
    });

    Ok(submarine.result())
}

pub fn run_2() -> Result<i32,Error> {
    
    let input = match fs::read_to_string("src\\input\\day_2.txt") {
        Err(error) =>  return Err(error),
        Ok(file) => file 
    };
    let commands: Vec<_> = input.lines().map(|line| {
        line.split_whitespace().collect::<Vec<_>>()
    }).collect();
    
    let mut submarine = Submarine::new();

    commands.iter()
            .for_each(|cmd| {
                let instruction = cmd[0];
                let value = cmd[1].parse().expect("Number");
                match instruction {
                    "forward" => submarine.foward_2(value),
                    "down" => submarine.down_2(value),
                    "up" => submarine.up_2(value),
                    _ => ()
            }
    });

    Ok(submarine.result())
}