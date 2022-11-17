use std::{fs};

fn flash(i: i64, j: i64, matrix: &mut Vec<Vec<i64>>, flashed: &mut Vec<Vec<bool>>) -> () {
    let nb = [(1,0),(1,1),(-1,0),(-1,-1),(0,1),(0,-1),(1,-1),(-1,1),];
    flashed[i as usize][j as usize] = true;

    nb
     .iter()
     .for_each(|(p,q)|{
        if let Some(crr_row) = matrix.get_mut((i+p) as usize) {
            if let Some(elem) = crr_row.get_mut((j+q) as usize) {
                *elem += 1;
                if !flashed[(i+p) as usize][(j+q) as usize] && *elem > 9 {
                    flash(i+p,j+q,matrix,flashed);
                }
            }
        }
     });
}
pub fn run() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_11.txt").unwrap();

    let mut matrix: Vec<Vec<i64>> = input
        .lines()
        .map(|line|{
            line
                .chars()
                .map(|c| c.to_digit(10))
                .map(Option::unwrap)
                .map(|digit| digit as i64)
                .collect()
        })
        .collect();

    let steps: usize = 100;
    let mut flashes = 0;

    let row = matrix.len() as i64;
    let col = matrix[0].len() as i64;

    let mut flashed = vec![vec![false;10];10 ];

    for _ in 0..steps {
        for i in 0..row{
            for j in 0..col {
                matrix[i as usize][j as usize] += 1;
                let energy_level = matrix[i as usize][j as usize]; 
                if energy_level > 9 && !flashed[i as usize][j as usize] {
                    flash(i,j,&mut matrix,&mut flashed);
                }
            }
        }
        for i in 0..row{
            for j in 0..col {
                let energy_level = matrix[i as usize][j as usize]; 
                if energy_level > 9 && flashed[i as usize][j as usize] {
                    matrix[i as usize][j as usize] = 0;
                    flashed[i as usize][j as usize] = false;
                    flashes += 1;
                }
            }
        }
        
    }

    Ok(flashes)
}


pub fn run_2() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_11.txt").unwrap();

    let mut matrix: Vec<Vec<i64>> = input
        .lines()
        .map(|line|{
            line
                .chars()
                .map(|c| c.to_digit(10))
                .map(Option::unwrap)
                .map(|digit| digit as i64)
                .collect()
        })
        .collect();

    let mut steps: i64 = 0;
    let mut big_flash = 0;

    let row = matrix.len() as i64;
    let col = matrix[0].len() as i64;

    let mut flashed = vec![vec![false;10];10 ];

    while big_flash != 100 {
        big_flash = 0;
        steps +=1;

        for i in 0..row{
            for j in 0..col {
                matrix[i as usize][j as usize] += 1;
                let energy_level = matrix[i as usize][j as usize]; 
                if energy_level > 9 && !flashed[i as usize][j as usize] {
                    flash(i,j,&mut matrix,&mut flashed);
                }
            }
        }
        for i in 0..row{
            for j in 0..col {
                let energy_level = matrix[i as usize][j as usize]; 
                if energy_level > 9 && flashed[i as usize][j as usize] {
                    matrix[i as usize][j as usize] = 0;
                    flashed[i as usize][j as usize] = false;
                    big_flash += 1;
                }
            }
        }
    }
    Ok(steps)

}
