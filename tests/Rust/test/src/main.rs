use serde::{Deserialize, Serialize};

use reqwest::Error;

fn main() {
    let plm = "2023-06-16T04:28:43.983Z".to_owned();
    let date_to = chrono::NaiveDate::parse_from_str(&plm, "%Y-%m-%dT%T%.3fZ").unwrap();

    println!("{:?}", date_to);
}
