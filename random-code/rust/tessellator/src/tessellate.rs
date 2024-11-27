use crate::{Point, Vertex};

pub struct Tessellate<S, F>
where
    F: FnOnce(S) -> Vec<Point>,
{
    input: S,
    tessellator: F,
}

impl<S, F> Tessellate<S, F>
where
    F: FnOnce(S) -> Vec<Point>,
{
    pub fn new(input: S, tessellator: F) -> Tessellate<S, F> {
        Tessellate { input, tessellator }
    }

    pub fn color(self, color: [f32; 4]) -> Vec<Vertex> {
        let points = (self.tessellator)(self.input);
        points
            .into_iter()
            .map(|point| Vertex::new([point.0 as f32, point.1 as f32, 0.0], color))
            .collect()
    }
}