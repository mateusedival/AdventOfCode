use std::{fs};

fn check_bounderies(i: i64, j: i64, row: i64, col: i64) -> bool {
     (i < row && i >= 0) && (j < col && j >= 0)
}

pub fn run() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_9.txt").unwrap();

    let matrix: Vec<Vec<i64>> = input
                                .lines()
                                .map(|line| line
                                                    .chars()
                                                    .map(|c| c
                                                                    .to_digit(10)
                                                                    .unwrap() as i64)
                                                    .collect()
                                ).collect();
    
    let row = matrix.len() as i64;
    let col = matrix[0].len() as i64;

    let mut low_points = Vec::new();

    for i in 0..row {
        for j in 0..col {
            let v = vec![(1,0),(0,1),(-1,0),(0,-1)];

            let point =  matrix[i as usize][j as usize];

            let count = v
                            .iter()
                            .fold(0, |acc,(p, q)| {
                                let nb = if check_bounderies(i+p, j+q, row, col) {
                                                matrix[(i+p) as usize][(j+q) as usize]
                                            } else {
                                                10_i64};
                                
                                let is_small = if nb > point {
                                                    1_i64
                                                } else {
                                                    0_i64
                                                };
                                acc + is_small
                            });
            if count == 4 {
                low_points.push(point);
            }
        }
    }

    Ok(low_points.iter().sum::<i64>() + low_points.len() as i64)
}


fn flood_fill(last: i64, i: i64, j: i64, matrix: &Vec<Vec<i64>>, visited: &mut Vec<Vec<bool>>) -> i64 {
    let row = matrix.len() as i64;
    let col = matrix[0].len() as i64;

    let coords = vec![(1,0),(0,1),(-1,0),(0,-1)];

    let point =  matrix[i as usize][j as usize];

    if visited[i as usize][j as usize] || point < last || point == 9{
        return 0;
    }

    
    visited[i as usize][j as usize] = true;

    let mut sum = 0;

    for (p,q) in coords {
        if check_bounderies(i+p, j+q, row, col) {
            sum += flood_fill(point, i+p, j+q, matrix, visited);
        }
    }

    return sum + 1;

}


pub fn run_2() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_9.txt").unwrap();

    let matrix: Vec<Vec<i64>> = input
                                .lines()
                                .map(|line| line
                                                    .chars()
                                                    .map(|c| c
                                                                    .to_digit(10)
                                                                    .unwrap() as i64)
                                                    .collect()
                                ).collect();
    
    let row = matrix.len() as i64;
    let col = matrix[0].len() as i64;

    let mut low_points = Vec::new();

    for i in 0..row {
        for j in 0..col {
            let v = vec![(1,0),(0,1),(-1,0),(0,-1)];

            let point =  matrix[i as usize][j as usize];

            let count = v
                            .iter()
                            .fold(0, |acc,(p, q)| {
                                let nb = if check_bounderies(i+p, j+q, row, col) {
                                                matrix[(i+p) as usize][(j+q) as usize]
                                            } else {
                                                10_i64};
                                
                                let is_small = if nb > point {
                                                    1_i64
                                                } else {
                                                    0_i64
                                                };
                                acc + is_small
                            });
            if count == 4 {
                low_points.push((point,(i,j)));
            }
        }
    }

    let mut visited = vec![vec![false;100];100];

    let mut basins = low_points
                                                .iter()
                                                .map(|(point,(i,j))| {
                                                   flood_fill(point.to_owned() -1, i.to_owned(), j.to_owned(), &matrix, &mut visited)  
                                                })
                                                .collect::<Vec<i64>>();
    basins.sort();


    Ok(basins.iter().rev().take(3).product())

}
