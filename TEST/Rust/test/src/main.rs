use std::{fs::File, fmt, io::{BufReader, BufRead}};

enum Packet {
    Value(u8),
    Packets(Vec<Packet>),
}

impl fmt::Debug for Packet {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Packet::Value(v) => write!(f, "{}", v),
            Packet::Packets(packets) => {
                write!(f, "[")?;
                for packet in packets {
                    write!(f, "{:?}, ", packet)?;
                }
                write!(f, "]")
            }
        }
    }
}

// "[[1],[2,3,4]]" -> Packets([Packets([Value(1)]), Packets([Value(2), Value(3), Value(4)])])
fn parse_packets(line: &str) -> Packet {
    let contents = &line[1..line.len() - 1];

    let mut packets = vec![];
    let mut packet = vec![];

    for c in contents.chars() {
        match c {
            '[' => {
                packets.push(Packet::Packets(packet));
                packet = vec![];
            }
            ']' => {
                packets.push(Packet::Packets(packet));
                packet = vec![];
            }
            ',' => {
                packets.push(Packet::Packets(packet));
                packet = vec![];
            }
            _ => {
                packet.push(Packet::Value(c.to_digit(10).unwrap() as u8));
            }
        }
    }
}

fn main() {
    // read from file
    let file = File::open("./src/input.txt").unwrap();

    // parse file into packets
    let packets = BufReader::new(file)
        .lines()
        .map(|line| line.unwrap())
        .filter(|line| !line.is_empty())
        .map(|line| parse_packets(&line));

    // print packets
    for packet in packets {
        println!("{:?}", packet);
    }
}