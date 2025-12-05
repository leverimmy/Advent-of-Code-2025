fn is_invalid(n: i64) -> i64 {
    let s = n.to_string();
    let half = s.len() / 2;
    if &s[..half] == &s[half..] {
        n
    } else {
        0
    }
}

fn main() {
    let input = std::fs::read_to_string("../assets/input.txt").unwrap();
    let ranges: Vec<&str> = input.trim().split(',').collect();
    let mut result = 0;
    for range in ranges {
        let bounds: Vec<&str> = range.split('-').collect();
        let l = bounds[0].parse::<i64>().unwrap();
        let r = bounds[1].parse::<i64>().unwrap();
        result += (l..=r).map(|n| is_invalid(n)).sum::<i64>();
    }
    println!("{}", result);
}

// Answer: 24747430309
