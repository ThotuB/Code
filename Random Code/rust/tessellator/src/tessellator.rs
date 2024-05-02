use crate::{tessellate::Tessellate, Point};

pub trait Tessellator {
    #[inline]
    fn tessellate<F>(self, f: F) -> Tessellate<Self, F>
    where
        Self: Sized,
        F: FnOnce(Self) -> Vec<Point>
    {
        Tessellate::new(self, f)
    }
}