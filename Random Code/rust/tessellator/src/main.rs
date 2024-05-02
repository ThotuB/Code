use crate::tessellator::Tessellator;

mod tessellate;
mod tessellator;

struct Point(f64, f64);
struct Triangle(Point, Point, Point);

impl Tessellator for Triangle{}

fn tess_line(tri: Triangle) -> Vec<Point> {
    vec![tri.0, tri.1, tri.2]
}

#[derive(Debug, Copy, Clone)]
pub struct Vertex {
    position: [f32; 3], // x, y, z
    color: [f32; 4],    // r, g, b, a
}

impl Vertex {
    pub fn new(position: [f32; 3], color: [f32; 4]) -> Vertex {
        Vertex { position, color }
    }
}

fn main() {
    let vec = vec![1, 2, 3, 4, 5].iter().map(|x| x * 2).collect::<Vec<i32>>();

    let tri = Triangle(Point(0.0, 0.0), Point(1.0, 1.0), Point(2.0, 2.0)).tessellate(tess_line).color([1.0, 0.0, 0.0, 1.0]);


}
