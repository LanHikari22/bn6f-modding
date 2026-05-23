//! Handles logging related setup and use

use log::{LevelFilter, SetLoggerError};

pub fn init_logging_with_level(level: LevelFilter) -> Result<(), SetLoggerError> {
    env_logger::builder()
        .filter_level(level)
        .filter_module("rustyline", LevelFilter::Warn)
        .try_init()
}
