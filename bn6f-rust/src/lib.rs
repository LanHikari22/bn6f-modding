pub mod io;

pub fn add(a: i32, b: i32) -> i32 {
    a + b
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::sync::Once;

    static G_INIT_ONCE: Once = Once::new();

    fn init() {
        G_INIT_ONCE.call_once(|| {
            let _ = crate::io::logging::init_logging_with_level(log::LevelFilter::Trace);
        });
    }

    #[test]
    fn test_add() {
        init();

        assert_eq!(add(1, 1), 2);
    }
}
