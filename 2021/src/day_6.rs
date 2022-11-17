use std::{fs};
#[derive(Clone)]
struct Laternfish {
    day: i64,
}

impl Laternfish {
    fn new() -> Self {
        Laternfish { day: 8 }
    }

    fn create(count: i64) -> Self {
        Laternfish { day: count }
    }

    fn dec_and_check(&mut self) -> i64 {
        if self.day == 0 {
            self.day = 6;
            return 1;  
        }

        self.day -= 1;

        return 0;
    }
}

pub fn run() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_6.txt").unwrap();

    let mut laternfishs: Vec<Laternfish> = input
                                        .split(",")
                                        .map(|x| Laternfish::create(x.parse::<i64>().unwrap()))
                                        .collect();

    for _ in 0..80 {
        let count_news = laternfishs
                .iter_mut()
                .fold(0, |acc, laternfish | acc + laternfish.dec_and_check());

        let mut new_laternfishs: Vec<Laternfish> = (0..count_news).map(|_| Laternfish::new()).collect();
        
        laternfishs.append(&mut new_laternfishs);
    }

    Ok(laternfishs.len() as i64)
}

pub fn run_2() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_6.txt").unwrap();

    let laternfishs: Vec<i64> = input
                                    .split(",")
                                    .map(|x|x.parse::<i64>().unwrap())
                                    .collect();

    let mut days: [i64; 9] = [0;9];

    laternfishs.iter().for_each(|day| days[*day as usize] += 1);

    for _ in 0..256 {
        days.rotate_left(1);
        days[6] += days[8]; // position 8 has how many new fishs were created plus the ones that reset
    }

    Ok(days.iter().sum::<i64>())
}