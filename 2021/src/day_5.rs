use std::{fs, cmp};
use std::collections::{HashMap};

pub fn run() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_5.txt").unwrap();

    let mut points = HashMap::new();

    input
        .lines()
        .for_each(|line | {
            let pairs = line.split(" -> ").collect::<Vec<&str>>();
            let p1: Vec<i64> = pairs[0].split(",").map(|s| s.parse::<i64>().unwrap()).collect();
            let p2: Vec<i64> = pairs[1].split(",").map(|s| s.parse::<i64>().unwrap()).collect();

            if p1[0] == p2[0] { 
                let max = cmp::max(p2[1], p1[1]);

                let mut y = cmp::min(p1[1], p2[1]);

                while y <= max {
                    if !points.contains_key(&(p1[0],y)) {
                        points.insert((p1[0],y), 1 as i64);
                    }
                    else {
                        if let Some(point) = points.get_mut(&(p1[0],y)) {
                            *point += 1;
                        }
                    }
                    y+=1;
                }
            }
            if p1[1] == p2[1] {
                let max = cmp::max(p1[0],p2[0]);

                let mut x = cmp::min(p1[0], p2[0]);

                while x <= max {
                    if !points.contains_key(&(x,p1[1])) {
                        points.insert((x, p1[1]), 1 as i64);
                    }
                    else {
                        if let Some(point) = points.get_mut(&(x, p1[1])) {
                            *point += 1;
                        }
                    }
                    x+=1;
                }
            }
        });

    let result = points.values().filter(|point| *point > &1).count() as i64;

    Ok(result)
}

pub fn run_2() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_5.txt").unwrap();

    let mut points = HashMap::new();

    input
        .lines()
        .for_each(|line | {
            let pairs = line.split(" -> ").collect::<Vec<&str>>();
            let p1: Vec<i64> = pairs[0].split(",").map(|s| s.parse::<i64>().unwrap()).collect();
            let p2: Vec<i64> = pairs[1].split(",").map(|s| s.parse::<i64>().unwrap()).collect();

            

            if p1[0] == p2[0] {
                let max = cmp::max(p1[1], p2[1]);

                let mut y = cmp::min(p1[1], p2[1]);

                while y <= max {
                    if !points.contains_key(&(p1[0],y)) {
                        points.insert((p1[0],y), 1 as i64);
                    }
                    else {
                        if let Some(point) = points.get_mut(&(p1[0],y)) {
                            *point += 1;
                        }
                    }
                    y+=1;
                }
            }

            else if p1[1] == p2[1] {
                
                let max = cmp::max(p1[0], p2[0]);

                let mut x = cmp::min(p1[0], p2[0]);

                while x <= max {
                    if !points.contains_key(&(x,p1[1])) {
                        points.insert((x, p1[1]), 1 as i64);
                    }
                    else {
                        if let Some(point) = points.get_mut(&(x, p1[1])) {
                            *point += 1;
                        }
                    }
                    x+=1;
                }
            }
            else {
                let inc_x = if p1[0] > p2[0] {-1} else {1};
                let inc_y = if p1[1] > p2[1] {-1} else {1};
                let mut x = p1[0];
                let mut y = p1[1];

                if !points.contains_key(&(x,y)) {
                    points.insert((x, y), 1 as i64);
                }
                else {
                    if let Some(point) = points.get_mut(&(x, y)) {
                        *point += 1;
                    }
                }

                while x != p2[0] && y != p2[1] {
                    x += inc_x;
                    y += inc_y;

                    if !points.contains_key(&(x,y)) {
                        points.insert((x, y), 1 as i64);
                    }
                    else {
                        if let Some(point) = points.get_mut(&(x, y)) {
                            *point += 1;
                        }
                    }
                } 
            }
        });
    
    let result = points.values().filter(|point| *point > &1).count() as i64;
    Ok(result)
}